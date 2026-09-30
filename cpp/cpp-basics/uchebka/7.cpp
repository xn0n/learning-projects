#include <iostream>
#include <ctime>

using namespace std;

void FillArray(int* const arr, const int size)
{

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
	}
}




void ShowArray(const int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}




void push_back(int *&arr, int &size,const int value)
{
	int* newArray = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}

	newArray[size] = value;

	size++;

	delete[] arr;

	arr = newArray;

}




void pop_back(int*& arr, int& size)
{
	size--;

	int* newArray = new int[size];

	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}

	delete[] arr;

	arr = newArray;
}





void main7()
{
	int size = 7;
	int* arr = new int[size];

	FillArray(arr, size);
	ShowArray(arr, size);

	push_back(arr, size, 123);
	ShowArray(arr, size);

	pop_back(arr, size);
	ShowArray(arr, size);





	delete[] arr;
}