/*
Title: List.cpp
Abstract: This program can make a list and perform various list operations on it.
Author: Jasdeep Singh Dhillon
Email: jdhillon@csumb.edu
Estimtate: 12 hours
Date: 4/14/2020
*/

#include<iostream>
#include "List.h"
using namespace std;

List::List() : mySize(0), myCapacity(50) 
{
  myArray = new int[myCapacity];
}

List::List(int capacityValue) : mySize(0), myCapacity(capacityValue) 
{
  myArray = new int[myCapacity];
}

List::~List()
{
  delete [] myArray;
}

List::List(const List& org)
{
  mySize = org.mySize;
  myCapacity = org.myCapacity;
  myArray = new int [myCapacity];
  for(int i=0; i<mySize; i++)
  {
    myArray[i] = org.myArray[i];
  }
}

List& List::operator=(const List &rightSide)
{
  if(this != &rightSide)
  {
    if(myCapacity != rightSide.myCapacity)
    {
      delete [] myArray;
      myCapacity = rightSide.myCapacity;
      myArray = new int [myCapacity];
    }
    mySize = rightSide.mySize;
    for(int i=0; i<mySize; i++)
    {
      myArray[i] = rightSide.myArray[i];
    }
  }
  return *this;
}

bool List::empty() const 
{
  return mySize == 0;
}

void List::display() const 
{
  for (int i = 0; i < mySize; i++) 
  {
    cout << myArray[i] << "  ";
  }
  cout << endl;
}

void List::insert(int item, int pos) 
{
  if (mySize == myCapacity) 
  {
    resize(2*myCapacity);
  }

  if (pos < 0 || pos > mySize) 
  {
    cerr << "*** Illegal location to insert -- " << pos 
         << ".  List unchanged. ***\n";
    return;
  }

    // First shift array elements right to make room for item
  for(int i = mySize; i > pos; i--) 
  {
    myArray[i] = myArray[i - 1];
  }

    // Now insert item at position pos and increase list size  
  myArray[pos] = item;
  mySize++;
}

//--- Definition of erase()
void List::erase(int pos) 
{
  if (mySize == 0) 
  {
    cerr << "*** List is empty ***\n";
    return;
  }
  if (pos < 0 || pos >= mySize) 
  {
    cerr << "Illegal location to delete -- " << pos
         << ".  List unchanged. ***\n";
    return;
  }

  for(int i = pos; i < mySize; i++) 
  {
    myArray[i] = myArray[i + 1];
  }

  // Decrease list size
  mySize--;
}

void List::append(int item)
{
  if(mySize == myCapacity)
  {
    resize(2*myCapacity);
  }
  myArray[mySize] = item;
  mySize++;
}

bool List::removeLast()
{
  if(!empty())
  {
    mySize--;
    return true;
  }
  cerr << "Cannot remove element from an empty list" << endl;
  return false;
}

void List::resize(int newCapacity)
{
  setCapacity(newCapacity);
}

void List::setCapacity(int newCapacity)
{
  int *temp = new int[myCapacity];
  for(int i=0; i<mySize; i++)
  {
    temp[i] = myArray[i];
  }
  delete [] myArray;
  
  myCapacity = newCapacity;
  
  if(mySize > myCapacity)
  mySize = myCapacity;

  myArray = new int [myCapacity];
  for(int i=0; i<mySize; i++)
  myArray[i] = temp[i];

  delete [] temp;

}