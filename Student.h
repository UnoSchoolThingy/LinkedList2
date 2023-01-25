#pragma once

#include <iostream>
#include <cstring>
#include <iomanip>

class Student {
 private:
  char firstname[35];
  char lastname[35];
  int id;
  float gpa;

 public:
  Student(char* firstname, char* lastname, int id, float gpa);
  int getID();
  void print();
};
