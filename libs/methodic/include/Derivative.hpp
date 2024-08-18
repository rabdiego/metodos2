#ifndef Derivative_H
#define Derivative_H

namespace Methodic {
    class Derivative {
        private:
            double first_derivative_forward(double (*function) (double), double, double);
            double first_derivative_backward(double (*function) (double), double, double);
            double first_derivative_central(double (*function) (double), double, double);

            double second_derivative_forward(double (*function) (double), double, double);
            double second_derivative_backward(double (*function) (double), double, double);
            double second_derivative_central(double (*function) (double), double, double);

        public:
            double first_derivative(double (*function) (double), double, double, int);
            double second_derivative(double (*function) (double), double, double, int);
    };
};

#endif