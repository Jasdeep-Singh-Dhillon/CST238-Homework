/*
Title: hw2-3.cpp
Abstract: To search for the individual asked by the user and output his/her information.
Author: Jasdeep Singh Dhillon
Email: jdhillon@csumb.edu
Estimate: 2 hours
Date: 1/29/2020
*/

#include <iostream>
#include <fstream>
using namespace std;

struct bank
{
  string name, anumber;
  double balance;
};

void pattern();

const int size=30;

int main()
{
  string file;
  cout << "Enter an input file: ";
  cin >> file;

  bank account[size];
  int asize=0; 

  ifstream data(file);
  if(data.fail())
  {
    cout << "Error: Invalid Input File" << endl;
    return 0;
  }

  for(int i=0; i<size; i++)
  {
    data >> account[i].name >> account[i].anumber >> account[i].balance;
    if(account[i].name=="STOP")
    break;
    asize++;
  }

  char ch;

  do
  {
    pattern();
    string find;
    cout << "Record Finder - Enter a customer name: ";
    cin >> find;
    pattern();

    int f=0;

    for(int i=0; i<asize; i++)
    {
      if(account[i].name==find)
      {
        if(f==1)
        cout << endl;
        cout << "Name: " << account[i].name << endl;
        cout << "Account: " << account[i].anumber << endl;
        cout << "Balance: " << account[i].balance << endl;
        f=1;
      }
    }
    if(f==0)
    cout << "Fail. " << find << " doesn't exist." << endl;
    pattern();
    cout << endl;
    cout << "Do you want to continue? (y/n) ";
    cin >> ch;
    cout << endl;

  }while( ch=='Y' || ch=='y');

  cout << "BYE!";

  return 0;
}

void pattern()
{
  cout << "---------------------------------------------------" << endl ;
}