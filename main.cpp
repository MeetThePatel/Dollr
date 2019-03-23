#include <iostream>
#include "src/timeSeries.h"
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
    DailyTS aaplcopy("/Users/meetpatel/XCodeProjects/Dollr/Dollr/AAPLCOPY.csv");
    std::sort(aaplcopy.data.begin(), aaplcopy.data.end());
    std::cout << aaplcopy;
    
    return 0;

}
