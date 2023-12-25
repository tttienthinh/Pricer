//
// Created by Jacques Zhang on 24/12/2023.
//
#include <random>
#include "Stock.h"
using namespace std;

Stock::Stock(float vol, float S) {
    this -> vol = vol;
    this -> S = S;
}

float Stock::Get_price_at_T(float r, float So, int T) {
    /*
On utilise la récursivité pour calculer le prix à T
*/
    if (T==0) {
        return So;
    } else {
        float dW = generate_normal_rand(0, 1);
        float dS = So * (r + vol * dW);
        return Get_price_at_T(r, (So + dS), (T-1));
    }
}

float Stock::generate_normal_rand(float mu, float sig) {
    random_device rd; // Change le seed (racine) à chaque appel
    default_random_engine generator(rd()); // Positionne le seed
    normal_distribution<float> distribution(mu, sig); // Crée la distribution
    return distribution(generator);
}

float Stock::get_S() {
    return S;
}
