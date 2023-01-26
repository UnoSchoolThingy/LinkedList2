/* Uno Pasadhika 
 * Linked lists 2: a continuation of student list but with linked lists and auto sort thingy
 * 1/26/2023 
 */ 

#include <iostream>
#include "Node.h"
#include "Utils.h"

using namespace std;

// Insert a student 
bool insertStudent(Node*& listHead, Node* prev, Node* curr, Node* newNode) {
  // If the list is empty 
  if (listHead == nullptr) {
    listHead = newNode;
    return true;
  }
  // If we reached the end of the list 
  if (curr == nullptr) {
    prev->setNext(newNode);
    return true;
  }
  // Linear ID search
  int currID = curr->getStudent()->getID();
  int newID = newNode->getStudent()->getID();
  if (currID == newID) return false;
  if (currID > newID) {
    if (prev != nullptr) prev->setNext(newNode);
    else listHead = newNode;
    newNode->setNext(curr);
    return true;
  }
  return insertStudent(listHead, curr, curr->getNext(), newNode);
}

// Prompt the user to add a student 
bool promptAddStudent(Node*& listHead) {
  char in[100];
  char in2[35];
  int id;
  float gpa;
  cout << "Enter first name: ";
  cin >> in;
  cout << "Enter last name: ";
  cin >> in2;
  cout << "Enter student ID: ";
  cin >> id;
  cout << "Enter GPA: ";
  cin >> gpa;
  Node* newNode = new Node(new Student(in, in2, id, gpa));
  return insertStudent(listHead, nullptr, listHead, newNode);
}

// Print the entire list of students 
void printList(Node* listHead) {
  if (listHead == nullptr) return;
  listHead->getStudent()->print();
  printList(listHead->getNext());
}

// Delete a student by ID 
bool deleteStudent(Node*& listHead, Node* prev, Node* curr, int id) {
  if (curr == nullptr) return false;
  if (curr->getStudent()->getID() == id) {
    if (prev != nullptr) prev->setNext(curr->getNext());
    else listHead = curr->getNext();
    delete curr;
    return true;
  }
  return deleteStudent(listHead, curr, curr->getNext(), id);
}

// Prompt the user for an ID of a student to delete 
bool promptDeleteStudent(Node*& listHead) {
  cout << "Enter the ID to delete: ";
  int id;
  cin >> id;
  return deleteStudent(listHead, nullptr, listHead, id);
}

float getInsaneAverage(Node* curr, float sum, int num) {
  if (curr == nullptr) return sum / (float)num;
  return getInsaneAverage(curr->getNext(), sum + curr->getStudent()->getGPA(), num + 1);
}

int main() {
  Node* listHead = nullptr;
  char in[35];
  while (true) {
    cout << "Enter command (ADD, PRINT, DELETE, AVERAGE, or QUIT): ";
    cin >> in;
    try {
      if (Utils::chkcmd(in, "add")) cout << (promptAddStudent(listHead) ? "Added!" : "Couldn't add, student with the same ID already exists!") << endl;
      else if (Utils::chkcmd(in, "print")) printList(listHead);
      else if (Utils::chkcmd(in, "delete")) cout << (promptDeleteStudent(listHead) ? "Deleted!" : "Couldn't delete, there was no student with that ID!") << endl;
      else if (Utils::chkcmd(in, "average")) {
	if (listHead == nullptr) cout << "Couldn't display average, the list is empty!";
	else cout << "Average GPA: " << fixed << setprecision(2) << getInsaneAverage(listHead, 0.f, 0);
	cout << endl;
      }
      else if (Utils::chkcmd(in, "quit")) break;
      else cout << "That command isn't recognized!\n";
    }
    catch (...) {
      cout << "Oopsie, make sure you only enter the right stuff!\n";
    }
  }
}
