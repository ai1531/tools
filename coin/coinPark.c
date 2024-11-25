#include <stdio.h>
#include <string.h>

#include "coinPark.h"

// declarate global value
Holiday holidayList[NUM];
DayOff dayOffList[NUM];
Night nightTimeList[NUM];
DayTime dayTime;
PayType payTypeList[NUM_OF_PAYTYPE + 1];

void initializeLists()
{
    // initialise : holidayList
    for (int i = 0; i < NUM; i++) {
        strcpy(holidayList[i].name, "Holiday Name");
        holidayList[i].startMonth = 0;
        holidayList[i].startDay = 0;
        holidayList[i].endMonth = 0;
        holidayList[i].endDay = 0;
        holidayList[i].validFlg = 0;
    }

    // initialise : dayOffList
    for (int i = 0; i < NUM; i++) {
        strcpy(dayOffList[i].name, "DayOff Name");
        dayOffList[i].sunday = 0;
        dayOffList[i].monday = 0;
        dayOffList[i].tuesday = 0;
        dayOffList[i].wednesday = 0;
        dayOffList[i].thursday = 0;
        dayOffList[i].friday = 0;
        dayOffList[i].saturday = 0;
        dayOffList[i].validFlg = 0;
    }

    // initialise : nightTimeList
    for (int i = 0; i < NUM; i++) {
        strcpy(nightTimeList[i].name, "Night Name");
        nightTimeList[i].startHour = 0;
        nightTimeList[i].startMinute = 0;
        nightTimeList[i].endHour = 0;
        nightTimeList[i].endMinute = 0;
        nightTimeList[i].validFlg = 1;
    }

    // initialise : payTypeList
    for (int i = 0; i < NUM; i++) {
        strcpy(payTypeList[i].name, "PayType Name");
        payTypeList[i].minUnit = 0;
        payTypeList[i].yenUnit = 0;
        payTypeList[i].maxYen = 0;
    }

    //initialize : dayTime
    dayTime.startHour = 0;
    dayTime.startMinute = 0;
    dayTime.endHour = 0;
    dayTime.endMinute = 0;
    
}

int main ()
{
    int initAns;
    initializeLists();

    initAns = initSetting(holidayList, dayOffList, nightTimeList, payTypeList);
    if (initAns != 0)
    {
        return -1;
    }
    manager();
    return 0;
} 