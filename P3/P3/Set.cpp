#include "Set.h"
#include <iostream>
using namespace std;

Set::Set(int max) {
	nums = new int[max];
	pos = 0;
	this->max = max;
}

Set::~Set() {
	delete[] nums;
}

void Set::add(int elem) {
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

	for (int i = 0; i < pos; i++)
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
			cout << nums[i] << " ";
		}
	}
}

void Set::sort()
{
	for (int j = 0; j < pos; j++)
	{
		for (int i = 0; i < max - 1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				int temp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = temp;
			}
		}
	}
}


