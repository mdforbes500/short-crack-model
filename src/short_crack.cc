#include "short_crack.h"
#include "right_hand_side.cc"
#include "boundary_values.cc"

template <int dim>
ShortCrack<dim>::ShortCrack ()
  :
  fe (1),
  dof_handler (triangulation)
{}

template <int dim>
void ShortCrack<dim>::make_grid ()
{
  dealii::GridGenerator::hyper_cube (triangulation, -1, 1);
  triangulation.refine_global (4);

  std::cout << "   Number of active cells: "
            << triangulation.n_active_cells()
            << std::endl
            << "   Total number of cells: "
            << triangulation.n_cells()
            << std::endl;
}

template <int dim>
void ShortCrack<dim>::setup_system ()
{
  dof_handler.distribute_dofs (fe);

  std::cout << "   Number of degrees of freedom: "
            << dof_handler.n_dofs()
            << std::endl;

  dealii::DynamicSparsityPattern dsp(dof_handler.n_dofs());
  dealii::DoFTools::make_sparsity_pattern (dof_handler, dsp);
  sparsity_pattern.copy_from(dsp);

  system_matrix.reinit (sparsity_pattern);

  solution.reinit (dof_handler.n_dofs());
  system_rhs.reinit (dof_handler.n_dofs());
}

template <int dim>
void ShortCrack<dim>::assemble_system ()
{
  dealii::QGauss<dim>  quadrature_formula(2);

  const RightHandSide<dim> right_hand_side;

  dealii::FEValues<dim> fe_values (fe, quadrature_formula,
                           dealii::update_values   | dealii::update_gradients |
                           dealii::update_quadrature_points | dealii::update_JxW_values);

  const unsigned int   dofs_per_cell = fe.dofs_per_cell;
  const unsigned int   n_q_points    = quadrature_formula.size();

  dealii::FullMatrix<double>   cell_matrix (dofs_per_cell, dofs_per_cell);
  dealii::Vector<double>       cell_rhs (dofs_per_cell);

  std::vector<dealii::types::global_dof_index> local_dof_indices (dofs_per_cell);

  for (const auto &cell: dof_handler.active_cell_iterators())
    {
      fe_values.reinit (cell);
      cell_matrix = 0;
      cell_rhs = 0;

      for (unsigned int q_index=0; q_index<n_q_points; ++q_index)
        for (unsigned int i=0; i<dofs_per_cell; ++i)
          {
            for (unsigned int j=0; j<dofs_per_cell; ++j)
              cell_matrix(i,j) += (fe_values.shape_grad (i, q_index) *
                                   fe_values.shape_grad (j, q_index) *
                                   fe_values.JxW (q_index));

            cell_rhs(i) += (fe_values.shape_value (i, q_index) *
                            right_hand_side.value (fe_values.quadrature_point (q_index)) *
                            fe_values.JxW (q_index));
          }

      cell->get_dof_indices (local_dof_indices);
      for (unsigned int i=0; i<dofs_per_cell; ++i)
        {
          for (unsigned int j=0; j<dofs_per_cell; ++j)
            system_matrix.add (local_dof_indices[i],
                               local_dof_indices[j],
                               cell_matrix(i,j));

          system_rhs(local_dof_indices[i]) += cell_rhs(i);
        }
    }

  std::map<dealii::types::global_dof_index,double> boundary_values;
  dealii::VectorTools::interpolate_boundary_values (dof_handler,
                                            0,
                                            BoundaryValues<dim>(),
                                            boundary_values);
  dealii::MatrixTools::apply_boundary_values (boundary_values,
                                      system_matrix,
                                      solution,
                                      system_rhs);
}

template <int dim>
void ShortCrack<dim>::solve ()
{
  dealii::SolverControl           solver_control (1000, 1e-12);
  dealii::SolverCG<>              solver (solver_control);
  solver.solve (system_matrix, solution, system_rhs,
                dealii::PreconditionIdentity());

  std::cout << "   " << solver_control.last_step()
            << " CG iterations needed to obtain convergence."
            << std::endl;
}

template <int dim>
void ShortCrack<dim>::output_results () const
{
  dealii::DataOut<dim> data_out;

  data_out.attach_dof_handler (dof_handler);
  data_out.add_data_vector (solution, "solution");

  data_out.build_patches ();

  std::ofstream output (dim == 2 ?
                        "solution-2d.vtk" :
                        "solution-3d.vtk");
  data_out.write_vtk (output);
}

template <int dim>
void ShortCrack<dim>::run ()
{
  std::cout << "Solving problem in " << dim << " space dimensions." << std::endl;

  make_grid();
  setup_system ();
  assemble_system ();
  solve ();
  output_results ();
}
