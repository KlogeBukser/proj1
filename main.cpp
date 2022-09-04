#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "exactSolution.cpp"
#include "readWrite.cpp"
#include "TriDiagonalSolver.cpp"


using namespace std;
double u(double);

int main(int argc, char * argv[]) {
    std::cout << "Hello, World!\n";


    /*
    double result[100] = {0};

    std::ofstream output;
    output.open("textfiles/exact.txt", std::ios::out);
    if(!output)
        {
            std::cerr<<"Cannot open the output file."<<std::endl;
            return 1;
        }
    for (int i=0;i<100;i++) {
        double x = double(i)/SAMPLE_COUNT;
        result[i] = u(x);
//        std::cout << std::setiosflags(std::ios::scientific) << double(i)/SAMPLE_COUNT << "," << result[i] << std::endl;

        output << std::setiosflags(std::ios::scientific) << double(i)/SAMPLE_COUNT << "," << result[i] << std::endl; // need fixing
    }
    output.close();
    */


    /*The following section makes an array x, and finds the exact solution*/
    int m;
    if (argc < 2){
      cout << "Choose number of iterations: ";
      cin >> m;
    } else {
      m = atoi(argv[1]);
    }
    while (m < 4){
      cout << "Input must be at least 4, try again: ";
      cin >> m;
    }

    writeFile("textfiles/exact.txt", m, &u);

    vector<double> x(m);
    x[0] = 0; x[m-1] = 1;
    double h = double(1)/(m-1);
    for (int i = 1; i < m-1; i++){
      x[i] = x[i-1] + h;
    }

    /*computes general solution*/
    int n = m - 2;
    vector<double> a(n-1);
    vector<double> b(n);
    vector<double> c(n-1);
    vector<double> g(n);
    for (int i = 0; i < n-1; i++){
      a[i] = -1; c[i] = -1; b[i] = 2;
      g[i] = 100*h*h*exp(-10*x[i + 1]); //extra index on x since we're ignoring the first index for this algo
    }
    b[n-1] = 2;
    g[n-1] = 100*h*h*exp(-10*x[n]);
    vector<double> genSol = general(a,b,c,g);
    vector<double> genVectors[2];
    genVectors[0] = x;
    genVectors[1] = genSol;
    writeFile("textfiles/general.txt",genVectors, 2);


    return 0;
}
double u(double y) {
    return 1 - (1 - exp(-10))*y - exp(-10*y);
}
