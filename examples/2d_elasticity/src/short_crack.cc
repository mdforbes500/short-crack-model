#include "short_crack.h"
#include "right_hand_side.cc"
#include "boundary_values.cc"

template <int dim>
ShortCrack<dim>::ShortCrack ()
  :
  fe (dealii::FE_Q<dim>(1), dim),
  dof_handler (triangulation)
{}

template <int dim>
ShortCrack<dim>::~ShortCrack()
{
  system_matrix.clear();
}

template <int dim>
void ShortCrack<dim>::make_grid ()
{
  // Reads GMSH type file in and processes it.
  // Requires a square transfinite mesh from GMSH to work.
  dealii::GridIn<dim> gridin;
  gridin.attach_triangulation(triangulation);
  std::ifstream f("../resources/input/mesh.msh");
  gridin.read_msh(f);

  std::cout << "   Reading mesh from file..." << std::endl;
}

template <int dim>
void ShortCrack<dim>::setup_system ()
{
  // Distribute degrees of freedom
  dof_handler.distribute_dofs (fe);
  dealii::DoFRenumbering::Cuthill_McKee (dof_handler);    //optimize w/ C-M

  // Set up hanging node contraints for mesh refinement
  constraints.clear();
  dealii::DoFTools::make_hanging_node_constraints(dof_handler, constraints);

  // Apply Dirichlet boundary conditions
  // BC's held in the BoundaryValues class
  dealii::VectorTools::interpolate_boundary_values (dof_handler,
                                            0,
                                            BoundaryValues<dim>(),
                                            constraints);
  // Close hanging node constraints
  constraints.close();

  // Create sparsity pattern matrix and condense hanging nodes
  dealii::DynamicSparsityPattern dsp(dof_handler.n_dofs(), dof_handler.n_dofs());
  dealii::DoFTools::make_sparsity_pattern (dof_handler, dsp, constraints,
                                           /* keep constrained dofs = */ true);
  constraints.condense(dsp);
  sparsity_pattern.copy_from(dsp);

  // Reinitilize full eqution: A, U, & F
  system_matrix.reinit (sparsity_pattern);    // A -> global stiffness matrix
  solution.reinit (dof_handler.n_dofs());     // U -> global nodes vector
  system_rhs.reinit (dof_handler.n_dofs());   // F -> global force vector

  // Output sparsity pattern image for review
  std::ofstream out("../resources/output/sparsity_pattern.svg");
  sparsity_pattern.print_svg(out);

  // Print the numbber of DOF in system
  std::cout << "   Setting up system..." << std::endl
            << "   Number of degrees of freedom: "
            << dof_handler.n_dofs()
            << std::endl;
}

