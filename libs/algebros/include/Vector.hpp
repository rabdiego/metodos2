#ifndef Vector_H
#define Vector_H

namespace Algebros {
    class Vector {
        private:
            int size;
            double *values;

        public:
            Vector(int);
            Vector();
            int getSize();
            void setValue(int, double);
            double getValue(int);
            void printVector();

            Vector operator+(Vector);
            Vector operator*(double);
            Vector norm();
            double dot(Vector);
            void operator<<(Vector);
    };
};

#endif