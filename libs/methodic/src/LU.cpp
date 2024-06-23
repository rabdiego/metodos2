#include "libs/methodic/include/LU.hpp"

using namespace Methodic;

LU::LU() { }

void LU::setMatrix(Algebros::Matrix m) {
    this->M = m;
    this->L.setSize(m.getSize());
    this->U.setSize(m.getSize());
}

LU::LU(Algebros::Matrix m) {
    this->M = m;
    this->L.setSize(m.getSize());
    this->U.setSize(m.getSize());
}

void LU::compute() {
    int size = this->M.getSize();
    this->U = this->M;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) { 
                this->L.setValue(i, j, 1.0);
            } else {
                this->L.setValue(i, j, 0.0);
            }
        }
    }

    double factor, diag, pivot;

    for (int j = 0; j < size - 1; j++) {
        diag = this->U.getValue(j, j);
        for (int  i = j + 1; i < size; i++) {
            pivot = this->U.getValue(i, j);
            factor = pivot/diag;

            this->L.setValue(i, j, factor);

            for (int k = 0; k < size; k++) {
                this->U.setValue(i, k, this->U.getValue(i, k) - factor * this->U.getValue(j, k));
            }
        }
    }
}

Algebros::Vector LU::solve(Algebros::Vector b) {
    int size = this->L.getSize();
    Algebros::Vector y(size);
    Algebros::Vector x(size);

    for (int i = 0; i < size; i++) {
        double value = b.getValue(i);
        for (int j = 0; j < i; j++) {
            value -= this->L.getValue(i, j) * y.getValue(j);
        }
        y.setValue(i, value);
    }

    for (int i = size - 1; i >= 0; i--) {
        double value = y.getValue(i);
        for (int j = size - 1; j > i; j--) {
            value -= x.getValue(j) * this->U.getValue(i, j);
        }
        value /= this->U.getValue(i, i);
        x.setValue(i, value);
    }

    return x;
}

Algebros::Matrix LU::getL() { return this->L; }
Algebros::Matrix LU::getU() { return this->U; }
