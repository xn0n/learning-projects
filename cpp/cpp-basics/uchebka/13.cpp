#include "Header.h"
//#define UNARBINAR
//тернарный оператор





void main13()
{
	setlocale(LC_ALL, "RUS");
#ifdef UNARBINAR
	int a = 5;	//
	a++;		//унарная операция

	int b = 6;	//
	a + b;		//бинарная операция
#endif

	int a;
	cout << "Введите значение переменной А" << endl;
	cin >> a;


	if (a < 10)
	{
		cout << "A меньше 10" << endl;	//(a < 10) ? (cout << "A меньше 10") << endl
	}
	else if(a>10)
	{
		cout << "А больше 10" << endl;	//cout << ("А больше 10") << endl
	}
	else
	{
		cout << "А равна 10" << endl;	//cout << "А равна 10" << endl;
	}



	(a < 10) ? cout << "A меньше 10" << endl : (a > 10) ? cout << "А больше 10" << endl : cout << "А равна 10" << endl;
}