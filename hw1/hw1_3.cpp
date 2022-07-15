/*
Title: hw1-3.cpp
Abstract: This program creates a vertical histogram from the text file
Author: Jasdeep Singh Dhillon
Email: jdhillon@csumb.edu
Estimtate: 3 hours
Date: 1/27/2020
*/

#include <iostream>
#include <climits>
#include <fstream>
using namespace std;

int maximum(int vals[], int size);

const int size=7;

int main()
{
  string file;
  cout << "Enter file name: ";
  cin >> file;

  ifstream histogram(file);
  if(histogram.fail())
  cout << "Error: Can't open the requested file" << endl;
  
  int vals[size];

  for(int i=0; i<size; i++)
  {
    histogram >> vals[i];
  }
  
  cout << endl << "==== Vertical Histogram ====" << endl;

  int max=maximum(vals,size);

  int vsize;
  if(max>size)
  vsize = max;
  else
  vsize = size; 

  for(int i=vsize-1; i>=0; i--)
  {
    for(int j=0; j<vsize; j++)
    {
      if(i<vals[j])
      cout << "* ";
      else
      cout << "  ";
    }
    cout << endl;
  }

  for(int i=0; i<vsize; i++)
  cout << "--";

  cout << endl ;
  for(int i=0; i<vsize; i++)
  {
    cout << vals[i] << " ";
  }

  histogram.close();
  return 0;
}

int maximum(int vals[], int size)
{
  int max=INT_MIN;
  for(int i=0; i<size; i++)
  {
    if(max < vals[i])
    max = vals[i];
  }
  return max;
}