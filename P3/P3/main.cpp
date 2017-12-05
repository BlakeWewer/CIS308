/**********************************************
* Name: Blake Wewer							  *
* Date: 12/3/17								  *
* Assignment: Project 3: Sets				  *
***********************************************
* The main.cpp file contains the main()		  *
*  method.  It asks the user to input two	  *
*  vectors which are used to create two sets. *
*  The user is then given the option to print *
*  out either their intersection, union,	  *
*  difference, or to quit the program		  *
*  completely.  When one is selected, the	  *
*  sets are placed into a new one according   *
*  to the selected modification and printed   *
*  out onto the console.  Memory is released  *
*  at the end of execution.					  *
***********************************************/

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

	Set * v1 = new Set(1);
	Set * v2 = new Set(1);
	stringstream stream(s);

	int i;
	while (stream >> i)
	{
		v1->add(i);
		if (stream.peek() == ',' || stream.peek() == ' ' || stream.peek() == '(' || stream.peek() == ')')
			stream.ignore();
	}
	v1->sort();

	string s2;
	cout << "Input Vector 2 (like num1,num2,...,numN): ";
	cin >> s2;
	stringstream stream2(s2);

	int j;
	while (stream2 >> j)
	{
		v2->add(j);
		if (stream2.peek() == ',' || stream2.peek() == ' ' || stream2.peek() == '(' || stream2.peek() == ')')
			stream2.ignore();
	}

	v2->sort();

	cout << "\n\n" << "The sorted sets are: " << endl;
	v1->print();
	cout << endl;
	v2->print();
	cout << endl;

	char response;
	cout << "\nEnter (i)ntersect, (u)nion, (d)ifference, or (q)uit: ";
	cin >> response;

	while ((char)toupper(response) != 'Q')
	{
		if ((char)toupper(response) == 'I')
		{
			Intersection(*v1, *v2);
		}
		else if ((char)toupper(response) == 'U')
		{
			Union(*v1, *v2);
		}
		else if ((char)toupper(response) == 'D')
		{
			Difference(*v1, *v2);
		}
		else if ((char)toupper(response) == 'Q')
		{
			break;
		}

		cout << "\n\nEnter (i)ntersect, (u)nion, (d)ifference, or (q)uit: ";
		cin >> response;
	}
	delete v1;
	delete v2;

	return 0;
}

void Intersection(Set& v1, Set&v2)
{
	vector<int> vectU;
	Set * u = new Set(1);
	int i = 0;
	while (i < v1.size)
	{
		for (int j = 0; j < v2.size; j++)
		{
			if ((v1.nums[i] == v2.nums[j]))
			{
				u->add(v1.nums[i]);
			}
		}
		i++;
	}

	cout << "\nIntersection: ";
	u->print();
	delete u;
}

void Union(Set& v1, Set& v2)
{
	Set * u = new Set(1);;
	int min = v1.size;
	if (v2.size < min)
		min = v2.size;
	for (int i = 0; i < v1.size; i++)
	{
		u->add(v1.nums[i]);
	}
	for (int i = 0; i < v2.size; i++)
	{
		u->add(v2.nums[i]);
	}

	cout << "\nUnion: ";
	u->print();
	delete u;
}

void Difference(Set& v1, Set& v2)
{
	Set * u = new Set(1);
	int i = 0;
	while (i < v1.size)
	{
		bool shared = false;
		for (int j = 0; j < v2.size; j++)
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
	while (i < v2.size)
	{
		bool shared = false;
		for (int j = 0; j < v1.size; j++)
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

	cout << "\nDifference: ";
	u->print();
	delete u;
}