#include <iostream> // cout
#include <string.h>
#include <cstring>
#include <random>
#include <typeinfo> // typeid().name
#include <algorithm> // max
#include "Stock.h"
#include "MonteCarlo.h"
#include "BlackScholes.h"
using namespace std;

int main(){
    float r = 0.02; // taux d'intérêt sans risque
    float vol = 0.5; // volatilité du prix de l'action
    float K = 50; // Strike
    float S = 40; // Valeur actuelle
    int T = 10; // Maturité
    int N = 100000; // Nombre de simulations pour le Monte Carlo
    /*
    J'ai fait des tests sur ce site
    http://www.finance-calculators.com/mclookbackoption/
    */
    MonteCarlo MC = MonteCarlo(vol, S, r, K, T, N);
    BlackScholes BS = BlackScholes(vol, S, K, r, T);
    cout << "Prix (Monte Carlo) " << MC.simulation() << "\n";
    cout << "Prix (Black, Scholes et Merton) " << BS.calculate();
}