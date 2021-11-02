#include "display.h"


//显示温度
void showTemperature(double temp){
    int tmp1;
    double tmp2;
    char str1[20];
    tmp1 = 0;    					            //由于未知原因, 串口通信后(可能是用过printf)sprintf在转换
    tmp1 = (int)temp;                              //float型时会直接把小数部分直接丢掉, 所以使用传统方法进行转换
    tmp2 = 100*(temp-tmp1);
    sprintf(str1, "Temp: %02d.%02d", tmp1, (int)tmp2);
    #if USE_LCD
    LCD_ShowString(78,140,240,16,16,str1);
    #else
    printf(str1);
    #endif
}
