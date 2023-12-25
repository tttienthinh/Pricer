//
// Created by Jacques Zhang on 25/12/2023.
//

#ifndef PRICER_STOCK_H
#define PRICER_STOCK_H



class Stock {
public:
    Stock(float vol, float S);
    float Get_price_at_T(float r, float So, int T);
    float generate_normal_rand(float mu, float sig);
    float get_S();

protected:
    float vol;
    float S;

};

#endif //PRICER_STOCK_H
