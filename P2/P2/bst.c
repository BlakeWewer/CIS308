#include "bst.h"
#include <stdio.h>


void InsertNode(struct NODE* newNode, struct NODE* head)
{
	if (head->key == NULL)
	{
		head = newNode;
	}
	else {
		if (newNode->key < head->key)
		{
			insertNode(newNode, head->left);
		}
		else if (newNode->key > head->key)
		{
			insertNode(newNode, head->right);
		}
	}
}

struct NODE SearchTree(int target, struct NODE * head)
{
	return NODE;
}

void PrintTree(struct NODE * head)
{

}

void ReleaseMemory(struct NODE * head)
{

}

