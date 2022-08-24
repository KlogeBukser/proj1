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

double u(double x);

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    
    double result[100] = {0};
    
    for (int i=0;i<100;i++) {
        double x = double(i)/100;
        result[i] = u(x);
        std::cout << std::setiosflags(std::ios::scientific) << double(i)/100 << "," << result[i] << std::endl;

    }
    
    return 0;
}

double u(double x) {
    return 1 - (1 - exp(-10*x))*x - exp(-10*x);
}


