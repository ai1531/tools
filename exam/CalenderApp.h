/*
  2024/10/07
  @Arisa Ito

  CalenderApp
*/

#include<iostream>

class CalenderManager
   {
      public:
         CalenderManager(){};
      public:
         struct Dates
         {
            int Analised_year;
            int Analised_month;
            int Analised_num;
            int* Last_day;
            int* First_weekday;
            bool Check_leap;
         }KoyomiDates;
         Dates createStruct(int Analised_year, int Analised_month, int Analised_num, int* Last_day, int* First_weekday, bool Check_leap);
      private:
         int CM_year;
         int CM_month;
         int CM_num;
         int* CM_Last_day;
         int* CM_First_weekday;
         bool CM_Check_leap;
      public:
         ~CalenderManager(){};
   };

class BoundaryControl
   {
      public:
         BoundaryControl(){};
         void Analyse_input(int year, int month, int num, bool StartClassFlg);
      private:
         int BC_year;
         int BC_month;
         int BC_num;
         int errorCode;
         int kariNum;
      public:
         void set(CalenderManager &CM);
         std::tuple<int, int, int> get();
         ~BoundaryControl(){};
   };

