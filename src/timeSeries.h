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

struct DailyTS_Point {
    boost::gregorian::date date;
    Dollar open, high, low, close;
    mpz_class volume;
    
    DailyTS_Point(boost::gregorian::date, Dollar, Dollar, Dollar, Dollar, mpz_class);
    
    friend std::ostream& operator<< (std::ostream&, const DailyTS_Point&);
};

class DailyTS {
private:
    std::vector<DailyTS_Point> points;
    
public:
    DailyTS();
    DailyTS(std::vector<DailyTS_Point>);
    DailyTS(std::string);
    
    void push_back(DailyTS_Point);
    
    friend std::ostream& operator<< (std::ostream&, const DailyTS&);
};

#endif
