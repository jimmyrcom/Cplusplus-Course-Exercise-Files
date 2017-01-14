// James Ruska
// COSC 1436 GE #3 Fall 2013
// Filename: C04PC21.cpp
// This program displays a menu and performs some function based on the selection

#include<iomanip>
#include<math.h>
#include<iostream>
#include<ctime>  
#include<cstdlib>

using namespace std;

double get_valid_number(string prompt){
  double number;
  cout << prompt << ": ";
  cin >> number;
  if (number < 0)
    {
      cout << "Invalid Number: " << number;
      exit(EXIT_FAILURE);
    }
  return number;
}

void circle()
{
  double radius;
  const double PI = 3.14159;
  radius = get_valid_number("Enter the radius of the circle");
  cout << "The area is: " << (PI*radius*radius) << endl;
}

void rect()
{
  double length, width;
  length = get_valid_number("Enter the length of the rectangle");
  width = get_valid_number("Enter the width of the rectangle");
  cout << "The area is: " << (length*width) << endl;
}

void triangle()
{
  double base, height;
  base = get_valid_number("Enter the base of the rectangle");
  height = get_valid_number("Enter the height of the rectangle");
  cout << "The area is: " << (base*height*0.5) << endl;
}	

int main()
{

  double wavelength = 0;
  char choice;

  cout << "Geometry calculator \n"
       << "1. Calculate the Area of a Circle\n"
       << "2. Calculate the Area of a Rectangle\n"
       << "3. Calculate the Area of a Triangle\n"
       << "4. Quit\n"
       << "Enter your choice (1-4):";
  cin >> choice;
  
  if (choice == '1') circle();
  else if (choice == '2') rect();
  else if (choice == '3') triangle();
  else if (choice == '4') return 0;
  else cout << "Menu choice out of range!" << endl;

  return 0;
}

