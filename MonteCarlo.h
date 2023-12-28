#ifndef PRICER_MONTECARLO_H
#define PRICER_MONTECARLO_H

#include "Stock.h"


class MonteCarlo {
public:
    MonteCarlo(double vol, double S, double r, double K, double T, int N);
    double simulation();
protected:
    double vol; // Volatility of the option
    double S; // Spot price of the option
    double r; // Interest rate of the option
    double K; // Strike of option
    double T; // Maturity of the option in year
    int N; // Number of simulations
};


#endif //PRICER_MONTECARLO_H
