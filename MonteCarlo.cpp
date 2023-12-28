#include "MonteCarlo.h"
#include <cmath>
#include <random>

using namespace std;

MonteCarlo::MonteCarlo(double vol, double S, double r, double K, double T, int N) : Stock(vol, S) {
    this -> r = r;
    this -> K = K;
    this -> T = T;
    this -> N = N;
}


double MonteCarlo::simulation() {
    /*
A part le fait qu'il ne multiplie pas par S le prix dans simulate_paths,
Ce site m'a l'air bon
https://towardsdatascience.com/monte-carlo-pricing-in-python-eafc29e3b6c9
*/
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d((r - 0.5 * vol * vol) * T, vol * std::sqrt(T));

    double sum_payoffs = 0.0;
    for (int i = 0; i < N; ++i) {
        double price_path = S * std::exp(d(gen));
        double payoff = std::max(price_path - K, 0.0);
        sum_payoffs += payoff;
    }

    double option_price = std::exp(-r * T) * (sum_payoffs / N);
    return option_price;
}