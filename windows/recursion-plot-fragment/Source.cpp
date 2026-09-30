#include"MyForm.h"
#include"Recursion.h"
#include<string.h>
#include<stdlib.h>
#include"MyFormInput.h"



using namespace MyApp;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Globalization;







void MyApp::MyForm::T() {
    ClearToNewTask();
    TB_Titul->Text = "Составление значений исходя из заданных парметров\r\n";
    TB_Titul->AppendText("Введите пременные А и k, они должны быть положительными");

    cout << "Лабораторная работа №3 Тема: Циклические алгоритмы: Организация цикла с несколькими параметрами и проверкой условий\n\n";
    cout << "Условие задачи: Вычислить N значений функции Y = для аргумента Х, изменяющегося от\n" <<
        "Х 1 с шагом Dx.\n\n";
    int n22;
    double A, N, k, n = 0, x_1 = -1, i;//Объявление переменных
    const double LN = 57;
    double H, dx, y{}, x;//Объявление переменных

    MyFormInput^ f = gcnew MyFormInput;


    do { // Исключение некорректного значения N
        f->Text = "\nВведите количество точек N: \n";
        if (f->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            N = Convert::ToDouble(f->GetText());
            if (N < 1) {
                LB_Oytput->Items->Add("Ошибка! N должно быть натуральным!\n");
            }
        }
    } while (N < 1);


    MyFormInput^ itp = gcnew MyFormInput();
    do { // Исключение некорректного значения A
        itp->Text = "Введите положительный параметр A: \n";
        if (itp->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            A = Convert::ToDouble(itp->GetText());
            if (A < 0) {
                LB_Oytput->Items->Add("A должно быть положительным\n");
            }
            else if (A == 0) {
                LB_Oytput->Items->Add("Ошибка! A не может быть равным нулю\n");
            }
        }
    } while (A < 0 || A == 0);

    dx = (A / static_cast<double>(4));

    MyFormInput^ itp1 = gcnew MyFormInput();
    do { // Исключение неккоректного значения k
        itp1->Text = "Введите положительное значение коэффициента выбранной функции K: ";
        if (itp1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            k = Convert::ToDouble(itp1->GetText());
            if (k < 0) {
                LB_Oytput->Items->Add("k должно быть положительным\n");
            }


        }
    } while (k < 0);

    LB_Oytput->Items->Add("\n\nИсходные данные:\t\r"); //+ "\nКоличество точек = " + N + "\nПараметр A = " + A+ "\nКоэффициент выбранной функции K = " + k + "\nШаг = " + dx + "\nНачальная точка = "+ x_1);
    LB_Oytput->Items->Add("\nКоличество точек =" + N);
    LB_Oytput->Items->Add("\nПараметр A = " + A);
    LB_Oytput->Items->Add("\nКоэффициент выбранной функции K = " + k);
    LB_Oytput->Items->Add("\nШаг = " + dx);
    LB_Oytput->Items->Add("\nНачальная точка = " + x_1 + "\n\r");

    LB_Oytput->Items->Add("\n\n№\t\t" + "X\t\t" + "Y\t\t");

    x = x_1;
    while (n < N) { //Цикл отвечающий за количество точек, которые будут выведены
        if (x < 0) { //Определение по какой формуле будем считать коорджинату Y
            H = (pow(A, 2. / 3.) - (pow(x + A, 2. / 3.)));
            y = sqrt(pow(H, 3));
        }
        if (x >= 0) {
            if (abs(2 * A - x) == 0) {
                y = -sqrt(pow(x, 3));
            }
            else {
                y = -sqrt((pow(x, 3) / abs(2 * A - x)));
            }
        }
        //Вывод точек
        n = n + 1;
        //LB_Oytput->Items->Add((n + 1) + "\t\t" + x + "\t\t" + y);
        LB_Oytput->Items->Add((n + 1) + "\t\t" + x + "\t\t" + y.ToString("F6"));


        x = x + dx;
        n22 = n;

        float NextRec2(float x, float nSum, int i, float y, pstRecursion pstRec);

    }
}

