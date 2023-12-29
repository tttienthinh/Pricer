#include "BlackScholes.h"
#include <cmath>

BlackScholes::BlackScholes(double vol, double S, double K, double r, double T) {
    this->vol = vol;
    this->S = S;
    this->r = r;
    this->K = K;
    this->T = T;
}

// Fonction pour calculer la fonction de répartition de la loi normale standard
double BlackScholes::standard_normal_cdf(double x) {
    return 0.5 *  erfc(-x / sqrt(2.0));
}

// Fonction pour calculer le prix de l'option selon le modèle de Black-Scholes
double BlackScholes::calculate(bool is_call) {
    double d1 = (log(S / K) + (r + vol * vol / 2) * T) / (vol * sqrt(T));
    double d2 = d1 - vol * sqrt(T);
    if (is_call){
        return S * standard_normal_cdf(d1) - K * exp(-r * T) * standard_normal_cdf(d2);
    }
    else{
        return S * (standard_normal_cdf(d1) - 1) - K * exp(-r * T) * (standard_normal_cdf(d2) - 1);
    }
}
