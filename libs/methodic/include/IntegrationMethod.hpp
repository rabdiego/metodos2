#include "libs/methodic/include/Log.hpp"

#ifndef IntegrationMethod_H
#define IntegrationMethod_H

namespace Methodic {
    class IntegrationMethod {
        public:
            virtual double intervalIntegrate(double (*function) (double), double start, double end, int numPoints) = 0;
            Log integrate(double (*function) (double), double start, double end, double precision, int numPoints);
    };
};

#endif

