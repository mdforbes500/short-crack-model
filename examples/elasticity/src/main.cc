/**
*
* short-crack-model.cc
* Author: Malcolm D. Forbes
* License: GNU 3.0
*
**/
#include <deal.II/base/logstream.h>

#include "short_crack.cc"

using namespace dealii;

int main ()
{
  deallog.depth_console (0);
  {
    ShortCrack<2> laplace_problem_2d;
    laplace_problem_2d.run ();

    return 1;
  }

  return 0;
}
