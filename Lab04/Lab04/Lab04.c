#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
	char name[30];
	int age;
	int year;
} S;

void display(struct Student *ptrS);

int main()
{
	printf_s("Enter Student Name: ");
	fgets(S.name, sizeof(S.name), stdin);
	printf_s("Enter Student Age: ");
	scanf_s("%d", &S.age, sizeof(S.age));
	printf_s("Enter Student Year in School: \n(FR = 1, SO = 2, JR = 3, SR = 4): ");
	scanf_s("%d", &S.year, sizeof(S.year));

	display(&S);

	S.age++;
	if (S.year != 4)
	{
		S.year++;
	}

	display(&S);

	scanf_s(" ");
	return 1;
}

void display(struct Student *ptrS)
{
	printf_s("\n\n\nStudent Name: %s\n", (*ptrS).name);
	printf_s("Student Age: %d\n", (*ptrS).age);

	switch((*ptrS).year)
	{
		case(1): printf_s("Student Age: Freshman\n");
			break;
		case(2): printf_s("Student Age: Sophomore\n");
			break;
		case(3): printf_s("Student Age: Junior\n");
			break;
		case(4): printf_s("Student Age: Senior\n");
			break;
	}
}