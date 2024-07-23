#include "libs/methodic/include/QR.hpp"
#include <cmath>

using namespace Methodic;

Algebros::Matrix QR::getQRMatrix(Algebros::Matrix A, int i, int j) {
    int size = A.getSize();
    
    Algebros::Matrix J(size);
    double e = 1e-6, theta;
    J.I();

    if (std::abs(A.getValue(i, j)) < e) {
        return J;
    }

    if (std::abs(A.getValue(j, j)) < e) {
        if (A.getValue(i, j) < 0) {
            theta = 3.14159265356 / 2;
        } else {
            theta = - 3.14159265356 / 2;
        }
    } else {
        theta = atan((-A.getValue(i, j))/(A.getValue(j, j)));
    }

    J.setValue(i, i, cos(theta));
    J.setValue(j, j, cos(theta));
    J.setValue(i, j, sin(theta));
    J.setValue(j, i, -sin(theta));

    return J;
}

std::pair <Algebros::Matrix, Algebros::Matrix> QR::innerQRLoop(Algebros::Matrix A) {
    int n = A.getSize();
    
    Algebros::Matrix QT(n), J_ij(n), R_n(n), R_v(n), R(n);

    QT.I();
    R_v = A;

    for (int j = 0; j < n-1; j++) {
        for (int i = j+1; i < n; i++) {
            J_ij = this->getQRMatrix(R_v, i, j);

            R_n = J_ij * R_v;

            R_v = R_n;

            QT = J_ij * QT;
        }
    }

    R = R_n;

    std::pair <Algebros::Matrix, Algebros::Matrix> return_value{QT.T(), R};
    return return_value;
}

double QR::getSquaredSumBelowDiag(Algebros::Matrix A) {
    int n = A.getSize();

    double result = 0;

    for (int i = 1; i < n-1; i++) {
        for (int j = 0; j < i; j++) {
            result += A.getValue(i, j) * A.getValue(i, j);
        }
    }

    return result;
}

std::pair <Algebros::Matrix, Algebros::Vector> QR::getDiagonalValues(Algebros::Matrix A, double e) {
    int n = A.getSize();
    
    Algebros::Matrix P(n), Q(n), R(n), A_n(n), A_v(n), A_b(n);
    Algebros::Vector lamb(n);
    double val = 100;

    P.I();

    A_v = A;
    while (val >  e) {
        std::pair <Algebros::Matrix, Algebros::Matrix> innerPair = this->innerQRLoop(A_v);

        Q = std::get<0>(innerPair);
        R = std::get<1>(innerPair);

        A_n = R * Q;
        A_v = A_n;

        P = P * Q;

        val = this->getSquaredSumBelowDiag(A_n);
    }

    for (int i = 0; i < n; i++) {
        lamb.setValue(i, A_n.getValue(i, i));
    }

    std::pair <Algebros::Matrix, Algebros::Vector> return_value{P, lamb};

    return return_value;
}