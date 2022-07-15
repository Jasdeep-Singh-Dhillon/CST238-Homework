/*
  Title: Queue Operations
  Abstract: A Queue list which tells if the array is sorted 
  Author: Jasdeep Singh Dhillon
  Email: jdhillon@csumb.edu
  Estimate: 4 hours
  Date: 2/12/2020
*/

#include <iostream>
using namespace std;

const int QUEUE_CAPACITY = 7;
typedef char QueueElement;

void swap(int& a, int& b)
{
  int temp = a;
  a = b;
  b = temp;
}

class Queue
{
public:
  Queue();
  bool empty() const;
  void enqueue(QueueElement value);
  void display() const;
  QueueElement front() const;
  void dequeue();
  void printPrivateInfo();

  bool isSorted() const;
  bool drop(QueueElement value);
  bool indexUsed(int index) const;
  void dump() const;
  
private:
  int myFront;
  int myBack;
  QueueElement myArray[QUEUE_CAPACITY];
};

Queue::Queue()
: myFront(0), myBack(0)
{}

bool Queue::empty() const
{ 
  return (myFront == myBack); 
}

void Queue::printPrivateInfo() 
{
  cout << "myFront: " << myFront << endl;
  cout << "myBack: " << myBack << endl;
  cout << "Elements: " << endl;
  for (int i = 0; i < QUEUE_CAPACITY; i++) 
  {
    cout << "\t" << i << ": " << myArray[i] << endl;
  }
}

void Queue::enqueue(QueueElement value)
{
  int newBack = (myBack + 1) % QUEUE_CAPACITY;
  if (newBack != myFront)     // queue isn't full
  { 
    myArray[myBack] = value;
    myBack = newBack;
  }
  else
  {
    cerr << "*** Queue full -- can't add new value ***\n"
            "Must increase value of QUEUE_CAPACITY.\n";
  }
}

void Queue::display() const
{
  for (int i = myFront; i != myBack; i = (i + 1)%QUEUE_CAPACITY) 
  {
    cout << myArray[i] << "  ";
  }
  cout << endl;
}

QueueElement Queue::front() const
{
  if ( !empty() ) 
  {
    return (myArray[myFront]);
  }
  else
  {
    cerr << "*** Queue is empty -- returning garbage value ***\n";
    QueueElement garbage;
    return garbage;
  }
}

void Queue::dequeue()
{
  if ( !empty() )
  {
    myFront = (myFront + 1) % QUEUE_CAPACITY;
  }
  else
  {
    cerr << "*** Queue is empty -- "
            "can't remove a value ***\n";
  }
}

bool Queue::isSorted() const
{
  int k;
  for(k=myFront; k != myBack; k=(k+1)%QUEUE_CAPACITY)
  {
    if(myArray[k]!=myArray[(k+1)%QUEUE_CAPACITY])
    break;
  }

  if ( myArray[k] < myArray[(k+1)%QUEUE_CAPACITY])
  {
    for(int i=k; i!=myBack-1; i=(i+1)%QUEUE_CAPACITY)
    {
      if( myArray[i] > myArray[(i+1)%QUEUE_CAPACITY])
      return false;
    }
  }
  
  if ( myArray[k] > myArray[(k+1)%QUEUE_CAPACITY])
  {
    for(int i=k; i!=myBack-1; i=(i+1)%QUEUE_CAPACITY)
    {
      if( myArray[i] < myArray[(i+1)%QUEUE_CAPACITY])
      return false;
    }
  }
  
  return true;
}

bool Queue::drop(QueueElement value)
{
  int index=-1;
  for(int i=myFront; i!=myBack; i=(i+1)%QUEUE_CAPACITY)
  {
    if(myArray[i] == value)
    {
      index = i;
      break;
    }
  }

  if(index == -1)
  return false;

  for(int i=index; i!=myBack; i=(i+1)%QUEUE_CAPACITY)
  {
    swap(myArray[i], myArray[(i+1)%QUEUE_CAPACITY]);
  }
  myBack--;
  if(myBack == -1)
  myBack = QUEUE_CAPACITY-1;
  return true;
}

bool Queue::indexUsed(int index) const
{
  for(int i=myFront; i!=myBack; i=(i+1)%QUEUE_CAPACITY)
  {
    if(index == i)
    return true;
  }
  return false;
}

void Queue::dump() const
{
  if(empty())
  {
    for(int i=0; i<QUEUE_CAPACITY; i++)
    cout << "_ ";
  }
  else if(myBack > myFront)
  {
    for(int i=0; i<QUEUE_CAPACITY; i++)
    {
      if(i>=myFront && i<myBack)
      cout << myArray[i] << " ";
      else
      cout << "_ ";
    }
  }
  else if(myFront > myBack)
  {
    for(int i=0; i<QUEUE_CAPACITY; i++)
    {
      if(i<=myFront && i>myBack)
      cout << myArray[i] << " ";
      else
      cout << "_ ";
    }
  }
  cout << endl;
}



int main()
{
Queue myQueue;
myQueue.enqueue('A');
myQueue.dump();
myQueue.enqueue('C');
myQueue.dump();
myQueue.enqueue('B');
myQueue.dump();
myQueue.enqueue('C');
myQueue.dump();



myQueue.display();


cout << "Sorted: " << myQueue.isSorted() << endl;
cout << "Drop: " << myQueue.drop('A') << endl;
cout << "Index Used: " << myQueue.indexUsed(3) << endl;
cout << "Dump: " ;
myQueue.dump();
myQueue.display();
}
