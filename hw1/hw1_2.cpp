/*
Title: hw1-2.cpp
Abstract: This program creates a horitzontal histogram from the text file
Author: Jasdeep Singh Dhillon
Email: jdhillon@csumb.edu
Estimtate: 1 hour
Date: 1/27/2020
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string file;
  cout << "Enter input file name: ";
  cin >> file;
  
  ifstream histogram(file);
  if(histogram.fail())
  cout << "Error: Can't open the file";

  cout << "====Horizontal Histogram====" << endl;
  
  for(int i=0; i<5; i++)
  {
  int size;
  histogram >> size;
  
  cout << size << ": ";
  for(int i=0; i<size; i++)
  {
    cout << "*";
  }
  cout << endl;
  }

  histogram.close();
  


  return 0;
}