 /*
Title: hw6-2.cpp
Abstract: This program takes input as a string and sorts them in an ascending order
Author: Jasdeep Singh Dhillon
Email: jdhillon@csumb.edu
Estimtate: 3 hours
Date: 4/8/2020
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<string> text; 
  string fileName;
  cout << "Enter a filename: ";
  cin >> fileName;
  
  ifstream input;
  input.open(fileName);
  string str;
  
  while(input >> str)
  {
    if(str == "")
    break;
    else
    text.push_back(str);
  }
  
  cout << "Words: " << endl;
  for(int i=0; i<text.size(); i++)
  {
    cout << "\t" << text[i] << endl;
  }
  
  cout << endl << "Sorting! " << endl << "Words: " << endl;
  sort(text.begin(), text.end());
  
  for(int i=0; i<text.size(); i++)
  {
    cout << "\t" << text[i] << endl;
  }
  
  return 0;
}