#ifndef BOUNDARYVALUES_H
#define BOUNDARYVALUES_H

#include <deal.II/base/function.h>
#include <deal.II/base/tensor.h>

//Class handeling natural boundary values of system
template <int dim>
class BoundaryValues : public dealii::Function<dim>
{
protected:
<<<<<<< HEAD
  //static constexpr double displacement_value = 0;
  //static const dealii::Tensor<1,dim> grad;
=======
  static const double displacement_value  =   5;
>>>>>>> 951bcd65eaf900631141d8023059be42c3f5e23c
public:
  BoundaryValues () : dealii::Function<dim>() {}    //constructor

  virtual double value (const dealii::Point<dim>   &p,
                        const unsigned int  component = 0) const;

<<<<<<< HEAD
//  virtual dealii::Tensor<1,dim> gradient (const dealii::Point<dim> &p,
//                        const unsigned int component = 0) const;
=======
  virtual Tensor<1,dim> gradient (const dealii::Point<dim> &p,
                        const unsigned int component = 0) const;
>>>>>>> 951bcd65eaf900631141d8023059be42c3f5e23c
};
#endif
