//
// Created by Jacques Zhang on 25/12/2023.
//

#ifndef PRICER_STOCK_H
#define PRICER_STOCK_H

class Stock {
public:
    Stock(double vol, double S);

protected:
    double vol;
    double S;
};

#endif //PRICER_STOCK_H
