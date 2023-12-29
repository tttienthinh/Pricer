#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {
    // Paramètres du mouvement brownien géométrique
    double initialPrice = 100.0;
    double drift = 0.05;
    double volatility = 0.2;
    int intervals = 100;
    double dt = 1.0 / intervals;

    // Initialiser le générateur aléatoire avec une graine fixe pour la reproductibilité
    std::random_device rd;
    std::mt19937 generator(rd());
    std::normal_distribution<double> normalDistribution(0.0, 1.0);

    // Générer le mouvement brownien géométrique
    std::vector<double> prices(intervals + 1);
    prices[0] = initialPrice;

    for (int i = 1; i <= intervals; ++i) {
        double randomValue = normalDistribution(generator);
        double increment = drift * dt + volatility * sqrt(dt) * randomValue;
        prices[i] = prices[i - 1] * exp(increment);
    }

    // Tracer le mouvement brownien géométrique
    plt::plot(prices);
    plt::title("Mouvement Brownien Géométrique");
    plt::xlabel("Intervalle");
    plt::ylabel("Prix");
    plt::show();

    return 0;
}
