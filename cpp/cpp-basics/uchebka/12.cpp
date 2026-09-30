#include "Header.h"
#define DEBUG 5

													//Условная компиляция
													// компиляция #ifdef, #endif, #else, #ifndef

void main12()
{
	setlocale(LC_ALL, "");

#if DEBUG

	cout << "cout 1" << endl;
#else
	cout << "cout 2" << endl;

#endif //DEBUG

}