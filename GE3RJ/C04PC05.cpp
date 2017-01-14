// James Ruska
// COSC 1436 GE #3 Fall 2013
// Filename: C04PC05.cpp
// This program insults you

#include<iomanip>
#include<math.h>
#include<iostream>
using namespace std;

int main()
{
  double weight, height, bmi;

  cout << "Enter your weight:" << endl;
  cin >> weight;
  
  cout << "Enter your height in inches:" << endl;
  cin >> height;

  bmi =  (weight / pow(height,2)) * 703;
  
  if(bmi > 25)
    {
      cout << "You are too fat!"; 
    }
  else if (bmi < 18.5)
    {
      cout << "You are too thin!";
    }
  else cout << "You are within normal weight... for now!";

  return 0;
}

