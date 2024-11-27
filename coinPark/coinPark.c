/******************************************************************************
*   MODULE      : main function
*   FUNCTION    : initialize golbal variable, get reCalcFlg, and call manager
*   NOTE        : 
*   CREATE      : 2024/11/26 A-0 Ito
*   UPDATE      : 2024/11/27 A-1 Ito
******************************************************************************/
#include <stdio.h>
#include <string.h>

#include "coinPark.h"


/*******************************************************************************
* MODULE NAME  : main
* ABSTRACT     : call initialize and manager
*******************************************************************************/
void main ()
{
    int simendflg = 1;
    simendflg = manager();
}