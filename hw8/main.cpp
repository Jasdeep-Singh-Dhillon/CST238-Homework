/*
Title: hw08-1.cpp
Abstract: This program will sort numbers and print them in folded order.
Author: Jasdeep Singh Dhillon
Email: jdhillon@csumb.edu
Estimtate: 12 hours
Date: 4/21/2020
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// reads a file and returns an array of integers; first number is # of elements in file
int * readInts(string filename, int & size);
// uses insertion sort to sort number in ascending order
void sort(int * a, int size);
// prints a sorted array in folded format
void printFolded(int * a, int size);
//swap function
void swap(int &a, int&b);

int main() 
{
  string fileName;
  cout << "Enter the file name: ";
  cin >> fileName;
  int size = 0;
  int* vals = readInts(fileName, size);
  sort(vals, size);
  printFolded(vals, size);
}

int * readInts(string filename, int & size)
{
  fstream input (filename);
  input >> size;
  int * numbers = new int[size];

  for(int i=0; i<size; i++)
  {
    input >> numbers[i];
  }

  return numbers;
}

void swap(int &a, int&b)
{
  int temp = a;
  a = b;
  b = temp;
}

void sort(int * a, int size)
{
  int index, value;
  
  for(int i = 1; i < size; i++)
  {
    index = i;
    value = a[i];
    while(value < a[index-1] && index > 0)
    {
      swap(a[index], a[index-1]);
      index--;
    }
  }
}

void printFolded(int * a, int size)
{
  for(int i=0; i<size; i++)
  {
    if(a[i+1] == a[i]+1 )
    {
      if(a[i-1] != a[i]-1 || i==0)
      cout << a[i] << "-";
    }
    else
    { 
      cout << a[i] << " "; 
    }
  }
}