template <int dim>
void ShortCrack<dim>::assemble_system ()
{
  // Setup quadrature for elements and faces of elements
  // Parameter of QGauss is order of polynomial
  dealii::QGauss<dim>  quadrature_formula(2);
  dealii::QGauss<dim-1> face_quadrature_formula(2);

  /*
   * Constants for assembly:
   *   Number of quadrature points
   *   Number of quadrature points on the external faces
   *   Number of degrees of freedom of each element
   */
  const unsigned int   n_q_points    = quadrature_formula.size();
  //const unsigned int   n_face_q_points    = face_quadrature_formula.size();
  const unsigned int   dofs_per_cell = fe.dofs_per_cell;

  /*
   * Information for each element:
   *   CELL_MATRIX: local stiffness matrix
   *   CELL_RHS: local force vector
   *   LOCAL_DOF_INDICIES: local node numbering
   */
  dealii::FullMatrix<double>   cell_matrix (dofs_per_cell, dofs_per_cell);
  dealii::Vector<double>       cell_rhs (dofs_per_cell);
  std::vector<dealii::types::global_dof_index> local_dof_indices (dofs_per_cell);

  // Applying the quadrature formula to the FE-element
  // Updating the values, gradients, quadrature points, and Jacobian of element
  dealii::FEValues<dim> fe_values (fe, quadrature_formula,
                  dealii::update_values | dealii::update_gradients |
                  dealii::update_quadrature_points | dealii::update_JxW_values);

  // Doing the same thing for the elements on the boundaries
  dealii::FEFaceValues<dim> fe_face_values (fe, face_quadrature_formula,
                  dealii::update_values | dealii::update_gradients |
                  dealii::update_quadrature_points | dealii::update_JxW_values);

  //Force vector object
  const RightHandSide<dim> rhs;

  //Values for lambda and mu (the Lame functions)
  std::vector<double>   lambda_values(n_q_points);
  std::vector<double>   mu_values(n_q_points);

  //Sample constant values for the Lame functions
  dealii::Functions::ConstantFunction<dim> lambda(1.), mu(1.);    //both are 1.0

  //Force vector values allocated from a
  std::vector<Tensor<1, dim> > rhs_values(n_q_points);

  //Begin global assembly loop
  typename dealii::DoFHandler<dim>::active_cell_iterator
                                    cell = dof_handler.begin_active(),
                                    endc = dof_handler.end();
  for (; cell != endc; ++cell)
    {
      cell_matrix = 0;
      cell_rhs = 0;

      fe_values.reinit (cell);

      lambda.value_list(fe_values.get_quadrature_points(), lambda_values);
      mu.value_list(fe_values.get_quadrature_points(), mu_values);
      rhs.right_hand_side(fe_values.get_quadrature_points(), rhs_values);

  // const BoundaryValues<dim> edges; // For Neumann B.C.'s

      // Assembling the vector-valued elements into global stiffness matrix
      for (unsigned int i=0; i<dofs_per_cell; ++i)
      {
        const unsigned int
        component_i = fe.system_to_component_index(i).first;

        for (unsigned int j=0; j<dofs_per_cell; ++j)
          {
            const unsigned int
            component_j = fe.system_to_component_index(j).first;

            for (unsigned int q_point=0; q_point<n_q_points; ++q_point)
            {
              cell_matrix(i,j)
              +=
                (
                 (fe_values.shape_grad (i, q_point)[component_i] *
                  fe_values.shape_grad (j, q_point)[component_j] *
                  lambda_values[q_point])
                  +
                 (fe_values.shape_grad (i, q_point)[component_j]*
                  fe_values.shape_grad (j, q_point)[component_i]*
                  mu_values[q_point])
                  +
                 ((componnt_i == component_j) ?
                  (fe_values.shape_grad (i, q_point)*
                   fe_values.shape_grad (j, q_point)*
                   mu_values[q_point])  :
                 0)
               )
               *
               fe_values.JxW(q_point);
             }
           }
         }
            //Assembly of global force vector
            cell_rhs(i) += (fe_values.shape_value (i, q_point) *
                            right_hand_side.value (
                              fe_values.quadrature_point (q_point)) *
                              fe_values.JxW (q_point));


/*        //Apply and handle Neumann boundary conditions
        for (unsigned int face_number=0; face_number<dealii::GeometryInfo<dim>::faces_per_cell; ++face_number)
          if (cell->face(face_number)->at_boundary()
              &&
              (cell->face(face_number)->boundary_id() == 1))
              {
                fe_face_values.reinit(cell, face_number);

                for (unsigned int q_point=0; q_point<n_face_q_points; ++q_point)
                {
                  const double neumann_value
                    = (edges.gradient(fe_face_values.quadrature_point(q_point)) *
                  fe_face_values.normal_vector(q_point));

                  for (unsigned int i=0; i<dofs_per_cell; ++i)
                  {
                    cell_rhs(i) += (neumann_value *
                                    fe_face_values.shape_value(i, q_point) *
                                    fe_face_values.JxW(q_point));
                  }
                }
              }
*/
      cell->get_dof_indices (local_dof_indices);
      constraints.distribute_local_to_global(cell_matrix, cell_rhs,
                                             local_dof_indices, system_matrix,
                                             system_rhs);
    }
}

template <int dim>
void ShortCrack<dim>::solve ()
{
  dealii::SolverControl           solver_control (1000, 1e-12);
  dealii::SolverCG<>              solver (solver_control);

  dealii::PreconditionSSOR<> preconditioner;
  preconditioner.initialize(system_matrix, 1.2);

  solver.solve (system_matrix, solution, system_rhs, preconditioner);

  constraints.distribute(solution);

  std::cout << "   " << solver_control.last_step()
            << " CG iterations needed to obtain convergence."
            << std::endl;
}

template <int dim>
void ShortCrack<dim>::refine_grid()
{
  dealii::Vector<float> estimated_error_per_cell(triangulation.n_active_cells());

  dealii::KellyErrorEstimator<dim>::estimate(dof_handler, dealii::QGauss<dim-1>(3),
                                             typename dealii::FunctionMap<dim>::type(),
                                             solution, estimated_error_per_cell);

  dealii::GridRefinement::refine_and_coarsen_fixed_number(triangulation,
                                                          estimated_error_per_cell,
                                                          0.3, 0.03);
  triangulation.execute_coarsening_and_refinement();

  std::cout << "   Number of active cells: "
            << triangulation.n_active_cells()
            << std::endl
            << "   Total number of cells: "
            << triangulation.n_cells()
            << std::endl;
}

template <int dim>
void ShortCrack<dim>::output_results (const unsigned int cycle) const
{
  dealii::GridOut grid_out;
  std::ofstream grid_output ("../resources/output/grid-" + std::to_string(cycle) + ".eps");
  grid_out.write_eps(triangulation,grid_output);
  dealii::DataOut<dim> data_out;

  data_out.attach_dof_handler (dof_handler);
  data_out.add_data_vector (solution, "solution");

  data_out.build_patches ();

  std::ostringstream filename;
  filename << "../resources/output/solution-" << cycle << ".eps";
  std::ofstream output (filename.str().c_str());
  data_out.write_eps (output);

  std::cout << "   Writing visualization..." << std::endl;
}

template <int dim>
void ShortCrack<dim>::run ()
{
  std::cout << "Solving problem in " << dim << " space dimensions." << std::endl;
  for (unsigned int cycle = 0; cycle < 8; cycle++)
  {
    if (cycle == 0)
    {
      make_grid();
    }
    else
    {
      refine_grid();
    }
    setup_system ();
    assemble_system ();
    solve ();
    output_results (cycle);
  }
  std::cout << "Done! Have a nice day. :)" << std::endl;
}
