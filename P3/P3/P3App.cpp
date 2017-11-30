#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include "Set.h"
using namespace std;

string StringCorrect(string);
int[] splitString(int[], string);

int main()
{
	string s;
	cout << "Input Vector 1 (like num1, num2, ..., numN): ";
	cin >> s;

	s = StringCorrect(s);
	int v1Array[] = ;
}

string StringCorrect(string in)
{
	if (in[0] == '(')
		in = in.substr(1);
	if (in[in.length - 1] == '(')
		in = in.substr(0, in.length - 1);
	return in;
}

int[] splitString(int vArray[], string in)
{

}