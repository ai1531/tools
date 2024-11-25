#include <stdio.h>
#include <string.h>

#include "coinPark.h"

int initSetting(Holiday holiList[NUM], DayOff dyOfList[NUM], Night nitList[NUM], PayType pyTpList[NUM_OF_PAYTYPE + 1])
{
    int ansHoli = 0;
    int ansDyOf = 0;
    int ansNit = 0;
    int ansPyT = 0;
    DayTime dayT = {0};

    ansHoli = setHoliday(holiList);
    ansDyOf = setDayOff(dyOfList);
    ansNit = setNightTime(nitList);
    dayT = calcDayTime(nitList);
    ansPyT = setPayType(pyTpList);

    if (ansHoli == -1) {
        printf("U>.<U <( Failed to load holiday list. )\n");
        return -1;
    }
    if (ansDyOf == -1) {
        printf("U>.<U <( Failed to load day off list. )\n");
        return -1;
    }
    // printList(holiList, dyOfList, nitList, dayT, pyTpList);
    return 0;
}

int setHoliday(Holiday holiList[NUM])
{
    FILE *fp;
    char *fname = ".\\config\\holidayList.csv";
    char header[100];
    int ret;
    int i = 0;

    fp = fopen(fname, "r" );
    if( fp == NULL )
    {
        printf("U>.<U <( file \"%s\" cannot open. )\n", fname );
        return -1;
    }

    // ignore header
    if (fgets(header, sizeof(header), fp) == NULL) {
        printf("U>.<U <( Failed to read header from \"%s\". )\n", fname);
        fclose(fp);
        return -1;
    }

    while( (ret=fscanf(fp, "%[^,],%d,%d,%d,%d,%d"
                        , &holiList[i].name, &holiList[i].startMonth, &holiList[i].startDay
                        , &holiList[i].endMonth, &holiList[i].endDay, &holiList[i].validFlg)) != EOF)
    {
        i++;
    }
    strcpy(holiList[i].name,"0");
    fclose( fp );
    return 0;
}

int setDayOff(DayOff dyOfList[NUM])
{
    FILE *fp;
    char *fname = ".\\config\\dayOffList.csv";
    char header[100];
    int ret;
    int i = 0;

    fp = fopen(fname, "r" );
    if( fp == NULL )
    {
        printf("U>.<U <( file \"%s\" cannot open. )\n", fname );
        return -1;
    }
    // ignore header
    if (fgets(header, sizeof(header), fp) == NULL) {
        printf("U>.<U <( Failed to read header from \"%s\". )\n", fname);
        fclose(fp);
        return -1;
    }

    while( (ret=fscanf(fp, "%[^,],%d,%d,%d,%d,%d,%d,%d,%d"
                        , &dyOfList[i].name, &dyOfList[i].sunday, &dyOfList[i].monday
                        , &dyOfList[i].tuesday, &dyOfList[i].wednesday, &dyOfList[i].thursday
                        , &dyOfList[i].friday, &dyOfList[i].saturday, &dyOfList[i].validFlg)) != EOF)
    {
        i++;
    }
    strcpy(dyOfList[i].name,"0");
    fclose( fp );
    return 0;
}

int setNightTime(Night nitList[NUM])
{
    FILE *fp;
    char *fname = ".\\config\\nightTimeList.csv";
    char header[100];
    int ret;
    int i = 0;

    fp = fopen(fname, "r" );
    if( fp == NULL )
    {
        printf("U>.<U <( file \"%s\" cannot open. )\n", fname );
        return -1;
    }

    // ignore header
    if (fgets(header, sizeof(header), fp) == NULL) {
        printf("U>.<U <( Failed to read header from \"%s\". )\n", fname);
        fclose(fp);
        return -1;
    }

    while( (ret=fscanf(fp, "%[^,],%d,%d,%d,%d,%d"
                        , &nitList[i].name, &nitList[i].startHour, &nitList[i].startMinute
                        , &nitList[i].endHour, &nitList[i].endMinute, &nitList[i].validFlg)) != EOF)
    {
        i++;
    }
    strcpy(nitList[i].name,"0");
    fclose( fp );
    return 0;
}



DayTime calcDayTime(Night nitList[NUM])
{
    DayTime dayT;
    int cnt = 0;
    int i = 0;
    int startOfDay = 0;   // means minutes of 0:00
    int endOfDay = 1440;  // means minutes of 24:00(nextDay 0:00)

    

    // In initial state, evety time is non-night
    int currentStart = startOfDay;

    for (i = 0; strcmp(nitList[i].name, "0") != 0; i++)
    {
        if (nitList[i].validFlg == 0)
        {
            continue;  // skip enable input
        }

        int nightStart = toMinutes(nitList[i].startHour, nitList[i].startMinute);
        int nightEnd = toMinutes(nitList[i].endHour, nitList[i].endMinute);

        // set now non-night to start time of night
        if (currentStart < nightStart)
        {
            dayT.startHour = currentStart / 60;
            dayT.startMinute = currentStart % 60;
            dayT.endHour = nightStart / 60;
            dayT.endMinute = nightStart % 60;
        }

        // set end of night to next start time of non-night
        currentStart = nightEnd;
    }

    return dayT;
}

