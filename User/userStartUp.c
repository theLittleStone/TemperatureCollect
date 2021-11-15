#include "userStartUp.h"
#include "userInclude.h"

void sysInit(void){
    delay_init();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    uart_init(115200);
    #if USE_LCD
    LCD_Init();
    #endif
    Adc_Init();
    BEEP_Init();
}
