#include "libs/algebros/include/Matrix.hpp"
#include <iostream>

using namespace Algebros;

Matrix::Matrix(int size) {
    this->size = size;
    this->values = (double *)malloc(sizeof(double) * size * size);
}

int Matrix::getSize() { return this->size; }

void Matrix::setValue(int i, int j, double value) {
    this->values[i * this->size + j] = value;
}

double Matrix::getValue(int i, int j) {
    return this->values[i * this->size + j];
}

void Matrix::printMatrix() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
        std::cout << this->values[i * this->size + j] << " ";
        }
        std::cout << std::endl;
    }
}

Vector Matrix::operator*(Vector vec) {
    Vector result(this->size);
    double value;

    for (int i = 0; i < this->size; i++) {
        value = 0;
        for (int j = 0; j < this->size; j++) {
        value += this->getValue(i, j) * vec.getValue(j);
        }
        result.setValue(i, value);
    }

    return result;
}