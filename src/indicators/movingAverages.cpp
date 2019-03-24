#include "movingAverages.h"

std::ostream& operator<< (std::ostream& os, const IndicatorTS_Point x) {
    os << x.indicatorName << "for " << x.ticker << ": " << x.price;
    return os;
}

std::ostream& operator<< (std::ostream& os, const IndicatorTS& x) {
    for (auto &i : x.data) {
        os << std::get<0>(i) << std::endl;
        for (auto &j : std::get<1>(i)) {
            os << "     " << j << std::endl;
        }
    }
    return os;
}

SimpleMovingAverage::SimpleMovingAverage(DailyTS x, std::string tick, mpz_class period) {
    auto i = x.data.begin();
    std::advance(i, period.get_ui());
    for (; i != x.data.end(); i++) {
        boost::gregorian::date date = std::get<0>(*i);
        Dollar rollAvg;
        auto j = i;
        for (auto z = 0; z < period; z++) {
            j--;
        }
        for (; j != i; j++) {
            auto vec = std::get<1>(*j);
            for (auto z : vec) {
                if (z.ticker == tick) {
                    rollAvg = rollAvg + z.close;
                }
            }
        }
        Dollar avgPoint = rollAvg / period;
        IndicatorTS_Point ret("SMA" + std::to_string(period.get_si()) + " ", tick, avgPoint);
        std::vector<IndicatorTS_Point> retVec{ret};
        std::pair<boost::gregorian::date, std::vector<IndicatorTS_Point> > point = std::make_pair(date, retVec);
        data.push_back(point);
    }
}
