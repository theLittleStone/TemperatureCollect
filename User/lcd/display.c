#include "display.h"


//显示温度
void showTemperature(double temp, double res){
    int tmp1, res1;
    double tmp2, res2;
    char str1[20];
    char str2[20];
    if(temp >= 30 && temp < 60){
        tmp1 = 0;    					            //由于未知原因, 串口通信后(可能是用过printf)sprintf在转换
        tmp1 = (int)temp;                              //float型时会直接把小数部分直接丢掉, 所以使用传统方法进行转换
        tmp2 = 100*(temp-tmp1);
        BEEP_OFF;
        sprintf(str1, "Temp: %02d.%02d    ", tmp1, (int)tmp2);
    }
    else if (temp > 60){
        BEEP_ON;
        sprintf(str1, "Temp: over 60      ");
    }
    else{
        BEEP_ON;
        sprintf(str1, "Temp: under 30     ");
    }
    res1 = 0;
    res1 = (int)res;
    res2 = 100*(res-res1);

    sprintf(str2, "Res: %02d.%02d", res1, (int)res2);
    #if USE_LCD
    LCD_ShowString(78,140,240,16,16,str1);
    LCD_ShowString(78,180,240,16,16,str2);
    #else
    printf(str1);
    #endif
}
