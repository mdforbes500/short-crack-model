#ifndef BOUNDARYVALUES_H
#define BOUNDARYVALUES_H

#include <deal.II/base/function.h>
#include <deal.II/base/tensor.h>

//Class handeling natural boundary values of system
template <int dim>
class BoundaryValues : public dealii::Function<dim>
{
protected:
  //static double displacement_value;
  //static const dealii::Tensor<1,dim> grad;
public:
  BoundaryValues () : dealii::Function<dim>() {}    //constructor

  virtual double value (const dealii::Point<dim>   &p,
                        const unsigned int  component = 0) const;

//  virtual dealii::Tensor<1,dim> gradient (const dealii::Point<dim> &p,
//                        const unsigned int component = 0) const;
};
#endif
