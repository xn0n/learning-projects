#include <iostream>
using namespace std;

void Foo(int a)
{
	a = 12;
}

void Foo1(int& a)
{
	a = 9;
}

void Foo2(int* a)
{
	*a = 8;
}

void main3()
{
	int value = 5;

	cout << "value = " << value << endl << endl;

	cout << "Foo" << endl;
	Foo(value);
	cout << "value = " << value << endl << endl;


	cout << "Foo1" << endl;
	Foo1(value);
	cout << "value = " << value << endl << endl;


	cout << "Foo2" << endl;
	Foo2(&value);
	cout << "value = " << value << endl << endl;

}