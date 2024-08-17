#include "libs/methodic/include/ExplicitEuler.hpp"
#include <iostream>

using namespace Methodic;

std::vector<Algebros::Vector> ExplicitEuler::compute(double (*functions[]) (double), Algebros::Vector s0, int n_points, double delta) {
    std::vector <Algebros::Vector> points;
    Algebros::Vector aux;

    int n = s0.getSize();

    aux << s0;
    
    for (int i = 0; i < n_points; i++) {
        Algebros::Vector aux_b;
        aux_b << aux;

        for (int j = 0; j < n; j++) {
            aux.setValue(j, functions[j](aux_b.getValue(0)));
        }

        aux << aux_b + aux * delta;
        aux_b << aux;
        points.push_back(aux_b);
    }

    return points;
}