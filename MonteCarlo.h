//
// Created by Jacques Zhang on 25/12/2023.
//

#ifndef PRICER_MONTECARLO_H
#define PRICER_MONTECARLO_H

#include "Stock.h"


class MonteCarlo: protected Stock {
public:
    MonteCarlo(float vol, float S, float r, float K, int T, int N);
    float get_average(float* list, int N);
    float simulation();
protected:
    float r; /* Interest rate of the option */
    float K; /* Strike of option */
    int T; /* Maturity of the option in year */
    int N; /* Number of simulations */
};


#endif //PRICER_MONTECARLO_H
