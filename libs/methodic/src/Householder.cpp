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

std::pair <Algebros::Matrix, Algebros::Matrix> Householder::getTridiagonal(Algebros::Matrix A) {
    int n = A.getSize();

    Algebros::Matrix H(n), H_i(n), A_i(n), A_imo(n),A_bar(n);

    A_imo = A;

    for (int i = 0; i < n-2; i++) {
        H_i = this->getHouseholderMatrix(A_imo, i);

        A_i = H_i.T() * A_imo * H_i;

        A_imo = A_i;

        H = H * H_i;
    }

    A_bar = A_i;

    std::pair <Algebros::Matrix, Algebros::Matrix> return_value{A_bar, H};
    return return_value;
}