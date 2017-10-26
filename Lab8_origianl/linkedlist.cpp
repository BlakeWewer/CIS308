#include "node.h"
#include "linkedlist.h"
#include <iostream>

LinkedList::LinkedList(void) {
	Node* head = new Node(NULL);
	Node * tail = new Node(NULL);
	//initialize head and tail to NULL
}

LinkedList::~LinkedList() {
	Node* cur = head;
	Node* temp = head;//release the memory for each node
	while (cur->next != nullptr)
	{
		cur = cur->next;
		delete(temp);
	}
	delete(cur);
}

void LinkedList::add(int val) {
	//this method is complete
	
	Node *cur = new Node(val);
	
	if (head == NULL) {
		head = cur;
		tail = cur;
	}
	else {
		tail->next = cur;
		tail = tail->next;
	}
}

void LinkedList::print(void) {
	Node * cur = new Node(NULL);
	if (head == NULL)
	{
		
	}
	else {
		cur = head;
		printf_s("%d ", cur->data);

		while (cur->next->data != NULL)
		{
			cur = cur->next;
			cur.print()
		}
	}
}