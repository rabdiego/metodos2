#include <iostream>
#include <cmath>
#include <vector>

#include "libs/algebros/include/Vector.hpp"
#include "libs/algebros/include/Matrix.hpp"
#include "libs/methodic/include/Autos.hpp"

#include "libs/methodic/include/ExplicitEuler.hpp"
#include "libs/methodic/include/RungeKutta.hpp"

#include "libs/methodic/include/Derivative.hpp"

double foo(double x) {
    return ((x-2.0)*(x-1.0)*(x)*(x+1.0)*(x+2.0))/120.0;
}

double bar(double x) {
    return x;
}

double pica(double x) {
    return 0.5 * x;
}

int main() {
    Methodic::Derivative* d = new Methodic::Derivative();
    

    std::cout << d->second_derivative(&foo, 2.0, 0.1, 0) << std::endl;
}