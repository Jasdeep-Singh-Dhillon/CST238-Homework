/*
Title: hw2-2.cpp
Abstract: Outputs quiz average of students
Author: Jasdeep Singh Dhillon
Email: jdhillon@csumb.edu
Estimate: 3 hours
Date: 1/29/2020
*/

#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

struct student
{
  string name, id;
  double score[5], average;
};

void pattern();
double minimum(double arr[], int size);

int main()
{
  string file;
  cout << "Enter an input file: ";
  cin >> file;

  ifstream data(file);
  if(data.fail())
  {
    cout << "Error: Input File Invalid " << endl;
    return 0;
  }

  student quiz[30]; int size=0;

  for(int i=0; i<30; i++)
  {
    data >> quiz[i].name >> quiz[i].id;
    quiz[i].average=0;
    
    if(quiz[i].name=="STOP")
    break;
    
    for(int j=0; j<5; j++)
    {
      data >> quiz[i].score[j];
      quiz[i].average += quiz[i].score[j];
    }
    quiz[i].average -= minimum(quiz[i].score, 5);
    size++;
  }
  
  pattern();
  cout << " Course Report: Quiz Average" << endl;
  pattern();

  for(int i=0; i<size; i++)
  {
    cout << "  " << quiz[i].name << " (" << quiz[i].id << "): ";
    quiz[i].average/=4;
    cout << quiz[i].average << endl;
  }
  pattern();

  return 0;
}

void pattern()
{
  cout << "--------------------------------------------------" << endl;
}

double minimum(double arr[], int size)
{
  double min=arr[0];
  for(int i=0; i<size; i++)
  {
    if(min > arr[i])
    min = arr[i];
  }
  return min;
}