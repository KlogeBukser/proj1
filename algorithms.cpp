
#include <vector>
#include <cmath>
#include "triDiagonalSolver.cpp"
#include "writeToFile.cpp"

using namespace std;

vector<double> generalAlgorithm(int m) {
    vector<double> x(m);
    x[0] = 0; x[m-1] = 1;
    double h = double(1)/(m-1);
    for (int i = 1; i < m-1; i++){
      x[i] = x[i-1] + h;
    }

    int n = m - 2;
    vector<double> a(n);
    vector<double> b(n);
    vector<double> c(n);
    vector<double> g(n);
    for (int i = 0; i < n; i++){
      a[i] = -1; c[i] = -1; b[i] = 2;
      g[i] = 100*h*h*exp(-10*x[i + 1]); //extra index on x since we're ignoring the first index for this algo
    }

    vector<double> genSol = general(a,b,c,g);

    vector<double> genVectors[2];

    genVectors[0] = x;
    genVectors[1] = genSol;


    string filename("general.txt");
    writeFile(filename, genVectors, 2);

    return genSol;
}

void specialAlgorithm(int m){
  vector<double> x(m);
  x[0] = 0; x[m-1] = 1;
  double h = double(1)/(m-1);
  for (int i = 1; i < m-1; i++){
    x[i] = x[i-1] + h;
  }

  int n = m - 2;
  vector<double> g(n);
  for (int i = 0; i < n-1; i++){
    g[i] = 100*h*h*exp(-10*x[i + 1]); //extra index on x since we're ignoring the first index for this algo
  }
  g[n-1] = 100*h*h*exp(-10*x[n]);
  vector<double> genSol = special(g);

  vector<double> genVectors[2];

  genVectors[0] = x;
  genVectors[1] = genSol;

  string filename("special.txt");
  writeFile(filename, genVectors, 2);
}
