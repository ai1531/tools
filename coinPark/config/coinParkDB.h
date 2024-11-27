/******************************************************************************
*   MODULE      : coinParkDB
*   FUNCTION    : Database for coinPark
*   NOTE        : 
*   CREATE      : 2024/11/27 A-0 Ito
*   UPDATE      : 
******************************************************************************/
#define CAL_CONT 1
#define CAL_FIN 0
#define TRUE 1
#define FALSE 0

#define SIM_END 0
#define SIM_START 1

#define IN_YEAR 0
#define IN_MONTH 1
#define IN_DAY 2
#define IN_HOUR 3
#define IN_MIN 4
#define OUT_YEAR 5
#define OUT_MONTH 6
#define OUT_DAY 7
#define OUT_HOUR 8
#define OUT_MIN 9
#define INPUT_COMPLETE 10

#define NO_ERROR         0
#define ERROR_INYEAR     1
#define ERROR_INMONTH    2
#define ERROR_INDAY      3
#define ERROR_INHOUR     4
#define ERROR_INMIN      5
#define ERROR_OUTYEAR    6
#define ERROR_OUTMONTH   7
#define ERROR_OUTDAY     8
#define ERROR_OUTHOUR    9
#define ERROR_OUTMIN    10
#define ERROR_INTHANOUT 11
#define ERROR_OVER72H   12

#define HOLIDAY            0
#define WORKDAY_MORNING    1
#define WORKDAY_NIGHT      2

#define SUNDAY      0
#define MONDAY      1
#define TUESDAY     2
#define WEDNESDAY   3
#define THURSDAY    4
#define FRIDAY      5
#define SATURDAY    6

#define MIN_YEAR 1000
#define MAX_YEAR 9999
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MIN_DAY 1
#define MAX_DAY 31
#define MIN_HOUR 0
#define MAX_HOUR 23
#define MIN_MIN 0
#define MAX_MIN 59