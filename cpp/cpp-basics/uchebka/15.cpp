#include "Header.h"


//Методы класса
//Функции класса

//геттеры
//сеттеры
//инкапсуляция

//Конструктор класса
//Конструктор по умолчанию

//Деструктор класса(срабатывает при разрушении объкта класса)

//Ключевое слово this(this->)

//Конструктор копирования

//Перегрузка оператора присваивания

//Перегрузка оператора == и !=

//Перегрузка оператора сложения

//Перегрузка оператора инкремента и декремента 

//Перегрузка оператора индексирования []

//Дружественные функции

//Как вынести реализацию метода из класса



class Test;

class Point
{

private:
	int x;
	int y;
	friend void ChangeX(Point& value, Test& testValue);	//Можно вписать абсолютно в любом месте, будет работать всегда

public:

	//Конструктор
	Point()
	{
		x = 0;
		y = 0;
		cout << this << " Constructor" << endl;
	}


	//Конструктор
	Point(int valueX, int valueY)
	{
		x = valueX;		//приравнием значения
		y = valueY;		//приравнием значения
		cout << this << " Constructor" << endl;
		
	}									//Если занести конструктор в private, то извне доступа нет, и отладчик его не видит
	
	bool operator == (const Point &other)
	{
		cout << "Объекты равны, согласно == или !=" << endl;
		return this->x == other.x && this->y == other.y;
	}

	bool operator != (const Point& other)
	{
		cout << "Объекты не равны, согласно == или !=" << endl;
		return !(this->x == other.x && this->y == other.y);
	}

	Point operator + (const Point &other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}


	/*Point(int valueX, bool boolean)
	{
		x = valueX;

		if (boolean)
		{
			y = 1;
		}
		else
		{
			y = -1;
		}
	}*/

	//void SetY(int y)		//установить значение Y
	//{
	//	this->y = y;
	//}

	int GetY()					//получить значение Y
	{
		return y;
	}

	//void SetX(int valueX)		//установить значение X
	//{
	//	x = valueX;
	//}

	int GetX()					//получить значение X
	{
		return x;
	}

	void Print()
	{
		cout << "X = " << x << "\tY = " << y << "\n\n";
	}

	Point& operator ++()	//префиксная форма записи
	{
		this->x++;			//эти записи равны
		this->y += 1;		//эти записи равны

		return *this;
	}

	Point& operator ++(int value)		//постфиксная форма записи(используем переменную value для определения постфиксной формы
	{
		Point temp(*this);		//запоминаем текущее состояние объекта

		this->x++;			//эти записи равны
		this->y += 1;		//эти записи равны

		return *this;

	}

	Point& operator --()	//префиксная форма записи
	{
		this->x--;			//эти записи равны
		this->y -= 1;		//эти записи равны

		return *this;
	}

	Point& operator --(int value)		//постфиксная форма записи(используем переменную value для определения постфиксной формы
	{
		Point temp(*this);		//запоминаем текущее состояние объекта

		this->x--;			//эти записи равны
		this->y -= 1;		//эти записи равны

		return temp;

	}

	
};

class Human	//класс
{
public:

	int age;			//свойства класса(поля)
	int weight;			//свойства класса(поля)
	string name;		//свойства класса(поля)

	void Print()
	{
		cout << "\n" << "Имя - " << name << "\nВес - " << weight << "\nВозраст - " << age << endl << endl;
	}



};

class CoffeeGrinder
{
private:
	
	bool CheckVoltage()
	{
		return true;
	}

public:

	
};

class MyClass
{
//private:
//	int data;

public:
	int* data;
	MyClass(int size)		//Конструктор
	{
		this->Size = size;
		this->data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}

		cout << "\nВызвался конструктор " << this << endl;
	};

	MyClass(const MyClass& other)		//Конструктор копирования
	{
		this->Size = other.Size;

		/*this->data = other.data;*/			//Так нельзя

		this->data = new int[other.Size];		//Так надо

		for (int i = 0; i < other.Size; i++)
		{
			this->data[i] = other.data[i];
		}
	
		cout << "\nВызвался конструктор копирования " << this << endl;
	};


	MyClass & operator = (const MyClass& other)		//Оператор присваивания
	{
		cout << "\nВызвался оператор присваивания " << this << endl;

		this->Size = other.Size;

		if (this->data!=nullptr)
		{
			delete[] this->data;
		}

		this->data = new int[other.Size];		//Так надо

		for (int i = 0; i < other.Size; i++)
		{
			this->data[i] = other.data[i];
		}


		return *this;
	}



	~MyClass(/*Параметров нет*/)		//Деструктор(ОДИН деструктор на ОДИН класс)
	{
		cout << "\nВызвался деструктор " << this << endl;
		delete[] data;
	};

private:
	int Size;
};

class TestClass
{
public:
	int& operator [] (int index)		//вписываем &(int& operator), чтобы мы могли менять значение в массиве
	{
		return arr[index];
	}

private:
	int arr[5]{ 5,11,33,516,23 };
};

class Test
{
private:
	int Data = 0;

	friend void ChangeX(Point& value, Test& testValue);
};


void ChangeX(Point& value, Test &testValue)
{
	value.x = -1;
	testValue.Data = -1;
}

int main15()
{
	setlocale(LC_ALL, "RU");

	Test test;

	Point a(5, 12);

	a.Print();

	ChangeX(a, test);

	a.Print();

	return 0;
}




//В количестве конструкторов нет ограничения системных, только с точки зрения логики.