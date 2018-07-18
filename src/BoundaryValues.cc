#include "BoundaryValues.h"

template <int dim>
double BoundaryValues<dim>::value (const dealii::Point<dim> &p,
                                   const unsigned int /*component*/) const
{
  return p.square();
}
