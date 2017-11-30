#ifndef SET_H
#define SET_H

class Set {
protected:
	int *nums;
	int pos;
	int max;
public:
	Set(int);
	~Set();
	void add(int);
	void print();
	void sort(void);
	//Need a friend method to access nums array
};

#endif