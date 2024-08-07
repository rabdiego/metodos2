#ifndef Jacobi_H
#define Jacobi_H

#include <utility>

#include "libs/algebros/include/Matrix.hpp"
#include "libs/algebros/include/Vector.hpp"
#include "libs/methodic/include/Autos.hpp"

namespace Methodic {
    class Jacobi {
        public:
            Algebros::Matrix getJacobiMatrix(Algebros::Matrix, int, int);
            std::pair <Algebros::Matrix, Algebros::Matrix> innerJacobiLoop(Algebros::Matrix);
            std::pair <Algebros::Matrix, Algebros::Vector> getDiagonalValues(Algebros::Matrix, double);
            double getSquaredSumBelowDiag(Algebros::Matrix);
    };
};

#endif