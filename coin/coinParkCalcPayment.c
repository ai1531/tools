#include <stdio.h>
#include <string.h>
#include <time.h>

#include "coinPark.h"

int calcPayment(Dates startDate, Dates endDate, Dates diffDates)
{
    int totalPayment = 0;

    Dates currentDate = startDate;

    while (jdgSameDates(currentDate, endDate) == false)
    {
        // judge : time and paymentTime
        int pattern = checkDate(currentDate);
        int unitMinutes = payTypeList[pattern].minUnit;
        int unitRate = payTypeList[pattern].yenUnit;
        int maxRate = payTypeList[pattern].maxYen;
        printf("1");

        // calc : end time(in same payment type)
        Dates nextBoundary;
        switch (pattern)
        {
            case weekdays_daytime:
                nextBoundary = createStruct(currentDate.year, currentDate.month, currentDate.day
                                            , dayTime.endHour, dayTime.endMinute);
                break;
            case weekdays_night:
                nextBoundary = addMinutes(createStruct(currentDate.year, currentDate.month, currentDate.day
                                            , dayTime.startHour, dayTime.startMinute), 24 * 60);
                break;
            case holiday:
                nextBoundary = addMinutes(createStruct(currentDate.year, currentDate.month, currentDate.day
                                            , dayTime.startHour, dayTime.startMinute), 24 * 60);
                break;
        }
        printf("2");

        // compare : end time and next time
        Dates segmentEnd = getEarlierDate(endDate, nextBoundary);
        printf("3");

        // calc : time in this part
        Dates segmentDiff;
        calcTime(currentDate, segmentEnd, &segmentDiff);
        printf("4");
        int segmentMinutes = (segmentDiff.day * 24 * 60) +
                             (segmentDiff.hour * 60) +
                             segmentDiff.min;
        printf("5");

        // calc : payment in this part
        int segmentPayment = (segmentMinutes / unitMinutes) * unitRate;
        if (segmentPayment > maxRate) {
            segmentPayment = maxRate;
            printf("6");
        }

        totalPayment += segmentPayment;

        // set : next start time
        currentDate = segmentEnd;
        printf("7");
    }

    return totalPayment;
}


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
    int weekday = calcWeekday(date);
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
        pattern = weekdays_night;
    } else {
        pattern = weekdays_daytime;
    }
    return pattern;
}