#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include "lab10.h"
using namespace std;

template <class T>
class MyArray {
	private: 
		
	public: 
		T vArray[4];
		void initArray(MyArray<T>&a);
		void print(void) const;
};

template<class T>
void MyArray<T>::initArray(MyArray<T>&a)
{
	for (int i = 0; i < 4; i++)
	{
		cin >> a.vArray[i];
	}
}

template<class T>
void MyArray<T>::print(void) const
{
	cout << "You Entered: ";
	for(int i = 0; i < 4; i++)
	{
			cout << vArray[i] << " ";
	}
}

int main()
{
	MyArray<int> arrayOfInt;
	MyArray<string> arrayOfStrings;
	char result;
	cout << ("Would you like to enter an [I]nteger or a [S]tring?: ");
	cin >> result;
	result = toupper(result);
	
	if (result == 'I')
	{
		cout << "Enter four integers: ";
		arrayOfInt.initArray(arrayOfInt);
		arrayOfInt.print();
	}else if (result == 'S')
	{
		cout << "Enter four strings: ";
		arrayOfStrings.initArray(arrayOfStrings);
		arrayOfStrings.print();
	}
	else {
		cout << "Value not valid";
	}
	scanf_s(" ");
	return 0;
}



