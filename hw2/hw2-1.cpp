/*
Title: hw2-1.cpp
Abstract: The program can perform one of three tasks depending on the user input. The three tasks that can be performed are deleting the max element from the array, append a number in the array and reverse the array
Author: Jasdeep Singh Dhillon
Email: jdhillon@csumb.edu
Estimate: 2 hours
Date: 1/29/2020
*/

#include <iostream>
#include <climits>
using namespace std;

int i_max(int records[], int size);
void d_max(int records[], int& size);
void append(int records[], int& size);
void print(int records[], int size);
void reverse(int records[], int size);
void swap (int& a, int& b);

int main()
{
  int arr[10] = {10, 20, 30, 40, 50, 15, 25, 35, 45, 55}, choice=0, size=10;
  int asize = size;
  char ch = 'Y';

  cout << "Array Values: ";
  for(int i=0; i<size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << "This is a list of operations\n\t1. Delete the max\n\t2. Append a number\n\t3. Reverse Array" << endl;
  
  do
  {
    cout << endl << "Enter your option: ";
    cin >> choice;

    if(choice==1)
    {
      if(asize>0)
      {
        d_max(arr, asize);
        cout << "New ";
      }
      else
      cout << "Can't delete more elements" << endl;
      print(arr, size);
    }

    else if(choice==2)
    {
      if(asize<size)
      {
        append(arr, asize);
        cout << "New ";
      }
      else
      {
        cout << "Array is full can't append anymore." << endl;
      }
      print(arr, size);
    }

    else if(choice==3)
    {
      reverse(arr, asize);
      print(arr, size);
    }
    else
    {
      cout << "Error. Enter a valid command." << endl;
      continue;
    }

    cout << "Continue? (Y/N): ";
    cin >> ch;
  }while( ch=='Y' || ch == 'y' );
  
  return 0;
}

//deletes the max
void d_max(int records[], int& size)
{
  int index = i_max(records, size);
  for(int i=0; i<size; i++)
  {
    if(i>index)
    records[i-1] = records[i];
  }
  records[size-1]=0;
  size--;
}

//returns index of the max
int i_max(int records[], int size)
{
  int index=0, max=INT_MIN;
  for(int i=0; i<size; i++)
  {
    if(max<records[i])
    {
      max = records[i];
      index = i;
    }
  }
  return index;
}

// adds elements in the array
void append(int records[], int& size)
{
  int app;
  cout << "Enter the number to append: ";
  cin >> app;
  records[size] = app;
  size++;
}

// reverses the elements of the array
void reverse(int records[], int size)
{
  int j=size-1;
  for(int i=0; i<size/2; i++)
  {
    swap(records[i], records[j]);
    j--;
  }
}

// prints the array values
void print(int records[], int size)
{
  cout << "Array Values: ";
  for(int i=0; i<size; i++)
  {
    cout << records[i] << " ";
  }
  cout << endl;
}

// swap the values of two numbers
void swap (int& a, int& b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}