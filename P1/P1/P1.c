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
	char check[100];

	while (fscanf_s(file, "%s", eq, sizeof(eq)) != EOF)
	{
		for (int i = 0; i < strlen_s(eq); i++)
		{
			if (((int)eq[i] < 40 && (int)eq[i] != 32) || ((int)eq[i] > 57 && ((int)eq[i] != 61) && ((int)eq[i] != 91) && ((int)eq[i] != 93) && ((int)eq[i] != 123) && ((int)eq[i] != 125)))
			{
				printf_s("Invalid Characters.");
				break;
			}
		}
		
		
	}
	printf_s("Equation: \n");
	printf_s("%600s", eq);
	printf_s("Solve this shit here.");
	scanf_s("");
//	fclose(file);
}