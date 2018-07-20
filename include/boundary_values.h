#ifndef BOUNDARYVALUES_H
#define BOUNDARYVALUES_H

#include <deal.II/base/function.h>
#include <deal.II/base/tensor.h>

//Class handeling natural boundary values of system
template <int dim>
class BoundaryValues : public dealii::Function<dim>
{
protected:
  static const double displacement_value  =   5;
public:
  BoundaryValues () : dealii::Function<dim>() {}    //constructor

  virtual double value (const dealii::Point<dim>   &p,
                        const unsigned int  component = 0) const;

  virtual Tensor<1,dim> gradient (const dealii::Point<dim> &p,
                        const unsigned int component = 0) const;
};
#endif
