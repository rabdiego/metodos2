#ifndef InversePower_H
#define InversePower_H

#include "libs/methodic/include/EigenMethod.hpp"

namespace Methodic {
    class InversePower : public EigenMethod {
        public:
            Autos findEigen(Algebros::Matrix, Algebros::Vector, double) override;
    };
};

#endif