float NextRec2(float x, float nSum, int i, float nXi, pstRecursion pstRec) {

    nSum = nSum + nXi;
    pstRec[i - 1].nID = i;
    pstRec[i - 1].nValue = nXi;
    pstRec[i - 1].nSum = nSum;


    (pstRec + i - 1)->nValue = nXi;
    (*(pstRec + i - 1)).nValue = nXi;

    if (i < 32) return NextRec2(x, nSum, i + 1, nXi, pstRec);

    return nSum;

}


float NextRec(float x, float nSum, int i, float nXi, pstRecursion pstRec) {

    //nXi = (n == 1) ? nXi * x * x / n : nXi * (n - 1) * x * x / n;
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


void MyForm::Recursion2() {

    TB_Titul->Text = "";
    TB_Titul->AppendText("\r\n\  последовательность из 20 членов");
    //float x, y = 0, nSum = 0, nXi = 0;
    float nSum = 0;
    MyFormInput^ idt = gcnew MyFormInput;
    //idt->SetLable("Введите начальное значение");
    //if (idt->ShowDialog() == System::Windows::Forms::DialogResult::OK); {
        //String^ sRes = idt->GetText();
        //x = Convert::ToDouble(sRes);
        //idt->Visible = false;
        //x = 1;

    ///////////////////////////////////////////////////////////////////////////////////////
    ClearToNewTask();
    TB_Titul->Text = "Составление значений исходя из заданных парметров\r\n";
    TB_Titul->AppendText("Введите пременные А и k, они должны быть положительными");

    cout << "Лабораторная работа №3 Тема: Циклические алгоритмы: Организация цикла с несколькими параметрами и проверкой условий\n\n";
    cout << "Условие задачи: Вычислить N значений функции Y = для аргумента Х, изменяющегося от\n" <<
        "Х 1 с шагом Dx.\n\n";
    int n22;
    double A, N, k, n = 0, x_1 = -1, i;//Объявление переменных
    const double LN = 57;
    double H, dx, y{}, x;//Объявление переменных

    MyFormInput^ f = gcnew MyFormInput;


    do { // Исключение некорректного значения N
        f->Text = "\nВведите количество точек N: \n";
        if (f->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            N = Convert::ToDouble(f->GetText());
            if (N < 1) {
                LB_Oytput->Items->Add("Ошибка! N должно быть натуральным!\n");
            }
        }
    } while (N < 1);


    MyFormInput^ itp = gcnew MyFormInput();
    do { // Исключение некорректного значения A
        itp->Text = "Введите положительный параметр A: \n";
        if (itp->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            A = Convert::ToDouble(itp->GetText());
            if (A < 0) {
                LB_Oytput->Items->Add("A должно быть положительным\n");
            }
            else if (A == 0) {
                LB_Oytput->Items->Add("Ошибка! A не может быть равным нулю\n");
            }
        }
    } while (A < 0 || A == 0);

    dx = (A / static_cast<double>(4));

    MyFormInput^ itp1 = gcnew MyFormInput();
    do { // Исключение неккоректного значения k
        itp1->Text = "Введите положительное значение коэффициента выбранной функции K: ";
        if (itp1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            k = Convert::ToDouble(itp1->GetText());
            if (k < 0) {
                LB_Oytput->Items->Add("k должно быть положительным\n");
            }


        }
    } while (k < 0);

    LB_Oytput->Items->Add("\n\nИсходные данные:\t\r"); //+ "\nКоличество точек = " + N + "\nПараметр A = " + A+ "\nКоэффициент выбранной функции K = " + k + "\nШаг = " + dx + "\nНачальная точка = "+ x_1);
    LB_Oytput->Items->Add("\nКоличество точек =" + N);
    LB_Oytput->Items->Add("\nПараметр A = " + A);
    LB_Oytput->Items->Add("\nКоэффициент выбранной функции K = " + k);
    LB_Oytput->Items->Add("\nШаг = " + dx);
    LB_Oytput->Items->Add("\nНачальная точка = " + x_1 + "\n\r");

    LB_Oytput->Items->Add("\n\n№\t\t" + "X\t\t" + "Y\t\t");

    x = x_1;

    RecOut = new stRecursion[20];
    memset(RecOut, 0, sizeof(stRecursion) * 20);

    while (n < N) { //Цикл отвечающий за количество точек, которые будут выведены
        if (x < 0) { //Определение по какой формуле будем считать коорджинату Y
            H = (pow(A, 2. / 3.) - (pow(x + A, 2. / 3.)));
            y = sqrt(pow(H, 3));
        }
        if (x >= 0) {
            if (abs(2 * A - x) == 0) {
                y = -sqrt(pow(x, 3));
            }
            else {
                y = -sqrt((pow(x, 3) / abs(2 * A - x)));
            }
        }
        //Вывод точек
        n = n + 1;
        //LB_Oytput->Items->Add((n + 1) + "\t\t" + x + "\t\t" + y);
        LB_Oytput->Items->Add((n + 1) + "\t\t" + x + "\t\t" + y.ToString("F6"));


        x = x + dx;
        n22 = n;

        //float NextRec2(float x, float y, 1, 1, pstRecursion pstRec);
        //y = NextRec2(x, nSum, 1, 1, RecOut);
        NextRec2(x, y, 1, 1, RecOut);
        //Запись данных в массив
     //RecOut.setRec[i].nIdSet = i + 1;
     //RecData.setRec[i].nValue1 = x;
     //RecData.setRec[i].nValue2 = y;

    }



    //////////////////////////////////////////////////////////////////////////////////////







        //String^ sItems = gcnew String("");
        //NumberFormatInfo^ ift = gcnew NumberFormatInfo;
        //CultureInfo^ ifc = gcnew CultureInfo("ru-RU");
        //ift->NumberDecimalDigits = 6;
        //ifc->NumberFormat->NumberDecimalDigits = 6;

        /*LB_Oytput->Items->Add("№\tЗначение\t\tМинимальная сумма");
        for (int i = 0; i < 20; i++) {
            sItems = Convert::ToString(RecOut[i].nID);
            //  sItems == "\t" + Convert::ToString(RecOut[i].nValue);//, ifp);
            //  sItems == "\t\t" + Convert::ToString(RecOut[i].nSum);//, ifc);

            sItems += "\t  " + RecOut[i].nValue.ToString("n", ift);
            sItems += " \t\t " + RecOut[i].nSum.ToString("N", ifc);
            LB_Oytput->Items->Add(sItems);
        }

        LB_Oytput->Items->Add("");
        LB_Oytput->Items->Add("\r\r Вывести конечные значения y =" + y.ToString("N", ifc) + "x = " + x.ToString("n", ift));
        */



        //}
        //idt->Close();
}

void MyForm::Recursion() {

    TB_Titul->Text = "";
    TB_Titul->AppendText("\r\n\  Расчет рекурентного соотношения последовательности\nиз 20 членов, с последующим суммированием\n\n");

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

        LB_Oytput->Items->Add("№\tЗначение\t\tМинимальная сумма");
        for (int i = 0; i < 20; i++) {
            sItems = Convert::ToString(RecOut[i].nID);
            //  sItems == "\t" + Convert::ToString(RecOut[i].nValue);//, ifp);
            //  sItems == "\t\t" + Convert::ToString(RecOut[i].nSum);//, ifc);

            sItems += "\t  " + RecOut[i].nValue.ToString("n", ift);
            sItems += "   \t\t       " + RecOut[i].nSum.ToString("N", ifc);
            LB_Oytput->Items->Add(sItems);
        }

        LB_Oytput->Items->Add("");
        LB_Oytput->Items->Add("\r\r Вывести конечные значения y =" + y.ToString("N", ifc) + "x = " + x.ToString("n", ift));


    }
    idt->Close();
}







