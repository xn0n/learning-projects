#include "Header.h"


//указатель на функции C++
//тип функции(*имя указателя)(спецификация параметров)


string GetDataFromBD()
{
	return "Data From BD";
}

string GetDataFromWebServer()
{
	return "Data From WebServer";
}

string GetDataFromAstral()
{
	return "Data From Astral";
}

void ShowInfo(string (*foo)())
{
	cout << foo() << endl;
}

void main10()
{
	ShowInfo(GetDataFromBD);
}