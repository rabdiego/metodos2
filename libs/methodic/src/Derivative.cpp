#include "libs/methodic/include/Derivative.hpp"
#include <cmath>

using namespace Methodic;

double Derivative::first_derivative_forward(double (*f) (double), double x, double i) {
    return (f(x + i) - f(x))/i;
}

double Derivative::first_derivative_backward(double (*f) (double), double x, double i) {
    return (f(x) - f(x - i))/i;
}

double Derivative::first_derivative_central(double (*f) (double), double x, double i) {
    return (f(x + i) - f(x - i))/(2 * i);
}

double Derivative::first_derivative(double (*f) (double), double x, double i, int method) {
    if (method == -1) {
        return this->first_derivative_backward(f, x, i);
    } 
    
    if (method == 0) {
        return this->first_derivative_central(f, x, i);
    }

    return this->first_derivative_forward(f, x, i);
}

double Derivative::second_derivative_forward(double (*f) (double), double x, double i) {
    return (f(x + 2*i) - 2*f(x + i) + f(x))/(std::pow(i, 2));
}

double Derivative::second_derivative_backward(double (*f) (double), double x, double i) {
    return (f(x - 2*i) - 2*f(x - i) + f(x))/(std::pow(i, 2));
}

double Derivative::second_derivative_central(double (*f) (double), double x, double i) {
    return (f(x+2*i) + f(x+i) + f(x-i) + f(x-2*i) - 4*f(x))/(5*std::pow(i, 2));
}

double Derivative::second_derivative(double (*f) (double), double x, double i, int method) {
    if (method == -1) {
        return this->second_derivative_backward(f, x, i);
    } 
    
    if (method == 0) {
        return this->second_derivative_central(f, x, i);
    }

    return this->second_derivative_forward(f, x, i);
}