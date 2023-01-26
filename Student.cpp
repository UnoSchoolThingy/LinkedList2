#include "Student.h"

Student::Student(char* firstname, char* lastname, int id, float gpa) {
    strcpy(this->firstname, firstname);
    strcpy(this->lastname, lastname);
    this->id = id;
    this->gpa = gpa;
}

int Student::getID() {
  return this->id;
}

float Student::getGPA() {
  return this->gpa;
}

void Student::print() {
  std::cout << '[' << id << "] " << firstname << ' ' << lastname << " (" << std::fixed << std::setprecision(2) << gpa << ")\n";
}
