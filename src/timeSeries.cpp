#include "timeSeries.h"

ostream& operator<< (ostream& os, const OHLCV_Point& x) {
    os << "Open: " << x.open << "  High: " << x.high << "  Low: " << x.low << "  Close: " << x.close << "  Volume: " << x.volume.get_str() << endl;
    return os;
}
