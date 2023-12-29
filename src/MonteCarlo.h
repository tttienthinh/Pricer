#ifndef PRICER_MONTECARLO_H
#define PRICER_MONTECARLO_H

class MonteCarlo {
public:
    MonteCarlo(double vol, double S, double r, double K, double T, int N);
    double calculate(bool is_call);
protected:
    double vol; // Volatilité de l'option
    double S; // Prix spot de l'option
    double r; // Taux d'intérêt de l'option
    double K; // Strike de l'option
    double T; // Maturité de l'option en années
    int N; // Nombre de simulations
};


#endif //PRICER_MONTECARLO_H
