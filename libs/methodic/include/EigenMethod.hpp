#ifndef EigenMethod_H
#define EigenMethod_H

#include "libs/algebros/include/Vector.hpp"
#include "libs/algebros/include/Matrix.hpp"
#include "libs/methodic/include/Autos.hpp"

namespace Methodic {
    class EigenMethod {
        public:
            virtual Autos findEigen(Algebros::Matrix, Algebros::Vector, double) = 0;
    };
};

#endif
