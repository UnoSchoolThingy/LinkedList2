/* Created by Sahil Pai
* Project: linked lists part 1
* Date: 1/12/23
*/

#include <iostream>
#include <cstring>
#include "Student.h"

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
