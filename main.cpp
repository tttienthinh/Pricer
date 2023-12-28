#include <iostream>
#include "MonteCarlo.h"
#include "BlackScholes.h"
using namespace std;

int main(){
    float r = 0.05; // taux d'intérêt sans risque
    float vol = 0.25; // volatilité du prix de l'action
    float K = 110; // Strike
    float S = 100; // Valeur actuelle
    float T = 0.5; // Maturité
    int N = 100000; // Nombre de simulations pour le Monte Carlo
    /*
    J'ai fait des tests sur ce site
    http://www.finance-calculators.com/mclookbackoption/
    */
    MonteCarlo my_monte_carlo = MonteCarlo(vol, S, r, K, T, N);
    BlackScholes my_black_scholes = BlackScholes(vol, S, K, r, T);
    cout << "Prix (Monte Carlo): " << my_monte_carlo.simulation() << "\n";
    cout << "Prix (Black, Scholes et Merton): " << my_black_scholes.calculate() << "\n";
    cout << "Différence: " << my_monte_carlo.simulation() - my_black_scholes.calculate() << "\n";
}