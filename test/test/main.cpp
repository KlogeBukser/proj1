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

#define SAMPLE_COUNT 100

double u(double x);

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";

    double result[100] = {0};

    for (int i=0;i<100;i++) {
        double x = double(i)/SAMPLE_COUNT;
        result[i] = u(x);
//        std::cout << std::setiosflags(std::ios::scientific) << double(i)/SAMPLE_COUNT << "," << result[i] << std::endl;

        std::ofstream output;
        std::ofstream fs("output.txt");
        if(!fs)
            {
                std::cerr<<"Cannot open the output file."<<std::endl;
                return 1;
            }

        output.open("output.txt", std::ios::out);
        output << std::setiosflags(std::ios::scientific) << double(i)/SAMPLE_COUNT << "," << result[i] << std::endl; // need fixing
        output.close();

    }

    return 0;
}

double u(double x) {
    return 1 - (1 - exp(-10*x))*x - exp(-10*x);
}
