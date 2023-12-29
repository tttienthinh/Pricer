#include <iostream>
#include <vector>
#include "src/MonteCarlo.h"
using namespace std;

int main(){
    float r = 0.03; // taux d'intérêt sans risque
    float vol = 0.35; // volatilité du prix de l'action
    float K = 110; // Strike
    float S = 15; // Valeur actuelle
    float T = 2; // Maturité
    int N = 1000; // Nombre de simulations pour le Monte Carlo
    MonteCarlo my_monte_carlo = MonteCarlo(vol, S, r, K, T, N);

    my_monte_carlo.simulation(10000);
}