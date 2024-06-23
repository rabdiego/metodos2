#ifndef Autos_H
#define Autos_H

#include "libs/algebros/include/Vector.hpp"

namespace Methodic {
    class Autos {
        public:
            Autos(double, Algebros::Vector);
            
            Algebros::Vector eigenvector;
            double eigenvalue;
    };
};

#endif