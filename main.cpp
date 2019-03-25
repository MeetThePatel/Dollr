#include <iostream>
#include <vector>
#include "src/timeSeries.h"

using namespace std;
using namespace boost::gregorian;

// TODO:
//     [ ] Create new time series for Simple Moving Average (SMA)
//     [ ] Create new time series for Exponential Moving Average (EMA)
//     [ ] Create new time series for Double Exponential Moving Average (DEMA)
//     [ ] Create new time series for Triple Exponential Moving Average (TEMA)
//     [ ] Create new time series for Linearly Weighted Moving Average (LWMA)
//     [ ] Create new time series for Guppy Multiple Moving Average (GMMA)

int main() {
    
    OHLCV_Point test_ohlcv_point {Dollar(5), Dollar(6), Dollar(4), Dollar(4), 34823};
    vector<OHLCV_Point> test_vec = {test_ohlcv_point};
    
    //pair<date, vector<T> >& x
    
    pair<date, vector<OHLCV_Point> > x = make_pair(from_string("2012-5-5"), test_vec);
    
    OHLCV_Point test_ohlcv_point2 {Dollar(5), Dollar(6), Dollar(4), Dollar(4), 34823};
    vector<OHLCV_Point> test_vec2 = {test_ohlcv_point2};
    
    pair<date, vector<OHLCV_Point> > y = make_pair(from_string("2012-5-5"), test_vec2);
    
    auto z = x + y;
    
    
    
    return 0;
}
