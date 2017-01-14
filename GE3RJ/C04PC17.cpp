// James Ruska
// COSC 1436 GE #3 Fall 2013
// Filename: C04PC17.cpp
// This program prompts for a wavelength and displays its name

#include<iomanip>
#include<math.h>
#include<iostream>
#include<ctime>  
#include<cstdlib>

using namespace std;
 	

int main()
{

  double wavelength = 0;

  cout << "Enter the wavelength: ";
  cin >> wavelength;
  cout << endl;
      
  if (wavelength < 1e-11) cout << "Gamma Rays";
  else if (wavelength < 1e-8) cout << "X Rays";
  else if (wavelength < 4e-7) cout << "Ultraviolet";
  else if (wavelength < 7e-10) cout << "Visible Light";
  else if (wavelength < 1e-3) cout << "Infrared";
  else if (wavelength < 1e-2) cout << "Microwaves";
  else cout << "Radio Waves";
  cout << endl;
  
  return 0;
}
