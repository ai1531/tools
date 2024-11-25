#include <stdio.h>

#include "coinPark.h"

int calcTime(Dates startDates, Dates endDates, Dates diffDates)
{
    int CT_errCode = 0;
    calcDiffDates(startDates, endDates, diffDates);
    CT_errCode = jdgDiffDates(diffDates);
    if (CT_errCode == 1)
    {
        diffDates = createStruct(-1, -1, -1, -1, -1);
    }
    return CT_errCode;
}

void calcDiffDates(Dates start, Dates end, Dates diff)
{
    diff.year = end.year - start.year;
    diff.month = end.month - start.month;
    diff.day = end.day - start.day;
    diff.hour = end.hour - start.hour;
    diff.min = end.min - start.min;
    if (diff.min < 0)
    {
        diff.min = diff.min + (MAX_MIN - MIN_MIN + 1);
        diff.hour = diff.hour - 1;
    }
    else if (diff.hour < 0)
    {
        diff.hour = diff.hour + (MAX_HOUR - MIN_HOUR + 1);
        diff.day = diff.day - 1;
    }
    else if (diff.day < 0)
    {
        diff.day = diff.day + (mkLastDay(start.year, start.day) - MIN_DAY + 1);
        diff.month = diff.month - 1;
    }
    else if (diff.month < 0)
    {
        diff.month = diff.month + (MAX_MONTH - MIN_MONTH + 1);
        diff.year = diff.year - 1;
    }
}

int jdgDiffDates(Dates date)
{
    int jdg = 0;
    if ( (MIN_YEAR < date.year || date.year < MAX_YEAR)
        || (MIN_MONTH < date.month || date.month < MAX_MONTH)
        || (MIN_DAY < date.day || date.day < mkLastDay(date.year, date.month))
        || (MIN_HOUR < date.hour || date.hour < MAX_HOUR)
        || (MIN_MIN < date.min || date.min < MAX_MIN) )
    {
        jdg = 1;
    }
    return jdg;
}
