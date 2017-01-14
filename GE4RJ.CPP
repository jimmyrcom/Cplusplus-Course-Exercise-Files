// James Ruska
// GE4
#include<iostream>
#include<iomanip>
#include<math.h>
#include<iostream>
#include<ctime>  
#include<cstdlib>
#include<string>

using namespace std;

bool isLeapYear(int year) 
{
  if (year % 4 != 0) return false;
  if (year % 400 == 0) return true;
  if (year % 100 == 0) return false;
  return true;
}

bool isValidDate(int month, int day, int year)
{
  int end_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (isLeapYear(year)) end_days[1] = 29;
  if (!(month>=1 && month<=12)) return false;
  if (!(day>=1 && day<=end_days[month-1])) return false;
  if (!(year>=1601 && year<=2099)) return false; 
  return true;
}

int getJulianDayNumber(int month, int day, int year)
{
  if (!isValidDate(month,day,year)) return -1;
  year+=8000;
  if (month<3) { year--; month+=12; }
  return (year*365) +(year/4) -(year/100) +(year/400) -1200820+(month*153+3)/5-92+day-1;
}

int generateRandomNumber(int rand_min, int rand_max)
{
  if (!(rand_min>=0 && (rand_min<rand_max) && (rand_max-rand_min+1)<=25000)) return -1;
  return rand_min + (int)((double)rand() / (RAND_MAX+1) * (rand_max-rand_min+1));
}
