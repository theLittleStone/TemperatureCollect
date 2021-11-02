#include "userStartUp.h"
#include "userInclude.h"

void sysInit(void){
    delay_init();
    uart_init(115200);
    LCD_Init();
}
