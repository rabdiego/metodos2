#ifndef RegularPower_H
#define RegularPower_H

#include "libs/methodic/include/EigenMethod.hpp"

namespace Methodic {
    class RegularPower : public EigenMethod {
        public:
            Autos findEigen(Algebros::Matrix, Algebros::Vector, double) override;
    };
};

#endif