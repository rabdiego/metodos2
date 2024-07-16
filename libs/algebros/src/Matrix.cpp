#include "libs/algebros/include/Matrix.hpp"
#include <iostream>
#include <fstream>

using namespace Algebros;

Matrix::Matrix(int size) {
    this->size = size;
    this->values = (double *)malloc(sizeof(double) * size * size);
}

Matrix::Matrix(std::string filename) {
    std::string line;
    std::string delimiter = " ";
    std::ifstream file (filename);
    int itter = 0;
    int i = -1, j = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (itter == 0) {
                this->size = std::stoi(line);
                this->values = (double *)malloc(sizeof(double) * this->size * this->size);
                itter++;
            } else {
                size_t pos = 0;
                std::string token;

                while ((pos = line.find(delimiter)) != std::string::npos) {
                    this->setValue(i, j, stod(line.substr(0, pos)));
                    line.erase(0, pos + delimiter.length());
                    j++;
                }
                this->setValue(i, j, stod(line.substr(0, pos)));
            }
            i++;
            j = 0;
        }
        file.close();
    }
}

Matrix::Matrix() { 
    this->size = 0;
}

int Matrix::getSize() { return this->size; }

void Matrix::setSize(int n) {
    this->size = n;
    this->values = (double *)malloc(sizeof(double) * n * n);
}

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

void Matrix::I() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (i == j) {
                this->setValue(i, j, 1.0);
            } else {
                this->setValue(i, j, 0.0);
            }
        }
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

Matrix Matrix::operator*(double f) {
    Matrix result(this->size);

    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            result.setValue(i, j, this->getValue(i, j) * f);
        }
    }

    return result;
}

Matrix Matrix::operator+(Matrix f) {
    Matrix result(this->size);

    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            result.setValue(i, j, this->getValue(i, j) + f.getValue(i, j));
        }
    }

    return result;
}

Matrix Matrix::operator-(Matrix f) {
    Matrix result(this->size);

    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            result.setValue(i, j, this->getValue(i, j) - f.getValue(i, j));
        }
    }

    return result;
}