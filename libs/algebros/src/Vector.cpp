#include "libs/algebros/include/Vector.hpp"
#include <iostream>
#include <cmath>

using namespace Algebros;

Vector::Vector(int size) {
    this->size = size;
    this->values = (double *)malloc(sizeof(double) * size);
}

Vector::Vector() { }

int Vector::getSize() { return this->size; }

void Vector::setValue(int i, double value) { this->values[i] = value; }

double Vector::getValue(int i) { return this->values[i]; }

void Vector::printVector() {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->values[i] << " ";
    }
    std::cout << std::endl;
}

Vector Vector::operator+(Vector vec) {
    Vector vec2(this->size);

    for (int i = 0; i < this->size; i++) {
        vec2.setValue(i, this->getValue(i) + vec.getValue(i));
    }

    return vec2;
}

Vector Vector::operator*(double a) {
    Vector vec2(this->size);

    for (int i = 0; i < this->size; i++) {
        vec2.setValue(i, this->getValue(i) * a);
    }

    return vec2;
}

Vector Vector::norm() {
    Vector vec(this->size);

    double p = 0;
    for (int i = 0; i < this->size; i++) {
        vec.setValue(i, this->getValue(i));
        p += pow(this->getValue(i), 2);
    }

    p = sqrt(p);

    return vec * (1/p);
}

double Vector::dot(Vector vec2) {
    double p = 0;

    for (int i = 0; i < this->size; i++) {
        p += this->getValue(i) * vec2.getValue(i);
    }

    return p;
}

void Vector::operator<<(Vector vec) {
    for (int i = 0; i < this->size; i++) {
        this->setValue(i, vec.getValue(i));
    }
}