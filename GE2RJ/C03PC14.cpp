// James Ruska
// COSC 1436 GE #1 Fall 2013
// Filename: C03PC14.cpp
// This program calculates the annual property tax a senior will be charged
// and what the quarterly tax bill will be

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main()
{
 const double VALUE_OF_PROPERTY_RATIO = 0.60;
 const int SENIOR_DISCOUNT = 5000;
 double taxRatePerHundredDollars, valueOfProperty;
 double taxDue, assessedValue;
  
 cout << "Enter the value of the property: " << endl;
 cin >> valueOfProperty;
 assessedValue = VALUE_OF_PROPERTY_RATIO * valueOfProperty - SENIOR_DISCOUNT;
 
 cout << "Enter tax rate per $100: " << endl;
 cin >> taxRatePerHundredDollars;
 taxDue = taxRatePerHundredDollars  * (assessedValue / 100);

 cout << fixed << showpoint << setprecision(2)
      << "Assessed value of the property: "  << assessedValue << endl
      << "Total Tax Due: "  << taxDue << endl
      << "Quartarly Payment: "  << taxDue / 4 << endl
      << endl;
      
 return 0;
}
