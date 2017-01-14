// James Ruska
// COSC 1436 GE #5 Fall 2013
// Filename: GE5Part2.cpp
#include<iostream>
#include<iomanip>
#include<math.h>
#include<ctime>  
#include<algorithm>
using namespace std;

double calculateMonthlyPayment(double loan_amount, double yearly_interest_rate, int years_until_due){
  if (   !(loan_amount >= 1 && loan_amount <= 1000000)
      || !(yearly_interest_rate >= 2.0 && yearly_interest_rate <= 20.0)
      || !(years_until_due >= 5 && years_until_due <= 30)) return -1;
  int number_of_payments = years_until_due * 12;
  yearly_interest_rate /= 1200;
  return (yearly_interest_rate + (yearly_interest_rate / (pow(1+yearly_interest_rate, number_of_payments)-1))) * loan_amount;
}

void displayCalendarDays(int start_day, int total_days){
  if (!(start_day >= 0 && start_day <= 6) || !(total_days >= 1 && total_days <= 31)){
    if (!(start_day >= 0 && start_day <= 6)) cout << "Error: First parameter to displayCalendarDays() must be between 0 and 6 inclusive!" << endl;
    if (!(total_days >= 1 && total_days <= 31)) cout << "Error: Second parameter to displayCalendarDays() must be between 1 and 31 inclusive!" << endl;
    return;
  }
  cout << "  S  M  T  W  T  F  S" << endl;
  for (int i=1; i<=total_days; i++)
    if (i<(start_day+1)) cout << "   ";
    else cout << setw(3) << i << ((i%7==0) ? "\r\n" : "");
  cout << endl;
}

int getStartDay(int month, int day, int year){
  tm time_in = { 0, 0, 0, day, month-1, year - 1900 };
  time_t time_temp = mktime(&time_in);
  return (localtime(&time_temp))->tm_wday;
}

void generateLotteryNumbers(int lotteryNumbers []){
  for(int counter=0; counter<5; counter++)
    do{ lotteryNumbers[counter] = rand() % 50 + 1; }
    while (counter!=0 && find(lotteryNumbers, &lotteryNumbers[counter], lotteryNumbers[counter]) < &lotteryNumbers[counter]);
}
