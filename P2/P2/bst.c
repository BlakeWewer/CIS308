#include "bst.h"
#include <stdio.h>


struct NODE* InsertNode(struct NODE* newNode, struct NODE* head)
{
//	struct NODE temp = *head;
	if (head->key == NULL) 
	{
		return head;
	}
	else {
		if (newNode->key < head->key)
		{
			InsertNode(newNode, head->left);
		}
		else if (newNode->key > head->key)
		{
			InsertNode(newNode, head->right);
		}
	}
}

int SearchTree(int target, struct NODE * head)
{
	struct NODE* cur = head;
	if (cur->key == NULL)
	{
		return 0;
	}
	if (cur->key == target)
	{
		return 1;
	}
	else {
		if (target < cur->key)
		{
			struct NODE* l = (cur->left);
			SearchTree(target, l);
		}
		else if (target > cur->key)
		{
			struct NODE* r = (cur->right);
			SearchTree(target, r);
		}
	}
	return 0;
} 

char PrintTree(struct NODE * head)
{
	char result[100];
	if(head->left != NULL)
	{
		PrintTree(head->left);
	}

	int key = head->key;
	sprintf_s(result, 100, "%d ", key);

	if(head->right != NULL)
	{
		PrintTree(head->right);
	}
	return *result;
}

void ReleaseMemory(struct NODE * head)
{
	if (head->left != NULL)
	{
		free(head->left);
	}
	if (head->right != NULL)
	{
		free(head->right);
	}
	free(*head);
}

