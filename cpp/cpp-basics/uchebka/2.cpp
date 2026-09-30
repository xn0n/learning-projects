#include <iostream>
using namespace std;

void Swap(int *a, int *b)
{
	int Temperate = *a;
	*a = *b;
	*b = Temperate;
}
void main2()
{
	int var1 = 24, var2 = 41;

	cout << "var1\t" << var1 << endl;

	cout << "var2\t" << var2 << endl;

	cout << "swap" << endl;

	Swap(&var1, &var2);

	cout << "var1\t" << var1 << endl;

	cout << "var2\t" << var2 << endl;
}