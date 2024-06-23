#include <iostream>
#include <cmath>
#include "libs/algebros/include/Vector.hpp"
#include "libs/algebros/include/Matrix.hpp"
#include "libs/methodic/include/Autos.hpp"
#include "libs/methodic/include/RegularPower.hpp"

double foo(double x) {
    return sin(x) + cos(3*x) + 3;
}

int main() {
    int n = 3;

    Algebros::Vector v(n);
    Algebros::Matrix m(n);

    v.setValue(0, 1.0);
    v.setValue(1, 1.0);
    v.setValue(2, 1.0);

    m.setValue(0, 0, 5.0);
    m.setValue(0, 1, 2.0);
    m.setValue(0, 2, 1.0);
    m.setValue(1, 0, 2.0);
    m.setValue(1, 1, 3.0);
    m.setValue(1, 2, 1.0);
    m.setValue(2, 0, 1.0);
    m.setValue(2, 1, 1.0);
    m.setValue(2, 2, 2.0);

    Methodic::RegularPower* method = new Methodic::RegularPower();
    Methodic::Autos a = method->findEigen(m, v, 0.000001);
    a.eigenvector.printVector();
    std::cout << a.eigenvalue << std::endl;
}