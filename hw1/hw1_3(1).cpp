/*
* Title: hw1_3.cpp
* Abstract: This program makes vertical histogram 
* Author: Shyam Patel
* Email: shypatel@csumb.edu
* Estimate: 4 hours
* Date: 09/04/2020
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string f_name;
  // cout << "Enter input file name: ";
  // cin >> f_name;
  ifstream f_input("t5");

  int size = 7;
  int value[7];
  for(int i=0; i<size; i++)
  {
    f_input >> value[i];
  }

  cout << "===== Vertical Histogram =====" << endl;
  
  for(int i = size-1; i>=0 ;i--)
  {
    for(int j = 0; j < size; j++) 
    {
      if(value[j] > i)
      {
        cout << "* ";
      }
      else
      {
        cout << "  ";
      }
    }
    cout << endl;
  }
  for(int i=0; i<size; i++)
  cout << "--";
  cout << endl;
  for(int i=0; i<size; i++)
  cout << value[i] << " ";
  cout << endl;
    return 0;
}


