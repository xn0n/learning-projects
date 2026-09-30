#include <iostream>
#include <ctime>
using namespace std;
#define rows строчка
#define cols колонка







void main6()
{
	setlocale(LC_ALL, "RUS");
	srand(0);
	int rows = 5;
	int cols = 10;
	cout << "enter rows count" << endl;
	cin >> rows;
	cout << "enter cols count" << endl;
	cin >> cols;
	cout << "\n\n\n";
	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	//заполнение данными
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 2;
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}




	for (int i = 0; i < строчка; i++)		//удаляем второй массив(колонки)
	{
		delete[] arr[i];
	}

	

	delete[] arr;		//удаляем первый массив(строчки)
}