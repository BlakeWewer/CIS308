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

};

#endif