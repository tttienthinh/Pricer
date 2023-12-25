//
// Created by Jacques Zhang on 25/12/2023.
//

#ifndef PRICER_BLACKSCHOLES_H
#define PRICER_BLACKSCHOLES_H
#include "Stock.h"

class BlackScholes : protected Stock{
public:
    BlackScholes(float vol, float S, float K, float r, int T);
    double calculate();
protected:
    float K;
    float r;
    int T;
    double standard_normal_cdf(double x);
};


#endif //PRICER_BLACKSCHOLES_H
