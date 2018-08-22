#include "boundary_values.h"

template <int dim>
virtual double value (const std::vector<dealii::Point<dim> >  &points,
                      const std::vector<deallii::Tensor<dim,1> > &values)
{
  return p.square();
}

/**
REMOVE FOR SAMPLE GRADIENT FUNCTION
For computation of flux boundary conditions
template <int dim>
dealii::Tensor<1,dim> BoundaryValues<dim>::gradient (const dealii::Point<dim> &p,
                                    const unsigned int) const;
{
  N.B.: My original thinking (@mdforbes500)
  Use numerical gradient computation here.
  Assume each element has one gradient across it (gradient averaging) and use
  that for computation. Best method? Dunno. See below for other ideas.

  Another thought is to use automaic differentition
  This is implemented in the deal.II API.
  (see: https://www.dealii.org/9.0.0/doxygen/deal.II/group__auto__symb__diff.html)
  Cool idea. Possibly less error than a numerical gradient, especially with the
  time-stepping we are planning to implement. (@mdforbes500)

  Example function implementation:
  const dealii::Tensor<1,dim> x_minus_xi = p;
  dealii::Tensor<1,dim> return_value = std::exp(-x_minus_xi.norm_square());
  return return_value;
} //FIXME
**/
