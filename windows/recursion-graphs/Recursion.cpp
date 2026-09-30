#include"MyForm.h"
#include"Recursion.h"
#include "MyHeader.h"
#include<string.h>
#include<stdlib.h>
#include"1Semestr.h"



using namespace MyForm;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Globalization;





float NextRec(float x, float nSum, int i, float nXi, pstRecursion pstRec) {

    //nXi = (n == 1) ? An * xxx * xxx / n : An * (n - 1) * xxx * xxx / n;
    nXi = i > 1 ? nXi * x * x * (i - 1) / i : nXi * x * x / i;
    nSum = nSum + nXi;
    pstRec[i - 1].nID = i;
    pstRec[i - 1].nValue = nXi;
    pstRec[i - 1].nSum = nSum;


    (pstRec + i - 1)->nValue = nXi;
    (*(pstRec + i - 1)).nValue = nXi;

    if (i < 20) return NextRec(x, nSum, i + 1, nXi, pstRec);

    return nSum;

}

void MyForm::Recursion() {

    tb_Title->Text = "";
    TB_Titul->AppendText("\r\n\  последовательность из 20 членов");
    float x, y = 0, nSum = 0, nXi = 0;
    MyFormInput^ idt = gcnew MyFormInput;
    idt->SetLable("Введите начальное значение");
    if (idt->ShowDialog() == System::Windows::Forms::DialogResult::OK); {
        String^ sRes = idt->GetText();
        x = Convert::ToDouble(sRes);
        idt->Visible = false;
        RecOut = new stRecursion[20];
        memset(RecOut, 0, sizeof(stRecursion) * 20);
        y = NextRec(x, nSum, 1, 1, RecOut);

        String^ sItems = gcnew String("");
        NumberFormatInfo^ ift = gcnew NumberFormatInfo;
        CultureInfo^ ifc = gcnew CultureInfo("ru-RU");
        ift->NumberDecimalDigits = 6;
        ifc->NumberFormat->NumberDecimalDigits = 6;

        lb_Output->Items->Add("№\tЗначение\t\tМинимальная сумма");
        for (int i = 0; i < 20; i++) {
            sItems = Convert::ToString(RecOut[i].nID);
            //  sItems == "\t" + Convert::ToString(RecOut[i].nValue);//, ifp);
            //  sItems == "\t\t" + Convert::ToString(RecOut[i].nSum);//, ifc);

            sItems += "\t  " + RecOut[i].nValue.ToString("n", ift);
            sItems += "\t\t" + RecOut[i].nSum.ToString("N", ifc);
            LB_Oytput->Items->Add(sItems);
        }

        LB_Oytput->Items->Add("");
        LB_Oytput->Items->Add("\r\r Вывести конечные значения y =" + y.ToString("N", ifc) + "x = " + x.ToString("n", ift));


    }
    idt->Close();
}



