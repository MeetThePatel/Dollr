#include <iostream>
#include "src/timeSeries.h"
#include "src/indicators/movingAverages.h"
#include <vector>
#include <curl.h>

// TODO:
//     [ ] Create new time series for Simple Moving Average (SMA)
//     [ ] Create new time series for Exponential Moving Average (EMA)
//     [ ] Create new time series for Double Exponential Moving Average (DEMA)
//     [ ] Create new time series for Triple Exponential Moving Average (TEMA)
//     [ ] Create new time series for Linearly Weighted Moving Average (LWMA)
//     [ ] Create new time series for Guppy Multiple Moving Average (GMMA)

int main() {
    DailyTS spy("/Users/meetpatel/XCodeProjects/Dollr/Dollr/SPY.csv");
    DailyTS dia("/Users/meetpatel/XCodeProjects/Dollr/Dollr/DIA.csv");
    
    auto x = spy + dia;
    std::cout << x;
//    SimpleMovingAverage x(spy, "SPY", 5);
//    std::cout << x;
    
//    auto y = spy + x;
    
    return 0;
}
