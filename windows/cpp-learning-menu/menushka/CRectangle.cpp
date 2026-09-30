#include "Classes.h"

CRectangle::CRectangle() :CFigure() {
	BrushColor(RGB(150, 192, 255));		// цвет заливки кисти
	sname = "CRectangle";
}

CRectangle::CRectangle(int pnx, int pny, int pnWidth, int pnHeight) : CFigure(pnx, pny, pnWidth, pnHeight) {
	BrushColor(RGB(150, 192, 255));		// цвет заливки кисти
	sname = "CRectangle";
}
CRectangle::CRectangle(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor)
	: CFigure(pnx, pny, pnWidth, pnHeight, pbrushcolor, ppencolor) {
	sname = "CRectangle";
}

void CRectangle::Draw() {
	LOGBRUSH lpBrush;
	lpBrush.lbColor = BrushColor();
	lpBrush.lbStyle = BS_SOLID;

	HDC hdc = GetDC(GetConsoleWindow());

	HBRUSH hbrush = CreateBrushIndirect(&lpBrush);
	SelectObject(hdc, hbrush);

	HPEN hpen = CreatePen(PS_SOLID, 2, PenColor());
	SelectObject(hdc, hpen);

	Rectangle(hdc, Left(), Top(), Right(), Bottom());
	string text = to_string(ID());
	TextOutA(hdc, MiddleX(), MiddleY(), text.c_str(), text.length());
	DeleteObject(hbrush);
	DeleteObject(hpen);
	ReleaseDC(GetConsoleWindow(), hdc);
}