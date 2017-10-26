#include "linkedlist.h"
#include <iostream>

using namespace std;

int main() {
	//YOU DO THIS
	//create a new (dynamically allocated) linked list
	LinkedList list = new LinkedList();
	//add numbers 1-10
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	list.add(6);
	list.add(7);
	list.add(8);
	list.add(9);
	list.add(10);
	//call print
	list.print();
	//release all memory
	delete(list);
	return 0;
}