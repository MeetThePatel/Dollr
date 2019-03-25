#ifndef timeSeries_h
#define timeSeries_h

#include <vector>
#include <tuple>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <gmpxx.h>
#include <iostream>
#include "units.h"
#include "../lib/parser.hpp"

using namespace std;
using namespace boost::gregorian;

enum class TimeSeries_Resolution {
    Tick,
    Minute,
    Day
};

template <class T>
struct TimeSeries_Point {
    string ticker;
    T data;
    
    TimeSeries_Point<T>(string ticker, T data) : ticker(ticker), data(data){};
};

template <class T>
ostream& operator<< (ostream& os, const TimeSeries_Point<T>& x) {
    os << x.ticker << ": " << x.data;
    return os;
}

template <TimeSeries_Resolution R, class T>
struct TimeSeries {
    string name;
    vector<pair<date, vector<T> > > data;
    
    TimeSeries<R, T>() {};
    TimeSeries<R, T>(string x) : name(x), data(vector<pair<date, vector<T> > >{}){};
    TimeSeries<R, T>(vector<pair<date, vector<T> > > x) : name(""), data(x){};
    TimeSeries<R, T>(string x, vector<pair<date, vector<T> > > y) : name(x), data(y){};
};

template <TimeSeries_Resolution R, class T>
ostream& operator<< (ostream& os, const TimeSeries<R, T>& x) {
    os << x.name << endl;
    for (auto const &i : x.data) {
        os << get<0>(i) << endl;
        for (auto const &j : get<1>(i)) {
            os << "   " << j;
        }
    }
    return os;
}

struct OHLCV_Point {
    Dollar open, high, low, close;
    mpz_class volume;
    
    OHLCV_Point(Dollar open, Dollar high, Dollar low, Dollar close, mpz_class volume) : open(open), high(high), low(low), close(close), volume(volume) {};
    
    friend ostream& operator<< (ostream&, const OHLCV_Point&);
};



using OHLCV_TimeSeries_Point = TimeSeries_Point<OHLCV_Point>;
using Tick_OHLCV_TimeSeries = TimeSeries<TimeSeries_Resolution::Tick, OHLCV_TimeSeries_Point>;
using Minute_OHLCV_TimeSeries = TimeSeries<TimeSeries_Resolution::Minute, OHLCV_TimeSeries_Point>;
using Daily_OHLCV_TimeSeries = TimeSeries<TimeSeries_Resolution::Day, OHLCV_TimeSeries_Point>;

#endif
