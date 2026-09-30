#pragma once
#include "MyHeader.h"
#include<string>

typedef
enum enColor {
	CL_BLACK,   //черный
	CL_BLUE,
	CL_GREEN,
	CL_CYAN,
	CL_RED,
	CL_PURPLE,
	CL_YELLOW,
	CL_WHITE,
	CL_LIGHT_BLACK,   //черный
	CL_LIGHT_BLUE,
	CL_LIGHT_GREEN,
	CL_LIGHT_CYAN,
	CL_LIGHT_RED,
	CL_LIGHT_PURPLE,
	CL_LIGHT_YELLOW,
	CL_LIGHT_WHITE,
	CL_LIGHT_GRAY = 8,
	ЧЕРНЫЙ = 0,
	СИНИЙ,
	ЗЕЛЕНЫЙ,
	ГОЛУБОЙ,
	КРАСНЫЙ,
	ФИОЛЕТОВЫЙ,
	ЖЕЛТЫЙ,
	БЕЛЫЙ,
	СЕРЫЙ,
	СВ_СИНИЙ,
	СВ_ЗЕЛЕНЫЙ,
	СВ_ГОЛУБОЙ,
	СВ_КРАСНЫЙ,
	СВ_ФИОЛЕТОВЫЙ,
	СВ_ЖЕЛТЫЙ,
	СВ_БЕЛЫЙ
}COLORS, ЦВЕТА;

void SetColor(int  pnColorBackground, int pnColorText);
void SetColor(int pnColor);
void SetCursor(short int pnRow, short int pnCol);
void ClearScreen();  //ВСТАВИТЬ КОД ПЕРД МАСКОЙ В MYFICTION CPP КОТОРЫЙ СКИНУЛИ В ТИМС!
void clear();
//void ClearGraph();
//string GetNameFromFile(string ptext);


