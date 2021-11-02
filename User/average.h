#ifndef __AVERAGE__
#define __AVERAGE__

typedef struct{
    //记录一共进行了几次迭代
    int count;
    //上次的平均值
    double lastAvg;
}AvgStructure;

//初始化, 重置平均数结构体
AvgStructure resetAvg(AvgStructure AvgStru);
//进行一次迭代
AvgStructure computeAvg(AvgStructure AvgStru, double newData);


#endif
