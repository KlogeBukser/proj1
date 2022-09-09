#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

#include "algorithms.cpp"
using namespace std;

//TODO: save u and v in main to pass int error calculations;

int main(int argc, char * argv[]) {

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


    vector<double> exa_sol = writeExact(m); // u
    vector<double> gen_sol = generalAlgorithm(m); // v with general algo
    specialAlgorithm(m); // v with special algo

    writeCalError(exa_sol, gen_sol,m, 1); // absolute error
    writeCalError(exa_sol, gen_sol,m, 0); // relative error

    return 0;
}
