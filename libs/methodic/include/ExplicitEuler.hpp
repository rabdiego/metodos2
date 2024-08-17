#ifndef ExplicitEuler_H
#define ExplicitEuler_H

#include "libs/algebros/include/Vector.hpp"
#include <vector>

namespace Methodic {
    class ExplicitEuler {
        public:
            std::vector<Algebros::Vector> compute(double (*functions[]) (double), Algebros::Vector, int, double);
    };
};


#endif