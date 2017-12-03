/**********************************************
* Name: Blake Wewer							  *
* Date: 12/3/17								  *
* Assignment: Project 3: Sets				  *
***********************************************
* This is the header file for the Set class   *
*  defined in Set.cpp						  *
***********************************************/

#ifndef SET_H
#define SET_H

class Set {
protected:	
	int pos;	
public:
	int *nums;
	int size;
	int max;
	Set(int);
	~Set();	
	void add(int);
	void print();
	void sort(void);
	int operator[](int);

};

#endif