#include <iostream>
#include <cmath>
#include <vector>

#include "libs/algebros/include/Vector.hpp"
#include "libs/algebros/include/Matrix.hpp"
#include "libs/methodic/include/Autos.hpp"

#include "libs/methodic/include/ExplicitEuler.hpp"


double foo(double x) {
    return -10.0 - (0.25/2.0)*x;
}

double bar(double x) {
    return x;
}

int main() {
    
    Methodic::ExplicitEuler* ee = new Methodic::ExplicitEuler();
    Algebros::Vector v(2);

    v.setValue(0, 5.0);
    v.setValue(1, 200.0);

    double (*foos[])(double) = {&foo, &bar};
    
    std::vector<Algebros::Vector> result = ee->compute(2, foos, v, 200, 0.1);

    for (int i = 0; i < 200; i += 10) {
        result[i].printVector();
    }
}