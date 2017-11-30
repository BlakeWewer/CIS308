#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Rectangle.h"
#include "Square.h"
using namespace std;

int main()
{
	Rectangle * r;
	Square * s;

	r = new Rectangle(3, 4);
	s = new Square(5);

	cout << "Area of Rectangle: " << r->Area() << endl;
	cout << "\nArea of Square: " << s->Area() << endl;

	cout << "\n" << endl;

	r->print();
	cout << "\n" << endl;
	s->print();

	scanf_s(" ");

	return 0;
}
