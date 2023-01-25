#include <iostream>
#include "Node.h"
#include "Utils.h"

using namespace std;

bool insertStudent(Node*& listHead, Node* newNode) { // do dis later (currently broken)
  if (listHead == nullptr) {
    listHead = newNode;
    return true;
  }
  if (listHead->getStudent()->getID() == newNode->getStudent()->getID()) return false;
  if (listHead->getStudent()->getID() > newNode->getStudent()->getID()) {
    Node* oldHead = listHead;
    listHead = newNode;
    newNode->setNext(oldHead);
  }
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
  return insertStudent(listHead, newNode);
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
      if (Utils::chkcmd(in, "add")) promptAddStudent(listHead);
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
