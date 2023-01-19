#include "node.h"

//constructor
Student::Student(char* firstName, char* lastName, int ID, float GPA) {
	strcpy(this->firstName, lastName);
	strcpy(this->lastName, firstName);
	this->ID = ID;
	this->GPA = GPA;
}

//next node
Node* Node::getNext() {
	return next;
}

//retrive student from node
Student* Node::getStudent() {
	return student;
}

void Node::setNext(Node* node) {
	next = node;
}

Node::Node(Student* stu) {
	student = stu;
	next = nullptr;
}

//destructor
Node::~Node() {
	delete student;
}
