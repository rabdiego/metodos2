#include <string>

#ifndef Vector_H
#define Vector_H

namespace Algebros {
    class Vector {
        private:
            int size;
            double *values;

        public:
            Vector(int);
            Vector(std::string);
            Vector();
            void zeros();
            
            int getSize();
            void setValue(int, double);
            double getValue(int);
            void printVector();

            void setSize(int);

            double getLenght();

            Vector operator+(Vector);
            Vector operator-(Vector);
            Vector operator*(double);
            double operator*(Vector);
            Vector norm();
            void operator<<(Vector);
    };
};

#endif