#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	ROUND(a) ((int)a)


typedef struct{
	char name[30];
	int age;

	union {
		struct {
			char school[30];
		} child;
		struct {
			char college[30];
			double gpa;
		} college_student;
		struct {
			char company[30];
			int salary;
		} adult;
	}kind;

	enum{childK, college_studentK, adultK} kindOfPerson;
}  Person;

void display(struct Person* PtrS);

int main()
{
	Person p1;
	p1.kindOfPerson = college_studentK;
	strcpy_s(p1.name, 30, "Bob");
	p1.age = 20;
	strcpy_s(p1.kind.college_student.college, 30, "K-State");
	p1.kind.college_student.gpa = 3.5;

	Person *PtrP2 = malloc(sizeof(Person));
	Person p2;
	PtrP2 = &p2; 
	(*PtrP2).kindOfPerson = childK;
	strcpy_s((*PtrP2).name, 30, "Alison");
	(*PtrP2).age = 10;
	strcpy_s((*PtrP2).kind.child.school, 30, "Amanda Arnold Elementary");
	
	display(&p1);
	display(PtrP2);

	printf_s("\n\n\n");
	double a = 2.2;
	printf_s("%.1f : %d\n", a, ROUND(a));
	a = 2.7;
	printf_s("%.1f : %d\n", a, ROUND(a));
	a = -2.2;
	printf_s("%.1f : %d\n", a, ROUND(a));
	a = -2.7;
	printf_s("%.1f : %d\n", a, ROUND(a));

	scanf_s(" ");

	free(&p1);
	free(PtrP2);
}

void display(Person* PtrS)
{
	if ((*PtrS).kindOfPerson == childK)
	{
		printf_s("\nThe name is %s\n", (*PtrS).name);
		printf_s("The age is %d\n", (*PtrS).age);
		printf_s("The school of the child is %s\n", (*PtrS).kind.child.school);
	}else if ((*PtrS).kindOfPerson == college_studentK)
	{
		printf_s("\nThe name is %s\n", (*PtrS).name);
		printf_s("The age is %d\n", (*PtrS).age);
		printf_s("The college of the student is %s\n", (*PtrS).kind.college_student.college);
		printf_s("The gps of the student is %.2f\n", (*PtrS).kind.college_student.gpa);
	}else if ((*PtrS).kindOfPerson == adultK)
	{
		printf_s("\nThe name is %s\n", (*PtrS).name);
		printf_s("The age is %d\n", (*PtrS).age);
		printf_s("The company of the adult is %s\n", (*PtrS).kind.adult.company);
		printf_s("The salary of the adult is %d\n", (*PtrS).kind.adult.salary);
	}
}