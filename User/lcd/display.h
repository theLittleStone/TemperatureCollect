#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "stm32f10x.h"
#include "display.h"
#include "lcd.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "beep.h"

//决定是使用串口还是lcd
#define USE_LCD 1

void showTemperature(double temp, double res);

#endif
