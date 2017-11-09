#include "set.h"
#include <iostream>
using namespace std;

void expandSet(Set *set);

int main() {
	Set *set = new Set(5);
	expandSet(set);
	set->print();
	scanf_s(" ");
	delete set;
	return 0;	
}

void expandSet(Set *set) {
	for (int i = 0; i < 10; i++)
	{
		int value;
		printf_s("Enter an Integer to add to the Set: ");
		cin >> value;
		set->add(value);
	}
}