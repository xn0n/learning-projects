#include "Header.h"


//Как вынести реализацию метода из класса

class MyClass
{
public:
	MyClass();

	~MyClass();

	void PrintMessage();

private:

};

//Нужно выносить метод из класса для того, чтобы разбивать большие методы, не путаясь в коде. Или создать видимость одного класса для другого.

MyClass::MyClass()		//Вынесли конструктор из класса
{
}

void MyClass::PrintMessage()		//Вынесли метод из класса
{
		cout << PI << endl;
}

MyClass::~MyClass()		//Вынесли деструктор из класса
{
}

int main16()
{
	setlocale(LC_ALL, "Rus");

	MyClass a;
	a.PrintMessage();


	return 0;
}