// James Ruska
// COSC 1436 GE #1 Fall 2013
// Filename: C03PC10.cpp
// This program converts Celcius to Fahrenheit F=9/5 C + 32

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
 double temperatureInCelcius;
  
 cout << "Enter the temperature in Celcius: " << endl;
 cin >> temperatureInCelcius; 

 cout << fixed << showpoint << setprecision(2)
      << "The temperature in degrees is Fahrenheit is: "
      << ((9.0/5) * temperatureInCelcius) + 32
      << endl;
      
 return 0;
}
