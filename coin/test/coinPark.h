#include <stdio.h>

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
#define true 1
#define false 0
#define NUM 100
#define weekdays_daytime 0
#define weekdays_night 1
#define holiday 2
#define NUM_OF_PAYTYPE 3

// coinPark.c
typedef struct
{
    char name[50];
    int startMonth;
    int startDay;
    int endMonth;
    int endDay;
    int validFlg;
}Holiday;

typedef struct
{
    char name[50];
    int sunday;
    int monday;
    int tuesday;
    int wednesday;
    int thursday;
    int friday;
    int saturday;
    int validFlg;
}DayOff;

typedef struct
{
    char name[50];
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
    int validFlg;
}Night;

typedef struct {
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
}DayTime;

typedef struct
{
    char name[50];
    int minUnit;
    int yenUnit;
    int maxYen;
}PayType;

// coinParkInit.c
Holiday holidayList[NUM];
DayOff dayOffList[NUM];
Night nightTimeList[NUM];
DayTime dayTime;
PayType payTypeList[NUM_OF_PAYTYPE + 1];
int initSetting(Holiday holiList[NUM], DayOff dyOfList[NUM], Night nitList[NUM], PayType pyTpList[NUM_OF_PAYTYPE + 1]);
int setHoliday(Holiday holiList[NUM]);
int setDayOff(DayOff dyOfList[NUM]);
int setNightTime(Night nitList[NUM]);
int toMinutes(int hour, int minute);
DayTime calcDayTime(Night nitList[NUM]);
int setPayType(PayType pyTpList[NUM_OF_PAYTYPE + 1]);
void printList(Holiday holiList[NUM], DayOff dyOfList[NUM], Night nitList[NUM], DayTime dayT, PayType pyTpList[NUM_OF_PAYTYPE + 1]);

// coinParkManager.c
typedef struct
{
    int year;
    int month;
    int day;
    int hour;
    int min;
} Dates;