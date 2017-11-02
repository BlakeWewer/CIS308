#include "set.h"
#include <iostream>

Set::Set(int max) {
	nums = new int[max];
	pos = 0;
	this->max = max;
}

Set::~Set() {
	delete[] nums;
}

void Set::add(int elem) {
	int i;

	if (pos >= max)
	{
		while (pos >= max)
		{
			max *= 2;
		}
		int *temp = new int[max];
		for (int i = 0; i < pos; i++)
		{
			if (nums[i] != NULL)
			{
				temp[i] = nums[i];
			}
		}
		temp[pos] = elem;

		nums = temp;
		this->max = max;
		return;
	}

	for (i = 0; i < pos; i++) 
	{
		if (nums[i] == elem) return;
	}

	nums[pos++] = elem;
}

void Set::print() {
	for (int i = 0; i < pos; i++)
	{
		if (nums[i] != NULL)
		{
			printf_s("%d ", nums[i]);
		}
	}
}