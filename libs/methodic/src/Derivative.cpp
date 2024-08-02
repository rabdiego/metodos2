#include "libs/methodic/include/Derivative.hpp"

using namespace Methodic;

double Derivative::derivate_forward(double (*function) (double), double x, double interval) {
    return (function(x + interval) - function(x))/interval;
}