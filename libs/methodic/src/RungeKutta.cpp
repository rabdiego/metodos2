#include "libs/methodic/include/RungeKutta.hpp"
#include "libs/methodic/include/ExplicitEuler.hpp"

using namespace Methodic;

std::vector<Algebros::Vector> RungeKutta::firstOrder(double (*functions[]) (double), Algebros::Vector s0, int n_points, double delta) {
    ExplicitEuler* aux = new ExplicitEuler();
    return aux->compute(functions, s0, n_points, delta);
}

std::vector<Algebros::Vector> RungeKutta::secondOrder(double (*functions[]) (double), Algebros::Vector s0, int n_points, double delta) {
    ExplicitEuler* gross = new ExplicitEuler();
    std::vector <Algebros::Vector> gross_point;
    std::vector <Algebros::Vector> points;

    int n = s0.getSize();

    Algebros::Vector s1, s2(n), s3(n);
    s1 << s0;
    
    for (int i = 0; i < n_points; i++) {
        Algebros::Vector aux;
        gross_point = gross->compute(functions, s1, 1, delta);

        for (int j = 0; j < n; j++) {
            s2.setValue(j, functions[j](s1.getValue(0)));
            s3.setValue(j, functions[j](gross_point[0].getValue(0)));
        }

        aux << s1 + (s2 * 0.5 + s3 * 0.5) * delta;

        points.push_back(aux);

        s1 << aux; 
    }

    return points;
}

std::vector<Algebros::Vector> RungeKutta::thirdOrder(double (*functions[]) (double), Algebros::Vector s0, int n_points, double delta) {
    ExplicitEuler* gross = new ExplicitEuler();
    std::vector <Algebros::Vector> gross_point;
    std::vector <Algebros::Vector> points;

    int n = s0.getSize();

    Algebros::Vector s1, s2(n), s3(n), s4(n);
    s1 << s0;
    
    for (int i = 0; i < n_points; i++) {
        Algebros::Vector aux;
        gross_point = gross->compute(functions, s1, 1, delta/2);

        for (int j = 0; j < n; j++) {
            s2.setValue(j, functions[j](s1.getValue(0)));
            s3.setValue(j, functions[j](gross_point[0].getValue(0)));
            s4.setValue(j, functions[j](gross_point[1].getValue(0)));
        }

        aux << s1 + (s2 * (1.0/6.0) + s3 * (4.0/6.0) + s4 * (1.0/6.0)) * delta;

        points.push_back(aux);

        s1 << aux; 
    }

    return points;
}