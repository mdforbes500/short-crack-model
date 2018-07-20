#ifndef SHORTCRACK_H
#define SHORTCRACK_H

#include <deal.II/dofs/dof_handler.h>
#include <deal.II/grid/grid_generator.h>
#include <deal.II/grid/grid_out.h>
#include <deal.II/grid/tria_accessor.h>
#include <deal.II/grid/tria_iterator.h>
#include <deal.II/dofs/dof_accessor.h>
#include <deal.II/dofs/dof_renumbering.h>
#include <deal.II/fe/fe_q.h>
#include <deal.II/dofs/dof_tools.h>
#include <deal.II/fe/fe_values.h>
#include <deal.II/base/quadrature_lib.h>
#include <deal.II/numerics/vector_tools.h>
#include <deal.II/numerics/matrix_tools.h>
#include <deal.II/lac/vector.h>
#include <deal.II/lac/full_matrix.h>
#include <deal.II/lac/sparse_matrix.h>
#include <deal.II/lac/dynamic_sparsity_pattern.h>
#include <deal.II/lac/solver_cg.h>
#include <deal.II/lac/precondition.h>

#include <deal.II/numerics/data_out.h>

#include <fstream>
#include <iostream>

//ShortCrack Class
template <int dim>
class ShortCrack
{
public:
  ShortCrack ();    //constructor
  void run ();      //run script

private:
  void make_grid ();
  void setup_system();
  void assemble_system ();
  void solve ();
  void output_results () const;

  dealii::Triangulation<dim>   triangulation;
  dealii::FE_Q<dim>            fe;
  dealii::DoFHandler<dim>      dof_handler;

  dealii::SparsityPattern      sparsity_pattern;
  dealii::SparseMatrix<double> system_matrix;

  dealii::Vector<double>       solution;
  dealii::Vector<double>       system_rhs;
};
#endif
