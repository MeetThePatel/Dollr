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
    OHLCV_TimeSeries_Point test_point ("AAPL", test_ohlcv_point);
    
    OHLCV_Point test_ohlcv_point2 {Dollar(5), Dollar(6), Dollar(4), Dollar(4), 34823};
    OHLCV_TimeSeries_Point test_point2 ("GOOG", test_ohlcv_point2);
    
    vector<TimeSeries_Point<OHLCV_Point> > test_vec {test_point, test_point2};
    vector<pair<date, vector<OHLCV_TimeSeries_Point> > > vec {make_pair(from_string("2012-5-5"), test_vec)};
    
    Daily_OHLCV_TimeSeries x("Test Time Series", vec);
    
    cout << x;
    
    return 0;
}
