
// James Ruska
// COSC 1436 GE #3 Fall 2013
// Filename: C04PC07.cpp
// This program breaks down how many hours, days, minutes, seconds are in X many seconds

y
#include<iomanip>
#include<math.h>
#include<iostream>
using namespace std;

int main()
{
  vector<string> v = {"Hello", "World"};
   std::ostringstream ss;
   std::copy(v.begin(), v.end() - 1, std::ostream_iterator<int>(ss, ", "));
   ss << v.back();
   std::cout << ss.str() << "\n";
  
  return 0
}
