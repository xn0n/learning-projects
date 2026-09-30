#include "labirint.h"

const int nL = 32;
const int nC = 32;
UINT map[32] = {
0b10111111111111111111111111111111,
0b10100000000000000000010001000111,
0b10101011011010111101010101010111,
0b10001011010010111101010101010111,
0b10111111010110111101000100010111,
0b10100000010110111101111111110111,
0b10001011110110000000000000000011,
0b11111010000111111111111111111011,
0b10011011111100001000100000000011,
0b10100010001111101010001111111111,
0b10101100100000001011111100010011,
0b10001101111110100011000101000111,
0b11101100000000111100010101111111,
0b11101111101110000101110001111111,
0b11100011101111110000111111110001,
0b11111011101100001110111000000101,
0b11010001101101100000001010111101,
0b11010101101100011111101111111101,
0b11010100101001110001100000000001,
0b11000110101101100101111111111111,
0b11010110000000001101000110001111,
0b11000110101001100000010110101111,
0b11011110111011101111110000100011,
0b11000000000011101111111111111011,
0b11111111111011000000000000000001,
0b11110000000011011111111111111101,
0b10000110101100000001000000011101,
0b11110010100001111101111101000001,
0b11011010001100010001000001111111,
0b11001011101111010111011111000001,
0b11100010001000010001000000011101,
0b11111111111111111111111111111101
},

	win[32] = {
	0b10111111111111111111111111111111,
	0b10100000000000000000010001000111,
	0b10101011011010111101010101010111,
	0b10001011010010111101010101010111,
	0b10111111010110111101000100010111,
	0b10100000010110111101111111110111,
	0b10001011110110000000000000000011,
	0b11111010000111111111111111111011,
	0b10011011111100001000100000000011,
	0b10100011111111111111111111111111,
	0b10001001000000000000000010010011,
	0b11010111001010011001001011101011,
	0b10010111001010100101001011101001,
	0b10101111000100100101001011110101,
	0b10101111000100011000110011110101,
	0b10101111000000000000000011110101,
	0b10101111000000000000000011110101,
	0b10101111010101001001001011110101,
	0b10010111010101000001101011101001,
	0b11010111010101001001011011101001,
	0b11001001001010001001001010010101,
	0b11000101000000000000000010100001,
	0b11010011111111111111111111011011,
	0b11010100110000000000001100000011,
	0b10010101001110000001110001110111,
	0b10110000100001111110001011000001,
	0b10000110101100000001000000011101,
	0b11110010100001111101111101000001,
	0b11011010001100010001000001111111,
	0b11001011101111010111011111000001,
	0b11100010001000010001000000011101,
	0b11111111111111111111111111111101 },
	mapl[nL]{ 0 },				// лабиринт с освещением 1-да, 0-нет
	* nMov = 0,
	nbit = 0b1000'0000'0000'0000'0000'0000'0000'0000;
int nSRow = 0, nSCol = 1;			// вход
int nERow = 31, nECol = 30;			// выход
int nRow = nSRow, nCol = nSCol;		// текущая позиция жука в лабиринте
const int P1y = 8, P1x = 5, P2y = 7, P2x = 10;		// портал one
const int P3y = 12, P3x = 19, P4y = 25, P4x = 19;	// портал two
bool SetLight = false,				//проверяет режим фонаря вкл или выкл
ext = false,					//проверяет аварийный выход
SetRoute = false,				//проверяет режим поиска маршрута
SetPortal = false;				//проверяет режим порталов


int LabirintMenu() {
	UCHAR ch = 0;
	do {
		CLS;
		cout << "\n\tМеню лабиринта\n";
		cout << "\n  L - Играть\n";
		cout << "\n  1 - Режимы игры\n";
		cout << "\n  2 - Таблица результатов\n";
		cout << "\n  3 - Управление\n";

		cout << "\nДля выхода нажмите ESC\n";
		ch = _getch();
		switch (ch) {
		case 228: case 0: case 108: Labirint(); break;			// 'L'
		case '1': Gamemode(); break;
		case '2': Res(); break;
		case '3': Help(); break;
		}
	} while (ch != ESC);
	return 0;
}

