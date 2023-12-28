#include <cmath>
#include <random>
#include <iostream>
using namespace std;

double monte_carlo_pricer(double spot_price, double strike_price, double risk_free_rate, double volatility, double time_to_maturity, int num_simulations) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d((risk_free_rate - 0.5 * volatility * volatility) * time_to_maturity, volatility * std::sqrt(time_to_maturity));

    double sum_payoffs = 0.0;
    for (int i = 0; i < num_simulations; ++i) {
        double price_path = spot_price * std::exp(d(gen));
        double payoff = std::max(price_path - strike_price, 0.0);
        sum_payoffs += payoff;
    }

    double option_price = std::exp(-risk_free_rate * time_to_maturity) * (sum_payoffs / num_simulations);
    return option_price;
}

int main(){
    double r = 0.05; // taux d'intérêt sans risque
    double vol = 0.25; // volatilité du prix de l'action
    double K = 110; // Strike
    double S = 100; // Valeur actuelle
    double T = 0.5; // Maturité
    int N = 100000; // Nombre de simulations pour le Monte Carlo
    /*
    J'ai fait des tests sur ce site
    http://www.finance-calculators.com/mclookbackoption/
    */
    double monte_carlo_price = monte_carlo_pricer(S, K, r, vol, T, N);
    cout << "Prix (Monte Carlo): " << monte_carlo_price << "\n";
}