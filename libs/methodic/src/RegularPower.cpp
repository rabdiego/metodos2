#include "libs/methodic/include/RegularPower.hpp"

using namespace Methodic;

double myAbs(double x) {
    if (x > 0) { return x; }
    return -x;
}

Autos RegularPower::findEigen(Algebros::Matrix A, Algebros::Vector v0, double e) {
    int size = v0.getSize();

    double l1 = 1;
    double l0 = 0;
    Algebros::Vector v1(size);
    Algebros::Vector v2(size);

    v2 << v0;

    while (myAbs((l1 - l0)/l1) > e) {
        l0 = l1;
        v1 << v2;

        v1 << v1.norm();
        v2 << A * v1;

        l1 = v2.dot(v1);
    }

    Autos a(l1, v1);
    return a;
}