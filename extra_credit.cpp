// JAMES RUSKA
// TUE THURSDAY 5pm COURSE C++ 1
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  int loan_amount = 0;
  double yearly_interest_rate, monthly_payment_on_loan = 0.0;
  int term_of_loan_in_years = 0;
  double number_of_payments = 0;
  
  cout << "Enter the loan amount:\n$";
  cin >> loan_amount;
  cout << endl;
  
  cout << "Enter the yearly interest rate:\n";
  cin >> yearly_interest_rate;
  cout << endl;
  
  cout << "Enter the term of the loan in years:\n";
  cin >> term_of_loan_in_years;
  number_of_payments = term_of_loan_in_years*12;
  cout << endl;
  
  monthly_payment_on_loan = (yearly_interest_rate* pow(1+yearly_interest_rate, number_of_payments)
  	                         /                           
						    (pow(1+ yearly_interest_rate,number_of_payments) - 1))
						    * loan_amount;

 cout << "The monthly payment is " << monthly_payment_on_loan << endl;

  return 0;
}
