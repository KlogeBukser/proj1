#include "triDiagonalSolver.h"
#include <iostream>
using namespace std;

vector<double> general(vector<double> a, vector<double> b, vector<double> c, vector<double> g){
  int n = b.size();
  double p;
  vector<double> v(n);
  c[0] = c[0]/b[0]; g[0] = g[0]/b[0];
  for (int i = 1; i < n-1; n++){
    p = 1/(b[i] -a[i]*c[i-1]);
    c[i] = p*c[i]; g[i] = p*g[i];
  }
  v[n-1] = g[n-1]/(b[n-1] - a[n-1]*c[n-2]);
  for (int i = n-2; i > -1; i--){
    v[i] = g[i] - v[i+1]*c[i];
  }
  return v;
}
