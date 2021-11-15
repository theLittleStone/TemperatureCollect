#include "userStartUp.h"
#include "userInclude.h"
#include <math.h>

double convertToTemperature(double resister){
    return 67.919 - 29.23 * log(resister);
}
double convertToResister(double voltage){
    return 5 * voltage / (5 - voltage);
}

double convertToVoltage(double adcx){
    return adcx * (3.3/4096);
}

int main(void){
    int temp_ADC;
    int i;
    double vol, temp, res;
    AvgStructure avgStruc;
    avgStruc = resetAvg(avgStruc);
    sysInit();
    while (1){
        //每50ms采样一次, 10次为一周期取平均值
        for (i = 0; i < 10; i++){
            delay_ms(50);
            temp_ADC = Get_Adc(ADC_Channel_1);
            avgStruc = computeAvg(avgStruc, temp_ADC);
        }
        //转换成温度
        vol = convertToVoltage(avgStruc.lastAvg);
        res = convertToResister(vol);
        temp = convertToTemperature(res);
        //显示到lcd
        showTemperature(temp, res);
        //重置平均数结构体
        avgStruc = resetAvg(avgStruc);
     }
}

