#include <iostream>
#include <cmath>
#include <vector>

#include "libs/algebros/include/Vector.hpp"
#include "libs/algebros/include/Matrix.hpp"
#include "libs/methodic/include/Autos.hpp"

#include "libs/methodic/include/ExplicitEuler.hpp"
#include "libs/methodic/include/RungeKutta.hpp"

double foo(double x) {
    return (2.0 / 3.0) * x;
}

double bar(double x) {
    return x;
}

double pica(double x) {
    return 0.5 * x;
}

int main() {
    Methodic::RungeKutta* ee = new Methodic::RungeKutta();
    Algebros::Vector v(1);

    v.setValue(0, 2.0);

    double (*foos[])(double) = {&foo};

    std::vector <Algebros::Vector> result = ee->thirdOrder(foos, v, 10, 0.5);

    for (int i = 0; i < 10; i++) {
        result[i].printVector();
    }
}