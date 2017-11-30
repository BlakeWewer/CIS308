#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Square.h"
using namespace std;

Square::Square(int size) : Rectangle(size, size)
{
	Rectangle(size, size);
}

void Square::print()
{
	cout << "size " << this->height << " square" << endl;
}