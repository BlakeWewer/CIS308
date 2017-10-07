#include "io.h"
#include <stdio.h>


char MainMenu()
{
	char answer;
	printf_s("Enter [i]nsert, [s]earch, inorder [t]raversal, or [q]uit: ");
	scanf_s("%c", &answer);
	while (answer == '\n')
	{
		scanf_s("%c", &answer);
	}
	return answer;
}

int Insert()
{
	int insert;
	printf_s("Enter a number to insert: ");
	scanf_s("%d", &insert);
	while (insert == '\n')
	{
		scanf_s("%c", &insert);
	}
	return insert;
	
}

int Search()
{
	int target;
	printf_s("Enter a number to search for: ");
	scanf_s("%d", &target);
	while (target == '\n')
	{
		scanf_s("%c", &target);
	}
	return target;
}

void PrintSearchResults(int result, int target)
{
	if (result == 1)
	{
		printf_s("%d is in the tree", target);
	}
	else {
		printf_s("%d is not in the tree", target);
	}
}

void InorderTraversal(char *result)
{
	printf_s("%s", result);
}

