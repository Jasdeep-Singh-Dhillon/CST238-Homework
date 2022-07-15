/*
  Title: Binary Converter
  Abstract: Converts the decimal value to binary
  Author: Jasdeep Singh Dhillon
  Email: jdhillon@csumb.edu
  Estimate: 4 hours
  Date: 2/12/2020
*/

#include <iostream>
using namespace std;

const int CAPACITY = 128;

class Binary
{
  private:
  int arr[CAPACITY];
  int top;

  public:
  Binary();
  void conversion(int num);
  void display();

};

Binary::Binary():top(-1)
{

}

void Binary::conversion(int num)
{
  for(int i=0; i < CAPACITY; i++)
  {
    arr[i] = num%2;
    num /= 2;
    
    if(num == 0 && arr[i] == 0)
    break;

    top++;
    
    // cout << "num at " << i << ": " << num << endl;
    // cout << "arr at " << i << ": " << arr[i] << endl;
  }
}

void Binary::display()
{
  for(int i=top; i >= 0; i--)
  {
    cout << arr[i];
  }
  cout << endl;
}

int main()
{
  int num = 0;
  while(true)
  {
    cout << "Enter a number: " ;
    cin >> num;
    if(num == 0)
    break;
    Binary b;
    b.conversion(num);
    cout << num << " => " ;
    b.display();
    cout << endl;
  }
  cout << "Exiting";
}