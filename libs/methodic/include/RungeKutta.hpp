#ifndef RungeKutta_H
#define RungeKutta_H

#include "libs/algebros/include/Vector.hpp"
#include <vector>

namespace Methodic {
    class RungeKutta {
        public:
            std::vector<Algebros::Vector> firstOrder(double (*functions[]) (double), Algebros::Vector, int, double);
            std::vector<Algebros::Vector> secondOrder(double (*functions[]) (double), Algebros::Vector, int, double);
            std::vector<Algebros::Vector> thirdOrder(double (*functions[]) (double), Algebros::Vector, int, double);
    };
};

#endif