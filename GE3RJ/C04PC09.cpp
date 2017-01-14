// James Ruska
// COSC 1436 GE #3 Fall 2013
// Filename: C04PC09.cpp
// This is an arithmetic trainer program


#include<iomanip>
#include<math.h>
#include<iostream>
#include<ctime>  
#include<cstdlib>

using namespace std;
 	
int random_number(int rand_min, int rand_max)
{
  return rand_min + (int)((double)rand() / (RAND_MAX+1) * (rand_max-rand_min+1));
}

int main()
{
  int seed = time(NULL);
  srand (seed);
  int rand_max, rand_min, answer, number1, number2, correct = 0, wrong = 0;
  string my_answer;
  char operation;
 
  while (true) // configuration loop
    {
      string mult_table_prompt = "n";
      int mult_table = 0;
      char difficulty;
      cout << "Enter the difficulty setting:\n"
           << "1. Easy (1-99)\n"
           << "2. Medium (10-999)\n"
           << "3. Hard (100-9999)\n"
           << "4. Custom\n"
           << "Enter a number (1-4):";
      cin >> difficulty;

      if (difficulty == '1')
        {
          rand_min = 1;
          rand_max = 99;
        }
      else if (difficulty == '2')
        {
          rand_min = 10;
          rand_max = 999;
        }
      else if (difficulty == '3')
        {
          rand_min = 100;
          rand_max = 9999;
        }
      else {
        cout << "Enter the minimum number: ";
        cin >> rand_min; 
        cout << "Enter the max number: ";
        cin >> rand_max;
        if (rand_min > rand_max) swap(rand_min, rand_max);
      }

      cout << "Enter operation. Allowed: +, -, *: ";
      cin >> operation;
    
      if (operation == '*')
        {
          cout << "\nYou chose multiplication. Would you \nlike to do multiplications table mode? \n"
               << "If so enter a number that will always \nbe the first, otherwise type n: ";
          cin >> mult_table_prompt;
          if (mult_table_prompt != "n") mult_table = atoi(mult_table_prompt.c_str());
        }
 

      if (operation !='+' && operation !='-' && operation !='*') return 1;
 
      while(true) // quiz loop
        {
          if (mult_table_prompt == "n") number1 = random_number(rand_min, rand_max);
          else number1 = mult_table;
          number2 = random_number(rand_min, rand_max);

          if (operation == '+') answer = number1 + number2;
          else if (operation == '-') answer = number1 - number2;
          else if (operation == '*') answer = number1 * number2;

          cout << "\nWhat is " << number1 << " " << operation << " " << number2 << "? Type q to quit, c to configure, r to reset score." << endl;
          cin >> my_answer;

          if (my_answer == "q") return 0;
          else if (my_answer == "c") break;
          else if (my_answer == "r") wrong = correct = 0;
          else if (atoi(my_answer.c_str()) == answer)
            {
              cout << "Correct! -- ";
              correct++;
            }
          else
            {
              cout << "Incorrect, the answer was " << answer << " -- ";
              wrong++;
            }
          cout << "Correct: " << correct << " | Wrong: " << wrong << " | Total: " << correct+wrong << endl;
        }
    }
  return 0;
}
