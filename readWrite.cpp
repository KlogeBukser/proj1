#include "files.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void writeFile(string filename, vector<double> vectors[], int nVectors){
  ofstream outFile;
  outFile.open(filename);
  vector<double> vec;

  int n = 0;
  for (int i = 0; i < nVectors; i++){
    //Determines length of longest vector
    if (n < vectors[i].size()){
      n = vectors[i].size();
    }
  }

  for (int i = 0; i < n; i++){
    //loops through each element in the vectors
    for (int j = 0; j < nVectors; j++){
      //loops through set of vectors
      vec = vectors[j];
      if (vec.size() < i + 1){
        outFile << ".";
      }
      else{
        outFile << vec[i];
      }
      if (j < nVectors - 1){
        outFile << ",";
      }
    }
    outFile << "\n";
  }
  outFile.close();
}
