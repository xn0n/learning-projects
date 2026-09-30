//Записать в файл структурные данные, содержащие сведения о 10 продаваемых моделей. Структура имеет поля: фирма, модель, вид трансмиссии(механика, автомат, гибрид), кол-во штук на складе
//номер комплектации, цена за 1 автомобиль



#include <iostream>
#include <fstream>
#include <string>
#include <string.h>



using namespace std;



enum Transmission 
{
	T_Mechanic,
	T_Auto,
	T_Hybryd
};
struct Avto
{
	string firm;
	string model;
	Transmission transmission;
	int count; //количество
	int number; //номер
	float cost;
	Avto() : firm(""), model(""), transmission(T_Auto), count(0), number(0), cost(0) {}
	~Avto() {}
};



int main()
{
	int t = 0;
	int const total = 10;
	Avto objects[total];
	ofstream fout;
	fout.open("examples/local-input.txt");
	cout << "Заполните данные" << endl;
	setlocale(LC_ALL, "");
	for (int i = 0; i < total; i++)
	{
		cout << "Тип " << (i + 1) << endl;
		fout << "Model " << (i + 1) << endl;



		cout << "фирма: ";
		getline(cin, objects[i].firm);
		fout << "Фирма " << objects[i].firm << endl;

		cout << "Модель: ";
		getline(cin, objects[i].model);
		fout << "Модель " << objects[i].model << endl;

		cout << "Трансмиссия 1 - механика, 2 - авто, 3 - гиьрид" << endl;
		cin >> t;
		t = t - 1;
		fout << "Трансмиссия " << t;
		objects[i].transmission = (Transmission)t;
		cout << "Количество: ";
		cin >> objects[i].count;
		fout << "Количество " << objects[i].count;
		cout << "Номер комплектации: ";
		cin >> objects[i].number;
		fout << "Номер " << objects[i].number;
		cout << "Цена: ";
		cin >> objects[i].cost;
		fout << "Номер " << objects[i].cost;
		fout << "end" << endl;
	}
	fout.close();



	return 0;
}