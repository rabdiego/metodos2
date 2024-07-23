# Métodos Numéricos II
> rabdiego

## 1. Intro
This repository was made for storing all my implementations of the algorithms presented in my **numerical methods class**, in C++

There are two main custom libraries, one designed for representing vectors and matrices, called **Algebros**, and one designed for everything classified as a numerical method, called **Methodic**.

## 2. Functionalities implemented by now

### 2.a Algebros
- Matrix and Vector initialization by passing a .txt file
- Vector normalization
- Matrix transpose
- The following use operator overloads:
    - Matrix-Vector multiplication
    - Matrix and Vector scalar multiplication
    - Matrix multiplication
    - Vector dot product

### 2.b Methodic
- Integration methods
    - Newton-Cotes (closed and open)
    - Gauss-Legendre
- Linear algebra related methods
    - LU factorization
- Eigenvector methods
    - Regular power
    - Inverse power
    - Displacement power
    - Householder method
    - Jacobi method
    - QR method

## 3. Run locally

If this is your first run:

`cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .`

Then:

`make test`

And finally:

`./bin/test`