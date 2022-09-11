//
//  algorithms.h
//  Comp proj1
//
//  Created by Bukser Kloge on 11/9/22.
//

#ifndef algorithms_h
#define algorithms_h

#include <vector>
using namespace std;

vector<double> generalAlgorithm(int m, double *time);
void specialAlgorithm(int m, double *time);
void writeCalError(vector<double> u, vector<double> v, int step, int is_abs);

#endif /* algorithms_h */
