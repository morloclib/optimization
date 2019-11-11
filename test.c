#include "optimization.hpp"

double fn1(double x){
    return cos(x) + 1;
}

int
main (void)
{
  double m;

  m = optimize1D(fn1, 0.0, 6.0, 10);

  printf("%f\n", m);

  return 0;
}
