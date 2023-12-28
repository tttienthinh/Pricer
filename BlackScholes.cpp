#include "BlackScholes.h"
#include <cmath>

BlackScholes::BlackScholes(double vol, double S, double K, double r, double T) {
    this -> vol = vol;
    this -> S = S;
    this -> K = K;
    this -> r = r;
    this -> T = T;
    this -> is_call = is_call;
}

double BlackScholes::standard_normal_cdf(double x) {
    return 0.5 *  erfc(-x / sqrt(2.0));
}

double BlackScholes::calculate() {
    double d1 = (log(S / K) + (r + vol * vol / 2) * T) / (vol * sqrt(T));
    double d2 = d1 - vol * sqrt(T);
    if (is_call){
        return S * standard_normal_cdf(d1) - K * exp(-r * T) * standard_normal_cdf(d2);
    }
    else{
        return S * (standard_normal_cdf(d1) - 1) - K * exp(-r * T) * (standard_normal_cdf(d2) - 1);
    }

}

