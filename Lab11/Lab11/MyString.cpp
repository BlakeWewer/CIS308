#include <iostream>
#include <stdio.h>
#include "MyString.h"
using namespace std;

char& MyString::operator[](int x)
{
	return this->string[x];
}

ostream& operator<<(ostream& out, const MyString& StrObj) {
	out << StrObj.string;
	return out;
}
istream& operator >> (istream& in, MyString& StrObj) {
	in >> StrObj.string;
	return in;
}

int main()
{
	MyString string;
	char result;
	cout << ("Enter a string: ");
	cin >> string;
	
	string[0] = 'B';

	cout << string;

	scanf_s(" ");

	return 0;
}


