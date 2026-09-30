#pragma once
#include <fstream>
#include "Header.h"

class CID {
	int nid;			// идентификатор объекта
protected:
	string sname;		// имя класса
public:
	CID() :nid(0), sname("CID") {}
	CID(int pid, string pname = "CID") :nid(pid), sname(pname) {}

	int GetId() { return nid; }
	void SetId(int pid) { nid = pid; }
	int ID() { return nid; }
	virtual string GetName() { return sname; }
	virtual void SetName(string pname) { sname = pname; }
};

class CFigure : public CID {
	int nx,				// координата левого верхнего угла прямоугольника по оси x
		ny,				// координата левого верхнего угла прямоугольника по оси y
		nWidth,			// ширина фигуры
		nHeight;		// высота фигуры
	int brushcolor,		// цвет заливки кисти
		pencolor;		// цвет заливки пера

public:
	CFigure();
	CFigure(int pnx, int pny, int pnWidth, int pnHeight);
	CFigure(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor);

	int X() { return nx; }
	void X(int px) { nx = px; }
	int Y() { return ny; }
	void Y(int py) { ny = py; }

	int Width() { return nWidth; }
	void Width(int pWidth) { nWidth = pWidth; }
	int Height() { return nHeight; }
	void Height(int pHeight) { nHeight = pHeight; }

	int BrushColor() { return brushcolor; }
	void BrushColor(int pbcolor) { brushcolor = pbcolor; }
	int PenColor() { return pencolor; }
	void PenColor(int pcolor) { pencolor = pcolor; }

	int Left() { return nx; }
	int Top() { return ny; }
	int Right() { return nx + nWidth; }
	int Bottom() { return ny + nHeight; }

	int MiddleX() { return nx + nWidth / 2; }
	int MiddleY() { return ny + nHeight / 2; }

	virtual void Draw() {};
};

class CRectangle : public CFigure {
public:
	CRectangle();
	CRectangle(int pnx, int pny, int pnWidth, int pnHeight);
	CRectangle(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor);

	virtual void Draw();
};

class CTriangle : public CFigure {
public:
	CTriangle();
	CTriangle(int pnx, int pny, int pnWidth, int pnHeight);
	CTriangle(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor);

	virtual void Draw();
};

class CEllipse : public CFigure {
public:
	CEllipse();
	CEllipse(int pnx, int pny, int pnWidth, int pnHeight);
	CEllipse(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor);

	virtual void Draw();
};

class CUnion : public CID {		// соединитель объектов TFigure
	CFigure* fig1, * fig2;		// первая и вторая фигуры
	int color,					// цвет линии
		width;					// ширина линии в пикселях
public:
	CUnion(CFigure* pfig1 = NULL, CFigure* pfig2 = NULL);
	~CUnion();

	void SetFigure1(CFigure* pFig);
	void SetFigure2(CFigure* pFig);
	void SetColor(int pcolor);
	void SetWidth(int pwid);

	CFigure* GetFigure1();
	CFigure* GetFigure2();
	int GetColor();
	int GetWidth();

	void Draw();
};

class CManager {
private:
	CFigure** ofigury;		// динамический массив объектов: прямоугольников, треугольников, эллипсов
	int ncount;				// количество объектов в ofigury
	CUnion** ounions;		// динамический массив объектов CUnion
	int nunion;				// количество линий соединения
public:
	CManager();
	~CManager();

	CFigure* operator[](int index);
	int AddFigure(CFigure* pFigure);
	int Count();
	CFigure* GetFigure(int pid);

	CUnion* GetUnion(int index);
	int AddUnion(CFigure* pf1, CFigure* pf2);
	int AddUnion(CUnion* punion);

	void Draw();			// нарисовать все объекты класса
	void Draw(int pid);			// отрисовка по идентификатору
	void Draw(string pclass);	// отрисовка фигур класса
	void DrawGraph();			// отрисовка фигур и линий соединения

	void Load(string pfile);	// Функция чтения всех данных для восстановления CManager
	void Save(string pfile);	// Функция записи состояния объекта в файл
};

void ParamMenu(CManager& pmanager);