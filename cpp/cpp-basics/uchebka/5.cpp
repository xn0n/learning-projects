#include <iostream>
using namespace std;







void main5()
{
	int size = 05;

	int *arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}

	for (int i = 0; i <= size ; i++)
	{
		cout << arr[i] << "\t";		//arr[i] = *(arr + i) || != arr+i
		cout << arr + i << endl;
	}


	delete [] arr;
}