#include <iostream>
#include "src/timeSeries.h"
#include <vector>
#include <curl.h>

// TODO:
//   [ ] Charting Time Series
//   [ ] Sorting Time Series based on dates
//   [ ] Create function for merging Time Series's into one Time Series
//   [ ] Overload Time Series << ostream

int main() {
    DailyTS spy("/Users/meetpatel/XCodeProjects/Dollr/Dollr/SPY.csv");
    DailyTS dia("/Users/meetpatel/XCodeProjects/Dollr/Dollr/DIA.csv");
    
    DailyTS combined = spy + dia;
    
    std::cout << combined;
    
//    DailyTS_Point dts1("AAPL", Dollar(5), Dollar(6), Dollar(4), Dollar(5), 10000);
//    DailyTS_Point dts2("GOOG", Dollar(10), Dollar(11), Dollar(9), Dollar(10), 5000);
//
//    std::vector<DailyTS_Point> p1;
//    std::vector<DailyTS_Point> p2;
//    p1.push_back(dts1);
//    p2.push_back(dts2);
//
//    std::pair<boost::gregorian::date, std::vector<DailyTS_Point> > x = std::make_pair(boost::gregorian::from_string("2019-3-21"), p1);
//    std::pair<boost::gregorian::date, std::vector<DailyTS_Point> > y = std::make_pair(boost::gregorian::from_string("2019-3-21"), p2);
//
//    mergePair(x, y);
    
    
//    std::cout << spy;
//    std::cout << combined;

//    std::cout << timeseries;
//
//    for (auto i = 5; i < timeseries.points.size(); i++) {
//
//        mpz_class sum = 0;
//        for (auto j = 0; j < 5; j++) {
//            sum += timeseries.points.at(i).close.value;
//        }
//        sum = sum / 10000;
//        std::cout << sum.get_si() / 5.0 << std::endl;
//    }
//
//    std::cout << timeseries.points.size();
    return 0;

}