void DrawGraf(Graphics^ pgraph, pstRecursion pRec, int pSizeRec, RECT pstRect) {          //имеем адрес на глобальную структуру

    static int i;
    if (pSizeRec == 0 || pRec == NULL) return;

    float nMinAxix, nMaxAxix, nMinAxiy, nMaxAxiy;

    //Отрисовка графика
    nMinAxiy = nMaxAxiy = pRec[0].nValue;
    nMinAxix = pRec[0].nID;
    nMaxAxix = pRec[pSizeRec - 1].nID;
    for (int j = 1; j < pSizeRec; j++) {
        if (nMinAxiy > pRec[j].nValue) nMinAxiy = pRec[j].nValue;
        if (nMinAxiy > pRec[j].nSum) nMinAxiy = pRec[j].nSum;

        if (nMaxAxiy < pRec[j].nValue) nMaxAxiy = pRec[j].nValue;
        if (nMaxAxiy < pRec[j].nSum) nMaxAxiy = pRec[j].nSum;
    }

    //отрисовка графов
    Pen^ blackPen = gcnew Pen(Color::Black, 1);
    pgraph->DrawRectangle(blackPen, pstRect.left, pstRect.top, pstRect.right - pstRect.left, pstRect.bottom - pstRect.top);

    Font^ nfont = gcnew Font("New Time Romans", 14);

    SolidBrush^ nbrush = gcnew SolidBrush(Color::Red);

    /*String^ sHeadlog = "График рекурентного соотношения";

     /*int zind = ((pstRect.right - pstRect.left) - nfont->Size * sHeadlog->Length) / 2 + zind;
     int rHeading = sHeadlog->Length, zind - 100;
     pgraph->DrawString(sHeadlog,nfont,nbrush,pstRect.left + zind,pstRect.top);*/

    String^ sHeadlog = "График рекурентного соотношения";
    int rHeading = sHeadlog->Length;
    int zind = ((pstRect.right - pstRect.left) - nfont->Size * sHeadlog->Length) / 2 + zind;

    pgraph->DrawString(sHeadlog, nfont, nbrush, pstRect.left + zind, pstRect.top);


    RECT rAxisx{ 530, 230, 1230, 530 };

    //RECT rAxisx;
   // rAxisx.top = 200;
    //rAxisx.left = 100;
   // rAxisx.right = 200;
   // rAxisx.bottom = 606;

    //float nPxPerVal = (rAxisx.right - rAxisx.left);
    float nPxPerVal = static_cast<float>(rAxisx.right - rAxisx.left);


    int nY = (int)(rAxisx.bottom - (pRec[0].nValue - nMinAxiy) * (rAxisx.bottom - rAxisx.top) / (nMaxAxiy - nMinAxiy));
    int nSY = (int)(rAxisx.bottom - (pRec[0].nSum - nMinAxiy) * (rAxisx.bottom - rAxisx.top) / (nMaxAxiy - nMinAxiy));
    int nPxOld = rAxisx.left;
    blackPen->Width = 4;
    for (int i = 1; i < pSizeRec; i++) {
        float nPxStep = rAxisx.left + (i)*nPxPerVal / (pSizeRec - 1);

        int nY2 = (int)(rAxisx.bottom - (pRec[i].nValue - nMinAxiy) * (rAxisx.bottom - rAxisx.top) / (nMaxAxiy - nMinAxiy));

        blackPen->Color = Color::Blue;
        pgraph->DrawLine(blackPen, (int)nPxOld, nY, (int)nPxStep, nY2);
        nY = nY2;

        int nSY2 = (int)(rAxisx.bottom - (pRec[i].nSum - nMinAxiy) * (rAxisx.bottom - rAxisx.top) / (nMaxAxiy - nMinAxiy));
        blackPen->Color = Color::Red;
        pgraph->DrawLine(blackPen, (int)nPxOld, nSY, (int)nPxStep, nSY2);
        nSY = nSY2;

        nPxOld = nPxStep;
    }



    DrawAxisX(pgraph, rAxisx, nMinAxix, nMaxAxix, pSizeRec);
    DrawAxisY(pgraph, rAxisx, nMinAxiy, nMaxAxiy, 5);

}



