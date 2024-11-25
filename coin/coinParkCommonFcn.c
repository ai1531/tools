#include <stdio.h>
#include <string.h>
#include <time.h>

#include "coinPark.h"

// create : create struct Dates
Dates createStruct(int year, int month, int day, int hour, int min)
{
    Dates d;
    d.year = year;
    d.month = month;
    d.day = day;
    d.hour = hour;
    d.min = min;
    return d;
}

int checkleap (int year)
{
    int ans;
    if (year % 4 == 0)
    {
        if ((year % 100 == 0) && (year % 400 != 0))
        {
            ans = false;
        }
        else
        {
            ans = true;
        }
    }
    else
    {
        ans = false;
    }
}

// convert : hour -> minute
int toMinutes(int hour, int minute)
{
    return hour * 60 + minute;
}

Dates getEarlierDate(Dates date1, Dates date2)
{
    if (date1.year < date2.year) return date1;
    if (date1.year > date2.year) return date2;

    if (date1.month < date2.month) return date1;
    if (date1.month > date2.month) return date2;

    if (date1.day < date2.day) return date1;
    if (date1.day > date2.day) return date2;

    if (date1.hour < date2.hour) return date1;
    if (date1.hour > date2.hour) return date2;

    if (date1.min < date2.min) return date1;
    return date2;
}

Dates addMinutes(Dates date, int x) {
    struct tm timeStruct = {0};
    time_t timeValue;

    // convert : Dates -> struct tm
    timeStruct.tm_year = date.year - 1900;
    timeStruct.tm_mon = date.month - 1;
    timeStruct.tm_mday = date.day;
    timeStruct.tm_hour = date.hour;
    timeStruct.tm_min = date.min;

    // convert : struct tm -> time_t
    timeValue = mktime(&timeStruct);

    // calc :  add x[min] (60[sec] * x[min])
    timeValue += x * 60;

    // convert : time_t -> struct tm
    struct tm *newTimeStruct = localtime(&timeValue);

    // convert : struct tm -> Dates
    Dates newDate;
    newDate.year = newTimeStruct->tm_year + 1900;
    newDate.month = newTimeStruct->tm_mon + 1;
    newDate.day = newTimeStruct->tm_mday;
    newDate.hour = newTimeStruct->tm_hour;
    newDate.min = newTimeStruct->tm_min;

    return newDate;
}

int calcWeekday(Dates date)
{
    struct tm day = {0};
    time_t tDay = {0};
    // tm_year : year. since 1900
    day.tm_year = date.year - 1900;
    // tm_month : month. January is 0 
    day.tm_mon = date.month - 1;
    // tm_mday : day. 1st is 1
    day.tm_mday = date.day;
    // mktime : convert. struct tm -> time_t
    tDay = mktime(&day);

    // localtime : convert. time_t -> struct tm
    // tm_wday : weekday. [Sunday, Monday, ..., Saturday  is 0, 1, ..., 6
    return localtime(&tDay)->tm_wday;
}

int mkLastDay (int year, int month)
{
    int ans = 0;
    switch (month)
    {
    case 1:
        ans = 31;
        break;
    case 2:
        if (checkleap(year) == 1)
        {
            ans = 29;
        }
        else
        {
            ans = 28;
        }
        break;
    case 3:
        ans = 31;
        break;
    case 4:
        ans = 30;
        break;
    case 5:
        ans = 31;
        break;
    case 6:
        ans = 30;
        break;
    case 7:
        ans = 31;
        break;
    case 8:
        ans = 31;
        break;
    case 9:
        ans = 30;
        break;
    case 10:
        ans = 31;
        break;
    case 11:
        ans = 30;
        break;
    case 12:
        ans = 31;
        break;
    default:
        ans = 0;
        break;
    }
    return ans;
}