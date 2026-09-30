#include "Header.h"

//Дружественные методы класса

//Дружественные классы

class Human;
class Apple;

class Human
{

public:
	void TakeApple(Apple& apple);

	void EatApple(Apple& apple)
	{

	}
};



class Apple
{
	friend Human;		//Полная дружественность классов

public:

	static int Count;



	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		Count++;		//Проверка на кол-во вызовов конструктора
	}

private:
	int weight;
	string color;

};

int Apple::Count = 0;




void Human::TakeApple(Apple& apple)		//Реализация функции вынесена, так как по другому выведет ошибку
{
	cout << "\t\tTakeApple\n" << "Вес = " << apple.weight << " Цвет = " << apple.color << endl;
}


int main()
{
	setlocale(LC_ALL, "Rus");




	Apple apple(150, "Red");
	Apple apple2(100, "Green");
	Apple apple3(310, "Yellow");


	cout << apple.Count << endl;		//вместо apple.Count можно вписать и apple2, потому что Count одна на всех

	//А можно и вот так:

	cout << Apple::Count << endl;


	return 0;
}
