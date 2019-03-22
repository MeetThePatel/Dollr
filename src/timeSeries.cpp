#include "timeSeries.h"

DailyTS_Point::DailyTS_Point(std::string t, Dollar o, Dollar h, Dollar l, Dollar c, mpz_class v) {
    ticker = t;
    open = o;
    high = h;
    low = l;
    close = c;
    volume = v;
}

std::ostream& operator<< (std::ostream& os, const DailyTS_Point& x) {
    os << x.ticker << ": ";
    os << "  Open: " << x.open << "  High: " << x.high << "  Low: " << x.low;
    os << "  Close: " << x.close << "  Volume: " << x.volume.get_si() << std::endl;
    return os;
}

DailyTS::DailyTS(){};

DailyTS::DailyTS(std::vector<std::pair<boost::gregorian::date, std::vector<DailyTS_Point> > > x) {
    data = x;
}

DailyTS::DailyTS(std::string x) {
    std::ifstream f(x);
    aria::csv::CsvParser parser(f);
    
    auto indexOfSlash = x.find_last_of("/");
    auto indexOfPeriod = x.find_last_of(".");
    
    std::string t = x.substr(indexOfSlash + 1, indexOfPeriod - indexOfSlash - 1);
    
    for (auto i = std::next(parser.begin()); i != parser.end(); ++i) {
        Dollar o(std::stof(i->at(1)));
        Dollar h(std::stof(i->at(2)));
        Dollar l(std::stof(i->at(3)));
        Dollar c(std::stof(i->at(4)));
        mpz_class v(i->at(6));
        
        DailyTS_Point x{t, o, h, l, c, v};
        
        boost::gregorian::date d = boost::gregorian::from_string(i->at(0));
        std::vector<DailyTS_Point> j;
        j.push_back(x);
        std::tuple<boost::gregorian::date, std::vector<DailyTS_Point> > tup = std::make_tuple(d, j);
        
        data.push_back(tup);
    }
}

void mergePair(std::pair<boost::gregorian::date, std::vector<DailyTS_Point> > &x, std::pair<boost::gregorian::date, std::vector<DailyTS_Point> > &y) {
    
    if (std::get<0>(x) == std::get<0>(y)) {
        std::get<1>(x).insert(std::get<1>(x).end(), std::get<1>(y).begin(), std::get<1>(y).end());
    }
    
}

DailyTS operator+ (DailyTS x, DailyTS y) {
    DailyTS ret = x;
    for (auto &i : ret.data) {
        for (auto &j : y.data) {
            mergePair(i, j);
        }
    }
    return ret;
}

void DailyTS::push_back(std::pair<boost::gregorian::date, std::vector<DailyTS_Point> > x) {
    data.push_back(x);
}

std::ostream& operator<< (std::ostream& os, const DailyTS& x) {
    for (auto &i : x.data) {
        std::cout << std::get<0>(i) << std::endl;
        for (auto &j : std::get<1>(i)) {
            std::cout << "     " << j;
        }
    }
    return os;
}
