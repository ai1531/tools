/*
  2024/10/07
  @Arisa Ito

  CalenderApp
*/

#include<iostream>
// #include".\CalenderApp.h"
#include".\CalenderApp.h"

CalenderManager::Dates CalenderManager::createStruct(int Analised_year, int Analised_month, int Analised_num, int* Last_day, int* First_weekday, bool Check_leap)
{
   CalenderManager::Dates s;
   s.Analised_year = Analised_year;
   s.Analised_month = Analised_month;
   s.Analised_num = Analised_num;
   s.Last_day = Last_day;
   s.First_weekday = First_weekday;
   s.Check_leap = Check_leap;
   return s;
};

int main(void)
{
   std::string cmd;
   int year, mon, num;

   CalenderManager CM;
   bool StartClassFlg = false;

   if (cmd == "MyCal") {
      StartClassFlg = true; 
   }

   BoundaryControl BC;

   BC.Analyse_input(year, mon, num, StartClassFlg);
   std::cout << "flg:" << StartClassFlg << std::endl;
   BC.set(CM);

   std::cout << "Year : " << CM.KoyomiDates.Analised_year << std::endl;
   std::cout << "Month : " << CM.KoyomiDates.Analised_month << std::endl;
   std::cout << "Num : " << CM.KoyomiDates.Analised_num << std::endl;

   return 0; 

};