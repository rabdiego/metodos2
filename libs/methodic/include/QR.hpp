#ifndef QR_H
#define QR_H

#include <utility>

#include "libs/algebros/include/Matrix.hpp"
#include "libs/algebros/include/Vector.hpp"
#include "libs/methodic/include/Autos.hpp"

namespace Methodic {
    class QR {
        public:
            Algebros::Matrix getQRMatrix(Algebros::Matrix, int, int);
            std::pair <Algebros::Matrix, Algebros::Matrix> innerQRLoop(Algebros::Matrix);
            std::pair <Algebros::Matrix, Algebros::Vector> getDiagonalValues(Algebros::Matrix, double);
            double getSquaredSumBelowDiag(Algebros::Matrix);
    };
};

#endif