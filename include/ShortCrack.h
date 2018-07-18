#ifndef SHORTCRACK_H
#define SHORTCRACK_H
#include "short-crack-model.h"

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
