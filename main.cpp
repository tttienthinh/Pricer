#include <iostream>
#include "src/MonteCarlo.h"
#include "src/BlackScholes.h"
using namespace std;

int main(){
    float r = 0.05; // taux d'intérêt sans risque
    float vol = 0.25; // volatilité du prix de l'action
    float K = 110; // Strike
    float S = 100; // Valeur actuelle
    float T = 10; // Maturité
    int N = 100000; // Nombre de simulations pour le Monte Carlo
    
    bool is_call = true; // Call : true, Put : false. Permet de pricer un put ou un call
    cout << "Prix d'un CALL européen:\n";
    MonteCarlo my_monte_carlo = MonteCarlo(vol, S, r, K, T, N, is_call);
    BlackScholes my_black_scholes = BlackScholes(vol, S, K, r, T, is_call);
    cout << "Prix (Monte Carlo): " << my_monte_carlo.simulation() << "\n";
    cout << "Prix (Black, Scholes et Merton): " << my_black_scholes.calculate() << "\n\n";
    
    is_call = false; // Call : true, Put : false. Permet de pricer un put ou un call
    cout << "Prix d'un PUT européen:\n";
    my_monte_carlo = MonteCarlo(vol, S, r, K, T, N, is_call);
    my_black_scholes = BlackScholes(vol, S, K, r, T, is_call);
    cout << "Prix (Monte Carlo): " << my_monte_carlo.simulation() << "\n";
    cout << "Prix (Black, Scholes et Merton): " << my_black_scholes.calculate() << "\n";
}