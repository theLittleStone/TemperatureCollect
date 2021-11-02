#ifndef __DISPLAY_H__
#define __DISPLAY_H__

enum Message{
    GettingTime = 0,
    GetTimeSuccessfully = 1,
    FailToGetTime = 2
};
enum settingType{
    NONE = 0, ALARM_SETTING, CLOCK_SETTING
};
enum settingPart{
    HOUR = 0, MINUTE, SECOND, YEAR, MONTH, DAY
};

void showH_T(void);
#endif
