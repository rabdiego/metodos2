#include "libs/algebros/include/Vector.hpp"

#ifndef Matrix_H
#define Matrix_H

namespace Algebros {
    class Matrix {
        private:
            int size;
            double *values;

        public:
            Matrix(int);
            int getSize();
            void setValue(int, int, double);
            double getValue(int, int);
            void printMatrix();

            Vector operator*(Vector);
    };
}

#endif