#include <stdio.h>
#include <string.h>

#include "coinPark.h"

Dates manager()
{
    Dates startDate;
    Dates endDate;
    Dates diffDates;
    int reCalcFlg = 1;
    int permEndFlg = 1;
    int reSetStartDateFlg = 1;
    int reSetDateFlg = 1;
    int CT_errCode = 0;
    printf("oO oO oO Welcome to coinPark teamA oO oO oO\n");
    while (reCalcFlg != 0)
    {
        while (reSetDateFlg != 0)
        {
            printf("Uo.oU <( Please set START date! )\n");
            printf("Uo.oU <( Please input data and press Enter key. )\n");
            startDate = setData("start");
            endDate = setData("end");
        }

        CT_errCode = calcTime(startDate, endDate, diffDates);
        if (CT_errCode == 1)
        {
            reSetDateFlg = 1;
            continue;
        }
        calcPayment(startDate, endDate, diffDates);
    }
}



void printSetMessage(int errCode, char *name, char *phase)
{
    if (errCode == 1) {
        printf("U>.<U <( Your data is error, please set data again.. )\n");
    }

    if (strcmp(name,"year")) {
        printf("%s YEAR(ex.2024) : ", phase);
    } else if (strcmp(name, "month")) {
        printf("%s MONTH(ex.11) : ", phase);
    } else if (strcmp(name, "month")) {
        printf("%s DAY(ex.18) : ", phase);
    } else if (strcmp(name, "hour")) {
        printf("%s HOUR(ex.15) : ", phase);
    } else if (strcmp(name, "min")) {
        printf("%s MINUTE(ex.31) : ", phase);
    }
}

int getInputData(Dates data, char *name, char *phase)
{
    int errCode = 1;
    while (errCode != 0)
    {
        printSetMessage(errCode, name, phase);
        errCode = inputAnalisys(data, name);
    }
    return errCode;
}

int inputAnalisys(Dates data, char *name)
{
    int errCode = 0;
    int min = 0;
    int max = 0;
    int x = 0;

    if (strcmp(name, "year")) {
        scanf("%d", &data.year);
        x = data.year;
        min = MIN_YEAR;
        max = MAX_YEAR;
    } else if (strcmp(name, "month")) {
        scanf("%d", &data.month);
        x = data.month;
        min = MIN_MONTH;
        max = MAX_MONTH;
    } else if (strcmp(name, "day")) {
        scanf("%d", &data.day);
        x = data.day;
        min = MIN_DAY;
        max = mkLastDay(data.year, data.month);
    } else if (strcmp(name, "hour")) {
        scanf("%d", &data.hour);
        x = data.hour;
        min = MIN_HOUR;
        max = MAX_HOUR;
    } else if (strcmp(name, "min")) {
        scanf("%d", &data.min);
        x = data.min;
        min = MIN_MIN;
        max = MAX_MIN;
    }

    if (min <= x && x <= max) {
        errCode = 0;
    } else{
        errCode = 1;
    }
    return errCode;
}

Dates setData(char *phase)
{
    Dates date;
    int errCode = 0;
    int reSetDateFlg = 1;
    while (reSetDateFlg != 0)
    {
        getInputData(date, "year", phase);
        getInputDatas(date, "month", phase);
        getInputData(date, "day", phase);
        getInputData(date, "hour", phase);
        errCode = getInputData(date, "min", phase);
        if (errCode == 0)
        {
            reSetDateFlg = 0;
        }
    }
    return date;
}