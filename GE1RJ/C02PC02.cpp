// James Ruska
// COSC 1436 GE #1 Fall 2013
// Filename: C02PC02.cpp
// This program calculates the sales prediction

#include<iostream>
using namespace std;

int main()
{
  double salesThisYear; // = 4600000;
  double salesPercent; //  = 0.62;
  double salesDivisionTotalSales;

  cout << "Enter total sales this year:" << endl << "$";
  cin >> salesThisYear;

  cout << "Enter salesPercent:" << endl << "%";
  cin >> salesPercent;
  salesPercent /= 100;

  salesDivisionTotalSales = salesThisYear * salesPercent;
  
  cout << fixed << (salesPercent*100) << "% of $" << salesThisYear 
       << " in sales is $" << salesDivisionTotalSales << endl;
  
  return 0;
}

