#include <stdio.h>
#include <string.h>

#include "coinPark.h"


int main ()
{
    memset(holidayList, 0, sizeof(holidayList));
    memset(dayOffList, 0, sizeof(dayOffList));
    memset(nightTimeList, 0, sizeof(nightTimeList));
    memset(payTypeList, 0, sizeof(payTypeList));
    dayTime.startHour = 0;
    dayTime.startMinute = 0;
    dayTime.endHour = 0;
    dayTime.endMinute = 0;

    initSetting(holidayList, dayOffList, nightTimeList, payTypeList);
}