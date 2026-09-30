#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw()
{
    system("cls"); // очистка консоли

    // рисуем верхнюю границу поля
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // рисуем боковые границы поля и змейку
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    // рисуем нижнюю границу поля
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // выводим счет
    cout << "Score: " << score << endl;
}

void Input()
{
    if (_kbhit()) // проверяем, была ли нажата клавиша
    {
        switch (_getch()) // получаем код клавиши
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i - 1];
        prev2Y = tailY[i - 1];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }



    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }


    // проверяем, если змейка вышла за границы поля, то игра заканчивается
    if (x < 0 || x >= width || y < 0 || y >= height)
        gameOver = true;

    // проверяем, если змейка "съела" фрукт, то добавляем к счету, увеличиваем змейку и генерируем новый фрукт
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }

    // проверяем, если змейка столкнулась со своим хвостом, то игра заканчивается
    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }
}

int zmeika()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(50); // замедляем игру на 50 миллисекунд, чтобы змейка не двигалась слишком быстро
    }
    return 0;
}

