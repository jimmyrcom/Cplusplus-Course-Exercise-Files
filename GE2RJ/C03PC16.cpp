// James Ruska
// COSC 1436 GE #1 Fall 2013
// Filename: C03PC16.cpp
// This program calculates  balance in a savings account after one year Amount= Principal * (1+(Rate/T))^T

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main()
{

 double principal, timesCompounded, interestRate, amountInSavings;
  
 cout << "What is the principal: " << endl;
 cin >> principal;
 
 cout << "How many times is the interest compounded: " << endl;
 cin >> timesCompounded;
 
 cout << "What is the interest rate (eg 4.25): " << endl;
 cin >> interestRate;
 
 amountInSavings = principal * pow(1 + (interestRate / 100) / timesCompounded, timesCompounded); 

 cout << fixed << showpoint << setprecision(2)
      << "Interest: $"  << amountInSavings - principal << endl
      << "Amount in Savings: "  << amountInSavings << endl
      << endl;
      
 return 0;
}