int Route(int pnRow, int pnCol) {
	int nRes = 0;
	SetColor(CL_WHITE);
	SetCursor(pnRow, pnCol * 2);
	cout << "  ";

	nMov[pnRow] |= nbit >> pnCol;
	if ((pnRow == nERow) && (pnCol == nECol)) return 99;

	if (pnRow - 1 >= 0) {		//up
		if (!(map[pnRow - 1] & (nbit >> pnCol)) && !(nMov[pnRow - 1] & (nbit >> pnCol))) {
			nRes = Route(pnRow - 1, pnCol);
			if (nRes) return nRes;
		}
	}
	if (pnCol + 1 <= nC) {		//left
		if (!(map[pnRow] & (nbit >> (pnCol + 1))) && !(nMov[pnRow] & (nbit >> (pnCol + 1)))) {
			nRes = Route(pnRow, pnCol + 1);
			if (nRes) return nRes;
		}
	}
	if (pnCol - 1 >= 0) {		//right
		if (!(map[pnRow] & (nbit >> (pnCol - 1))) && !(nMov[pnRow] & (nbit >> (pnCol - 1)))) {
			nRes = Route(pnRow, pnCol - 1);
			if (nRes) return nRes;
		}
	}
	if (pnRow + 1 <= nL) {		//down
		if (!(map[pnRow + 1] & (nbit >> pnCol)) && !(nMov[pnRow + 1] & (nbit >> pnCol))) {
			nRes = Route(pnRow + 1, pnCol);
			if (nRes) return nRes;
		}
	}
	SetCursor(pnRow, pnCol * 2);
	SetColor(CL_YELLOW);
	cout << "  ";

	return 0;
}

void SetLightMap(int pnRow, int pnCol) {			//свет фонаря
	for (int i = pnRow - 2; i <= pnRow + 2; i++) {
		for (int j = pnCol - 2; j <= pnCol + 2; j++)
			if ((i >= 0) && (j >= 0) && (i < nL) && (j < nC))
				(mapl[i] |= (nbit >> j));
	}
}

