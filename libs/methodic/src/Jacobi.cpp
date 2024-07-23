#include "libs/methodic/include/Jacobi.hpp"
#include <cmath>
#include <iostream>

using namespace Methodic;

Algebros::Matrix Jacobi::getJacobiMatrix(Algebros::Matrix A, int i, int j) {
    int size = A.getSize();
    
    Algebros::Matrix J(size);
    double e = 1e-6, theta;
    J.I();

    if (std::abs(A.getValue(i, j)) < e) {
        return J;
    }

    if (std::abs(A.getValue(i, i) - A.getValue(j, j)) <= e) {
        theta = 3.14159265359 / 4;
    } else {
        theta = 0.5 * atan((-2 * A.getValue(i,j))/(A.getValue(i, i) - A.getValue(j, j)));
    }

    J.setValue(i, i, cos(theta));
    J.setValue(j, j, cos(theta));
    J.setValue(i, j, sin(theta));
    J.setValue(j, i, -sin(theta));

    return J;
}

std::pair <Algebros::Matrix, Algebros::Matrix> Jacobi::innerJacobiLoop(Algebros::Matrix A) {
    int n = A.getSize();
    
    Algebros::Matrix J(n), J_ij(n), A_n(n), A_v(n), A_b(n);

    J.I();
    A_v = A;

    for (int j = 0; j < n-1; j++) {
        for (int i = j+1; i < n; i++) {
            J_ij = this->getJacobiMatrix(A_v, i, j);

            A_n = J_ij.T() * A_v * J_ij;

            A_v = A_n;

            J = J * J_ij;
        }
    }

    std::pair <Algebros::Matrix, Algebros::Matrix> return_value{A_n, J};
    return return_value;
}

double Jacobi::getSquaredSumBelowDiag(Algebros::Matrix A) {
    int n = A.getSize();

    double result = 0;

    for (int i = 1; i < n-1; i++) {
        for (int j = 0; j < i; j++) {
            result += A.getValue(i, j) * A.getValue(i, j);
        }
    }

    return result;
}

std::pair <Algebros::Matrix, Algebros::Vector> Jacobi::getDiagonalValues(Algebros::Matrix A, double e) {
    int n = A.getSize();
    
    Algebros::Matrix P(n), J(n), A_n(n), A_v(n);
    Algebros::Vector lamb(n);
    double val = 100;

    P.I();

    A_v = A;
    while (val >  e) {
        std::pair <Algebros::Matrix, Algebros::Matrix> innerPair = this->innerJacobiLoop(A_v);

        A_n = std::get<0>(innerPair);
        J = std::get<1>(innerPair);

        A_v = A_n;
        P = P * J;

        val = this->getSquaredSumBelowDiag(A_n);
    }

    for (int i = 0; i < n; i++) {
        lamb.setValue(i, A_n.getValue(i, i));
    }

    std::pair <Algebros::Matrix, Algebros::Vector> return_value{P, lamb};

    return return_value;
}