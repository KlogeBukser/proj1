#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;


double u(double y) {
    if (y > 1 - 1e-12){
      return 0;
    }
    return 1 - (1 - exp(-10))*y - exp(-10*y);
}

vector<double> writeExact(int n){
  /*Takes filename, number of steps,
  and a function to write two vectors to file without using vector elements*/
    double x = 0;
    double h = double(1)/(n - 1);
    vector<double> exa_sol(n);
    std::ofstream output;
    output.open("exact.txt", std::ios::out);
//    output.open("textfiles/exact.txt", std::ios::out);
    if(!output)
      {
          std::cerr<<"Cannot open the output file."<<std::endl;
      }
    for (int i = 0; i < n; i++) {
      output << std::setiosflags(std::ios::scientific) << x << "," << u(x) << std::endl;
      x += h;
      exa_sol[i] = u(x);
    }

    output.close();
    return exa_sol;
}

void writeFile(string filename, vector<double> vectors[], int nVectors){
  /*This version takes any number of vectors and write them all to file*/
    ofstream outFile;
    outFile.open(filename);
    vector<double> vec;

    unsigned long n = vectors[0].size();

    for (int i = 0; i < n; i++){
    //loops through each element in the vectors
    for (int j = 0; j < nVectors; j++){
      //loops through set of vectors
      vec = vectors[j];
      outFile << std::setiosflags(std::ios::scientific) << vec[i];
      if (j < nVectors - 1){
        outFile << ",";
      }
    }
        outFile << std::endl;
  }
  outFile.close();
}
