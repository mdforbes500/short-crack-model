#include "right_hand_side.h"

template <int dim>
virtual void right_hand_side (const std::vector<dealii::Point<dim> >  &points,
                                const std::vector<deallii::Tensor<dim,1> > &values)
{
  dealii::Point<dim> point_1, point_2;
  point_1(0) = 0.5;
  point_2(0) = -0.5;

  for (unsigned int point_n = 0; point_n < points.size(); ++point_n)
  {
    if(((points[point_n]-point_1).norm_square() < 0.2*0.2) ||
    ((points[point_n]-point_2).norm_square() < 0.2*0.2)))
      values[point_n][0] = 1.0;
    else
      values[point_n][0] = 0.0;

    if (points[point_n].norm_square() < 0.2*0.2)
      values[point_n][1] = 1.0;
    else
        values[point_n][1] = 0.0;
  }
}
