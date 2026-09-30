#include <iostream>
#include <string>
using namespace std;


template <typename Diff>

void Swap(Diff &a, Diff &b)
{
	Diff Temperate = a;
	a = b;
	b = Temperate;
}

void main4()
{
	string var1 = "halal", var2 = "haram";

	cout << "var1\t" << var1 << endl;

	cout << "var2\t" << var2 << endl;

	cout << "swap" << endl;

	Swap(var1, var2);

	cout << "var1\t" << var1 << endl;

	cout << "var2\t" << var2 << endl;
}