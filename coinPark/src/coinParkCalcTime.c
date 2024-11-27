/******************************************************************************
*   MODULE      : モジュール名(アルファベット小文字)
*   FUNCTION    : モジュールの機能
*   NOTE        : モジュールに間連した注意事項(ない場合は削除可)
*   CREATE      : 作成日付   バージョン番号    作成者(姓だけ)
*                 作成時コメント
*   UPDATE      : 更新日付   バージョン番号    更新者(姓だけ)
*                 更新内容
******************************************************************************/

#include <stdio.h>

#include "coinPark.h"

int calcTime(Dates startDates, Dates endDates, Dates *diffDates)
{
    int CT_errCode = 0;
    calcDiffDates(startDates, endDates, diffDates);
    printf("diffDates is %d, %d, %d, %d, %d",diffDates->year,diffDates->month,diffDates->day,diffDates->hour,diffDates->min);
    CT_errCode = jdgDiffDates(*diffDates);
    return CT_errCode;
}

void calcDiffDates(Dates start, Dates end, Dates *diff)
{
    diff->year = end.year - start.year;
    diff->month = end.month - start.month;
    diff->day = end.day - start.day;
    diff->hour = end.hour - start.hour;
    diff->min = end.min - start.min;
    if (diff->min < 0)
    {
        diff->min = diff->min + (MAX_MIN - MIN_MIN + 1);
        diff->hour--;
    }
    else if (diff->hour < 0)
    {
        diff->hour = diff->hour + (MAX_HOUR - MIN_HOUR + 1);
        diff->day--;
    }
    else if (diff->day < 0)
    {
        diff->day = diff->day + (mkLastDay(start.year, start.day) - MIN_DAY + 1);
        diff->month--;
    }
    else if (diff->month < 0)
    {
        diff->month = diff->month + (MAX_MONTH - MIN_MONTH + 1);
        diff->year--;
    }
}

int jdgDiffDates(Dates date)
{
    int jdg = 0;
    if (date.year < 0 || toHour(&date) > MAX_TIME)
    {
        jdg = 1;
    }
    return jdg;
}
