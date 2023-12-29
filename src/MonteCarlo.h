#ifndef PRICER_MONTECARLO_H
#define PRICER_MONTECARLO_H
#include <vector>

class MonteCarlo {
public:
    MonteCarlo(double vol, double S, double r, double K, double T, int N);
    double calculate(bool is_call);
    std::vector<std::vector<double>> simulation(int nb_delta_T = 100);
protected:
    double vol; // Volatility of the option
    double S; // Spot price of the option
    double r; // Interest rate of the option
    double K; // Strike of option
    double T; // Maturity of the option in year
    int N; // Number of simulations
};


#endif //PRICER_MONTECARLO_H
