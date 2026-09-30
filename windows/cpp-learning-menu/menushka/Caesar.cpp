#include "Caesar.h"
#include "MyFunction.h"

COCOJUMBO nCode = CD_Caesar;
char TextCode[128]{ "Школа"},
	TextCoding[128]{ "Школа"};
int Limit = 1;


void CodingMenu() {
	uchar ch = 0;
	do {
		system("cls");
		SetColor(0, CL_RED);
		cout << "Меню \nКодирования текста\n";
		SetColor(0, CL_LIGHT_RED);
		cout << "1) Метод \"Цезаря\"\n";
		SetColor(0, CL_YELLOW);
		cout << "2) Динамическое кодирование\n";
		SetColor(0, CL_GREEN);
		cout << "3) Бинарное кодирование\n";
		SetColor(0, CL_LIGHT_BLUE);
		cout << "0) Декодирование\n";
		SetColor(0, CL_BLUE);
		cout << "4) Определить строку кодирования\n";
		SetColor(0, CL_PURPLE);
		cout << "5) Отбразить текст для шифрования\n";
		SetColor(0, CL_WHITE);
		cout << "6) Отобразить шифрованный текст\n";
		SetColor(0, CL_LIGHT_RED);
		cout << "\n\nДля выхода нажмите клавишу ESC\n\n";
		SetColor(0, CL_RED);

		ch = _getch();

		switch (ch) 
		{
		case '1':Coding(); break;
		case '2':Dynamic(); break;
		case '3':BitCoding(); break;
		case '0':Decoding(); break;
		case '4':
			CLEAR;
			
			cout << "Введите текст для шифрования\n=> ";
			cin.getline((char*)TextCode, 128);
			break;
		case '5':
			CLEAR;
			
			cout << "\n=>";
			
			cout << TextCode << endl;
			PAUSE;
			break;
		case '6':
			CLEAR;
			
			cout << "Шифрованный текст\n=> ";
			
			cout << TextCoding << endl;
			PAUSE;
			break;
		}
	} while (ch != 27);
}

void Coding() {
	nCode = CD_Caesar;
	TextCoding[0] = 0;
	CLEAR;

	SetColor(0,CL_RED);
	cout << "Кодирование текста методом \"Цезаря\"\n\n";
	SetColor(0, CL_WHITE);
	
	cout << "Текст для шифрования => ";
	SetColor(0, CL_WHITE);
	cout << TextCode << endl;
	SetColor(0, CL_WHITE);
	cout << "На сколько символов смещать шифр?\n=> "; SetColor(0, CL_WHITE); cin >> Limit;

	for (int i = 0; i < strlen(TextCode); i++) {
		UCHAR ch = TextCode[i], cch = 0;
		UCHAR bc = 'А', ec = 'я', chE = 'Ё', che = 'ё';
		UCHAR bbc = 'A', eec = 'z';
		if (ch >= bc && ch <= ec) {
			cch = bc + (ch + Limit - bc) % (ec - bc + 1);
			TextCoding[i] = cch;
		}
		else if (ch >= bbc && ch <= eec) {
			cch = bbc + (ch + Limit - bbc) % (eec - bbc + 1);
			TextCoding[i] = cch;
		}
		else if (ch == chE) {
			TextCoding[i] = '#';
		}
		else if (ch == che) {
			TextCoding[i] = '*';
		}
		else if (ch == ' ') TextCoding[i] = ch;
	}
	TextCoding[strlen(TextCode)] = 0;
	cout << "Результат кодирования или декодирования => " << TextCoding << endl << endl;
	PAUSE;
}

