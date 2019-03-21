#ifndef timeSeries_h
#define timeSeries_h

#include <vector>
#include <tuple>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>

struct DailyTS_Point {
    boost::gregorian::date date;
    double open;
    
};

class DailyTS {
private:
    std::vector<DailyTS_Point> points;
};

#endif
