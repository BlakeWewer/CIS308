/**********************************************
* Name: Blake Wewer							  *
* Date: 12/3/17								  *
* Assignment: Project 3: Sets				  *
***********************************************
* This is the file that implements the header *
*  file Set.h.  It includes a constructor, an *
*  add method, a print method, a sort method, *
*  and an operator[] method.                  *
***********************************************/

#include "Set.h"
#include <iostream>
using namespace std;

Set::Set(int max) {
	nums = new int[max];
	pos = 0;
	this->max = max;
	size = 0;
}


Set::~Set() {
	delete[] nums;
}

void Set::add(int elem) {
	for (int i = 0; i < pos; i++)
	{
		if (elem == nums[i])
		{
			return;
		}
	}
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
		nums = temp;

		nums[pos] = elem;
		pos++;
		this->max = max;
		size++;
		return;
	}
	nums[pos] = elem;
	pos++;
	size++;
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
/*	for (int j = 0; j < pos; j++)
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
	}*/

	for (int i = 0; i < pos - 1; i++)
	{
		for (int j = 0; j < pos - i - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}

int Set::operator[](int x)
{
	return (*this).nums[x];
}
