/******************************************************************************
*   MODULE      : coinParkManager
*   FUNCTION    : scheduling each module
*   NOTE        : 
*   CREATE      : 2024/11/26 A-0 Ito
*   UPDATE      : 2024/11/27 A-1 Ito
******************************************************************************/

#include <stdio.h>
#include <string.h>

#include "coinPark.h"

/*******************************************************************************
* MODULE NAME  : manager
* ABSTRACT     : scheduling each module
*******************************************************************************/
int manager()
{
    Dates startDate;
    Dates endDate;
    Dates diffDates;
    int reCalcFlg = 1;
    int werrcode = 0;
    int totalPayment = 0;
    int simendflg = 1;

    printf("oO oO oO Welcome to coinPark teamA oO oO oO\n");
    while (permEndFlg != 1)
    {
        printf("Please set START date.\n");
        werrcode = userIn(Dates *data);
        if (werrcode != 0)
        {
            displayManager(totalPayment, werrcode);
            return simendflg;
        }

        printf("Now calcurating...\n");
        totalPayment = calManager(Dates data, Dates data,Dates diffDates);
        
        displayManager(totalPayment, werrcode);
        werrcode = 0;
        reCalcFlg = getRecalcFlg();
        if (reCalcFlg == 1)
        {
            continue;
        }
        printf("Finish calcurate.\n");
        printf("oO oO oO Thank you for coming to coinPark teamA oO oO oO\n");
    }
    return simendflg;
}

/*******************************************************************************
* MODULE NAME  : getRecalcFlg
* ABSTRACT     : print massage which order input and get reCalcFlg
*******************************************************************************/
int getRecalcFlg()
{
    int reCalcFlg = 0;
    printf("Please select FINISH or calcurate AGAIN.\n");
    printf("0 = FINISH, 1 = calcurate AGAIN : ");
    scanf("%d", reCalcFlg);
    return reCalcFlg;
}