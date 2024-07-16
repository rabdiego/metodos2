#include "libs/algebros/include/Vector.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace Algebros;

Vector::Vector(int size) {
    this->size = size;
    this->values = (double *)malloc(sizeof(double) * size);
}

Vector::Vector(std::string filename) {
    std::string line;
    std::string delimiter = " ";
    std::ifstream file (filename);
    int itter = 0, j = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (itter == 0) {
                this->size = std::stoi(line);
                this->values = (double *)malloc(sizeof(double) * this->size);
                itter++;
            } else {
                size_t pos = 0;
                std::string token;

                while ((pos = line.find(delimiter)) != std::string::npos) {
                    this->setValue(j, stod(line.substr(0, pos)));
                    line.erase(0, pos + delimiter.length());
                    j++;
                }
                this->setValue(j, stod(line.substr(0, pos)));
            }
        }
        file.close();
    }
}

Vector::Vector() { 
    this->size = 0;
}

void Vector::zeros() {
    for (int i = 0; i < this->size; i++) {
        this->setValue(i, 0.0);
    }
}

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

Vector Vector::operator-(Vector vec) {
    Vector vec2(this->size);

    for (int i = 0; i < this->size; i++) {
        vec2.setValue(i, this->getValue(i) - vec.getValue(i));
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

double Vector::getLenght() {
    double p = 0;
    for (int i = 0; i < this->size; i++) {
        p += pow(this->getValue(i), 2);
    }

    return sqrt(p);
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

double Vector::operator*(Vector vec2) {
    double p = 0;

    for (int i = 0; i < this->size; i++) {
        p += this->getValue(i) * vec2.getValue(i);
    }

    return p;
}

void Vector::setSize(int n) {
    this->size = n;
    this->values = (double *)malloc(sizeof(double) * n);
}

void Vector::operator<<(Vector vec) {
    if (this->size == 0) {
        this->setSize(vec.getSize());
    }

    for (int i = 0; i < this->size; i++) {
        this->setValue(i, vec.getValue(i));
    }
}