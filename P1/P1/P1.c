#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		for (int i = 0; i < strlen(eq); i++)
		{
			if (((int)eq[i] < 40 && (int)eq[i] != 32) || ((int)eq[i] > 57 && ((int)eq[i] != 61) && ((int)eq[i] != 91) && ((int)eq[i] != 93) && ((int)eq[i] != 123) && ((int)eq[i] != 125)))
			{
				printf_s("Invalid Characters.");
				break;
			}
		}
		check(eq);
		
	}
	printf_s("Equation: \n");
	printf_s("%s", eq);
	printf_s("Solve this shit here.");
	scanf_s(" ");
//	fclose(file);
}



void check(char eq[])
{
	char check[100];
	int j = 0;
	int h = 0;
	for (int i = 0; i < strlen(eq); i++)
	{
		if ((int)eq[i] == 40)
		{
			check[j] == '(';
			j++;
		}
		else if ((int)eq[i] == 41)
		{
			check[j] == ')';
			j++;
		}
		else if ((int)eq[i] == 91)
		{
			check[j] == '[';
			j++;
		}
		else if ((int)eq[i] == 93)
		{
			check[j] == ']';
			j++;
		}
		else if ((int)eq[i] == 123)
		{
			check[j] == '{';
			j++;
		}
		else if ((int)eq[i] == 125)
		{
			check[j] == '}';
			j++;
		}
	}

	char test[100];
	test[0] = check[0];
	int h = 0;
	for (int i = 1; i < countof(check); i++)
	{
		if ((int)eq[i] == 40)
		{
			check[i] == '(';
			h++;
		}
		else if ((int)eq[i] == 41)
		{
			check[i] == ')';
			h++;
		}
		else if ((int)eq[i] == 91)
		{
			check[i] == '[';
			h++;
		}
		else if ((int)eq[i] == 93)
		{
			check[i] == ']';
			h++;
		}
		else if ((int)eq[i] == 123)
		{
			check[i] == '{';
			h++;
		}
		else if ((int)eq[i] == 125)
		{
			check[i] == '}';
			h++;
		}
	}
}