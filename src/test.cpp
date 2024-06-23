#include <iostream>
#include <cmath>
#include "libs/algebros/include/Vector.hpp"
#include "libs/algebros/include/Matrix.hpp"
#include "libs/methodic/include/Autos.hpp"

#include "libs/methodic/include/EigenMethod.hpp"
#include "libs/methodic/include/RegularPower.hpp"
#include "libs/methodic/include/InversePower.hpp"
#include "libs/methodic/include/DisplacementPower.hpp"

double foo(double x) {
    return sin(x) + cos(3*x) + 3;
}

int main() {
    Algebros::Vector v("data/V5.txt");
    Algebros::Matrix m("data/M5x5.txt");

    Methodic::EigenMethod* r_method = new Methodic::RegularPower();
    Methodic::Autos a = r_method->findEigen(m, v, 1e-10);
    a.eigenvector.printVector();
    std::cout << a.eigenvalue << std::endl << std::endl;

    Methodic::EigenMethod* i_method = new Methodic::InversePower();
    Methodic::Autos b = i_method->findEigen(m, v, 1e-10);
    b.eigenvector.printVector();
    std::cout << b.eigenvalue << std::endl << std::endl;

    Methodic::DisplacementPower* d_method = new Methodic::DisplacementPower();
    d_method->setM(20);
    Methodic::Autos c = d_method->findEigen(m, v, 1e-10);
    c.eigenvector.printVector();
    std::cout << c.eigenvalue << std::endl << std::endl;
}