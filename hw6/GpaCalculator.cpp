 /*
Title: hw06_1.cpp
Abstract: This program takes the number of courses, their credits and the grade as an input. It then calculates the gpa based on those inputs.
Author: Jasdeep Singh Dhillon
Email: jdhillon@csumb.edu
Estimtate: 12 hours
Date: 4/8/2020
*/

#include<iostream>
#include "GpaCalculator.h"
using namespace std;

GpaCalculator::GpaCalculator()
{
 GpaCalculator(0);
}
GpaCalculator::GpaCalculator(int courseCount)
{
  myCoursesEntered = 0;
  myCredits = new int[courseCount];
  myGradePoints = new double[courseCount];
  myCourseCount = courseCount;
}
GpaCalculator::GpaCalculator(const GpaCalculator & source)
{
  myCourseCount = source.getCourseCount();
  myCoursesEntered = source.myCoursesEntered;
  myCredits = new int[myCourseCount];
  myGradePoints = new double[myCourseCount];
  
  for(int i=0; i<myCourseCount; i++)
  {
    myCredits[i] = source.myCredits[i];
    myGradePoints[i] = source.myGradePoints[i];
  }
}
GpaCalculator & GpaCalculator::operator=(const GpaCalculator & source)
{
  if(this != &source)
  {
    if(myCourseCount != source.myCourseCount)
    {
      myCourseCount = source.myCourseCount;
      delete [] myGradePoints;
      delete [] myCredits;
      myCredits = new int [myCourseCount];
      myGradePoints = new double [myCourseCount];
    }
    for(int i=0; i<myCourseCount; i++)
    {
      myCredits[i] = source.myCredits[i];
      myGradePoints[i] = source.myGradePoints[i];
    }
  }
  return *this;
}
void GpaCalculator::addCourse(int credits, string grade)
{
  if(myCoursesEntered>=myCourseCount)
  {
    cerr << "All courses entered";
    return;
  }
  myCredits[myCoursesEntered] = credits;
  myGradePoints[myCoursesEntered] = getGradePoints(grade);
  myGradePoints[myCoursesEntered] *= myCredits[myCoursesEntered];
  myCoursesEntered++;
}

double GpaCalculator::getTotalGradePoints() const
{
  double totalGradePoints = 0;
  for(int i=0; i<myCourseCount; i++)
  {
    totalGradePoints += myGradePoints[i];
  }
  return totalGradePoints;
}

int GpaCalculator::getTotalCredits() const
{
  int totalCredits = 0;
  for(int i=0; i<myCourseCount; i++)
  {
    totalCredits += myCredits[i];
  }
  return totalCredits;
}

double GpaCalculator::getGpa() const
{
  return getTotalGradePoints()/getTotalCredits();
}

double GpaCalculator::getGradePoints(string grade) 
{
  for (int i = 0; i < SIZE; i++) 
  {
    if(GRADES[i] == grade) 
    {
      return GRADEPOINTS[i];
    }
  }
  return 0;
}

GpaCalculator::~GpaCalculator()
{
  delete [] myCredits;
  cerr << "Deleting credits dynamic array" << endl;
  delete [] myGradePoints;
  cerr << "Deleting grade points dynamic array" << endl;
}