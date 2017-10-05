#ifndef BST_H
#define BST_H

	typedef struct NODE {
		int key;
		struct NODE* left;
		struct NODE* right;
	};

	void InsertNode(struct NODE* newNode, struct NODE* head);
	struct NODE SearchTree(int target, struct NODE* head);
	void PrintTree(struct NODE* head);
	void ReleaseMemory(struct NODE* head);

#endif