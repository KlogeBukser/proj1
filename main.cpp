#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

#include "generalAlgo.cpp"
#include "calError.hpp"
using namespace std;

//TODO: save u and v in main to pass int error calculations;

int main(int argc, char * argv[]) {
    std::cout << "Hello, World!\n";

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

    writeExact(m); // u
    generalAlgorithm(m); // v
    
    vector<double> errors = logAbsError(m);
    

    return 0;
}
