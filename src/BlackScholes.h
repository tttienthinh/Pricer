#ifndef PRICER_BLACKSCHOLES_H
#define PRICER_BLACKSCHOLES_H

class BlackScholes {
public:
    BlackScholes(double vol, double S, double K, double r, double T);
    double calculate(bool is_call);
protected:
    double vol; // Volatilité de l'option
    double S; // Prix actuel de l'option
    double r; // Taux d'intérêt de l'option
    double K; // Prix d'exercice de l'option
    double T; // Échéance de l'option en années
    double standard_normal_cdf(double x);
    bool is_call;
};


#endif //PRICER_BLACKSCHOLES_H
