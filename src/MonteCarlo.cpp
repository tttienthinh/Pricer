#include "MonteCarlo.h"
#include <cmath>
#include <random>
#include <iostream>
#include <vector>
using namespace std;

MonteCarlo::MonteCarlo(double vol, double S, double r, double K, double T, int N) {
    this->vol = vol;
    this->S = S;
    this->r = r;
    this->K = K;
    this->T = T;
    this->N = N;
}

// Calcule le prix de l'option en utilisant la méthode de Monte Carlo
double MonteCarlo::calculate(bool is_call) {
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> d((r - 0.5 * vol * vol) * T, vol * sqrt(T)); // Permet de générer des nombres aléatoires suivant une loi normale

    double sum_payoffs = 0.0;
    for (int i = 0; i < N; ++i) { // On fait N simulations
        double price_path = S*exp(d(gen)); // On calcule le prix de l'action à la maturité
        double payoff;
        if (is_call){   // On calcule le payoff du call
            payoff = max(price_path - K, 0.0);
        }
        else{           // On calcule le payoff du put
            payoff = max(K - price_path, 0.0);
        }
        sum_payoffs += payoff;
    }

    double option_price = exp(-r * T) * (sum_payoffs / N); // On calcule la moyenne des payoffs actualisés
    return option_price;
}
