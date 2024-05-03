#include "libs/methodic/include/OpenNewtonCotes.hpp"
#include <cmath>

using namespace Methodic;

double OpenNewtonCotes::intervalIntegrate(double (*function) (double), double start, double end, int numPoints) {
    double h = (end - start)/numPoints;

    switch (numPoints) {
        case 2:
            return (h/3)*(function(start) + 4*function(start + h) + function(end));
        case 3:
            return ((3*h)/8)*(function(start) + 3*function(start + h) + 3*function(start + 2*h) + function(end));
        default:
            return -1;
    }
}

