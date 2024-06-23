#ifndef DisplacementPower_H
#define DisplacementPower_H

#include "libs/methodic/include/EigenMethod.hpp"

namespace Methodic {
    class DisplacementPower : public EigenMethod {
        public:
            double m;
            void setM(double);
            
            Autos findEigen(Algebros::Matrix, Algebros::Vector, double) override;
    };
};

#endif