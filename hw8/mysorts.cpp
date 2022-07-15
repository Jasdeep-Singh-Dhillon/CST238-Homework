/*
Title: mySorts.cpp
Abstract: This program contains different sorting algorithms to sort int arrays.
Author: Jasdeep Singh Dhillon
Email: jdhillon@csumb.edu
Estimtate: 12 hours
Date: 4/21/2020
*/

#include <time.h>
#include <iostream>
#include "mysorts.h"
using namespace std;

bool isSorted(int * values, int size) 
{
  for(int i=0; i<size-1; i++)
  {
    if(values[i] > values[i+1])
    return false;
  }
  return true;
}

int * copyArray(int * values, int size) 
{
  int* source = new int [size];
  
  for(int i=0; i<size; i++)
  source[i] = values[i];

  return source;
}

void bubble_sort (int * values, int size) 
{
  int comps = 0;
  int swaps = 0;
  clock_t startClock;
  clock_t elapsedTime;
  
  cout << "Start the bubble sorting..." << endl;

  startClock = clock();

  for(int i=0; i<size-1; i++)
  {
    for(int j=0; j<size-i-1; j++)
    {
      if(values[j]>values[j+1])
      {
        swaps++;
        swap(values, j, j+1);
      }
      comps++;
    }
  }

  elapsedTime = clock() - startClock;
  cout << "Bubble sort completed. Is sorted: " << boolalpha <<
      isSorted(values, size) << endl;
  cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) 
      << " seconds" << endl;
  cout << "Swaps: " << swaps << endl;
  cout << "Comps: " << comps << endl << endl;
}
void insertion_sort (int * values, int size) 
{
  int comps = 0;
  int swaps = 0;
  clock_t startClock;
  clock_t elapsedTime;
  
  cout << "Start the insertion sorting..." << endl;

  startClock = clock();
  // sorting code goes here
  int index, value;
  
  for(int i = 1; i < size; i++)
  {
    for(int j=i; j>0; j--) 
    {
      comps++;
      if(values[j] < values[j-1])
      {
        swap(values, j, j-1);
        swaps++;
      }
      else
      {
        break;
      }
    }
  }
  elapsedTime = clock() - startClock;
  cout << "Insertion sort completed. Is sorted: " << boolalpha <<
      isSorted(values, size) << endl;
  cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) 
      << " seconds" << endl;
  cout << "Swaps: " << swaps << endl;
  cout << "Comps: " << comps << endl << endl;
}
void selection_sort (int * values, int size) 
{
  int comps = 0;
  int swaps = 0;
  clock_t startClock;
  clock_t elapsedTime;
  
  cout << "Start the selection sorting..." << endl;

  startClock = clock();

  for(int i=0; i<size; i++)
  {
    int index = i, min = values[i];
    for(int j=i+1; j<size; j++)
    {
      if(min > values[j])
      {
        min = values[j];
        index = j;
      }
      comps++;
    }

    if(index != i)
    {
      swap(values, index, i);
      swaps++;
    }
  }  
  elapsedTime = clock() - startClock;
  cout << "Selection sort completed. Is sorted: " << boolalpha <<
      isSorted(values, size) << endl;
  cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) 
      << " seconds" << endl;
  cout << "Swaps: " << swaps << endl;
  cout << "Comps: " << comps << endl << endl;
}

void swap(int * values, int i1, int i2)
{
  int temp = values[i1];
  values[i1] = values[i2];
  values[i2] = temp;
}

// void fast_insertion_sort (int * values, int size)
// { 
//   int comps = 0;
//   int swaps = 0;
//   clock_t startClock;
//   clock_t elapsedTime;
//   cout << "Start the Fast insertion sorting..." << endl;
//   startClock = clock();

//   int val;
//   int index;

//   for(int i = 1; i < size; i++) 
//   {
//     val = values[i];
//     index = i;

//     while (index > 0 && values[index-1] > val) 
//     {
//       values[index] = values[index-1];
//       index--;
//     }
//     if(index != i) 
//     {
//       values[index] = val;
//     }
//   }

//   for(int i=0; i<size; i++)
//   cout << values[i] << " ";
//   cout << endl;
//   elapsedTime = clock() - startClock;
//   cout << "Fast Insertion sort completed. Is sorted: " << boolalpha <<
//       isSorted(values, size) << endl;
//   cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) 
//       << " seconds" << endl;
//   cout << "Swaps: " << swaps << endl;
//   cout << "Comps: " << comps << endl << endl;
// }