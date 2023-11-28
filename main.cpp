#include <iostream> // cout
#include <string.h> 
#include <cstring> 
#include <random>
#include <typeinfo> // typeid().name
#include <algorithm> // max
using namespace std;


float generate_normal_random(float mu, float sig) {
    random_device rd; // Change le seed (racine) à chaque appel
    default_random_engine generator(rd()); // Positionne le seed
    normal_distribution<float> distribution(mu, sig); // Crée la distribution
    return distribution(generator);
}

float get_price_at_T(float r, float vol, float S, int T) {
    /*
    On utilise la récursivité pour calculer le prix à T
    */
    if (T==0) {
        return S;
    } else {
        float dW = generate_normal_random(0, 1);
        float dS = S * (r + vol * dW);
        return get_price_at_T(r, vol, (S+dS), (T-1));
    }
}

float get_average(float* liste, int N) {
    float avg = 0;
    for (int i=0; i<N; i++) {
        avg = avg + *(liste+i)/N;
    }
    return avg;
}

float simulation_Monte_Carlo(float r, float vol, float K, float S, int T, int N) {
    
    /*
    A part le fait qu'il ne multiplie pas par S le prix dans simulate_paths,
    Ce site m'a l'air bon
    https://towardsdatascience.com/monte-carlo-pricing-in-python-eafc29e3b6c9
    */
    float liste[N];
    float* p=liste;
    const float zero = 0;

    for (int i=0; i<N; i++) {
        float S_T = get_price_at_T(r, vol, S, T);
        *(p+i) = max(S_T-K, zero);
    }
    return get_average(liste, N);
}




int main(){
    float r = 0.02; // taux d'intérêt san risque
    float vol = 0.05; // volatilité du prix de l'action
    float K = 50; // Strike
    float S = 40; // Valeur actuelle
    int T = 10; // Maturité
    int N = 100000;

    /*
    J'ai fait des tests sur ce site
    http://www.finance-calculators.com/mclookbackoption/
    */
    cout << simulation_Monte_Carlo(r, vol, K, S, T, N) << "\n";
}