#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	const short N = 20;
	const short MIN = 100;
	const short MAX = 32500;

	setlocale(LC_ALL, "RUSSIAN");
	cout << "Автор: студент группы 1бИТС2 Борлаков Амин" << endl;
	srand(time(NULL));
	int i;
	int arr[N];
	int mask;
	cout << "Исходный массив:" << endl;
	for (int i = 0; i < N; i++)
	{
		arr[i] = MIN + rand() % MAX;
		cout << arr[i] << endl;
	}
	cout << "\nВведите битовую маску: ";
	cin >> mask;
	for (int i = 0; i < N; i++)
	{
		if ((arr[i] & mask) == mask)
		{
			cout << "Число " << arr[i] << " соответствует битовой маске " << mask << endl;
		}
		else if ((arr[i] & mask) != mask)
		{
			cout << "Число " << arr[i] << " несоответствует битовой маске " << mask << endl;
		}
	}
	return 0;
}

