/*
Title: hw1-1.cpp
Abstract: This program reads the records from a file and outputs the number of times each one is repeated
Author: Jasdeep Singh Dhillon
Email: jdhillon@csumb.edu
Estimtate: 1 hour
Date: 1/27/2020
*/

#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int duplicate_number(int records[], int size, int target);
int minimum(int values[], int size);
bool is_duplicate(int vals[], int size, int target);


int main() 
{
  string file;
  cout << "Enter input file name: ";
  cin >> file;
  cout << endl;

  ifstream repeat (file);

  if(repeat.fail())
  cout << "Error: Input file invalid" << endl;

  int size;
  repeat >> size;
  
  int records[size];

  for(int i=0; i<size; i++)
  repeat >> records[i];

  int min = minimum(records, size);
  cout << endl << "Min number: " << min << endl;

  int vals[size], vsize=1;
  vals[0] = records[0];

  for(int i=0; i<size; i++)
  {
    if(!(is_duplicate(vals,size,records[i])))
    {
      vals[vsize]=records[i];
      vsize++;
    }
  }

  int repetitions[vsize];

  for(int i=0; i<vsize; i++)
  {
    repetitions[i] = duplicate_number(records, size, vals[i]);
  }

  cout << endl << "Number     Count" << endl;

  for(int i=0; i<vsize; i++)
  {
    cout << vals[i];
    if(vals[i]>0 && vals[i]<10)
    cout << " "; 
    cout << "         " << repetitions[i] << endl;
  }

  return 0;
}

int duplicate_number(int records[], int size, int target)
{
  int count=0;
  for(int i=0; i<size; i++)
  {
    if(records[i] == target)
    count++;
  }

  return count;
}

int minimum(int values[], int size)
{
  int min = INT_MAX;
  for(int i=0; i<size; i++)
  {
    if(min > values[i])
    min = values[i];
  }
  return min;
}

bool is_duplicate(int vals[], int size, int target)
{
  for(int i=0; i<size; i++)
  {
    if(target == vals[i])
    return true;
  }
  return false;
}