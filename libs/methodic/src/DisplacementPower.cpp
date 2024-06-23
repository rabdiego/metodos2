#include "libs/methodic/include/DisplacementPower.hpp"
#include "libs/methodic/include/InversePower.hpp"
#include <cmath>

using namespace Methodic;

void DisplacementPower::setM(double m) { this->m = m; }

Autos DisplacementPower::findEigen(Algebros::Matrix A, Algebros::Vector v0, double e) {
    int size = v0.getSize();

    Algebros::Matrix I(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) { I.setValue(i, j, 1.0); }
            else { I.setValue(i, j, 0.0); }
        }
    }

    I = I * this->m;
    Algebros::Matrix Ah = A - I;
    InversePower* inverse = new InversePower();

    Autos a = inverse->findEigen(Ah, v0, e);
    a.eigenvalue += this->m;

    return a;
}