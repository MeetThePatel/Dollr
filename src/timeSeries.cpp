#include "timeSeries.h"

DailyTS_Point::DailyTS_Point(boost::gregorian::date d, Dollar o, Dollar h, Dollar l, Dollar c, mpz_class v) : date(d), open(o), high(h), low(h), close(c), volume(v) {}

std::ostream& operator<< (std::ostream& os, const DailyTS_Point& x) {
    os << x.date << "  Open: " << x.open << "  High: " << x.high << "  Low: " << x.low;
    os << "  Close: " << x.close << "  Volume: " << x.volume.get_si() << std::endl;
    return os;
}

DailyTS::DailyTS(){};

DailyTS::DailyTS(std::vector<DailyTS_Point> x) {
    points = x;
}

DailyTS::DailyTS(std::string x) {
    std::ifstream f(x);
    aria::csv::CsvParser parser(f);
    
    for (auto i = std::next(parser.begin()); i != parser.end(); ++i) {
        boost::gregorian::date d = boost::gregorian::from_string(i->at(0));
        Dollar o(std::stof(i->at(1)));
        Dollar h(std::stof(i->at(2)));
        Dollar l(std::stof(i->at(3)));
        Dollar c(std::stof(i->at(4)));
        mpz_class v(i->at(6));
        
        DailyTS_Point x{d, o, h, l, c, v};
        points.push_back(x);
    }
}

void DailyTS::push_back(DailyTS_Point x) {
    points.push_back(x);
}

std::ostream& operator<< (std::ostream& os, const DailyTS& x) {
    for (auto &i : x.points) {
        os << i;
    }
    return os;
}
