/*
  Title: hw03-2.cpp
  Abstract: 
  Author: Jasdeep Singh Dhillon
  Email: jdhillon@csumb.edu
  Estimate: 5 hours
  Date: 2/6/2020
*/

#include <iostream>
using namespace std;

const int CAPACITY = 16;

class List 
{
  public:
  List();
  bool empty() const; 
  void insert(int item, int pos);
  void erase(int pos);  
  void display() const; 
  int getSize() const;
  int getValue(int pos) const;
  bool hasDuplicates() const;
  bool isSorted() const;
  bool append(const List a);
  bool remove(int value);

  private:
  int mySize;
  int myArray[CAPACITY];  
}; 


List::List() : mySize(0) {}

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
  if (mySize == CAPACITY) 
  {
    cerr << "*** No space for list element -- terminating "
          "execution ***\n";
    return;
  }
	
  if (pos < 0 || pos > mySize) 
  {
    cerr << "*** Illegal location to insert -- " << pos 
         << ".  List unchanged. ***\n";
    return;
  }

  for(int i = mySize; i > pos; i--) 
  {
    myArray[i] = myArray[i - 1];
  }

  myArray[pos] = item;
  mySize++;
}

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

  mySize--;
}

int List::getSize() const
{
  return mySize;
}

int List::getValue(int pos) const
{
  if(pos >= mySize)
  return -1;

  return myArray[pos];
}

bool List::hasDuplicates() const
{
  for(int i=0; i<mySize; i++)
  {
    for(int k=0; k<mySize; k++)
    {
      if(myArray[i] == myArray[k] && i!=k)
      return true;
    }
  }
  return false;
}

bool List::isSorted() const
{
  for(int i=0; i<mySize; i++)
  {
    if(myArray[i] < myArray[i-1] && i!=0)
    return false;
  }
  return true;
}

bool List::append(const List a)
{
  if(mySize+a.getSize() > CAPACITY)
  return false;

  for(int i=0; i<a.getSize(); i++)
  {
    myArray[mySize+i] = a.getValue(i);
  }
  mySize += a.getSize();
  return true;
}

bool List::remove(int value)
{
  int f=0;
  for(int i=0; i<mySize; i++)
  {
    if(myArray[i] == value)
    {
      erase(i);
      f = 1;
    }
  }
  return (f==1);
}



int main()
{
  List intList;
  cout << "Constructing intList\n";

  if (intList.empty()) 
  {
    cout << "Empty List: \n";
    intList.display();
    cout<< endl;
  }


  for (int i = 0; i < 10; i++) 
  {
    intList.insert(i, i);
  }
  intList.insert(8,10);
	
  cout << "List empty? " << (intList.empty() ? "Yes" : "No") << endl;

  int index;
  cout << "\nGive an index of a list element to remove: ";
  cin >> index;

  intList.erase(index);
  intList.display();

  cout << "Size: " << intList.getSize() << endl;
  cout << "Duplicates: " << intList.hasDuplicates() << endl;
  cout << "Sorted: " << intList.isSorted() << endl;
  cout << "Remove: " <<intList.remove(4) << endl;
  intList.display();



  return 0;
}
