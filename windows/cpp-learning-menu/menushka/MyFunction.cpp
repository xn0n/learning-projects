#include "Header.h"

void SetColor(int pnColorBackground, int pnColorText) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)(((pnColorBackground & 0x000F) << 4) | (pnColorText & 0x000F)));
}

void SetColor(int pnColor) {
	SetColor(pnColor, pnColor);

}

void SetCursor(short int pnRow, short int pnCol) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position{ pnCol, pnRow };

	SetConsoleCursorPosition(hStdOut, position);

}

void ClearScreen() {

	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count;
	DWORD cellCount;
	COORD homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	SetConsoleCursorPosition(hStdOut, homeCoords);

	// Получить количество ячеек в текущем буфере //
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Заполните весь буфер пробелами */
	if (!FillConsoleOutputCharacterA(hStdOut, ' ', cellCount, homeCoords, &count)) return;

	/* Заполните весь буфер текущими цветами и атрибутами */
	if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) return;

	/* Переместите курсор домой */
	SetConsoleCursorPosition(hStdOut, homeCoords);

}

string GetFName(string ptext) {
	if (ptext.empty()) return "";

	string text{ "   " };
	int npos = ptext.find('=');
	if (npos > 0) {
		char* ctext = new char[42] { 0 };
		ptext.copy(ctext, npos);
		text = ctext;
		delete[] ctext;
		return text;
	}
	return ptext;
}

int GetValueInt(string ptext) {
	if (ptext.empty()) return 0;
	int npos = ptext.find('='),
		nval = atoi(ptext.substr(npos + 1).c_str());
	return nval;
}