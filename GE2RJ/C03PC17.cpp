// James Ruska
// COSC 1436 GE #1 Fall 2013
// Filename: C03PC17.cpp
// This program calculates monthly payments on a loan

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
 double loanAmount, monthlyInterestRate, yearlyInterestRate, loanTermInYears;
 double monthlyPayment, totalCostOfLoan, totalInterestPaid;
 double commonTerm, numerator, denominator;
  
 cout << "Enter loan amount (Example:265000)" << endl;
 cin >> loanAmount; 
 
 cout << "Enter monthly interest rate (Example:5.125)" << endl;
 cin >> monthlyInterestRate;
 yearlyInterestRate = monthlyInterestRate * 12;
 
 cout << "Enter term of loan in years (Example:15)" << endl;
 cin >> loanTermInYears;
 
 commonTerm = pow(1+yearlyInterestRate/1200, loanTermInYears*12);
 numerator = yearlyInterestRate/1200 * commonTerm;
 denominator = commonTerm -1;
 monthlyPayment = numerator / denominator * loanAmount;
 
 totalCostOfLoan = monthlyPayment * loanTermInYears * 12;
 totalInterestPaid = totalCostOfLoan - loanAmount;
 
 cout << fixed << showpoint << setprecision(2)
 
      << "Loan Amount: " << loanAmount << endl
      << "Monthly Interest Rate: " << yearlyInterestRate / 12 << endl
      << "Number of Payments: " << loanTermInYears * 12 << endl
      
      << "Monthly payment: " << monthlyPayment << endl
      << "Amount Paid Back: " << totalCostOfLoan << endl
      << "Interest Paid: " << totalInterestPaid << endl;

 return 0;
}
