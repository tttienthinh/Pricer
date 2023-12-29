#include "MonteCarlo.h"
#include <cmath>
#include <random>
#include <iostream>
#include <vector>
#include "matplotlibcpp.h"
using namespace std;
namespace plt = matplotlibcpp;

MonteCarlo::MonteCarlo(double vol, double S, double r, double K, double T, int N) {
    this->vol = vol;
    this->S = S;
    this->r = r;
    this->K = K;
    this->T = T;
    this->N = N;
}

double MonteCarlo::calculate(bool is_call) {    random_device rd;
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

    void MonteCarlo::simulation(int nb_delta_T) {
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> d((r - 0.5 * vol * vol) * T/nb_delta_T, vol * sqrt(T/nb_delta_T)); // Permet de générer des nombres aléatoires suivant une loi normale
    vector<vector<double>> values(N, std::vector<double>(nb_delta_T));

    double sum_payoffs = 0.0;
    for (int i = 0; i < N; ++i) { // On fait N simulations
        double price_path = S;
        std::vector<double> prices(nb_delta_T+1);
        prices[0] = price_path;


        for (int j = 0; j < nb_delta_T; ++j) { // On divise l'intervalle [0, T] en nb_delta_T sous-intervalles
            price_path *= exp(d(gen));
            prices[j+1] = price_path;
        }
        plt::plot(prices);   
    }
    plt::title("Mouvement Brownien Géométrique");
    plt::xlabel("Intervalle");
    plt::ylabel("Prix");
    plt::show(); 
}