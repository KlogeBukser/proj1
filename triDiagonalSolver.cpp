#include <iostream>
#include <vector>
using namespace std;

vector<double> general(vector<double> a, vector<double> b, vector<double> c, vector<double> g){
  int n = int(b.size());
  double p;
  vector<double> v(n+2);
  v[0] = 0; v[n+1] = 0;         //boundaries of v, not used in algo
  c[0] = c[0]/b[0];
  g[0] = g[0]/b[0];
  for (int i = 1; i < n-1; i++){
    p = 1/(b[i] - a[i]*c[i-1]);
    c[i] = p*c[i];
    g[i] = p*(g[i] - a[i]*g[i-1]);
  }
  v[n] = (g[n-1] - a[n-1]*g[n-2])/(b[n-1] - a[n-1]*c[n-2]);
  for (int i = n-1; i > 0; i--){
    v[i] = g[i-1] - v[i+1]*c[i-1];
  }
  return v;
}

vector<double> special(vector<double> g){
  int n = int(g.size());
  vector<double> v(n+2);
  vector<double> q(n);
  v[0] = 0; v[n+1] = 0;         //boundaries of v, not used in algo
  g[0] *= 0.5;
  q[0] = 0.5;
  for (int i = 1; i < n; i++){
    q[i] = double(i + 1)/(i + 2);
    g[i] = q[i]*(g[i] + g[i-1]);
  }
  v[n] = q[n-1]*g[n-1];
  for (int i = n-1; i > 0; i--){
    v[i] = q[i-1]*v[i+1] + g[i-1];
  }
  return v;
}
