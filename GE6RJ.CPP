// James Ruska
// GE6
#include<iostream>
#include<iomanip>
#include<math.h>
#include<ctime>  
#include<algorithm>
using namespace std;

void toUpper (char string []){
  for (int i=0, x; (x=string[i])!='\0'; i++) if (x>'a'-1 && x<'z'+1) string[i]-=32;
}

void getCharacterFrequency (char inputString [], unsigned int frequency[]){
  for (int i=0; i<26; i++) frequency[i] = 0;
  toUpper(inputString);
  for (int i=0; inputString[i]!='\0';i++) frequency[inputString[i]-'A']++;
}

void generateLotteryNumbers(int lotteryNumbers []){
  for(int counter=0; counter<5; counter++)
    do{ lotteryNumbers[counter] = rand() % 50 + 1; }
    while (counter!=0 && find(lotteryNumbers, &lotteryNumbers[counter], lotteryNumbers[counter]) < &lotteryNumbers[counter]);
}

void analyzeString (char inputString [], int & numVowels, int & numConsonants, int & numSeparators){
  char consonants[] = "bcdfghjklmnpqrstvwxyz";
  for (int i=0, x; (x=inputString[i])!='\0'; i++){
    if (x>=65 && x<=90) x+=32;
    if (x==' ' || x=='\t' || x=='\n') numSeparators++;
    else if (x=='a' || x=='e' || x=='i' || x=='o' || x=='u') numVowels++;
    else for (int j=0; consonants[j]!='\0'; j++) if(consonants[j]==x){ numConsonants++; continue; };
  }
}

void displayCalendarDays(int start_day, int total_days){
  if (!(start_day >= 0 && start_day <= 6) || !(total_days >= 1 && total_days <= 31)){
    if (!(start_day >= 0 && start_day <= 6)) cout << "Error: First parameter to displayCalendarDays() must be between 0 and 6 inclusive!" << endl;
    if (!(total_days >= 1 && total_days <= 31)) cout << "Error: Second parameter to displayCalendarDays() must be between 1 and 31 inclusive!" << endl;
    return;
  }
  cout << "  S  M  T  W  T  F  S" << endl;
  for (int i=1; i<=(total_days+start_day); i++)
    if (i<(start_day+1)) cout << "   ";
    else cout << setw(3) << (i-start_day) << ((i%7==0) ? "\n" : "");
  cout << endl << endl;
}

double calculateMonthlyPayment(double loan_amount, double yearly_interest_rate, int years_until_due){
  if (   !(loan_amount >= 1 && loan_amount <= 1000000)
      || !(yearly_interest_rate >= 2.0 && yearly_interest_rate <= 20.0)
      || !(years_until_due >= 5 && years_until_due <= 30)) return -1;
  int number_of_payments = years_until_due * 12;
  yearly_interest_rate /= 1200;
  return (yearly_interest_rate + (yearly_interest_rate / (pow(1+yearly_interest_rate, number_of_payments)-1))) * loan_amount;
}


// int main(){
//   char test[] = "abcdefghijklmn opqrstUVWXYZ";
//   unsigned int frequency[26];
//   displayCalendarDays(3,31);
//   int numVowels=0, numConsonants=0, numSeparators=0;
//   analyzeString (test, numVowels, numConsonants, numSeparators);
//   getCharacterFrequency (test, frequency);
//   for (int i=0; i<26;i++) cout << frequency[i] << ", ";
//   cout << endl << numConsonants << endl;
//   char foo[] = "mooswags";
//   toUpper(foo);
//   cout << foo << endl;
//   int lotto[5];
//   generateLotteryNumbers(lotto);
//   for (int i=0; i<5;i++) cout << lotto[i] << ", ";
//   return 0;
// }




