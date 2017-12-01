#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include "Set.h"
using namespace std;

void Intersection(Set&, Set&);
void Union(Set&, Set&);
void Difference(Set&, Set&);

int main()
{
	string s;
	cout << "Input Vector 1 (like num1,num2,...,numN): ";
	cin >> s;

	vector<int> vect1;
	vector<int> vect2;
	stringstream stream(s);

	int i;

	while (stream >> i)
	{
		vect1.push_back(i);

		if (stream.peek() == ',' || stream.peek() == ' ' || stream.peek() == '(' || stream.peek() == ')')
			stream.ignore();
	}

	sort(vect1.begin(), vect1.end());

	Set *v1 = new Set(vect1.size());
	for (int i = 0; i < vect1.size(); i++)
	{
		v1->add(vect1[i]);
	}

	cout << "Input Vector 2 (like num1,num2,...,numN): ";
	cin >> s;
	stringstream stream2(s);

	int j;

	while (stream2 >> j)
	{
		vect2.push_back(j);

		if (stream2.peek() == ',' || stream2.peek() == ' ' || stream2.peek() == '(' || stream2.peek() == ')')
			stream2.ignore();
	}

	sort(vect2.begin(), vect2.end());

	Set * v2 = new Set(vect2.size());
	for (int i = 0; i < vect2.size(); i++)
	{
		v2->add(vect2[i]);
	}

	cout << "\n\n" << "The sorted sets are: " << endl;
	v1->print();
	cout << endl;
	v2->print();
	cout << endl;

	char response[1];
	cout << "\nEnter (i)ntersect, (u)nion, (d)ifference, or (q)uit: ";
	cin >> response;

	while (toupper(*response) != 'Q')
	{
		if (toupper((*response)) == 'I')
		{
			Intersection(*v1, *v2);
		}
		else if (toupper((*response)) == 'U')
		{
			Union(*v1, *v2);
		}
		else if (toupper((*response)) == 'D')
		{
			//DIFFERENCE
		}
		else if (toupper((*response)) == 'Q')
		{
			break;
		}

		cout << "\n\nEnter (i)ntersect, (u)nion, (d)ifference, or (q)uit: ";
		cin >> response;
	}

	return 0;
}

void Intersection(Set& v1, Set&v2)
{
	Set * u;
	bool init = false;
	int i = 0;
	while (!init && i < v1.size)
	{
		bool added = false;
		for (int j = 0; j < v2.size; i++)
		{
			if (v1.nums[i] == v2.nums[j] && !added)
			{
				u = new Set(v1.nums[i]);
				init = true;
				added = true;
			}
		}
		i++;
	}
	while (i < v1.size)
	{
		bool added = false;
		for (int j = 0; j < v2.size; i++)
		{
			if (v1.nums[i] == v2.nums[j] && !added)
			{
				u->add(v1.nums[i]);
				added = true;
			}
		}
		i++;
	}
	
	u->print();
}

void Union(Set& v1, Set& v2)
{
	Set *u = new Set(v1);
	int min = u->size;
	if (v2.size < min)
		min = v2.size;
	for (int i = 0; i < v2.size; i++)
	{
		bool duplicate = false;
		for (int j = 0; j < min; i++)
		{
			if (i >= min)
			{
				u->add(v2.nums[i]);
			}else if (v2.nums[i] == u->nums[i])
			{
				duplicate = true;
			}
		}
		if (!duplicate)
		{
			u->add(v2.nums[i]);
		}
	}
	u->print();
}

void Difference(Set& v1, Set& v2)
{
	Set * u;
	int i = 0;
	bool init = false;
	while (i < v1.size && !init)
	{
		bool shared = false;
		for (int j = 0; j < v2.size; i++)
		{
			if (v1.nums[i] == v2.nums[j])
			{
				shared = true;
			}
		}
		if (!shared)
		{
			u = new Set(v1.nums[i]);
			init = true;
		}
		i++;
	}
	while (i < v1.size && init)
	{
		bool shared = false;
		for (int j = 0; j < v2.size; i++)
		{
			if (v1.nums[i] == v2.nums[j])
			{
				shared = true;
			}
		}
		if (!shared)
		{
			u->add(v1.nums[i]);
		}
		i++;
	}

	i = 0;
	while (i < v2.size && !init)
	{
		bool shared = false;
		for (int j = 0; j < v1.size; i++)
		{
			if (v2.nums[i] == v1.nums[j])
			{
				shared = true;
			}
		}
		if (!shared)
		{
			u = new Set(v2.nums[i]);
			init = true;
		}
		i++;
	}
	while (i < v2.size && init)
	{
		bool shared = false;
		for (int j = 0; j < v1.size; i++)
		{
			if (v2.nums[i] == v1.nums[j])
			{
				shared = true;
			}
		}
		if (!shared)
		{
			u->add(v2.nums[i]);
		}
		i++;
	}

	u->print();
}