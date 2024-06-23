#include "libs/methodic/include/IntegrationMethod.hpp"
#include <cmath>

using namespace Methodic;

Log IntegrationMethod::integrate(double (*function) (double), double start, double end, double precision, int numPoints) {
    int itter = -1;
    int numSplit;
    double h;
    double current = 0;
    double previous;
    double error;

    do {
        itter++;
        previous = current;

        numSplit = pow(2, itter);
        h = (end - start)/numSplit;

        current = 0;
        for (int i = 0; i < numSplit; i++) {
            current += this->intervalIntegrate(function, start + i*h, start + (i+1)*h, numPoints);
        }

        error = std::abs((current - previous)/current);
    } while (error > precision);

    Log log(current, itter, numSplit);

    return log;
}