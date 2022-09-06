#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
//#include "files.h"
//#include "functions.h"
//#include "exactSolution.cpp"
#include "fileHandling.hpp"
#include "TriDiagonalSolver.h"
#include "generalAlgo.hpp"

#define SAMPLE_COUNT 100
#define ERR_CANNOT_OPEN_FILE 1

using namespace std;
double u(double);

int main(int argc, char * argv[]) {
    std::cout << "Hello, World!\n";

    double result[100] = {0};

    string filename = "textfiles/exact.txt";
    std::ofstream output;
    output.open(filename, std::ios::out);
    if(!output)
        {
            std::cerr<<"Cannot open the output file."<<std::endl;
            return ERR_CANNOT_OPEN_FILE;
        }
    
    for (int i=0;i<100;i++) {
        double x = double(i)/SAMPLE_COUNT;
        result[i] = u(x);
//        std::cout << std::setiosflags(std::ios::scientific) << double(i)/SAMPLE_COUNT << "," << result[i] << std::endl;

        output << std::setiosflags(std::ios::scientific) << double(i)/SAMPLE_COUNT << "," << result[i] << std::endl;
    }
    output.close();



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
    
    /*
    vector<double> vectors[2];
    vectors[0] = x;
    vectors[1] = exactSolution(x);
    writeFile("exact.txt",vectors, 2);
    */


    /*computes general solution*/
    
    generalAlgorithm(m);

    return 0;
}
double u(double y) {
    return 1 - (1 - exp(-10))*y - exp(-10*y);
}
