
// James Ruska
// COSC 1436 GE #3 Fall 2013
// Filename: C04PC07.cpp
// This program breaks down how many hours, days, minutes, seconds are in X many seconds


#include<iomanip>
#include<math.h>
#include<iostream>
using namespace std;

int main()
{
  int seconds, days = 0, hours = 0, minutes = 0, years = 0;
  const int SECONDS_IN_A_MINUTE = 60,
    SECONDS_IN_AN_HOUR  = SECONDS_IN_A_MINUTE * 60,
    SECONDS_IN_A_DAY    = SECONDS_IN_AN_HOUR * 24,
    SECONDS_IN_A_YEAR   = SECONDS_IN_A_DAY * 365;

  cout << "Enter the amount of seconds:" << endl;
  cin >> seconds;
  if (seconds >= SECONDS_IN_A_YEAR)
    {
      years = seconds / SECONDS_IN_A_YEAR;
      seconds = seconds % SECONDS_IN_A_YEAR;
      cout << "Years: " << years << endl;
    }
  if (seconds >= SECONDS_IN_A_DAY)
    {
      days = seconds / SECONDS_IN_A_DAY;
      seconds = seconds % SECONDS_IN_A_DAY;
      cout << "Days: " << days << endl;
    }
  if (seconds >= SECONDS_IN_AN_HOUR)
    {
      hours = seconds / SECONDS_IN_AN_HOUR;
      seconds = seconds % SECONDS_IN_AN_HOUR;
      cout << "Hours: " << hours << endl;
    }
  if (seconds >= SECONDS_IN_A_MINUTE)
    {
      minutes = seconds / SECONDS_IN_A_MINUTE;
      seconds = seconds % SECONDS_IN_A_MINUTE;
      cout << "Minutes: " << minutes << endl;
    }
  if (seconds) cout << "Seconds: " << seconds << endl;
  
  return 0;
}
