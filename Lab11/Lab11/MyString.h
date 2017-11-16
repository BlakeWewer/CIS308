#ifndef MYSTRING_H
#define MYSTRING_H
using namespace std;

class MyString {
public:
	char string[100];
	char& operator[](int x);
};

ostream& operator<<(ostream&, const MyString&);
istream& operator>>(istream&, MyString&);

#endif