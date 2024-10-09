/*
  2024/10/07
  @Arisa Ito

  CalenderApp
*/

#include<iostream>
#include".\CalenderApp.h"

void BoundaryControl::Analyse_input(int year, int month, int num, bool StartClassFlg)
{
   if (StartClassFlg == true) {
      BC_year = year;
      BC_month = month;
      BC_num = num;
   }
}

void BoundaryControl::set(CalenderManager &CM)
{
   CM.KoyomiDates = CM.createStruct(BC_year, BC_month, BC_num, nullptr, nullptr, false);
}

std::tuple<int, int, int> BoundaryControl::get()
{
   return {BC_year, BC_month, BC_num};
}