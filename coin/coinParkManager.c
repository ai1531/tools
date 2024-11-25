#include <stdio.h>
#include <string.h>

#include "coinPark.h"

void manager()
{
    Dates startDate;
    Dates endDate;
    Dates diffDates;
    int reCalcFlg = 1;
    int permEndFlg = 0;
    int CT_errCode = 0;
    int totalPayment = 0;

    printf("oO oO oO Welcome to coinPark teamA oO oO oO\n");
    while (permEndFlg != 1)
    {
        printf("Uo.oU <( Please set START date! )\n");
        printf("Uo.oU <( Please input data and press Enter key. )\n");
        startDate = setData("start");
        endDate = setData("end");

        CT_errCode = calcTime(startDate, endDate, &diffDates);
        printf("CT_errCode is %d\n", CT_errCode);
        if (CT_errCode == 1)
        {
            continue;
            printf("CT_errCode was ONE.\n");
        }
        totalPayment = calcPayment(startDate, endDate, diffDates);
        printf("Uo.oU* <( TOTAL payment is %d yen. )\n", totalPayment);
        printf("Uo.oU <( Please select FINISH or calcurate AGAIN. )\n");
        printf("select 0=Fihish calcurate or 1=calcurate AGAIN : ");
        scanf("%d", &reCalcFlg);
        if (reCalcFlg == 1)
        {
            continue;
        }
        printf("Uo.oU <( May I finish calcurate? )\n");
        printf("select 0=NOT finish or 1=PERMIT finish : ");
        scanf("%d", &permEndFlg);
        if (permEndFlg == 0)
        {
            continue;
        }
    }
}



void printSetMessage(int errCode, char *name, char *phase)
{
    if (errCode == 1) {
        printf("U>.<U <( Your data is error, please set data again.. )\n");
    }

    if (strcmp(name,"year") == 0) {
        printf("%s YEAR(ex.2024) : ", phase);
    } else if (strcmp(name, "month") == 0) {
        printf("%s MONTH(ex.11) : ", phase);
    } else if (strcmp(name, "day") == 0) {
        printf("%s DAY(ex.18) : ", phase);
    } else if (strcmp(name, "hour") == 0) {
        printf("%s HOUR(ex.15) : ", phase);
    } else if (strcmp(name, "min") == 0) {
        printf("%s MINUTE(ex.31) : ", phase);
    }
}

int getInputData(Dates *data, char *name, char *phase)
{
    int errCode = 0;
    printSetMessage(errCode, name, phase);
    errCode = inputAnalisys(data, name);
    while (errCode != 0)
    {
        printSetMessage(errCode, name, phase);
        errCode = inputAnalisys(data, name);
    }
    return errCode;
}

int inputAnalisys(Dates *data, char *name)
{
    int errCode = 0;
    int min = 0;
    int max = 0;
    int x = 0;

    if (strcmp(name, "year") == 0) {
        scanf("%d", &data->year);
        x = data->year;
        min = MIN_YEAR;
        max = MAX_YEAR;
    } else if (strcmp(name, "month") == 0) {
        scanf("%d", &data->month);
        x = data->month;
        min = MIN_MONTH;
        max = MAX_MONTH;
    } else if (strcmp(name, "day") == 0) {
        scanf("%d", &data->day);
        x = data->day;
        min = MIN_DAY;
        max = mkLastDay(data->year, data->month);
    } else if (strcmp(name, "hour") == 0) {
        scanf("%d", &data->hour);
        x = data->hour;
        min = MIN_HOUR;
        max = MAX_HOUR;
    } else if (strcmp(name, "min") == 0) {
        scanf("%d", &data->min);
        x = data->min;
        min = MIN_MIN;
        max = MAX_MIN;
        printf("(minute, min, max) = (%d, %d, %d)\n",x, min, max);
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
        getInputData(&date, "year", phase);
        getInputData(&date, "month", phase);
        getInputData(&date, "day", phase);
        getInputData(&date, "hour", phase);
        errCode = getInputData(&date, "min", phase);
        printf("errCode is %d\n", errCode);
        if (errCode == 0)
        {
            reSetDateFlg = 0;
        }
        printf("reSetDateFlg is %d\n", reSetDateFlg);
    }
    return date;
}