#ifndef Householder_H
#define Householder_H

#include <utility>

#include "libs/algebros/include/Matrix.hpp"
#include "libs/algebros/include/Vector.hpp"
#include "libs/methodic/include/Autos.hpp"

namespace Methodic {
    class Householder {
        public:
            Algebros::Matrix getHouseholderMatrix(Algebros::Matrix, int);
            std::pair <Algebros::Matrix, Algebros::Matrix> getTridiagonal(Algebros::Matrix);
    };
};

#endif