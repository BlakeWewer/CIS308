#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	test[0] = check[0];
	for (int i = 1; i < strlen(check); i++)
	{
		if ((int)check[i] == 40)
		{
			test[i] = '(';
			h++;
		}
		else if ((int)check[i] == 41)
		{
			if (test[h] == 40)
			{
				test[h] = (char)0;
				h--;
			}
			else {
				test[i] = ')';
				h++;
			}
		}
		else if ((int)check[i] == 91)
		{
			test[i] = '[';
			h++;
		}
		else if ((int)check[i] == 93)
		{
			if (test[h] == 91)
			{
				test[h] = (char)0;
				h--;
			}
			else {
				test[i] = ']';
				h++;
			}
		}
		else if ((int)check[i] == 123)
		{
			test[i] = '{';
			h++;
		}
		else if ((int)check[i] == 125)
		{
			if (test[h] == 123)
			{
				test[h] = (char)0;
				h--;
			}
			else {
				test[i] = '}';
				h++;
			}
		}
	}

	if (strlen(test) == 0)
	{
		printf_s("Equation is Correct.\n\n");
	}
	else {
		printf_s("Equation is Incorrect");
	}
}

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
		scanf_s(" ");
	}
//	fclose(file);
}



