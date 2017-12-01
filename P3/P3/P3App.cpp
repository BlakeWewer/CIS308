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

void Union(Set&, Set&);

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
			//INTERSECTION
		}
		else if (toupper((*response)) == 'U')
		{
			//UNION
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
/*
void Union(Set& v1, Set& v2)
{
	Set *result = new Set(v1);
	for(int i = 0; i < v2.)
}
*/