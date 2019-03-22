#ifndef movingAverages_h
#define movingAverages_h

#include "../timeSeries.h"

class SimpleMovingAverage : DailyTS {
public:
    SimpleMovingAverage(DailyTS, mpz_class);
};

#endif
