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

/*
struct NODE SearchTree(int target, struct NODE * head)
{
	struct NODE* cur;
	if (head->key == NULL)
	{
		return 
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
	return NODE;
} */

void PrintTree(struct NODE * head)
{

}

void ReleaseMemory(struct NODE * head)
{

}

