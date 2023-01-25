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

void Student::print() {
  std::cout << '[' << id << "] " << firstname << ' ' << lastname << " (" << std::setprecision(3) << gpa << ")\n";
}
