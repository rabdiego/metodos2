#include <iostream>
#include <cmath>
#include "libs/methodic/include/Log.hpp"
#include "libs/methodic/include/IntegrationMethod.hpp"
#include "libs/methodic/include/GaussLegendre.hpp"

double foo(double x) {
    return sin(x) + cos(3*x) + 3;
}

int main() {
    Methodic::IntegrationMethod* model = new Methodic::GaussLegendre();
    std::cout << model->integrate(foo, 0, 10, 1e-3, 2).numPartitions << std::endl;
    std::cout << model->integrate(foo, 0, 10, 1e-3, 2).returnValue << std::endl;
}