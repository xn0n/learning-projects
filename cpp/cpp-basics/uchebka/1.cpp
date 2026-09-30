#include <iostream>
using namespace std;






void Foo(int* pa, int* pb)
{
	(*pa) = (*pa) + (*pb);
	(*pb) = (*pa) - (*pb);
	(*pa) = (*pa) - (*pb);
}

void main1()
{
	int a = 5;
	int b = 21;
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	Foo(&a, &b);
	cout << "magic trick:" << endl;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}
