#include <iostream>
#include <ctime>
using namespace std;


//ASCII symbols

int strLength(const char *str)
{
	int counter = 0;

	while (str[counter] != '\0')
	counter++;
	

	return counter;
	

}

void main8()
{
	setlocale(LC_ALL, "RUS");
	const char* str = {"Абоба"};


	cout << strLength(str) << endl;
}