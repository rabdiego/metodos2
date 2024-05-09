#include "libs/methodic/include/OpenNewtonCotes.hpp"
#include <cmath>

using namespace Methodic;

double OpenNewtonCotes::intervalIntegrate(double (*function) (double), double start, double end, int numPoints) {
    double h = (end - start)/(numPoints + 2);

    switch (numPoints) {
        case 2:
            return ((4*h)/3)*(2*function(start + h) - function(start + 2*h) + 2*function(start + 3*h));
        case 3:
            return ((5*h)/24)*(11*function(start + h) + function(start + 2*h) + function(start + 3*h) + 11*function(start + 4*h));
        case 4:
            return ((3*h)/10)*(11*function(start + h) - 14*function(start + 2*h) + 26*function(start + 3*h) - 14*function(start + 4*h) + 11*function(start + 5*h));
        default:
            return -1;
    }
}

