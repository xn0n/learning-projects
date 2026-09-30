#pragma once
#include"MyHeader.h"
#include <Windows.h>
#include<string>
#include"MyForm.h"

using namespace System::Drawing;
using namespace System;

typedef
struct _stRectItem {
	int nIdSet;		//Индефикатор набора данных
	double nValue1,	//Значение 1
		nValue2;	//Значение2

	_stRectItem() :nIdSet(0), nValue1(0), nValue2(0) {}
	_stRectItem(int pID, double pValue1, double pValue2) : nIdSet(pID), nValue1(pValue1), nValue2(pValue2) {}

}stRecItem, * pstRecItem;

typedef struct _stRecursion {
	int nID;
	double nValue, nSum;
	_stRecursion() {
		nID = 0;
		nValue = 0;
		nSum = 0;
	}
} stRecursion, * pstRecursion;

/*typedef enum enModel {
	mod_n_An_Y,	//данные n номера метки(х); An - член ряда, Y - накопленое значение
	mod_n_An,	//данные n номера метки(х); An - член ряда
	mod_n_Y,	//данные n номера метки(х); Y - накопленое значение
	mod_An_Y,	//данные An - (х);  Y - функция
	mod_X,		//это по оси х
	mod_Y		//это по оси у
}MODEL, * PMODEL;



typedef
struct _stRecursion {
	int nCount;			//Кол-во элементов структур в наборе данных
	pstRecItem setRec;	//мАССИВ стпуктур
	enModel model = mod_n_An_Y;	//модель данных

	_stRecursion() :nCount(0), setRec(NULL) {}
	_stRecursion(int pCount) { setRec = new stRecItem[pCount]; }
	~_stRecursion() { delete[]setRec; }

	int AddItem(int pId, double pV1, double pV2) {							//Добавить в конец новый набор данных
		nCount++;
		setRec = (pstRecItem)realloc(setRec, sizeof(stRecItem) * nCount);	//Создать новый набор данных

		setRec[nCount - 1].nIdSet = pId;
		setRec[nCount - 1].nValue1 = pV1;
		setRec[nCount - 1].nValue2 = pV2;
		return nCount;

	}
	/*

	void Clear() {
		nCount = 0;
		if (setRec != NULL); //{ free(setRec); setRec = NULL; }

	}
	pair<double, double> minimax(enModel pmod) {
		if (nCount == 0) return pair<double, double>(0, 0);
		double min = 0, max = 0;

		switch (pmod) { //данные по оси х или у
		case mod_X: {
			switch (model) {
			case mod_An_Y: {
				min = max = setRec[0].nValue1;
				for (int i = 1; i < nCount; i++) {
					if (min > setRec[i].nValue1) min = setRec[i].nValue1;
					if (max < setRec[i].nValue1) max = setRec[i].nValue1;
				}


			}break;
			default: {
				min = max = setRec[0].nIdSet;
				for (int i = 1; i < nCount; i++) {
					if (min > setRec[i].nIdSet) min = setRec[i].nIdSet;
					if (max < setRec[i].nIdSet) max = setRec[i].nIdSet;
				}
			}
			}

		}break;
		case mod_Y: {
			switch (model) {
			case mod_n_Y:
			case mod_An_Y: {
				min = max = setRec[0].nValue2;
				for (int i = 1; i < nCount; i++) {
					if (min > setRec[i].nValue2) min = setRec[i].nValue2;
					if (max < setRec[i].nValue2) max = setRec[i].nValue2;
				}
			}break;
			case mod_n_An: {
				min = max = setRec[0].nValue2;
				for (int i = 1; i < nCount; i++) {
					if (min > setRec[i].nValue1) min = setRec[i].nValue1;
					if (max < setRec[i].nValue1) max = setRec[i].nValue1;
				}
			}break;
			case mod_n_An_Y: {
				min = max = setRec[0].nValue2;
				for (int i = 1; i < nCount; i++) {
					if (min > setRec[i].nValue1) min = setRec[i].nValue1;
					if (max < setRec[i].nValue1) max = setRec[i].nValue1;
					if (min > setRec[i].nValue2) min = setRec[i].nValue2;
					if (max < setRec[i].nValue2) max = setRec[i].nValue2;
				}
			}break;
			}

		}break;
		}
		return pair<double, double>(min, max);
	}

	double X(int pIndex) {
		if (nCount == 0 || pIndex >= nCount) return 0;

		switch (model) {
		case mod_An_Y: {
			return setRec[pIndex].nValue1;
		}break;
		default: {
			return setRec[pIndex].nIdSet;
		}
		}
		return 0;
	}

	pair<double, double> Y(int pIndex) {
		if (nCount == 0 || pIndex >= nCount) return pair<double, double>(0, 0);

		switch (model) {
		case mod_n_An_Y: {//данные n номера метки(х); An - член ряда, Y - накопленое значение
			return pair<double, double>(setRec[pIndex].nValue1, setRec[pIndex].nValue2);
		} break;
		case	mod_n_An: {
			return pair<double, double>(setRec[pIndex].nValue1, 0);
		}break;
		case	mod_n_Y:
		case	mod_An_Y: {
			return pair<double, double>(setRec[pIndex].nValue2, 0);
		}break;
		}
	}


	int SetCount(int pnCount) {
		Clear();
		nCount = pnCount;
		setRec = new stRecItem[pnCount];
		return nCount;
	}

}stRecursion, * pstRecursion;

typedef struct stRect {
	UINT  nLeft,		//Левая координата
		nTop,			//Верхняя координата
		nWidth,			//Ширина
		nHeight;		//Высота
	stRect() : nLeft(0), nTop(0), nWidth(0), nHeight(0) {}
	stRect(UINT pLeft, UINT pTop) : nLeft(pLeft), nTop(pTop), nWidth(0), nHeight(0) {}
	stRect(UINT pLeft, UINT pTop, UINT pWid, UINT pHei) : nLeft(pLeft), nTop(pTop), nWidth(pWid), nHeight(pHei) {}



	UINT nBottom() { return nTop + nHeight; }		//Координата низа прямоуголника
	UINT nRight() { return nLeft + nWidth; }		//Координата правой сторны прямоугольника



}stRECT, * pstRECT;

extern stRecursion RecData;
void RecTable(bool pdelay = true);
void RecTable1(bool pdelay = true);
void RecTable2(bool pdelay = true);
void Semestr1(bool pdelay = true);
void RecGraf2();
void RecGraf();*/

//static stRecursion* RecOut;
static CURSORINFO pci;

void Recursion();
void DrawGraf(Graphics^ pgraph, pstRecursion pRec, int pnSizeRec, RECT pstRect);
//void DrawGrafSemestr1(stRect prect, stRecursion& pRecData);
void DrawAxisX(Graphics^ pgraph, RECT pArea, float pnMin, float pnMax, int pnSec = 10);
void DrawAxisY(Graphics^ pgraph, RECT pArea, float pnMin, float pnMax, int pnSec = 4);
void DrawTextRotate(Graphics^ pgraph, String^ ptext, System::Drawing::Rectangle prect, Font^ pfont, Brush^ pbrush, float angle);
void DrawSideText(Graphics^ gr, Font^ font, Brush^ brush, RECT bounds, StringFormat string_format, String^ txt);
float nNext(float x, float nSum, int i, float nXi, pstRecursion pstRec);