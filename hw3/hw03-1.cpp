/*
  Title: hw03-1.cpp
  Abstract: The program generates a list of students and can remove or add students.
  Author: Jasdeep Singh Dhillon
  Email: jdhillon@csumb.edu
  Estimate: 5 hours
  Date: 2/6/2020
*/

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 30;

class Student
{
  private:
  string name;
  int id;
  
  public:
  Student();
  Student(string sName, int sID);
  string getName() const;
  int getID() const;
  void setName(string sName);
};

class Course
{
  private:
  string title;
  int number;
  string instructorName;
  Student arr[SIZE];
  int courseSize;

  public:
  Course();
  Course(string cTitle, int cNumber, string cInstructor);
  string getTitle() const;
  string getInstructor() const;
  int getNumber() const;
  bool add(Student s);
  bool remove(Student s);
  void printAll() const;
  int search(int sID);
};

int main()
{
  Course c1("Intro to Everything", 123, "Dr. Gross");
  Student s1("Jane", 1234);
  Student s2("Phillipe", 1235);
  Student s3("Lu", 1236);
  Student s4("Enrique", 1237);
  c1.add(s1);
  c1.add(s2);
  c1.add(s3);
  c1.add(s4);
  c1.printAll();
  c1.remove(s2);
  c1.printAll();
  c1.remove(s1);
  c1.printAll();
  c1.add(Student("Jasdeep", 1239));
  c1.printAll();
}

Student::Student():name(""), id(0)
{
}

Student::Student(string sName, int sID)
{
  name = sName;
  id = sID;
}

string Student::getName() const
{
  return name;
}
  
int Student::getID() const
{
  return id;
}

void Student::setName(string sName)
{
  name = sName;
  return;
}

Course::Course():title(""), number(0), instructorName(""), courseSize(0)
{

}
  
Course::Course(string cTitle, int cNumber, string cInstructor):courseSize(0)
{
  title = cTitle;
  instructorName = cInstructor;
  number = cNumber;
}

string Course::getTitle() const
{
  return title;
}

string Course::getInstructor() const
{
  return instructorName;
}

int Course::getNumber() const
{
  return number;
}

bool Course::add(Student s)
{
  if( courseSize > SIZE )
  return false;
  if( !(search(s.getID()) == -1 ) )
  return false;

  arr[courseSize] = s;
  courseSize++;
  return true;
}

bool Course::remove(Student s)
{
  if( courseSize == 0 )
  return false;
  if( search(s.getID()) == -1  )
  return false;

  for(int i=search(s.getID()); i<courseSize; i++)
  {
    arr[i] = arr[i+1];
  }
  courseSize--;
  return true;
}

void Course::printAll() const
{
  cout << "Course Title: " << title << endl;
  cout << "Course Number: " << number << endl;
  cout << "Instructor Name: " << instructorName << endl;
  cout << "Enrollment: " << courseSize << endl;

  for(int i=0; i<courseSize; i++)
  {
    cout << "\t" << arr[i].getName() << ": " << arr[i].getID() << endl;
  }
  cout << endl;
}

int Course::search(int sID)
{
  for(int i=0; i<courseSize; i++)
  {
    if(arr[i].getID()==sID)
    return i;
  }
  return -1;
}
