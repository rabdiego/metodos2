#include <iostream>
#include <cmath>
#include "libs/algebros/include/Vector.hpp"
#include "libs/algebros/include/Matrix.hpp"
#include "libs/methodic/include/Autos.hpp"

#include "libs/methodic/include/Derivative.hpp"

double foo(double x) {
    return sin(x) + cos(3*x) + 3;
}

int main() {
    Methodic::Derivative* derivative = new Methodic::Derivative();

    std::cout << derivative->derivate_forward(foo, 2, 1e-10) << std::endl;    
}