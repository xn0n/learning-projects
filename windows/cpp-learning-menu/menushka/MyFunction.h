#pragma once
#include "Header.h"

typedef
enum enColor {
	CL_BLACK,
	CL_BLUE,
	CL_GREEN,
	CL_CYAN,
	CL_RED,
	CL_PURPLE,
	CL_YELLOW,
	CL_WHITE,
	CL_LIGHT_BLACK,
	CL_LIGHT_BLUE,
	CL_LIGHT_GREEN,
	CL_LIGHT_CYAN,
	CL_LIGHT_RED,
	CL_LIGHT_PURPLE,
	CL_LIGHT_YELLOW,
	CL_LIGHT_WHITE,
}COLORS;

void SetColor(int pnColorBg, int pnColorTxt);
void SetColor(int pnColor);
void SetCursor(short int pnRow, short int pnCol);
int fakt(int a);
double modul(double a);
void ClearScreen();
void clear();