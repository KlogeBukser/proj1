#include <time.h>
#include <vector>
#include <cmath>
#include <string>

#include "triDiagonalSolver.cpp"
#include "writeToFile.cpp"

using namespace std;

vector<double> generalAlgorithm(int m, double *time) {
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

    clock_t t1 = clock();
    vector<double> genSol = general(a,b,c,g);
    clock_t t2 = clock();
  
    *time = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
   
    cout << "General algo: n = " << m - 1 << ", t = " << *time << endl;

    vector<double> genVectors[2];

    genVectors[0] = x;
    genVectors[1] = genSol;


    string filename("textfiles/general" + to_string(m-1) + ".txt");
  // writing is slow, commented out
//    writeFile(filename, genVectors, 2);

    return genSol;
}

void specialAlgorithm(int m, double *time){
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

  clock_t t3 = clock();
  vector<double> genSol = special(g);
  clock_t t4 = clock();
  *time = ((double) (t4 - t3)) / CLOCKS_PER_SEC;
  
  cout << "Special algo: n = " << m - 1 << ", t = " << *time << endl;

  vector<double> genVectors[2];

  genVectors[0] = x;
  genVectors[1] = genSol;

  string filename("textfiles/special" + to_string(m-1) + ".txt");
  // writing is slow, commented out
//  writeFile(filename, genVectors, 2);
}

void writeCalError(vector<double> u, vector<double> v, int step, int is_abs) {

    /* calculates the absolute or relative error */

    vector<double> error(step-2);


    vector<double> x(step-2);
    double h = double(1)/(step-1);
    x[0] = h; x[step-3] = 1-h;
    for (int i = 1; i < step-2; i++){
      x[i] = x[i-1] + h;
    }


    string filename;
    if (is_abs) {
        for (int i=1;i<step-2;i++) { // starting from i=1 to avoid boundary points as error is 0 at those points.
            error[i] = log10(abs(u[i]-v[i]));
            filename = "textfiles/abs n = " + to_string(step-1) + ".txt";
        }
    }
    else {
        for (int i=1;i<step-2;i++) { // starting from i=1 to avoid boundary points as error is 0 at those points.
            error[i] = log10(abs(u[i]-v[i])/u[i]);
            filename = "textfiles/rel n = " + to_string(step-1) + ".txt";
        }
    }

    vector<double> error_vectors[2];

    error_vectors[0] = x;
    error_vectors[1] = error;

    writeFile(filename, error_vectors, 2);
}