int setPayType(PayType pyTpList[NUM_OF_PAYTYPE + 1])
{
    FILE *fp;
    char *fname = ".\\config\\payType.csv";
    char header[100];
    int ret;
    int i = 0;

    fp = fopen(fname, "r" );
    if( fp == NULL )
    {
        printf("U>.<U <( file \"%s\" cannot open. )\n", fname );
        return -1;
    }

    // ignore header
    if (fgets(header, sizeof(header), fp) == NULL) {
        printf("U>.<U <( Failed to read header from \"%s\". )\n", fname);
        fclose(fp);
        return -1;
    }

    while( (ret=fscanf(fp, "%[^,],%d,%d,%d,%d"
                        , &pyTpList[i].name, &pyTpList[i].minUnit, &pyTpList[i].yenUnit, &pyTpList[i].maxYen)) != EOF)
    {
        i++;
    }
    strcpy(pyTpList[i].name,"0");
    fclose( fp );
    return 0;
}

void printList(Holiday holiList[NUM], DayOff dyOfList[NUM], Night nitList[NUM], DayTime dayT, PayType pyTpList[NUM_OF_PAYTYPE + 1])
{
    int i = 0;
    printf("Holiday is \n");
    printf("Name                Start  End  valid\n");
    printf("-------------------------------------\n");
    while (strcmp(holiList[i].name, "0") != 0)
    {
        if (i == 0)
        {
            printf("%-19s %02d/%02d %02d/%02d %3d"
                , holiList[i].name, holiList[i].startMonth, holiList[i].startDay
                , holiList[i].endMonth, holiList[i].endDay, holiList[i].validFlg);
        }
        else
        {
            printf("%-20s %02d/%02d %02d/%02d %3d"
                    , holiList[i].name, holiList[i].startMonth, holiList[i].startDay
                    , holiList[i].endMonth, holiList[i].endDay, holiList[i].validFlg);
        }
        i++;
    }
    printf("\n");
    printf("\n");

    i = 0;
    printf("DayOff is \n");
    printf("Name                 Sun Mon Tue Wed Thu Fri Sat valid\n");
    printf("------------------------------------------------------\n");
    while (strcmp(dyOfList[i].name, "0") != 0)
    {
        if (i == 0)
        {
            printf("%-19s %3d %3d %3d %3d %3d %3d %3d %4d"
                    , dyOfList[i].name, dyOfList[i].sunday, dyOfList[i].monday
                    , dyOfList[i].tuesday, dyOfList[i].wednesday, dyOfList[i].thursday
                    , dyOfList[i].friday, dyOfList[i].saturday, dyOfList[i].validFlg);
        }
        else
        {
            printf("%-20s %3d %3d %3d %3d %3d %3d %3d %4d"
                    , dyOfList[i].name, dyOfList[i].sunday, dyOfList[i].monday
                    , dyOfList[i].tuesday, dyOfList[i].wednesday, dyOfList[i].thursday
                    , dyOfList[i].friday, dyOfList[i].saturday, dyOfList[i].validFlg);
        }
        i++;
    }
    printf("\n");
    printf("\n");

    i = 0;
    printf("NightTime is \n");
    printf("Name                Start  End  valid\n");
    printf("-------------------------------------\n");
    while (strcmp(nitList[i].name, "0") != 0)
    {
        if (i == 0)
        {
            printf("%-19s %02d:%02d %02d:%02d %3d"
                , nitList[i].name, nitList[i].startHour, nitList[i].startMinute
                , nitList[i].endHour, nitList[i].endMinute, nitList[i].validFlg);
        }
        else
        {
            printf("%-20s %02d:%02d %02d:%02d %3d"
                    , nitList[i].name, nitList[i].startHour, nitList[i].startMinute
                    , nitList[i].endHour, nitList[i].endMinute, nitList[i].validFlg);
        }
        i++;
    }
    printf("\n");
    printf("\n");

    printf("DayTime is %02d:%02d - %02d:%02d"
            , dayT.startHour, dayT.startMinute
            , dayT.endHour, dayT.endMinute);
    printf("\n");
    printf("\n");

    i = 0;
    printf("PayType is \n");
    printf("Name                normal                max\n");
    printf("---------------------------------------------\n");
    while (strcmp(pyTpList[i].name, "0") != 0)
    {
        if (i == 0)
        {
            printf("%-19s %02d[yen]/%02d[min] %5d[yen]"
                , pyTpList[i].name, pyTpList[i].yenUnit, pyTpList[i].minUnit, pyTpList[i].maxYen);
        }
        else
        {
            printf("%-20s %02d[yen]/%02d[min] %5d[yen]"
                    , pyTpList[i].name, pyTpList[i].yenUnit, pyTpList[i].minUnit, pyTpList[i].maxYen);
        }
        i++;
    }
    printf("\n");
}