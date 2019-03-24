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

struct TS_Point {
    std::string ticker;
    
    friend std::ostream& operator<< (std::ostream&, const TS_Point);
};

struct DailyTS_Point : TS_Point {
    Dollar open, high, low, close;
    mpz_class volume;
    
    DailyTS_Point(std::string, Dollar, Dollar, Dollar, Dollar, mpz_class);
    
    friend std::ostream& operator<< (std::ostream&, const DailyTS_Point&);
};

struct TS {
    std::vector<std::pair<boost::gregorian::date, std::vector<TS_Point> > > data;
    
    friend std::ostream& operator<< (std::ostream&, const TS&);
};

template <typename T>
void mergePair(std::pair<boost::gregorian::date, std::vector<T> > &x,
               std::pair<boost::gregorian::date, std::vector<T> > &y) {
    if (std::get<0>(x) == std::get<0>(y)) {
        std::get<1>(x).insert(std::get<1>(x).end(), std::get<1>(y).begin(), std::get<1>(y).end());
    }
}

struct DailyTS : TS {
    std::vector<std::pair<boost::gregorian::date, std::vector<DailyTS_Point> > > data;
    
    DailyTS();
    DailyTS(std::vector<std::pair<boost::gregorian::date, std::vector<DailyTS_Point> > >);
    DailyTS(std::string);
    
    void push_back(std::pair<boost::gregorian::date, std::vector<DailyTS_Point> >);
    
    friend std::ostream& operator<< (std::ostream&, const DailyTS&);
    friend DailyTS operator+ (DailyTS, DailyTS);
};

bool operator< (std::pair<boost::gregorian::date, std::vector<DailyTS_Point> >, std::pair<boost::gregorian::date, std::vector<DailyTS_Point> >);
//
//void mergePair(std::pair<boost::gregorian::date, std::vector<DailyTS_Point> >&, std::pair<boost::gregorian::date, std::vector<DailyTS_Point> >&);


#endif
