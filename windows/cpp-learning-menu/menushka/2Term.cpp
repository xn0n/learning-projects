#include "Header.h"
#include <ctime>;
int SecondTermMenu() {
	UCHAR ch = 0;
	do {
		CLS;
		cout << "\nМеню второго семестра\n";
		cout << "\n  1 - Битовая маска\n";
		cout << "\n  2 - Макросы\n";
		cout << "\nДля выхода нажмите ESC\n";

		ch = _getch();
		switch (ch) {
		case '1': BitMask(); break;
		case '2': Makros(); break;
	
		}

	} while (ch != 27);
	return 0;
}



void Makros() {
	CLS;
	cout << "Демонстрация макросов SWAP, MIN, MAX\n";
	cout << "SWAP, LOW, HIGH - Введите A (int), B (short)\n";
	uint a;
	ushort b;
	cout << "\n\nВвведите целочисленное значение A: ";
	cin >> a;

	cout << "Ввведите целочисленное значение B: ";
	cin >> b;
	cout << "A = " << a << endl;
	cout << "B = " << b << endl << endl;

	cout << "A = " << setfill('0') << setw(8) << hex << a << endl;
	cout << "B = " << setfill('0') << setw(4) << hex << b << endl << endl;

	cout << "A (LOW) = " << setfill('0') << setw(4) << hex << (b & 0xFFFF) << endl;
	cout << "A (HIGH) = " << setfill('0') << setw(4) << hex << (a & 0xFFFF) << endl;

	a = SWAP(a);
	b = SWAP(b);
	cout << "После SWAP'examples/local-input.txt";
	cout << "A = " << a << endl;
	cout << "B = " << b << endl << endl;
	cout << "A = " << setfill('0') << setw(8) << hex << a << endl;
	cout << "B = " << setfill('0') << setw(4) << hex << b << endl << endl;

	cout << "MIN Введите A и B (float):\n";
	float c, d;
	cin >> c >> d;
	cout << "\nМинимальное - " << min(c, d) << endl;

	cout << "\n\nMAX - Введите A и B (float):\n";
	cin >> c >> d;
	cout << "\nМаксимальное - " << max(c, d) << endl;

	PAUSE;

}

void BitMask() {
	CLS;
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	cout << "Задание:\nВывести числа, которые удовлетворяют маске " << endl;
	int i, a[ROWS], mask;
	cout << endl;
	cout << "Исходный массив заполненный случайными числами:" << endl;
	for (int i = 0; i < ROWS; i++)
	{
		a[i] = 100 + rand() % 32500;
		cout << a[i] << " ";
	}
	cout << "\n\n";
	cout << "Введите битовую маску - "; cin >> mask;
	cout << "Ответ:" << endl;
	for (int i = 0; i < ROWS; i++)
	{
		if ((a[i] & mask) == mask)
		{
			cout << a[i] << "\t";
		}

	}
	cout << "\n\nНажмите любую клавишу для продолжения..";
	_getch();
	CLS;
}

