#include "libs/methodic/include/InversePower.hpp"
#include "libs/methodic/include/LU.hpp"
#include <cmath>

using namespace Methodic;

Autos InversePower::findEigen(Algebros::Matrix A, Algebros::Vector v0, double e) {
    int size = v0.getSize();

    double l1 = 1;
    double l0 = 0;
    Algebros::Vector v1(size);
    Algebros::Vector v2(size);

    LU lu(A);
    lu.compute();

    v2 << v0;

    while (std::abs((l1 - l0)/l1) > e) {
        l0 = l1;
        v1 << v2;

        v1 << v1.norm();
        v2 = lu.solve(v1);

        l1 = v2 * v1;
    }

    l1 = 1 / l1;

    Autos a(l1, v1);
    return a;
}