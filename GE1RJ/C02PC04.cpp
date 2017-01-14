// James Ruska
// COSC 1436 GE #1 Fall 2013
// Filename: C02PC04.cpp
// This program calculates total cost of restaurant meal

#include<iostream>
using namespace std;

int main()
{
  double taxAmount, tipAmount, total, mealCost, taxRate, tipPercent;

  cout << "Enter meal cost: " << endl;
  cin >> mealCost;

  cout << "Enter tax rate: " << endl;
  cin >> taxRate;

  cout << "Enter tip rate: " << endl;
  cin >> tipPercent;

  taxAmount = (taxRate * mealCost) / 100;
  tipAmount = (tipPercent * mealCost) / 100;

  total = tipAmount+mealCost+taxAmount;

  cout << "Total Cost: $" << total << endl;

  return 0;
}

