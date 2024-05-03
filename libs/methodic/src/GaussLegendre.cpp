#include "libs/methodic/include/GaussLegendre.hpp"
#include <cmath>

using namespace Methodic;

double twoPointRoots[] = { -sqrt(1.0/3.0), sqrt(1.0/3.0) };
double twoPointWeights[] = { 1.0, 1.0 };

double threePointRoots[] = { -sqrt(3.0/5.0), 0 , sqrt(3.0/5.0) };
double threePointWeights[] = { 5.0/9.0, 8.0/9.0, 5.0/9.0 };

double* roots[] = { twoPointRoots, threePointRoots };
double* weights[] = { twoPointWeights, threePointWeights };

double variableChange(double a, double start, double end) {
    return (start + end)/2 + ((end - start)/2)*a;
}

double GaussLegendre::intervalIntegrate(double (*function) (double), double start, double end, int numPoints) {
    double sum = 0;

    for (int i = 0; i < numPoints; i++) {
        sum += function(variableChange(roots[numPoints - 2][i], start, end)) * weights[numPoints - 2][i];
    }

    return sum*((end - start)/2);
}

