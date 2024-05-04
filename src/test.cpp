#include <iostream>
#include <cmath>
#include "libs/methodic/include/Log.hpp"
#include "libs/methodic/include/IntegrationMethod.hpp"
#include "libs/methodic/include/GaussLegendre.hpp"
#include "libs/methodic/include/OpenNewtonCotes.hpp"

double foo(double x) {
    return sin(x) + cos(3*x) + 3;
}

int main() {
    std::cout << "Gauss Legendre" << std::endl;

    Methodic::IntegrationMethod* gauss = new Methodic::GaussLegendre();

    for (int i = 2; i <= 4; i++) {
        std::cout << gauss->integrate(foo, 0, 10, 1e-4, i).numPartitions << std::endl;
        std::cout << gauss->integrate(foo, 0, 10, 1e-4, i).returnValue << std::endl;
    }

    std::cout << "Open Newton Cotes" << std::endl;
    
    Methodic::IntegrationMethod* newton = new Methodic::OpenNewtonCotes();

    for (int i = 2; i <= 4; i++) {
        std::cout << newton->integrate(foo, 0, 10, 1e-4, i).numPartitions << std::endl;
        std::cout << newton->integrate(foo, 0, 10, 1e-4, i).returnValue << std::endl;
    }
}