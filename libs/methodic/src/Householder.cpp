#include "libs/methodic/include/Householder.hpp"

using namespace Methodic;

Algebros::Matrix Householder::getHouseholderMatrix(Algebros::Matrix A, int i) {
    int size = A.getSize();

    Algebros::Vector w(size), w_l(size), N(size), n(size), e(size);

    w.zeros();
    w_l.zeros();
    e.zeros();

    for (int idx = i + 1; idx < size; idx++) {
        w.setValue(idx, A.getValue(idx, i));
    }

    double L_w = w.getLenght();

    w_l.setValue(i+1, L_w);

    N = w - w_l;

    n = N.norm();

    Algebros::Matrix nn(size);

    for (int idx = 0; idx < size; idx++) {
        for (int j = 0; j < size; j++) {
            nn.setValue(idx, j, n.getValue(idx)*n.getValue(j));
        }
    }

    Algebros::Matrix H(size);
    H.I();

    H = H - nn*2;

    return H;
}