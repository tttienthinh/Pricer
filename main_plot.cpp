#include <iostream>
#include <vector>
#include "src/MonteCarlo.h"
using namespace std;

int main(){
    float r = 0.05; // taux d'intérêt sans risque
    float vol = 0.25; // volatilité du prix de l'action
    float K = 110; // Strike
    float S = 100; // Valeur actuelle
    float T = 10; // Maturité
    int N = 100000; // Nombre de simulations pour le Monte Carlo
    MonteCarlo my_monte_carlo = MonteCarlo(vol, S, r, K, T, N);

    std::vector<std::vector<double>> values = my_monte_carlo.simulation(100);

    cout << values[0][0] << "\n";
}