#ifndef RegularPower_H
#define RegularPower_H

#include "libs/algebros/include/Vector.hpp"
#include "libs/algebros/include/Matrix.hpp"
#include "libs/methodic/include/Autos.hpp"

namespace Methodic {
    class RegularPower {
        public:
            Autos findEigen(Algebros::Matrix, Algebros::Vector, double);
    };
};

#endif