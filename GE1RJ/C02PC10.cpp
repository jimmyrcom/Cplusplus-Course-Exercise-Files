// James Ruska
// COSC 1436 GE #1 Fall 2013
// Filename:  C02PC10.cpp
// This programs takes in miles driven until refueling needed and
// gallons in car, it then prints the miles per gallon

#include<iostream>
using namespace std;

int main()
{
  //double milesBeforeRefueling = 350;
  //double maxGallonsOfGas = 12;
  double milesBeforeRefueling, maxGallonsOfGas;

  cout << "Enter miles before refueling: " << endl;
  cin >> milesBeforeRefueling;

  cout << "Enter max Gallons of Gas: " << endl;
  cin >> maxGallonsOfGas;

  double milesPerGallon = milesBeforeRefueling / maxGallonsOfGas;

  cout << "Miles Per Gallon: " << milesPerGallon << endl;

  return 0;
}
