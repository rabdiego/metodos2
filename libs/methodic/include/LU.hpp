#ifndef LU_H
#define LU_H

#include "libs/algebros/include/Vector.hpp"
#include "libs/algebros/include/Matrix.hpp"

namespace Methodic {
    class LU {
        private:
            Algebros::Matrix M;
            Algebros::Matrix L;
            Algebros::Matrix U;
        
        public:
            LU();
            void setMatrix(Algebros::Matrix);
            LU(Algebros::Matrix);

            void compute();
            Algebros::Vector solve(Algebros::Vector);

            Algebros::Matrix getL();
            Algebros::Matrix getU();
    };
};

#endif