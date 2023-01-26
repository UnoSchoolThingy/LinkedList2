#include <iostream>
#include "Node.h"
#include "Utils.h"

using namespace std;

// Insert a student 
bool insertStudent(Node*& listHead, Node* prev, Node* curr, Node* newNode) { // do dis later (currently broken)
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
  return false;
}

void printList(Node* listHead) {
  if (listHead == nullptr) return;
  listHead->getStudent()->print();
  printList(listHead->getNext());
}

void deleteStudent(Node* listhead) {
  cout << "Pretend we are deleting a student xd" << endl;
}

int main() {
  Node* listHead = nullptr;
  char in[35];
  while (true) {
    cout << "Enter command (ADD, PRINT, DELETE, or QUIT): ";
    cin >> in;
    try {
      if (Utils::chkcmd(in, "add")) cout << (promptAddStudent(listHead) ? "Added!" : "Couldn't add, student with the same ID already exists!") << endl;
      else if (Utils::chkcmd(in, "print")) printList(listHead);
      else if (Utils::chkcmd(in, "delete")) deleteStudent(listHead);
      else if (Utils::chkcmd(in, "quit")) break;
      else cout << "That command isn't recognized!\n";
    }
    catch (...) {
      cout << "Oopsie, make sure you only enter the right stuff!\n";
    }
  }
}
