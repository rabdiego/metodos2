#ifndef RungeKutta_H
#define RungeKutta_H

#include "libs/algebros/include/Vector.hpp"
#include <vector>

namespace Methodic {
    class RungeKutta {
        public:
            Algebros::Vector firstOrder(double (*function) (double), double, int, double);
            std::vector<Algebros::Vector> secondOrder(double (*functions[]) (double), Algebros::Vector, int, double);
            std::vector<Algebros::Vector> thirdOrder(double (*functions[]) (double), Algebros::Vector, int, double);
    };
};

#endif