#ifndef BOUNDARYVALUES_H
#define BOUNDARYVALUES_H

#include <deal.II/base/function.h>

//Class handeling essential boundary values of system
template <int dim>
class BoundaryValues : public dealii::Function<dim>
{
public:
  BoundaryValues () : dealii::Function<dim>() {}    //constructor

  virtual double value (const dealii::Point<dim>   &p,
                        const unsigned int  component = 0) const;
};
#endif
