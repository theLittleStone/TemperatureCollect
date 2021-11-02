#include "userStartUp.h"
#include "userInclude.h"

void sysInit(void){
    delay_init();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    #if USE_LCD
    LCD_Init();
    #else
    uart_init(115200);
    #endif
    Adc_Init();
}