void DrawAxisX(Graphics^ pgraph, RECT pArea, float pnMin, float pnMax, int pnSec)
{

    PointF p1, p2;
    p1.X = pArea.left;
    p1.Y = pArea.bottom;

    p2.X = pArea.right;
    p2.Y = pArea.bottom;

    Pen^ pen = gcnew Pen(Color::Black, 2);

    pgraph->DrawLine(pen, p1, p2);


    Font^ font = gcnew Font("New Times Romans", 12);
    SolidBrush^ brush = gcnew SolidBrush(Color::Red);

    String^ saxis = gcnew String("Индефикатор значения");
    int indaxis = ((pArea.right - pArea.left) - saxis->Length) / 2;
    pgraph->DrawString(saxis, font, brush, pArea.left + indaxis, pArea.bottom + 30);

    float nPxPerVal = (pArea.right - pArea.left) / (pnMax - pnMin);

    pen->Width = 1;
    pen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dot;
    pen->Color = Color::Gray;
    for (int j = 0; j < (pnSec); j++) {
        float nPxStep = pArea.left + (j)*nPxPerVal * (pnMax - pnMin) / (pnSec - 1);
        pgraph->DrawLine(pen, nPxStep, (float)pArea.bottom + 2, nPxStep, (float)pArea.top);
        brush->Color = Color::Black;
        pgraph->DrawString(Convert::ToString(pnMin + j), font, brush, nPxStep - font->Size / 2, pArea.bottom + 4);


    }
}

