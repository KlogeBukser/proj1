//
//  main.cpp
//  test
//
//  Created by Bukser Kloge on 24/8/22.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "files.h"
#include "functions.h"
#include "exactSolution.cpp"
#include "readWrite.cpp"
#include "TriDiagonalSolver.cpp"


#define SAMPLE_COUNT 100
using namespace std;

double u(double x);

int main(int argc, char * argv[]) {
    std::cout << "Hello, World!\n";
    /*
    double result[100] = {0};

    for (int i=0;i<100;i++) {
        double x = double(i)/SAMPLE_COUNT;
        result[i] = u(x);
//        std::cout << std::setiosflags(std::ios::scientific) << double(i)/SAMPLE_COUNT << "," << result[i] << std::endl;

        std::ofstream output;
        std::ofstream fs("output.txt");
        if(!fs)
            {
                std::cerr<<"Cannot open the output file."<<std::endl;
                return 1;
            }

        output.open("output.txt", std::ios::out);
        output << std::setiosflags(std::ios::scientific) << double(i)/SAMPLE_COUNT << "," << result[i] << std::endl; // need fixing
        output.close();

    }*/

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
    vector<double> x(m);
    x[0] = 0; x[m-1] = 1;
    double h = double(1)/(m-1);
    for (int i = 1; i < m-1; i++){
      x[i] = x[i-1] + h;
    }
    vector<double> vectors[2];
    vectors[0] = x;
    vectors[1] = exactSolution(x);
    writeFile("exact.txt",vectors, 2);



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
    writeFile("general.txt",genVectors, 2);





    return 0;
}

double u(double x) {
    return 1 - (1 - exp(-10*x))*x - exp(-10*x);
}
