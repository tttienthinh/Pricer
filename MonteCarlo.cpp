//
// Created by Jacques Zhang on 24/12/2023.
//

#include "MonteCarlo.h"
#include <algorithm> // max

using namespace std;

MonteCarlo::MonteCarlo(float vol, float S, float r, float K, int T, int N) : Stock(vol, S) {
    this -> r = r;
    this -> K = K;
    this -> T = T;
    this -> N = N;
}

float MonteCarlo::get_average(float *list, int N) {
    float avg = 0;
    for (int i=0; i<N; i++) {
        avg = avg + *(list+i) / N;
    }
    return avg;
}

float MonteCarlo::simulation() {
    /*
A part le fait qu'il ne multiplie pas par S le prix dans simulate_paths,
Ce site m'a l'air bon
https://towardsdatascience.com/monte-carlo-pricing-in-python-eafc29e3b6c9
*/
    float list[N];
    float* p = list;
    const float zero = 0;

    for (int i=0; i<N; i++) {
        float S_T = Get_price_at_T(r, S, T);
        *(p+i) = max(S_T-K, zero);
    }
    return get_average(list, N);
}