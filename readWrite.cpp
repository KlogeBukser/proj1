#include files.h
#include <iostream>
#include <fstream>

void writeFile(string filename,vector<double>[] vectors, int nVectors, int lenVectors){
  ofstream outFile;
  outFile.open(filename);
  string line;
  for (vector<double> vec: vectors){
    line = "";
    for (i = 0; i < lenVectors; i++){
      line << vec[i] << " ";
    }
    outfile << line << "/n";
  }
}
