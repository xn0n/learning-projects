#include "Header.h"

//Дружественные методы класса

//Дружественные классы

//static что это

//Статические методы класса

//Вложенные классы

//Массив объектов класса

//Что такое агрегация и композиция

//Наследование в ООП

//Спецификаторы доступа при наследовании

//Порядок вызова конструкторов при наследовании

//Порядок вызова деструктора при наследовании

//class Human
//{
//
//public:
//	void TakeApple(Apple& apple);
//
//	void EatApple(Apple& apple)
//	{
//		
//	}
//};

//class Apple
//{
//	friend Human;		//Полная дружественность классов
//
//	static int Count;
//
//public:
//
//	Apple(int weight, string color)	//Конструктор
//	{
//		this->weight = weight;
//		this->color = color;
//		Count++;		//Проверка на кол-во вызовов конструктора
//		id = Count;
//	}
//
//	int GetId()
//	{
//		this->weight = 20;
//		return id;
//	}
//
//	static int GetCount()
//	{
//
//		return Count;
//	}
//
//	static void ChangeColor(Apple & apple, string color)
//	{
//		apple.color = color;
//	}
//
//	void ChangeColorNoStatic(string color)
//	{
//		this->color = color;
//	}
//
//private:
//	int weight;
//	string color;
//	int id;
//};

//class Pixel
//{
//
//public:
//
//	Pixel()
//	{
//		r = g = b = 0;
//	}
//
//
//	Pixel(int r, int g, int b)
//	{
//		this->r = r;
//		this->g = g;
//		this->b = b;
//	}
//
//	string GetInfo()
//	{
//		return "Pixel: r = " + to_string(r) + ", g = " + to_string(g) + ", b = " + to_string(b);
//	}
//
//private:
//
//	int r;
//	int g;
//	int b;
//};


//Пример агрегации(не привязано жестко к какому либо классу)

//class Cap
//{
//public:
//	string GetColor()
//	{
//		return color;
//	}
//
//private:
//	string color = "красного";
//	
//};

//class Model
//{
//public:
//	void InspectModel()
//	{
//		cout << "Кепка " << cap.GetColor() << " цвета." << endl;
//	}
//
//private:
//	Cap cap;
//};



//пример композиции(внутренний класс жестко привязан к своему классу)

//class Human
//{
//public:
//	void Think()
//	{
//		brain.Think();		//Делегирование
//	}
//
//
//	void InspectTheCap()
//	{
//		cout << "Моя кепка " << cap.GetColor() << " цвета." << endl;
//	}
//
//private:
//
//
//
//	class Brain
//	{
//	public:
//		void Think()
//		{
//			cout << "Я думаю, Ура!" << endl;
//		}
//	};
//
//
//	Brain brain;
//	Cap cap;
//};



//class Human
//{
//private:
//	string name;
//public:
//	string GetName()
//	{
//		return name;
//	}
//
//	void SetName(string name)
//	{
//		this->name = name;
//	}
//};

//class Student : public Human
//{
//public:
//	string group;
//	void learn()
//	{
//		cout << "я учусь" << endl;
//	}
//
//	
//};

//class Professor : public Human
//{
//public:
//	
//	string subject;
//};

//class ExtramuralStudent : public Student
//{
//public:
//	void learn()
//	{
//		cout << "я бываю в университете реже обычного студента, я заочник";
//	}
//};



class A
{
public:
	A()
	{
		cout << " Вызвался конструктор класса A " << endl;
	}

	~A()
	{
		cout << " Вызвался деструктор класса A " << endl;
	}
};

class B : public  A
{
public:
	B()
	{
		cout << " Вызвался конструктор класса B " << endl;
	}

	~B()
	{
		cout << " Вызвался деструктор класса B " << endl;
	}
};

class C : public B
{
public: 
	C()
	{
		cout << " Вызвался конструктор класса C " << endl;
	}

	~C()
	{
		cout << " Вызвался деструктор класса C " << endl;
	}
};


int main21()
{
	setlocale(LC_ALL, "ru");
	
	C value;

	cout << endl << endl;


	return 0;
}
