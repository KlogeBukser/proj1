#include "functions.h"
#include <iostream>
#include <vector>
using namespace std;

vector<double> exactSolution(vector<double> x){
  int n = x.size();
  vector<double> result(n);
  double a = v(x[0]);
  for (int i = 0; i < n-1; i++) {
      //Produces the known solution of the Poisson equation
      result[i] = v(x[i]);
  }
  result[n-1] = 0;
  return result;
}

double v(double y) {
    return 1 - (1 - exp(-10))*y - exp(-10*y);
}
