#ifndef BST_H
#define BST_H

typedef struct NODE {
	int key;
	NODE* left;
	NODE* right;

	void insertNode(NODE* newNode);
	NODE searchTree(NODE* targetNode);
	void printTree();
};

#endif