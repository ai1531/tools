/******************************************************************************
*   MODULE      : coinParkDisplay
*   FUNCTION    : display total payment or error message
*   NOTE        : 
*   CREATE      : 2024/11/26 A-0 Ito
*   UPDATE      : 2024/11/27 A-1 Ito
******************************************************************************/

#include <stdio.h>
#include <string.h>

#include "coinPark.h"

/*******************************************************************************
* MODULE NAME  : displayPayment
* ABSTRACT     : display user payment
*******************************************************************************/
void displayManager(int totalPayment, int errCode)
{
    if (errCode != 0)
    {
        displayErrMsg(errCode);
    }
    else
    {
        displayPayment(totalPayment);
    }
}

/*******************************************************************************
* MODULE NAME  : displayPayment
* ABSTRACT     : display user payment
*******************************************************************************/
void displayPayment(int totalPayment)
{
    printf("Your payment is %d yen.\n", totalPayment);
}

/*******************************************************************************
* MODULE NAME  : getRecalcFlg
* ABSTRACT     : print massage which order input and get reCalcFlg
*******************************************************************************/
void displayErrMsg(int errCode)
{
    switch(errCode)
    {
        case 1:
            printf("[error]Your input time is over.\n");
            break;
        case 2:
            printf("[error]Your left is before enter.\n");
            break;
        case 3:
            printf("[error]Your left is same as enter.\n");
            break;
        case 4:
            printf("[error]Your time is past.\n");
            break;
        case 5:
            printf("[error]Your input is not correct format.\n");
            break;
        case 6:
            printf("[error]Your input is out of range.\n");
            break;
        default:
            break;
    }
    printf("Please set time, again.\n");
}