void Decoding() {
	CLEAR;
	switch (nCode) {

	case CD_Caesar:

		for (int i = 0; i < strlen(TextCoding); i++)
		{
			uchar ch = TextCoding[i], cch = 0;
			uchar bc = 'А', ec = 'я', chE = 'Ё', che = 'ё';
			uchar bbc = 'A', eec = 'z';
			if (ch >= bc && ch <= ec) {
				cch = (ch - Limit < bc) ? ec - (bc - (ch - Limit + 1)) : ch - Limit;
				TextCoding[i] = cch;
			}
			else if (ch >= bbc && ch <= eec) {
				Limit = i + 1;
				cch = (ch - Limit < bbc) ? eec - (bbc - (ch - Limit + 1)) : ch - Limit;
				TextCoding[i] = cch;
			}
			else if (ch == '#') {
				TextCoding[i] = chE;
			}
			else if (ch == '*')
			{
				TextCoding[i] = che;
			}
			else TextCoding[i] = ch;
		}

		cout << "Результат кодирования или декодирования =>" << TextCoding << endl << endl;
		PAUSE;
		break;
	case CD_Dynamic:
		for (int i = 0; i < strlen(TextCoding); i++)
		{
			uchar ch = TextCoding[i], cch = 0;
			uchar bc = 'А', ec = 'я', chE = 'Ё', che = 'ё';
			uchar bbc = 'A', eec = 'z';
			if (ch >= bc && ch <= ec) {
				Limit = i + 1;
				cch = (ch - Limit < bc) ? ec - (bc - (ch - Limit + 1)) : ch - Limit;
				TextCoding[i] = cch;
			}
			else if (ch >= bbc && ch <= eec) {
				Limit = i + 1;
				cch = (ch - Limit < bbc) ? eec - (bbc - (ch - Limit + 1)) : ch - Limit;
				TextCoding[i] = cch;
			}
			else if (ch == '#') {
				TextCoding[i] = chE;
			}
			else if (ch == '*')
			{
				TextCoding[i] = che;
			}
			else TextCoding[i] = ch;
		}
		cout << "Результат кодирования или декодирования =>" << TextCoding << endl << endl;
		PAUSE;
		break;
	case CD_Bit:
		BitCoding(false);
		break;
	}
}


void Dynamic() {
	nCode = CD_Dynamic;
	TextCoding[0] = 0;

	CLEAR;
	SetColor(0, CL_RED);
	cout << "Кодирование текста методом \"Цезаря с динамическим смещением\"\n\n";
	SetColor(0, CL_WHITE);
	cout << "Текст для шифрования => ";
	cout << TextCode << endl;

	strcpy_s(TextCoding, TextCode); // Копирование исходного текста в массив TextCoding

	for (int i = 0; i < strlen(TextCoding); i++) {
		uchar ch = TextCoding[i], cch = 0;
		uchar bc = 'А', ec = 'я', chE = 'Ё', che = 'ё';
		uchar bbc = 'A', eec = 'z';
		if (ch >= bc && ch <= ec) {
			Limit = i + 1;
			cch = (ch - Limit < bc) ? ec - (bc - (ch - Limit + 1)) : ch - Limit;
			TextCoding[i] = cch;
		}
		else if (ch == chE) {
			TextCoding[i] = '#';
		}
		else if (ch == che) {
			TextCoding[i] = '*';
		}
		else if (ch >= bbc && ch <= eec) {
			Limit = i + 1;
			cch = bbc + (ch + Limit - bbc) % (eec - bbc + 1);
			TextCoding[i] = cch;
		}
		else TextCoding[i] = ch;
	}
	TextCoding[Limit] = '\0';
	CLEAR;
	cout << "Результат кодирования или декодирования =>" << TextCoding << endl << endl;
	PAUSE;
}


void BitCoding(bool pToLeft) {
	nCode = CD_Bit;

	CLEAR;
	int nLen = strlen(TextCoding);
	UCHAR sbit = 0;
	switch (pToLeft) {
	case true:
		sbit = TextCoding[0] & 0x80;
		for (int i = 0; i < nLen - 1; i++) {
			TextCoding[i] <<= 1;
			TextCoding[i] |= ((UCHAR)TextCoding[i + 1] & 0x80) >> 7;
		}
		TextCoding[nLen - 1] <<= 1;
		TextCoding[nLen - 1] |= sbit >> 7;
		break;
	case false:
		sbit = TextCoding[nLen - 1] & 0x01;
		for (int i = nLen - 1; i > 0; i--) {
			TextCoding[i] = (UCHAR)TextCoding[i] >> 1;
			TextCoding[i] |= (TextCoding[i - 1] & 0x01) << 7;
		}
		TextCoding[0] = (UCHAR)TextCoding[0] >> 1;
		TextCoding[0] |= sbit << 7;
		break;
	}
	cout << "Результат кодирования или декодирования => " << TextCoding << endl << endl;
	PAUSE;
}