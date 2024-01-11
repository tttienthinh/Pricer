#include <iostream>
#include <cmath>
#include <random>
#include <iostream>
#include <vector>
#include "src/matplotlibcpp.h"
using namespace std;
namespace plt = matplotlibcpp;

int main(){
    float r = 0.03; // taux d'intérêt sans risque
    float vol = 0.35; // volatilité du prix de l'action
    float K = 110; // Strike
    float S = 15; // Valeur actuelle
    float T = 2; // Maturité
    int N = 1000; // Nombre de simulations pour le Monte Carlo
    int nb_delta_T = 100; // Nombre de sous-intervalles pour le mouvement brownien géométrique

    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> d((r - 0.5 * vol * vol) * T/nb_delta_T, vol * sqrt(T/nb_delta_T)); // Permet de générer des nombres aléatoires suivant une loi normale

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