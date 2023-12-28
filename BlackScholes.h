#ifndef PRICER_BLACKSCHOLES_H
#define PRICER_BLACKSCHOLES_H
#include "Stock.h"

class BlackScholes {
public:
    BlackScholes(double vol, double S, double K, double r, double T, bool is_call);
    double calculate();
protected:
    double vol; // Volatility of the option
    double S; // Spot price of the option
    double r; // Interest rate of the option
    double K; // Strike of option
    double T; // Maturity of the option in year
    double standard_normal_cdf(double x);
    bool is_call;
};


#endif //PRICER_BLACKSCHOLES_H
