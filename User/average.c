#include "average.h"

AvgStructure computeAvg(AvgStructure AvgStru, double newData){
    int c;
    AvgStru.count ++;
    c = AvgStru.count;
    AvgStru.lastAvg = (c-1) * (AvgStru.lastAvg) / c + newData / c;
    return AvgStru;
}

AvgStructure resetAvg(AvgStructure AvgStru){
    AvgStru.count = 0;
    AvgStru.lastAvg = 0;
    return AvgStru;
}
