// James Ruska
// COSC 1436 GE #5 Fall 2013
// Filename: GE5Part1.cpp
#include<iostream>
#include<iomanip>
#include<math.h>
#include<ctime>  
#include<algorithm>
using namespace std;

void break_points(int &break_point1, int &break_point2){
  break_point1=rand() % 999 + 1;
  do { break_point2=rand() % 999 + 1; } while (break_point1 == break_point2);
  if (break_point1 > break_point2) swap(break_point1, break_point2);
}

void breakage_pieces(int break_point1, int break_point2, int &segment1, int &segment2, int &segment3){
  segment1=break_point1;
  segment2=break_point2-break_point1;
  segment3=1000 - break_point2;
}

bool is_triangle(int segment1, int segment2, int segment3){
  return (   (segment1 + segment2) > segment3 
          && (segment1 + segment3) > segment2 
          && (segment2 + segment3) > segment1);
}

int main(){
  srand(time(NULL));
  int break_point1, break_point2, segment1, segment2, segment3, triangles=0, counter;
  for (counter=0; counter<1000000; counter++){
    break_points(break_point1, break_point2);
    breakage_pieces(break_point1, break_point2, segment1, segment2, segment3);
    if (is_triangle(segment1, segment2, segment3)) triangles++;
  }
  cout << "After dropping " << counter << " rods, " <<  ((triangles * 1.0) / counter)*100 
       << "% of the drops resulted in three pieces that formed a triangle." << endl;
  return 0;
}