void DrawTextRotate(Graphics^ pgraph, String^ ptext, System::Drawing::Rectangle prect, Font^ pfont, Brush^ pbrush, float angle) {
    System::Drawing::Rectangle rect(0, 0, prect.Height, prect.Width);
    pgraph->ResetTransform();
    pgraph->RotateTransform(angle);

    pgraph->TranslateTransform(prect.Left, prect.Bottom, System::Drawing::Drawing2D::MatrixOrder::Append);
    StringFormat^ string_format = gcnew StringFormat();
    string_format->Alignment = StringAlignment::Center;
    string_format->LineAlignment = StringAlignment::Center;
    Pen^ pen = gcnew Pen(Color::Black, 2);
    pgraph->DrawRectangle(pen, prect);
    pgraph->DrawString(ptext, pfont, pbrush, rect, string_format);
    pgraph->ResetTransform();
};

void DrawAxisY(Graphics^ pgraph, RECT pArea, float pnMin, float pnMax, int pnSec)
{

    PointF p1, p2;
    p1.X = pArea.left;
    p1.Y = pArea.bottom;

    p2.X = pArea.left;
    p2.Y = pArea.top;

    Pen^ pen = gcnew Pen(Color::Black, 2);

    pgraph->DrawLine(pen, p1, p2);


    float nIDt = (pnMax - pnMin) / pnSec;

    float nPxPerVal = (pArea.bottom - pArea.top) / (pnMax - pnMin);


    Font^ font = gcnew Font("New Times Romans", 12);
    SolidBrush^ brush = gcnew SolidBrush(Color::Red);

    String^ f = gcnew String(" Значение");
    int indaxis = ((pArea.bottom - pArea.top) - f->Length) / 2;

    System::Drawing::Rectangle rect(pArea.left - font->Height, pArea.top, font->Height, pArea.bottom - pArea.top);
    //pgraph->DrawString(saxis, font, brush, pArea.left + indaxis, pArea.bottom + 30);
    DrawTextRotate(pgraph, f, rect, font, brush, -90);

    String^ sItem = gcnew String("");
    NumberFormatInfo^ ifp = gcnew NumberFormatInfo;
    CultureInfo^ ifc = gcnew CultureInfo("ru-RU");
    ifp->NumberDecimalDigits = 6;
    ifc->NumberFormat->NumberDecimalDigits = 6;

    for (int i = 0; i <= pnSec; i++) {
        float nPxStep = pArea.bottom - (i)*nPxPerVal * (pnMax - pnMin) / pnSec;
        if (i > 0) {
            pen->Width = 1;
            pen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dot;
            pen->Color = Color::Gray;

            pgraph->DrawLine(pen, pArea.left - 3, int(nPxStep), pArea.right, int(nPxStep));

        }
        float val = (pnMin + (i * nIDt));
        brush->Color = Color::Black;
        pgraph->DrawString(val.ToString("n", ifp), font, brush, pArea.left - 100, int(nPxStep));


    }

};




