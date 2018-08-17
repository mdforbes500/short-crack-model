#ifndef RIGHTHANDSIDE_H
#define RIGHTHANDSIDE_H

#include <deal.II/base/function.h>

//Class handeling right hand side of equation
template <int dim>
class RightHandSide : public dealii::Function<dim>
{
public:
  RightHandSide () : dealii::Function<dim>() {}   //constructor

  virtual double value (const dealii::Point<dim>   &p,
                        const unsigned int  component = 0) const;
};
#endif
