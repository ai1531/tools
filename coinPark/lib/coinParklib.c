/******************************************************************************
*   MODULE      : coinParklib
*   FUNCTION    : library for coinPark simulator
*   NOTE        : 
*   CREATE      : 2024/11/26 A-1 Ito
*   UPDATE      : 
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "coinParklib.h"

/*******************************************************************************
* MODULE NAME  : createStruct
* ABSTRACT     : create struct Dates from year, month, hour, min
*******************************************************************************/
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

/*******************************************************************************
* MODULE NAME  : checkleap
* ABSTRACT     : check input year is leap(=1:TRUE) or NOT(=0:FALSE)
*******************************************************************************/
int checkleap (int year)
{
    if (year % 4 == 0)
    {
        if ((year % 100 == 0) && (year % 400 != 0))
        {
            return FALSE;
        }
        else
        {
            return TRUE;
        }
    }
    return FALSE;
}

/*******************************************************************************
* MODULE NAME  : toMinutes
* ABSTRACT     : convert hour to minutes
*******************************************************************************/
int toMinutes(int hour, int minute)
{
    return hour * 60 + minute;
}

/*******************************************************************************
* MODULE NAME  : getEarlierDate
* ABSTRACT     : return eariler Dates between 2 input Dates
*******************************************************************************/
int getEarlierDate(Dates date1, Dates date2)
{
    if (date1.year < date2.year) return 0;
    if (date1.year > date2.year) return 1;

    if (date1.month < date2.month) return 0;
    if (date1.month > date2.month) return 1;

    if (date1.day < date2.day) return 0;
    if (date1.day > date2.day) return 1;

    if (date1.hour < date2.hour) return 0;
    if (date1.hour > date2.hour) return 1;

    if (date1.min < date2.min) return 0;
    return 1;
}

/*******************************************************************************
* MODULE NAME  : jdgSameDates
* ABSTRACT     : judge 2 input Dates is same(=1:TRUE) or NOT(=0:FALSE)
*******************************************************************************/
int jdgSameDates(Dates date1, Dates date2)
{
    if (date1.year != date2.year) return FALSE;
    if (date1.month != date2.month) return FALSE;
    if (date1.day != date2.day) return FALSE;
    if (date1.hour != date2.hour) return FALSE;
    if (date1.min != date2.min) return FALSE;
    return TRUE;
}

/*******************************************************************************
* MODULE NAME  : addMinutes
* ABSTRACT     : add x[minute] to Dates
*******************************************************************************/
Dates addMinutes(Dates date, int x)
{
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

/*******************************************************************************
* MODULE NAME  : calcWeekday
* ABSTRACT     : calculate weekday of Dates
*******************************************************************************/
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

/*******************************************************************************
* MODULE NAME  : mkLastDay
* ABSTRACT     : calculate lastday of input year and month
*******************************************************************************/
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

/*******************************************************************************
* MODULE NAME  : jdgCompDates
* ABSTRACT     : judge date is in range or not
*******************************************************************************/
int jdgCompDates (int data, int min, int max)
{
   int wiunit;

    if (min <= data && data <= max) {
        wiunit = 0;
    } else{
        wiunit = 1;
    }
    return wiunit;
}