#include <iostream>
#include <cmath>
#include <vector>

#include "libs/algebros/include/Vector.hpp"
#include "libs/algebros/include/Matrix.hpp"
#include "libs/methodic/include/Autos.hpp"

#include "libs/methodic/include/ExplicitEuler.hpp"
#include "libs/methodic/include/RungeKutta.hpp"

double foo(double x) {
    return -10.0 - (0.25/2.0)*x;
}

double bar(double x) {
    return x;
}

int main() {
    
    Methodic::RungeKutta* rk = new Methodic::RungeKutta();
    Methodic::ExplicitEuler* ee = new Methodic::ExplicitEuler();
    Algebros::Vector v(2);

    v.setValue(0, 5.0);
    v.setValue(1, 200.0);

    double (*foos[])(double) = {&foo, &bar};
    
    std::vector<Algebros::Vector> result = rk->secondOrder(foos, v, 200, 0.1);
     std::vector<Algebros::Vector> result2 = ee->compute(foos, v, 200, 0.1);

    for (int i = 0; i < 100; i += 10) {
        result[i].printVector();
    }
    std::cout << std::endl;
    for (int i = 0; i < 100; i += 10) {
        result2[i].printVector();
    }
}