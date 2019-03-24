#ifndef movingAverages_h
#define movingAverages_h

#include "../timeSeries.h"
#include <vector>

struct IndicatorTS_Point : TS_Point {
    std::string indicatorName;
    std::string ticker;
    Dollar price;
    
    IndicatorTS_Point(std::string x, std::string y, Dollar price) : indicatorName(x), ticker(y), price(price){};
    
    friend std::ostream& operator<< (std::ostream&, const IndicatorTS_Point);
};

struct IndicatorTS : TS {
    std::vector<std::pair<boost::gregorian::date, std::vector<IndicatorTS_Point> > > data;
    
    IndicatorTS(){};
    IndicatorTS(std::vector<std::pair<boost::gregorian::date, std::vector<IndicatorTS_Point> > > x) : data(x){};
    
    friend std::ostream& operator<< (std::ostream&, const IndicatorTS&);
};

struct SimpleMovingAverage : IndicatorTS {
    SimpleMovingAverage(DailyTS, std::string, mpz_class);
};

#endif
