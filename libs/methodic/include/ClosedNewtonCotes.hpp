#include "libs/methodic/include/IntegrationMethod.hpp"

#ifndef ClosedNewtonCotes_H
#define ClosedNewtonCotes_H

namespace Methodic {
    class ClosedNewtonCotes : public IntegrationMethod {
        public:
            double intervalIntegrate(double (*function) (double), double start, double end, int numPoints) override;
    };
};

#endif