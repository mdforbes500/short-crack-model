#ifndef BOUNDARYVALUES_H
#define BOUNDARYVALUES_H

#include <deal.II/base/function.h>
#include <deal.II/base/tensor.h>

//Class handeling boundary conditions of system
template <int dim>
class BoundaryValues : public dealii::Function<dim>
{
protected:
  /** STORES GRADIENT VALUE FOR CONSTANT GRADIENT
  static const dealii::Tensor<1,dim> grad;           //FIXME
  **/
public:
  BoundaryValues () : dealii::Function<dim>() {}    //constructor

  //Dirichlet B.C. method for Vector-valued elastic system
  virtual double value (const std::vector<dealii::Point<dim> >  &points,
                        const std::vector<deallii::Tensor<dim,1> > &values)

/** REMOVE COMMENT FOR WORKING ON NEUMANN B.C.'s
  virtual dealii::Tensor<1,dim> gradient (const dealii::Point<dim> &p,
                       const unsigned int component = 0) const; //FIXME
**/
};
#endif
