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

            void setSize(int);

            Vector operator+(Vector);
            Vector operator*(double);
            double operator*(Vector);
            Vector norm();
            void operator<<(Vector);
    };
};

#endif