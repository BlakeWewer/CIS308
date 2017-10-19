#include "person.h"
#include <iostream>
#include <cstdio>
using namespace std;

void Person::setVals(char n[], int a) {
	strcpy_s(name, 20, n);
	age = a;
}
void Person::print(void) {
	cout << name << " " << age <<
		endl;
}
