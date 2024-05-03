#include "libs/methodic/include/IntegrationMethod.hpp"

#ifndef OpenNewtonCotes_H
#define OpenNewtonCotes_H

namespace Methodic {
    class OpenNewtonCotes : public IntegrationMethod {
        public:
            double intervalIntegrate(double (*function) (double), double start, double end, int numPoints) override;
    };
};

#endif