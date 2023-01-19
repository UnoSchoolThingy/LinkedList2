/* Created by Sahil Pai
* Project: linked lists part 1
* Date: 1/12/23
*/

#include <iostream>
#include <cstring>

class Student {
public:
	char firstName[50];
	char lastName[50];
	int ID;
	float GPA;

	Student(char*, char*, int, float); //prototype
};

class Node {
private:
	Student* student;
	Node* next;
public:
	Node* getNext(); //get next node
	Student* getStudent(); //get next student
	void setNext(Node*); //set next node
	Node(Student*); //constructor
	~Node(); //destructor
};
