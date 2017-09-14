/*********************************************************
* Name: Blake Wewer                                      *
* Date: 9/14/2017                                        *
* Assignment: Project 1 - Sequence and Order Validation  *
**********************************************************
* This program reads in mathematical expression from a   *
* text file and tests to see if the parenthesis,         *
* brackets, and braces are all balanced and correct.     *
**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************
* Description: Checks the balance of the        *
*			expression                          *
* Input: an array of characters (the expression)*
* Output: void									*
* Precondition: The array of chars passed into  *
*			checkEq is not null                 *
* Post condition: The checkEq method will return*
* whether the passed expression is balanced by  *
*			the earlier definition.				*
************************************************/
void checkEq(char a[])
{
	char check[100];
	int j = 0;
	int h = 0;
	for (int i = 0; i < strlen(a); i++)
	{
		if ((int)a[i] == 40)
		{
			check[j] = '(';
			j++;
		}
		else if ((int)a[i] == 41)
		{
			check[j] = ')';
			j++;
		}
		else if ((int)a[i] == 91)
		{
			check[j] = '[';
			j++;
		}
		else if ((int)a[i] == 93)
		{
			check[j] = ']';
			j++;
		}
		else if ((int)a[i] == 123)
		{
			check[j] = '{';
			j++;
		}
		else if ((int)a[i] == 125)
		{
			check[j] = '}';
			j++;
		}
	}

	char test[100];
	test[j] = (char)0;
	check[j] = (char)0;
	test[0] = check[0];
	for (int i = 1; i < strlen(check); i++)
	{
		if ((int)check[i] == 40)
		{
			test[h+1] = '(';
			h++;
		}
		else if ((int)check[i] == 41)
		{
			if (test[h] == 40)
			{
				for (int x = h; x < j - 1; x++)
				{
					test[x] = test[x + 1];
				}
				h--;
			}
			else {
				test[h + 1] = ')';
				h++;
			}
		}
		else if ((int)check[i] == 91)
		{
			test[h + 1] = '[';
			h++;
		}
		else if ((int)check[i] == 93)
		{
			if (test[h] == 91)
			{
				for (int x = h; x < j - 1; x++)
				{
					test[x] = test[x + 1];
				}
				h--;
			}
			else {
				test[h + 1] = ']';
				h++;
			}
		}
		else if ((int)check[i] == 123)
		{
			test[h + 1] = '{';
			h++;
		}
		else if ((int)check[i] == 125)
		{
			if (test[h] == 123)
			{
				for (int x = h; x < j - 1; x++)
				{
					test[x] = test[x + 1];
				}
				h--;
			}
			else {
				test[h + 1] = '}';
				h++;
			}
		}
	}
	test[h+1] = (char)0;

	if (strlen(test) == 0)
	{
		printf_s("Equation is Correct.\n\n\n\n\n");
	}
	else {
		printf_s("Equation is Incorrect.\n\n\n\n\n");
	}
}

/************************************************
* Description: The main method for P1           *
* Input: none									*
* Output: int									*
* Precondition: The file that is to be read in  *
* is valid and does not contain any invalid     *
*				characters                      *
* Post condition: The main method will display  *
* whether the passed expression is balanced by  *
*			the earlier definition.				*
************************************************/
int main()
{
	FILE *file;
	fopen_s(&file, "Problems.txt", "r");
	if (file == 0)
	{
		printf("Error opening the file\n");
		return 0;
	}

	char eq[100];
	

	while (fgets(eq, 100, file) != NULL)
	{
		for (int i = 0; i < strlen(eq) - 1; i++)
		{
			if (((int)eq[i] < 40 && (int)eq[i] != 32) || ((int)eq[i] > 57 && (((int)eq[i] != 61) && ((int)eq[i] != 91) && ((int)eq[i] != 93) && ((int)eq[i] != 123) && ((int)eq[i] != 125))))
			{
				printf_s("Invalid Characters.");
				break;
			}
		}
		printf_s("Equation: \n");
		printf_s("%s\n", eq);
		checkEq(eq);
	}
	scanf_s(" ");
	return 1;
}



