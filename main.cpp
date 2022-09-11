#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

#include "algorithms.cpp"
using namespace std;

#define MAX_RUN 10

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


    double gen_time = 0.0, spe_time = 0.0, tot_gt=0.0, tot_st=0.0;
    
    
    vector<double> exa_sol = writeExact(m); // u
    vector<double> gen_sol; //= generalAlgorithm(m, &gen_time); // v with general algo
//    specialAlgorithm(m,&spe_time); // v with special algo
    
    
    for (int i=0;i<MAX_RUN; i++) {
        gen_sol = generalAlgorithm(m, &gen_time);
        specialAlgorithm(m,&spe_time);
        tot_gt+=gen_time;
        tot_st+=spe_time;
    }
    
    cout << "Average runtime for general algo: " << tot_gt/ MAX_RUN << endl;
    cout << "Average runtime for special algo: " << tot_st/ MAX_RUN << endl;
    
    writeCalError(exa_sol, gen_sol,m, 1); // absolute error
    writeCalError(exa_sol, gen_sol,m, 0); // relative error

    return 0;
}
