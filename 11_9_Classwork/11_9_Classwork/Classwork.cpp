#include <iostream>
#include <stdio.h>

const int * ptrN = new int;	//Cannot change value (1st statement gives error)
*ptrN = 50;	//Error with const directly before and after int
ptrN = 8x;	//Error with const after *

int const * ptrN = new int;	//Cannot change value (1st statement gives error)

int * const ptrN = new int;	//Cannot change ptr address (2nd statement gives error)

const int * const ptrN = new int;	//Cannot change neither value nor ptr address (Both statements give errors)