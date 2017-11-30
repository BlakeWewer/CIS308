#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
protected:
	int width;
	int height;
public:
	Rectangle(int width, int height);
	int Area(void);
	void print(void);
};

#endif
