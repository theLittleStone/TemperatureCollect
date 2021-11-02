
#include "stm32f10x.h"
#include "display.h"
#include "lcd.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"




//显示湿度与温度
void showH_T(void){     
    float temp,humi;
    int tmp;
    char str1[20],str2[20];
    temp = 0;    					            //由于未知原因, 串口通信后(可能是用过printf)sprintf在转换 
    tmp = (int)temp;                              //float型时会直接把小数部分直接丢掉, 所以使用传统方法进行转换
    temp = 100*(temp-tmp);
    sprintf(str1, "Temp: %02d.%02d", tmp, (int)temp);
    humi = 0;
    tmp = (int)humi;
    humi = 100*(humi-tmp);
    sprintf(str2, "Humi: %02d.%02d%%", tmp, (int)humi);
    LCD_ShowString(78,140,240,16,16,str1);
    LCD_ShowString(78,160,240,16,16,str2);
}
