#ifndef SET_H
#define SET_H

class Set {
private:
	int *nums;
	int pos;
	int max;
public:
	Set(int);
	~Set();
	void add(int);
	void print();
};

#endif
