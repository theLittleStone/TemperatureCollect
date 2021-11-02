#include "userStartUp.h"
#include "userInclude.h"

double convertToTemperature(double voltage){
    return 22.1;
}

double convertToVoltage(double adcx){
    return adcx * (3.3/4096);
}

int main(void){
    int temp_ADC;
    int i;
    double vol, temp;
    AvgStructure avgStruc;
    avgStruc = resetAvg(avgStruc);
    sysInit();
    while (1){
        //每5 0ms采样一次, 10次为一周期取平均值
        for (i = 0; i < 10; i++){
            delay_ms(50);
            temp_ADC = Get_Adc(ADC_Channel_1);
            avgStruc = computeAvg(avgStruc, temp_ADC);
        }
        //转换成温度
        vol = convertToVoltage(avgStruc.lastAvg);
        temp = convertToTemperature(vol);
        //显示到lcd
        showTemperature(temp);
        //重置平均数结构体
        resetAvg(avgStruc);
    }
}

