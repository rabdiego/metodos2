#include "libs/methodic/include/ExplicitEuler.hpp"
#include <iostream>

using namespace Methodic;

Algebros::Vector ExplicitEuler::compute(double (*function) (double), double s0, int n_points, double delta) {
    Algebros::Vector points(n_points);
    double s1 = s0;
    double aux;

    for (int i = 0; i < n_points; i++) {
        aux = s1 +  delta * function(s1);
        points.setValue(i, aux);
        s1 = aux;
    }

    return points;
}

std::vector<Algebros::Vector> ExplicitEuler::compute(int n, double (*functions[]) (double), Algebros::Vector s0, int n_points, double delta) {
    std::vector <Algebros::Vector> points;
    Algebros::Vector aux;

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