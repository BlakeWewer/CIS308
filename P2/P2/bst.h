#ifndef BST_H
#define BST_H

	struct NODE {
		int key;
		struct NODE* left;
		struct NODE* right;
	};

	struct NODE* InsertNode(struct NODE* newNode, struct NODE* head);
	int SearchTree(int target, struct NODE* head);
	char PrintTree(struct NODE* head);
	void ReleaseMemory(struct NODE* head);

#endif