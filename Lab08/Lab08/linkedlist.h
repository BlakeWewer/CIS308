#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

class LinkedList {
	private:
		Node* head;
		Node* tail;
	public:
		LinkedList(void);
		~LinkedList();
		void add(int);
		void print(void);
};

#endif