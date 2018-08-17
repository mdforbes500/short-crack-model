#ifndef RIGHTHANDSIDE_H
#define RIGHTHANDSIDE_H

#include <deal.II/base/function.h>
#include <deal.II/base/tensor.h>

#include <deal.II/lac/vector.h>

//Class handeling right hand side of equation
template <int dim>
class RightHandSide : public dealii::Function<dim>
{
public:
  RightHandSide () : dealii::Function<dim>() {}   //constructor

  virtual void right_hand_side (const std::vector<dealii::Point<dim> >  &points,
                            const std::vector<deallii::Tensor<dim,1> > &values);
};
#endif
