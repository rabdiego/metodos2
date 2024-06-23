#include "libs/algebros/include/Vector.hpp"
#include <string>

#ifndef Matrix_H
#define Matrix_H

namespace Algebros {
    class Matrix {
        private:
            int size;
            double *values;

        public:
            Matrix(int);
            Matrix(std::string);
            Matrix();
            void setSize(int);

            int getSize();
            void setValue(int, int, double);
            double getValue(int, int);
            void printMatrix();

            Vector operator*(Vector);
            Matrix operator*(double);
            Matrix operator+(Matrix);
            Matrix operator-(Matrix);
    };
}

#endif