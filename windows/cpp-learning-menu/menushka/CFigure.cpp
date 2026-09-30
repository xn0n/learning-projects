#include "Classes.h"

CFigure::CFigure() :nx(0), ny(0), nWidth(20), nHeight(15) {
	brushcolor = RGB(255, 192, 203);		// цвет заливки кисти
	pencolor = 0x00FFFFFF;					// цвет заливки пера
	sname = "CFigure";
}

CFigure::CFigure(int pnx, int pny, int pnWidth, int pnHeight) :nx(pnx), ny(pny), nWidth(pnWidth), nHeight(pnHeight) {
	brushcolor = RGB(255, 192, 203);			// цвет заливки кисти
	pencolor = 0x00FFFFFF;						// цвет заливки пера
	sname = "CFigure";
}
CFigure::CFigure(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor) : CFigure(pnx, pny, pnWidth, pnHeight) {
	brushcolor = pbrushcolor;
	pencolor = ppencolor;
}