#include "libs/methodic/include/IntegrationMethod.hpp"

#ifndef GaussLegendre_H
#define GaussLegendre_H

namespace Methodic {
    class GaussLegendre : public IntegrationMethod {
        public:
            double intervalIntegrate(double (*function) (double), double start, double end, int numPoints) override;
            Log integrate(double (*function) (double), double start, double end, double precision, int numPoints);
    };
};

#endif