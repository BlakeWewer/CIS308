#include "person.h"
#include <iostream>
#include <cstdio>

int main()
{
	Person p;

	p.setVals("Bill", 20);
	p.print();
	
	getchar();
	return 0;
}