int Labirint() {
	CLS;

	// set cursore atributes info
	// после отработки восстановить
	if (SetLight)
		SetLightMap(nSRow, nSCol);

	UCHAR ch = 0;
	SetCursor(0, 0);
	nRow = nSRow;
	nCol = nSCol;
	double elapsed_time;

	for (int i = 0; i < nL; i++) {
		for (int j = 0; j < nC; j++) {
			if (map[i] & (nbit >> j)) {
				SetColor(CL_BLACK);
				cout << "00";
			}
			else {
				if ((i == nRow) && (j == nCol)) {
					SetColor(CL_LIGHT_BLUE);
					cout << "ЖЖ";
				}
				else {
					if (SetLight) {
						SetColor(CL_BLACK);
						cout << "  ";
					}
					else {
						SetColor(CL_YELLOW);
						cout << "  ";
					}
				}
			}
		}
		cout << endl;
	}


	clock_t start_time = clock();		//начало отсчета времени

	do {
		if (SetLight) {
			for (int i = nRow - 2; i <= nRow + 2; i++) {							//фонарь
				for (int j = nCol - 2; j <= nCol + 2; j++) {
					if ((i >= 0) && (j >= 0) && (i < nL) && (j < nC) && (mapl[i] & (nbit >> j))) {
						SetCursor(i, j * 2);
						if (map[i] & (nbit >> j)) {
							SetColor(CL_BLACK);
							cout << "00";
						}
						else {
							SetColor(CL_YELLOW);
							cout << "  ";
						}
					}
				}
			}
		}

		SetCursor(0, 1 * 2); SetColor(CL_GREEN, CL_LIGHT_WHITE); cout << "СТ";		//цвет входа
		SetCursor(31, 30 * 2); SetColor(CL_RED, CL_LIGHT_WHITE); cout << "ФИ";		//цвет выхода

		if (SetPortal) {
			SetCursor(P1y, P1x * 2); SetColor(CL_BLACK, CL_RED); cout << "()";			//портал 1	
			SetCursor(P2y, P2x * 2); SetColor(CL_BLACK, CL_RED); cout << "()";

			SetCursor(P3y, P3x * 2); SetColor(CL_BLACK, CL_RED); cout << "()";			//портал 2
			SetCursor(P4y, P4x * 2); SetColor(CL_BLACK, CL_RED); cout << "()";
		}


		SetCursor(nRow, nCol * 2); SetColor(CL_PURPLE); cout << "ЖЖ";				//цвет жука		

		ch = _getch();
		SetColor(CL_WHITE); SetCursor(nRow, nCol * 2); cout << "  ";				//заливка за жуком

		switch (ch) {

		case 0: case 224: {
			ch = _getch();
			switch (ch) {
			case 63:					//F5
				if (SetRoute) {
					nMov = new UINT[nL];				//выделить память кучи
					memset(nMov, 0, sizeof(UINT) * nL);	//заполнить нулями
					Route(nRow, nCol);
					delete[] nMov;
				}
				break;
			case 72:					//up
				if ((nRow == 0) || (map[nRow - 1] & (nbit >> nCol)))
					Beep(750, 300);
				else
					nRow--;
				break;
			case 75:					//left
				if ((nCol == 0) || (map[nRow] & (nbit >> (nCol - 1))))
					Beep(750, 300);
				else
					nCol--;
				break;
			case 77:					//right
				if ((nCol + 1 == nC) || (map[nRow] & (nbit >> (nCol + 1))))
					Beep(750, 300);
				else
					nCol++;
				break;
			case 80:					//down
				if ((nRow + 1 == nL) || (map[nRow + 1] & (nbit >> nCol)))
					Beep(750, 300);
				else
					nRow++;
				break;
			default:
				break;
			}
		}break;

		default:
			break;
		}
		if (SetLight)
			SetLightMap(nRow, nCol);
		if (SetPortal) {
			if ((nRow == P1y) && (nCol == P1x))					//работа порталов
				nRow = P2y, nCol = P2x;
			if ((nRow == P3y) && (nCol == P3x))
				nRow = P4y, nCol = P4x;
		}

	} while (!((nRow == nERow) && (nCol == nECol)) && (ch != ESC));

	SetCursor(nL + 3, 0);
	SetColor(CL_BLACK, CL_LIGHT_WHITE);
	if (ch == 27) {
		cout << "\t\t\tАВАРИЙНЫЙ ВЫХОД\n";
		cout << "\t\tНажмите любую клавишу для выхода в меню\n";

	}
	else {
		Win();
		cout << "\t\tПоздравляю, вы дошли до конца лабиринта!!!\n";
		ext = true;
		elapsed_time = double(clock() - start_time) / CLOCKS_PER_SEC;
		cout << "\t\tЗатраченное время: " << elapsed_time << " сек.\n";
		cout << "\t\tНажмите любую клавишу для выхода в меню\n";

	}

	if (ext) {
		fstream records("res.txt", ios_base::app);			//запись времени в файл txt
		records << elapsed_time << endl;
		records.close();
	}
	ext = false;											//возвращаем значение по умолчанию
	SetColor(CL_BLACK);
	PAUSE;
	SetColor(CL_BLACK, CL_LIGHT_WHITE);
	return 0;
}

int Win() {
	CLS;
	int x = 0, y = 0;
	for (int i = 0; i < nL; i++) {
		for (int j = 0; j < nC; j++) {
			if (((x > 6) && (x < 25)) && ((y > 8) && (y < 23))) {
				if (win[i] & (nbit >> j)) {
					SetColor(CL_LIGHT_BLUE);
					cout << "00";
				}
				else {
					SetColor(CL_LIGHT_WHITE);
					cout << "  ";
				}
			}
			else {
				if (win[i] & (nbit >> j)) {
					SetColor(CL_BLACK);
					cout << "00";
				}
				else {
					SetColor(CL_YELLOW);
					cout << "  ";
				}
			}
			x++;
		}
		x = 0;
		y++;
		cout << endl;
	}
	SetColor(CL_BLACK, CL_LIGHT_WHITE);
	return 0;
}

