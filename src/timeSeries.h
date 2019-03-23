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

struct TS_Point {
    std::string ticker;
    Dollar open, high, low, close;
    mpz_class volume;
};

struct DailyTS_Point : TS_Point {
    DailyTS_Point(std::string, Dollar, Dollar, Dollar, Dollar, mpz_class);
    
    friend std::ostream& operator<< (std::ostream&, const DailyTS_Point&);
};

struct TS {
    std::vector<std::pair<boost::gregorian::date, std::vector<TS_Point> > > data;
};

struct DailyTS : TS {
    std::vector<std::pair<boost::gregorian::date, std::vector<DailyTS_Point> > > data;
    
    // Empty Constructor
    DailyTS();
    // Full Constructor
    DailyTS(std::vector<std::pair<boost::gregorian::date, std::vector<DailyTS_Point> > >);
    // File Path Constructor
    DailyTS(std::string);
    
    void push_back(std::pair<boost::gregorian::date, std::vector<DailyTS_Point> >);
    
    friend std::ostream& operator<< (std::ostream&, const DailyTS&);
    friend DailyTS operator+ (DailyTS, DailyTS);
};

bool operator< (std::pair<boost::gregorian::date, std::vector<DailyTS_Point> >, std::pair<boost::gregorian::date, std::vector<DailyTS_Point> >);

void mergePair(std::pair<boost::gregorian::date, std::vector<DailyTS_Point> >&, std::pair<boost::gregorian::date, std::vector<DailyTS_Point> >&);


#endif
