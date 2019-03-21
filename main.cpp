#include <iostream>
#include "src/timeSeries.h"

// TODO:
//   [X] Print overload for DailyTS_Point
//   [X] Read into vector<DailyTS_Point>
//   [X] Print overload for DailyTS

int main() {
    DailyTS timeseries("/Users/meetpatel/XCodeProjects/Dollr/Dollr/SPY.csv");
    std::cout << timeseries;
    
    return 0;
}
