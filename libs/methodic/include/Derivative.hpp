#ifndef Derivative_H
#define Derivative_H

namespace Methodic {
    class Derivative {
        public:
            double derivate_forward(double (*function) (double), double, double);
    };
};

#endif