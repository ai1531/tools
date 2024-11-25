#include <stdio.h>
#include <time.h>

#include "coinPark.h"

int calcPayment(Dates startDates, Dates endDates, Dates diffDates)
{}



// the date is Holiday or not
int jdgHoliday(Dates date)
{
    int i = 0;
    int idx = -1;

    for (i = 0; strcmp(holidayList[i].name, "0") != 0; i++) {
        if (holidayList[i].validFlg == true &&
            ((date.month > holidayList[i].startMonth || 
             (date.month == holidayList[i].startMonth && date.day >= holidayList[i].startDay)) &&
             (date.month < holidayList[i].endMonth || 
             (date.month == holidayList[i].endMonth && date.day <= holidayList[i].endDay)))) {
            idx = i;
        }
    }
    return idx;
}

// the date is day off or not
int jdgDayOff(Dates date)
{
    int weekday = checkWeekday(date);
    int i = 0;
    int idx = -1;

    for (i = 0; strcmp(dayOffList[i].name, "0") != 0; i++) {
        if (dayOffList[i].validFlg == true)
        {
            switch (weekday)
            {
                case 0: if (dayOffList[i].sunday) idx = i; break;
                case 1: if (dayOffList[i].monday) idx = i; break;
                case 2: if (dayOffList[i].tuesday) idx = i; break;
                case 3: if (dayOffList[i].wednesday) idx = i; break;
                case 4: if (dayOffList[i].thursday) idx = i; break;
                case 5: if (dayOffList[i].friday) idx = i; break;
                case 6: if (dayOffList[i].saturday) idx = i; break;
            }
        }
    }
    return idx;
}

// the time is night time or not
int jdgNightTime(Dates date)
{
    int i = 0;
    int idx = -1;

    for (i = 0; strcmp(nightTimeList[i].name, "0") != 0; i++)
    {
        if (nightTimeList[i].validFlg == true &&
            ((date.hour > nightTimeList[i].startHour ||
             (date.hour == nightTimeList[i].startHour && date.min >= nightTimeList[i].startMinute)) &&
             (date.hour < nightTimeList[i].endHour ||
             (date.hour == nightTimeList[i].endHour && date.min <= nightTimeList[i].endMinute))))
        {
            idx = i;
        }
    }
    return idx;
}

// judge pattern
int checkDate(Dates date)
{
    int pattern = 0;
    if (jdgHoliday(date) == true || jdgDayOff(date) == true)
    {
        pattern = holiday;
    }
    else if (jdgNightTime(date) == true) {
        pattern = weekday_night;
    } else {
        pattern = weekday_daytime;
    }
    return pattern;
}



void calcSamePtnEndDates(Dates startDates, Dates endDates, Dates startList[NUM], Dates endList[NUM], PayType payTypeList[NUM])
{
    int i = 0;
    int ptn = 0;
    int holiIdx = -1;
    int dyOfIdx = -1;
    int nitIdx = -1;
    Dates tmpDates = {0};
    ptn = checkDate(startDates);
    startList = {0};
    endList = {0};
    startList[0] = startDates;
    while (endList[i] != endDates)
    {
        holiIdx = jdgHoliday(startList[i]);
        dyOfIdx = jdgDayOff(startList[i]);
        nitIdx = jdgNightTime(startList[i]);
        payType[i] = ptn;
        switch (ptn)
        {
            case weekdays_night:
                tmpDates = createStruct(startDates.year, startDates.month, startDates.day, nightTimeList[nitIdx].endHour, nightTimeList[nitIdx].endMinute);
                tmpDates = getEarlierDate(endDates, tmpDates);
                endList[i] = cerateStruct(startDates.year, startDates.month, startDates.day, tmpDates.Hour, tmpDates.Minutes);
                startList[i] = addMinutes(endList, 1);
                i++;
                break;
            case holiday:
                tmpDates = createStruct(startDates.year, startDates.month, startDates.day, MAX_HOUR, MAX_MIN);
                tmpDates = getEarlierDate(endDates, tmpDates);
                endList[i] = cerateStruct(startDates.year, startDates.month, startDates.day, tmpDates.Hour, tmpDates.Minutes);
                startList[i] = addMinutes(endList, 1);
                i++;
                break;
            case weekdays_daytime:
                tmpDates = createStruct(startDates.year, startDates.month, startDates.day, dayTime.endHour, dayTime.endMinute);
                tmpDates = getEarlierDate(endDates, tmpDates);
                endList[i] = cerateStruct(startDates.year, startDates.month, startDates.day, tmpDates.Hour, tmpDates.Minutes);
                startList[i] = addMinutes(endList, 1);
                i++;
                break;
            case default:
                endList[i] = cerateStruct(0, 0, 0, 0, 0);
                break;
        }
    }
}