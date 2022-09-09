//
//  calError.cpp
//  Comp proj1
//
//  Created by Bukser Kloge on 7/9/22.
//

#include <vector>
#include <cmath>

using namespace std;

// TODO: calculate u(x) - v_x without boundary points

vector<double> logAbsError(vector<double> u, vector<double> v, int step) {
    
    vector<double> error(step);
    error[0] = 0.0;
    error[step-1] = 0.0;
    
    for (int i=1;i<step;i++) { // starting from i=1 to avoid boundary points as error is 0 at those points.
        error[i] = log10(abs(u[i]-v[i]));
        
    }
    return error;
}


