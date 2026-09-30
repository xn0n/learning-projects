#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "MyFunction.h"
#include <locale.h>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <string>


#define UCHAR unsigned char
#define uchar unsigned char
#define uint unsigned int
#define UINT unsigned int
#define ushort unsigned short
#define USHORT unsigned short
#define CLS system("cls")
#define PAUSE system("pause")
#define DELAY _getch()
#define CLEAR system("cls")
#define CLRSCR ClearScreen()
#define ESC 27
#define SOT 15
#define ROWS 20
#define SWAP(a) ((short(a) >> 8) & 0x00FF) | (short(a) << 8)
#define SWAPI(a) ((int(a) >> 16) & 0x0000FFFF) | (int(a) << 16)
#define SWAPL(a) ((long long(a) >> 64) & 0x00000000FFFFFFFF) | (long long(a) << 64)
#define _min(a,b) a<b?a:b
#define _max(a,b) a>b?a:b
#define high(a) (a >> (sizeof(a)*4))
#define low(a) (a << (sizeof(a)*4) >> (sizeof(a)*4))
#define uint unsigned int

using namespace std;

void Makros();
void BitMask();
int FirstTermMenu();
int SecondTermMenu();
void ZadachiMenu();
int LabirintMenu();
void RecMenu();
void CodingMenu();
void labSort();
void Creator();
void ClassesMenu();

void lab1();
void lab2_1();
void lab2_2();
void lab3_1();
void lab3_2();
void lab4();

void z1();
void z2();
void z3();
void z4();
void z5();
void z6();
void z7();