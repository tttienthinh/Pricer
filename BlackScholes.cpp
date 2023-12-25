//
// Created by Jacques Zhang on 25/12/2023.
//

#include "BlackScholes.h"
#include <cmath>

BlackScholes::BlackScholes(float vol, float S, float K, float r, int T) : Stock(vol, S){
    this -> K = K;
    this -> r = r;
    this -> T = T;
}

double BlackScholes::standard_normal_cdf(double x) {
    return 0.5 * (1 + erf(x / sqrt(2)));
}

double BlackScholes::calculate() {
    double d1 = (log(S / K) + (r + vol*vol / 2) * T) / (vol * sqrt(T));
    double d2 = d1 - vol * sqrt(T);
    return S * standard_normal_cdf(d1) - K * exp(-r * T) * standard_normal_cdf(d2);

}

