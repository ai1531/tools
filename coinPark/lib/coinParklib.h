/******************************************************************************
*   MODULE      : library header
*   FUNCTION    : library header
*   NOTE        : 
*   CREATE      : 2024/11/26 A-1 Ito
*   UPDATE      : 
******************************************************************************/
#include <stdio.h>

typedef struct
{
    int year;
    int month;
    int day;
    int hour;
    int min;
} Dates;
Dates createStruct(int year, int month, int day, int hour, int min);
int checkleap (int year);
int toMinutes(int hour, int minute);
int getEarlierDate(Dates date1, Dates date2);
int jdgSameDates(Dates date1, Dates date2);
Dates addMinutes(Dates date, int x);
int calcWeekday(Dates date);
int mkLastDay (int year, int month);
int jdgCompDates (int data, int min, int max);