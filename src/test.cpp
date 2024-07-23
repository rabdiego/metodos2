#include <iostream>
#include <cmath>
#include "libs/algebros/include/Vector.hpp"
#include "libs/algebros/include/Matrix.hpp"
#include "libs/methodic/include/Autos.hpp"

#include "libs/methodic/include/EigenMethod.hpp"
#include "libs/methodic/include/RegularPower.hpp"
#include "libs/methodic/include/InversePower.hpp"
#include "libs/methodic/include/DisplacementPower.hpp"
#include "libs/methodic/include/Jacobi.hpp"

double foo(double x) {
    return sin(x) + cos(3*x) + 3;
}

int main() {
    Algebros::Vector v("data/V5.txt");
    Algebros::Matrix m("data/M5x5.txt");

    Methodic::Jacobi* jacobi = new Methodic::Jacobi();

    std::pair <Algebros::Matrix, Algebros::Vector> teste = jacobi->getDiagonalValues(m, 1e-6);

    (std::get<1>(teste)).printVector();

}