#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(int width, int height)
{
	this->width = width;
	this->height = height;
}

int Rectangle::Area()
{
	return (this->height * this->width);
}

void Rectangle::print()
{
	cout << this->height << "x" << this->width << " rectangle" << endl;
}
