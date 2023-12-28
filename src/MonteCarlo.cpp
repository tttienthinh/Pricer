#include "MonteCarlo.h"
#include <cmath>
#include <random>

using namespace std;

MonteCarlo::MonteCarlo(double vol, double S, double r, double K, double T, int N, bool is_call) {
    this->vol = vol;
    this->S = S;
    this->r = r;
    this->K = K;
    this->T = T;
    this->N = N;
    this->is_call = is_call;
}

double MonteCarlo::simulation() {
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> d((r - 0.5 * vol * vol) * T, vol * sqrt(T)); // Permet de générer des nombres aléatoires suivant une loi normale

    double sum_payoffs = 0.0;
    for (int i = 0; i < N; ++i) { // On fait N simulations
        double price_path = S * exp(d(gen));
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