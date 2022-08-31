#include "triDiagonalSolver.h"
#include <iostream>


void general(double *ap, double *bp, double *cp, double *gp, double *vp, int n){
  double p;
  c[0] = c[0]/b[0]; g[0] = g[0]/b[0];
  for (int i = 1; i < n-1; n++){
    p = 1/(b[i] -a[i]*c[i-1]);
    c[i] = p*c[i]; g[i] = p*g[i];
  }
  v[n-1] = g[n-1]/(b[n-1] - a[n-1]*c[n-2]);
  for (int i = n-2; i > -1; i--){
    v[i] = g[i] - v[i+1]*c[i];
  }
  return;
}
