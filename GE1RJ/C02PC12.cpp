// James Ruska
// COSC 1436 GE #1 Fall 2013
// Filename:  C02PC12.cpp
// This program takes squarefeet as input and prints how many acres that is

#include<iostream>
using namespace std;

int main()
{
  const int squareFeetPerAcre = 43560; 
  double acres, howManySquareFeet;

  cout << "Enter how many square feet:" << endl;
  cin >> howManySquareFeet;

  acres = howManySquareFeet / squareFeetPerAcre;
  cout << howManySquareFeet << " sqrft is " << acres << " acres " << endl;

  return 0;
}
