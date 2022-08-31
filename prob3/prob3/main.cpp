//
//  main.cpp
//  prob3
//
//

#include <iostream>
#include <cmath>>

//TODO: make a struct to store values and RK4 function takes 1 val at a time

double f(double x) {
    
    return 100*exp(-10x);
}

typedef struct con_t {
    double x_i = 0;
    double x_f = 1;
    double u_i = 0;
    double u_f = 0;
} boundaries;


double* RK4(const int steps, double x_i, double x_f, double u_i, double u_f, double(*f)(double) );

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    const int steps = 10;
    
    double* x = new double(steps);
    
    for (int i=0; i<steps; i++) {
        std::cout << x[i] << std:: endl;
    }
    
    
    return 0;
}

// v is the approximation of u
void euler2(con_t bc, double x, double* v, double dudx, double dwdx, double step_size) {
    
    *v += step_size * dudx - 0.5 * step_size * step_size * f(x);
    
}
//double RK4(const int steps, double x_i, double x_f, double u_i, double u_f, double(*f)(double), double curr_val) {
//
//
//
//    return 0.0;
//}
