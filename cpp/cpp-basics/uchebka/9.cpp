#include "Header.h"




//Конкатенация строк C++
//stringi


void main9()
{
	setlocale(LC_ALL, "RU");
	string str1 = "Борлаков";
	string str2 = "Амин";
	string str3 = "Ахматович";
	string result;


	result = "Фамилия "+ str1 + "\tИмя "+str2+"\tОтчество "+str3;

	cout << result << endl;
}