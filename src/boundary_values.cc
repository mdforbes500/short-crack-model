#include "boundary_values.h"

template <int dim>
double BoundaryValues<dim>::value (const dealii::Point<dim> &p,
                                   const unsigned int /*component*/) const
{
  return p.square();
}

//template <int dim>
//dealii::Tensor<1,dim> BoundaryValues<dim>::gradient (const dealii::Point<dim> &p,
//                                    const unsigned int /*component*/) const
//{
  //Should have numerical gradient computation here.
  //Assume each element has one gradient across it (gradient averaging) and use
  //that for computation. Best method? Dunno. But it is all I can come up with
  //right now. Possible to modify this technique later.

  //Use a domain-averaging gradient (in 2D area- and in 3D volume-averaging)
  //const dealii::Tensor<1,dim> x_minus_xi = p;
  //dealii::Tensor<1,dim> return_value = std::exp(-x_minus_xi.norm_square());
  //return return_value;
//}
