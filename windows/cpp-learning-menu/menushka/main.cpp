#include "Header.h"
//lecture.exe "lecture.txt"

void Creator() {
	CLS;
	cout << "\n  Программу создал хороший человек, Борлаков Амин, студент группы 1бИТС2.\n\n";
	PAUSE;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	SetConsoleTitle(L"Учебный проект по дисциплине \"Технология программирования\" студента Борлакова");
	if (argc > 0) {
		cout << "Аргументы у приложения есть\n";
		for (int i = 1; i < argc; i++) {
			cout << "Аргумент № " << i++ << "  " << argv[i] << endl;
		}
	}

	UCHAR ch = 0;
	do {
		CLS;
		SetColor(0, CL_WHITE);
		cout << "\n\tМеню программы\n";
		
		cout << "0 - Сведения о программисте\n";
	
		cout << "1 - Программы первого семестра\n";

		SetColor(0,CL_BLUE);
		cout << "2 - Программы второго семестра\n";
		
		cout << "L - Лабиринт\n";
		
		cout << "R - Рекурсия\n";
		
		SetColor(0, CL_RED);
		cout << "C - Шифрование\n";

		SetColor(0, CL_RED);
		cout << "S - Сортировка\n";

		SetColor(0, CL_RED);
		cout << "K - Классы\n";
		SetColor(0, CL_WHITE); 
		
		cout << "\n\n Для выхода нажмите ESC\n";
		SetColor(0, CL_WHITE);

		ch = _getch();
		switch (ch) 
		{
		case '0': Creator(); break;
		case '1': FirstTermMenu(); break;
		case '2': SecondTermMenu(); break;
		case 'L': case 'l': case (UCHAR)'Д': case (UCHAR)'д': LabirintMenu(); break;
		case 'R': case 'r': case (UCHAR)'К': case (UCHAR)'к': RecMenu(); break;
		case 'C': case 'c': case (UCHAR)'С': case (UCHAR)'с': CodingMenu(); break;
		case 'S':case 's':case (UCHAR)'Ы':case (UCHAR)'ы':labSort();
		case 'K':case 'k':case (UCHAR)'Л':case (UCHAR)'л':ClassesMenu();
		}
	} while (ch != ESC);

	//system("pause");
	return 0;
}