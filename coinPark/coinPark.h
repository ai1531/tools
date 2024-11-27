/******************************************************************************
*   MODULE      : function or variable header
*   FUNCTION    : function or variable header
*   NOTE        : 
*   CREATE      : 2024/11/26 A-0 Ito
*   UPDATE      : 2024/11/27 A-1 Ito
******************************************************************************/
#include <stdio.h>

#include ".//lib//coinParklib.h"
#include ".//config//coinParkDB.h"


// coinParkManager.c
int manager();
int getRecalcFlg();

// coinParkCommonFcn.c
Dates createStruct(int year, int month, int day, int hour, int min);
int checkleap (int year);
int toMinutes(int hour, int minute);
Dates getEarlierDate(Dates date1, Dates date2);
int jdgSameDates(Dates date1, Dates date2);
Dates addMinutes(Dates date, int x);
int calcWeekday(Dates date);
int mkLastDay (int year, int month);

// Monji.c
int userIn(Dates *data){return 0;}

// Hayashi.c
int calManager(Dates data, Dates data,Dates diffDates){return 0;}

// coinParkDisplay.c
void displayManager(int totalPayment, int errCode);
void displayPayment(int totalPayment);
void displayErrMsg(int errCode)
