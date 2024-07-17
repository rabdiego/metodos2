#include <iostream>
#include <cmath>
#include "libs/algebros/include/Vector.hpp"
#include "libs/algebros/include/Matrix.hpp"
#include "libs/methodic/include/Autos.hpp"

#include "libs/methodic/include/EigenMethod.hpp"
#include "libs/methodic/include/RegularPower.hpp"
#include "libs/methodic/include/InversePower.hpp"
#include "libs/methodic/include/DisplacementPower.hpp"
#include "libs/methodic/include/Householder.hpp"

double foo(double x) {
    return sin(x) + cos(3*x) + 3;
}

int main() {
    Algebros::Vector v("data/V5.txt");
    Algebros::Matrix m("data/M5x5.txt");

    Methodic::Householder* house_method = new Methodic::Householder();
    std::pair<Algebros::Matrix, Algebros::Matrix> house_pair = house_method->getTridiagonal(m);

    std::cout << "Matriz A barra\n"; 
    (std::get<0>(house_pair)).printMatrix();

    std::cout << "Matriz H\n";
    (std::get<1>(house_pair)).printMatrix();

    Methodic::EigenMethod* regular_power = new Methodic::RegularPower();
    Methodic::Autos a_bar_eigen = regular_power->findEigen(std::get<0>(house_pair), v, 1e-10);

    std::cout << "Autovetor de A barra\n";
    a_bar_eigen.eigenvector.printVector();
    std::cout << "Autovalor de A barra\n";
    std::cout << a_bar_eigen.eigenvalue << std::endl;

    Algebros::Vector a_eigenvector = std::get<1>(house_pair) * a_bar_eigen.eigenvector;
    std::cout << "Autovetor de A\n";
    a_eigenvector.printVector();

    Algebros::Vector l_a_eigenvector = m * a_eigenvector;
    double eigenvalue = l_a_eigenvector.getValue(0) / a_eigenvector.getValue(0);
    std::cout << "Autovalor de A\n" << eigenvalue << std::endl;
}