/*
double NextRec3(double xxx, int i, double An, double nSum) {

    //An = (((pow(xxx, (n))) * xxx * xxx) / n);
    An = (pow(xxx, 2 * i)) / i;
    nSum = nSum + An;

    RecData.setRec[i - 1].nIdSet = i;
    RecData.setRec[i - 1].nValue1 = An;
    RecData.setRec[i - 1].nValue2 = nSum;


    (RecData.setRec + i)->nIdSet = i;
    (*(RecData.setRec + i)).nIdSet = i;

    if (i < 20) return NextRec3(xxx, i + 1, An, nSum);
    return nSum;
}


void RecTable2(bool pdelay) {
    CLEAR;
    SetColor(CL_BLACK, CL_LIGHT_CYAN);
    cout << "   Расчет рекурентного соотношения последовательности\n";
    cout << "  из 20 членов, с последующим суммированием\n\n";

    SetColor(0, СВ_БЕЛЫЙ);
    double x;
    cout << "Введите начальное значение х:"; cin >> x;

    RecData.SetCount(20);
    double y = NextRec3(x, 1, 1, 0);


    printf("\nВывести конечные значения y=%f,\tпри x=%4f\n\n", y, x);

    SetColor(CL_BLACK, CL_LIGHT_YELLOW);
    cout << "№nn\t  член ряда\tнакопленное значение\n";

    SetColor(0, 15);
    for (int i = 0; i < RecData.nCount; i++) {

        cout << right << setw(4) << RecData.setRec[i].nIdSet << setw(7) << left << " " << setw(15) << RecData.setRec[i].nValue1
            << setw(17) << RecData.setRec[i].nValue2 << endl;
    }

    cout << endl;
    if (pdelay) PAUSE;
}


void RecTable(bool pdelay) {
    CLEAR;
    SetColor(CL_BLACK, CL_LIGHT_CYAN);
    cout << "   Расчет рекурентного соотношения последовательности\n";
    cout << "  из 20 членов, с последующим суммированием\n\n";

    SetColor(0, СВ_БЕЛЫЙ);
    double x;
    cout << "Введите начальное значение х:"; cin >> x;

    RecData.SetCount(20);
    double y = NextRec(x, 1, 1, 0);


    printf("\nВывести конечные значения y=%f,\tпри x=%4f\n\n", y, x);

    SetColor(CL_BLACK, CL_LIGHT_YELLOW);
    cout << "№nn\t  член ряда\tнакопленное значение\n";

    SetColor(0, 15);
    for (int i = 0; i < RecData.nCount; i++) {
        // cout << setw(4) << RecData.setRec[i].nIdSet << setw(15) << RecData.setRec[i].nValue1
            // << setw(17) << RecData.setRec[i].nValue2 << endl;
    // }

        cout << right << setw(4) << RecData.setRec[i].nIdSet << setw(7) << left << " " << setw(15) << RecData.setRec[i].nValue1
            << setw(17) << RecData.setRec[i].nValue2 << endl;
    }

    cout << endl;
    if (pdelay) PAUSE;
}



void Semestr1(bool pdelay) {
    CLEAR;
    Task3();
    SetColor(CL_BLACK, CL_LIGHT_WHITE);

    stRECT Rect(700, 600, 800, 450);
    DrawGrafSemestr1(Rect, RecData);
    _getch();
    //if (pdelay) PAUSE;
}

void RecGraf2() {
    RecData.Clear();
    RecTable2(false);

    stRECT Rect(40, 550, 900, 450);
    DrawGraf(Rect, RecData);
    _getch();
    //CLRSCR;


}

void RecGraf() {
    RecData.Clear();
    RecTable(false);

    stRECT Rect(40, 550, 900, 450);
    DrawGraf(Rect, RecData);
    _getch();
    //CLRSCR;


}

void DrawGrafSemestr1(stRect prect, stRecursion& pRecData) {          //имеем адрес на глобальную структуру
    if (pRecData.nCount == 0) { cout << "График построить невозможно ввиду отсутсвия данных" << endl; return; }

    int indx = 90, indy = 40, ngWidth = prect.nWidth - indx - 20, ngHeight = prect.nHeight - indy - 50;
    stRect inRect(prect.nLeft + indx, prect.nTop + indy, ngWidth, ngHeight);     //Границы под отрисовку гр.-ка.

    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    LOGBRUSH lgbr{ PS_SOLID, RGB(38,38,38) , 0 };
    HBRUSH brush = CreateBrushIndirect(&lgbr);
    SelectObject(hdc, pen);
    SelectObject(hdc, brush);

    SetBkColor(hdc, 0);

    Rectangle(hdc, prect.nLeft, prect.nTop, prect.nRight(), prect.nBottom());


    //Заголовок  и работа с тексом
    HFONT hftitle = CreateFontA(32, 0, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
        CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman"),
        holdfont = 0;
    SetTextColor(hdc, RGB(255, 255, 0));
    SetBkColor(hdc, RGB(38, 38, 38));

    holdfont = (HFONT)SelectObject(hdc, hftitle);
    char stitle[45]{ "График значений рекурентного соотношения" };
    SIZE sz{ 0 };
    GetTextExtentPoint32A(hdc, stitle, strlen(stitle), &sz);
    TextOutA(hdc, prect.nLeft + indx + (ngWidth - sz.cx) / 2, prect.nTop + 2, stitle, strlen(stitle));
    DeleteObject(SelectObject(hdc, holdfont)); hftitle = 0;

    pRecData.model = mod_An_Y;
    DrawAxisX(hdc, inRect, pRecData.nCount - 1, pRecData, (char*)"Номер члена ряда");
    DrawAxisY(hdc, inRect, 5, pRecData, (char*)"Значние");

    //Рисовать график
    double minx, miny, maxy, maxx, pxPerX = 0, pxPerY = 0;
    pair<double, double> res = pRecData.minimax(mod_X);
    minx = res.first;
    maxx = res.second;
    res = pRecData.minimax(mod_Y);
    miny = res.first;
    maxy = res.second;
    pxPerX = inRect.nWidth / (maxx - minx);
    pxPerY = inRect.nHeight / (maxy - miny);

    HPEN Pen[2]{ 0 };
    Pen[0] = CreatePen(PS_SOLID, 2, RGB(255, 45, 0));
    Pen[1] = CreatePen(PS_SOLID, 2, RGB(0, 45, 255));


    int limit = (pRecData.model == mod_n_An_Y) ? 2 : 1;

    for (int n = 0; n < limit; n++) {
        SelectObject(hdc, Pen[n]);
        //int coorx = 0, coory = 0;
        for (int i = 0; i < pRecData.nCount; i++) {
            res = pRecData.Y(i);
            double value = (n) ? res.second : res.first;

            int dY = (int)((value - miny) * pxPerY),
                dX = (int)((pRecData.X(i) - minx) * pxPerX);
            int coorx = inRect.nLeft + dX,
                coory = inRect.nBottom() - dY;
            if (i == 0)
                MoveToEx(hdc, coorx, coory, NULL);

            else
                LineTo(hdc, coorx, coory);
        }

    }
    DeleteObject(Pen[0]);
    DeleteObject(Pen[1]);
    DeleteObject(hftitle);
}


void DrawGraf(stRect prect, stRecursion& pRecData) {          //имеем адрес на глобальную структуру
    if (pRecData.nCount == 0) { cout << "График построить невозможно ввиду отсутсвия данных" << endl; return; }

    int indx = 90, indy = 40, ngWidth = prect.nWidth - indx - 20, ngHeight = prect.nHeight - indy - 50;
    stRect inRect(prect.nLeft + indx, prect.nTop + indy, ngWidth, ngHeight);     //Границы под отрисовку гр.-ка.

    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    LOGBRUSH lgbr{ PS_SOLID, RGB(38,38,38) , 0 };
    HBRUSH brush = CreateBrushIndirect(&lgbr);
    SelectObject(hdc, pen);
    SelectObject(hdc, brush);

    SetBkColor(hdc, 0);

    Rectangle(hdc, prect.nLeft, prect.nTop, prect.nRight(), prect.nBottom());


    //Заголовок  и работа с тексом
    HFONT hftitle = CreateFontA(32, 0, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
        CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman"),
        holdfont = 0;
    SetTextColor(hdc, RGB(255, 255, 0));
    SetBkColor(hdc, RGB(38, 38, 38));

    holdfont = (HFONT)SelectObject(hdc, hftitle);
    char stitle[45]{ "График значений рекурентного соотношения" };
    SIZE sz{ 0 };
    GetTextExtentPoint32A(hdc, stitle, strlen(stitle), &sz);
    TextOutA(hdc, prect.nLeft + indx + (ngWidth - sz.cx) / 2, prect.nTop + 2, stitle, strlen(stitle));
    DeleteObject(SelectObject(hdc, holdfont)); hftitle = 0;

    pRecData.model = mod_n_An_Y;
    DrawAxisX(hdc, inRect, pRecData.nCount - 1, pRecData, (char*)"Номер члена ряда");
    DrawAxisY(hdc, inRect, 5, pRecData, (char*)"Значние");

    //Рисовать график
    double minx, miny, maxy, maxx, pxPerX = 0, pxPerY = 0;
    pair<double, double> res = pRecData.minimax(mod_X);
    minx = res.first;
    maxx = res.second;
    res = pRecData.minimax(mod_Y);
    miny = res.first;
    maxy = res.second;
    pxPerX = inRect.nWidth / (maxx - minx);
    pxPerY = inRect.nHeight / (maxy - miny);

    HPEN Pen[2]{ 0 };
    Pen[0] = CreatePen(PS_SOLID, 2, RGB(255, 45, 0));
    Pen[1] = CreatePen(PS_SOLID, 2, RGB(0, 45, 255));


    int limit = (pRecData.model == mod_n_An_Y) ? 2 : 1;

    for (int n = 0; n < limit; n++) {
        SelectObject(hdc, Pen[n]);
        //int coorx = 0, coory = 0;
        for (int i = 0; i < pRecData.nCount; i++) {
            res = pRecData.Y(i);
            double value = (n) ? res.second : res.first;

            int dY = (int)((value - miny) * pxPerY),
                dX = (int)((pRecData.X(i) - minx) * pxPerX);
            int coorx = inRect.nLeft + dX,
                coory = inRect.nBottom() - dY;
            if (i == 0)
                MoveToEx(hdc, coorx, coory, NULL);

            else
                LineTo(hdc, coorx, coory);
        }

    }
    DeleteObject(Pen[0]);
    DeleteObject(Pen[1]);
    DeleteObject(hftitle);
}


void DrawAxisX(HDC phdc, stRECT pInRect, int psec, stRecursion& pRecData, char* ptext) {

    MoveToEx(phdc, pInRect.nLeft, pInRect.nBottom(), NULL);
    LineTo(phdc, pInRect.nRight(), pInRect.nBottom());

    //if (psec < pRecData.nCount) psec = 20;


    HPEN pen = CreatePen(PS_DOT, 1, RGB(98, 98, 98)),
        penold = (HPEN)SelectObject(phdc, pen);

    HFONT hold, haixes = CreateFontA(14, 0, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
        CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
    hold = (HFONT)SelectObject(phdc, haixes);
    SetTextColor(phdc, RGB(255, 255, 255));

    //float nPxSec = pInRect.nWidth / psec;
    //Отрисовка гориз. сетки на граф.
    char text[25]{ 0 };
    pair<double, double> res = pRecData.minimax(mod_X);
    double min = res.first, max = res.second;
    float nPxStep = (float)pInRect.nWidth / (psec - 1),
        nPxSec = (float)(max - min) / (psec - 1);
    SIZE sz{ 0 };

    for (int i = 0; i < psec; i++) {
        if (i > 0) {
            MoveToEx(phdc, pInRect.nLeft + i * nPxStep, pInRect.nBottom() + 2, NULL);
            LineTo(phdc, pInRect.nLeft + i * nPxStep, pInRect.nTop);
        }
        double nPxS = min + (nPxSec * i);

        switch (pRecData.model) {
        case mod_An_Y: sprintf_s(text, "%14.6f", pRecData.X(i)); break;
        default: sprintf_s(text, "%4.0f", nPxS);
        }
        GetTextExtentPoint32A(phdc, ptext, strlen(text), &sz);

        TextOutA(phdc, (int)(pInRect.nLeft + nPxStep * i) - sz.cx / 2, pInRect.nBottom() + 4, text, strlen(text));
    }

    pen = (HPEN)SelectObject(phdc, penold);
    DeleteObject(pen);
    //Работа с тектом и загловком
    HFONT  haixtitle = CreateFontA(24, 18, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
        CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
    //Текст название оси
    hold = (HFONT)SelectObject(phdc, haixtitle);
    if (ptext == NULL) ptext = (char*)"Название оси х";
    SetTextColor(phdc, RGB(255, 255, 0));
    GetTextExtentPoint32A(phdc, ptext, strlen(ptext), &sz);

    TextOutA(phdc, pInRect.nLeft + (pInRect.nWidth - sz.cx) / 2, pInRect.nBottom() + 18, ptext, strlen(ptext));
}

void DrawAxisY(HDC phdc, stRECT pInRect, int psec, stRecursion& pRecData, char* ptext) {
    MoveToEx(phdc, pInRect.nLeft, pInRect.nTop, NULL);
    LineTo(phdc, pInRect.nLeft, pInRect.nBottom());

    HPEN pen = CreatePen(PS_DOT, 1, RGB(98, 98, 98)),
        penold = (HPEN)SelectObject(phdc, pen);

    float nPxSec = (float)pInRect.nHeight / psec;
    //Отрисовка вертик. сетки на граф.
    char text[25]{ 0 };
    pair<double, double> res = pRecData.minimax(mod_Y);
    double min = res.first, max = res.second;
    float nPxStep = (float)pInRect.nHeight / (psec),
        nDlt = (float)(max - min) / (psec);

    HFONT hold, haixes = CreateFontA(14, 0, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
        CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
    hold = (HFONT)SelectObject(phdc, haixes);
    SetTextColor(phdc, RGB(255, 255, 255));
    SIZE sz{ 0 };

    for (int i = 0; i < psec + 1; i++) {
        if (i > 0) {
            MoveToEx(phdc, pInRect.nLeft - 2, (int)(pInRect.nBottom() - i * nPxSec), NULL);
            LineTo(phdc, pInRect.nRight(), (int)(pInRect.nBottom() - i * nPxSec));
        }
        int nPxSec = (int)(nPxStep * i);
        double value = min + nDlt * i;
        sprintf_s(text, "%14.6f", value);

        GetTextExtentPoint32A(phdc, ptext, strlen(text), &sz);

        TextOutA(phdc, pInRect.nLeft - 70, pInRect.nBottom() - nPxSec - sz.cy / 2, text, strlen(text));
    }

    pen = (HPEN)SelectObject(phdc, penold);
    DeleteObject(pen);

    //Работа с тектом и загловком
    HFONT  haixtitle = CreateFontA(24, 18, 900, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
        CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
    // haixes = CreateFontA(14, 0, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
       // CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");

 //Текст название оси
    hold = (HFONT)SelectObject(phdc, haixtitle);
    if (ptext == NULL) ptext = (char*)"Название оси y";
    SetTextColor(phdc, RGB(255, 255, 0));

    GetTextExtentPoint32A(phdc, ptext, strlen(ptext), &sz);

    TextOutA(phdc, pInRect.nLeft - 80, pInRect.nBottom(), ptext, strlen(ptext));
    TextOutA(phdc, pInRect.nLeft - 80, pInRect.nBottom(), ptext, strlen(ptext));
}
*/