void Help() {
	CLS;
	cout << "\n\tУправление в игре:\n\n";
	SetCursor(3, 2);
	SetColor(CL_YELLOW);
	cout << "  ";
	SetColor(CL_BLACK, CL_LIGHT_WHITE);
	cout << "  - проход\n\n";
	SetCursor(5, 2);
	SetColor(CL_BLACK);
	cout << "00";
	SetColor(CL_BLACK, CL_LIGHT_WHITE);
	cout << "  - стена\n\n";
	SetCursor(7, 2);
	SetColor(CL_BLUE);
	cout << "ЖЖ";
	SetColor(CL_BLACK, CL_LIGHT_WHITE);
	cout << "  - жук\n\n";
	SetCursor(9, 2);
	SetColor(CL_BLACK, CL_RED);
	cout << "()";
	SetColor(CL_BLACK, CL_LIGHT_WHITE);
	cout << "  - портал\n\n";

	cout << "  <   - движение влево\n\n";
	cout << "  >   - движение вправо\n\n";
	cout << "  ^   - движение вверх\n\n";
	cout << "  v   - движение вниз\n\n";
	cout << "  F5   - поиск маршрута\n\n";

	PAUSE;
}

int Gamemode() {
	UCHAR ch = 0;
	do {
		CLS;
		cout << "\n\tРежимы игры";
		cout << "\n\n  1 - ФОНАРЬ\t";
		if (SetLight) cout << "(ВКЛ)"; else cout << "(ВЫКЛ)";
		cout << "\n\n  2 - МАРШРУТ\t";
		if (SetRoute) cout << "(ВКЛ)"; else cout << "(ВЫКЛ)";
		cout << "\n\n  3 - ПОРТАЛЫ\t";
		if (SetRoute) cout << "(ВКЛ)"; else cout << "(ВЫКЛ)";
		cout << "\n\n\nДля выхода нажмите ESC\n";
		ch = _getch();
		switch (ch) {
		case '1':
			do {
				CLS;
				cout << "\n\tФОНАРЬ\t";
				if (SetLight) cout << "(ВКЛ)"; else cout << "(ВЫКЛ)";
				cout << "\n\n*Вокруг персонажа освещается пространство 4х4 клетки,\nостальная часть карты исследуется по мере прохождения лабиринта\n";
				cout << "\n\t1 - ВКЛ / 0 - ВЫКЛ\n";
				ch = _getch();
				switch (ch) {
				case '1': SetLight = true; break;
				case '0': SetLight = false; break;
				}
			} while (ch != ESC);
			ch = 0;
			break;
		case '2':
			do {
				CLS;
				cout << "\n\tМАРШРУТ\t";
				if (SetRoute) cout << "(ВКЛ)"; else cout << "(ВЫКЛ)";
				cout << "\n\n*Программа строит маршрут от текущей позиции персонажа до выхода,\nи выделяет его цветом\n";
				cout << "\n\t1 - ВКЛ / 0 - ВЫКЛ\n";
				ch = _getch();
				switch (ch) {
				case '1': SetRoute = true; break;
				case '0': SetRoute = false; break;
				}
			} while (ch != ESC);
			ch = 0;
			break;
		case '3':
			do {
				CLS;
				cout << "\n\tПОРТАЛЫ\t";
				if (SetPortal) cout << "(ВКЛ)"; else cout << "(ВЫКЛ)";
				cout << "\n\n*Встав на клетку портала, персонаж перемещается\nв другое место на карте, отмеченное знаком портала\n";
				cout << "\n\t1 - ВКЛ / 0 - ВЫКЛ\n";
				ch = _getch();
				switch (ch) {
				case '1': SetPortal = true; break;
				case '0': SetPortal = false; break;
				}
			} while (ch != ESC);
			ch = 0;
			break;
		}
	} while (ch != ESC);
	return 0;
}

int Res() {
//	UCHAR ch = 0;
//	do {
//		CLS;
//		int n = 40;
//		char maxRec = 0;
//		cout << "\n\tТАБЛИЦА РЕЗУЛЬТАТОВ\n";
//		ifstream records;
//		records.open("res.txt", ofstream::app);
//		if (!records.is_open())
//			cout << "Ошибка открытия файла";
//		while (!records.eof()) {
//			if (records > maxRec)
//				maxRec = records;
//		}
//		cout << maxRec;
//		/*for (int j = 0; j < n; j++)
//			cout << "_";
//		for (int i = 1; i <= 5; i++) {
//			cout << i << setw(3) << "|" << 
//		}*/
//		ch = _getch();
//		records.close();
//	} while (ch != ESC);
return 0;
}
