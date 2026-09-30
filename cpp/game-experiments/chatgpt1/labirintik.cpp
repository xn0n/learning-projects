// Подключаем библиотеки
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

// Определяем константы
const int MAZE_SIZE = 32; // Размер лабиринта
const char WALL = '1'; // Символ стены
const char SPACE = '0'; // Символ пустого пространства
const char BUG = '@'; // Символ жучка
const char FINISH = '$'; // Символ финиша
const int SOUND_CODE = 7; // Код звука при столкновении со стеной

// Определяем направления движения жучка
enum Direction { UP, DOWN, LEFT, RIGHT };

// Определяем класс жучка
class Bug {
private:
	int x; // Координата x жучка
	int y; // Координата y жучка
	bool flashlight; // Флаг фонарика

public:
	// Конструктор жучка с начальными координатами и выключенным фонариком
	Bug(int startX, int startY) {
		x = startX;
		y = startY;
		flashlight = false;
	}

	// Метод для получения координаты x жучка
	int getX() {
		return x;
	}

	// Метод для получения координаты y жучка
	int getY() {
		return y;
	}

	// Метод для включения или выключения фонарика по нажатию клавиши F (код 102)
	void toggleFlashlight() {
		// Получаем символ с клавиатуры
		char key = _getch();
		// Проверяем, является ли этот символ клавишей F
		if (key == 'F' || key == 'f') {
			flashlight = !flashlight;
		}
	}

	// Метод для проверки включен ли фонарик у жучка
	bool isFlashlightOn() {
		return flashlight;
	}

	// Метод для перемещения жучка в заданном направлении если это возможно,
	// иначе проигрывается звук при столкновении со стеной 
	// (если фонарик выключен) или выводится сообщение об ошибке 
	// (если фонарик включен)
	void move(Direction dir, vector<vector<char>>& maze) {
		int newX = x;
		int newY = y;

		switch (dir) {
		case UP:
			newY--;
			break;
		case DOWN:
			newY++;
			break;
		case LEFT:
			newX--;
			break;
		case RIGHT:
			newX++;
			break;
		}

		if (newX >= 0 && newX < MAZE_SIZE && newY >= 0 && newY < MAZE_SIZE && maze[newY][newX] != WALL) {
			// Очищаем текущую позицию жучка
			maze[y][x] = SPACE;
			// Обновляем координаты жучка
			x = newX;
			y = newY;
			// Устанавливаем новую пози
		// Если эта ячейка еще не отмечена как часть лабиринта
			if (maze[newY][newX] == WALL) {
				// Делаем ячейку частью лабиринта и отмечаем ее соседние стены в списке
				maze[newY][newX] = SPACE;
				if (newX > 0) walls.push_back({ newY, newX - 1 });
				if (newX < MAZE_SIZE - 1) walls.push_back({ newY, newX + 1 });
				if (newY > 0) walls.push_back({ newY - 1, newX });
				if (newY < MAZE_SIZE - 1) walls.push_back({ newY + 1, newX });
			}

			// Удаляем стену из списка
			walls.erase(walls.begin() + randIndex);
		}

		// Выбираем случайные координаты для финиша и помещаем его в лабиринт
		int finishX = rand() % MAZE_SIZE;
		int finishY = rand() % MAZE_SIZE;
		maze[finishY][finishX] = FINISH;

		// Выбираем случайные координаты для жучка и помещаем его в лабиринт
		int bugX, bugY;
		do {
			bugX = rand() % MAZE_SIZE;
			bugY = rand() % MAZE_SIZE;
		} while (maze[bugY][bugX] != SPACE);
		maze[bugY][bugX] = BUG;

		// Выводим лабиринт на экран
		printMaze(maze);
	}

	// Функция для проверки нахождения жучка на финише
	bool checkWin(Bug& bug, vector<vector<char>>& maze) {
		if (maze[bug.getY()][bug.getX()] == FINISH) {
			cout << "Победа!" << endl;
			return true;
		}
		return false;
	}

	int main2() {
		// Устанавливаем кодировку консоли
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		// Создаем лабиринт
		vector<vector<char>> maze(MAZE_SIZE, vector<char>(MAZE_SIZE));
		generateMaze(maze);

		// Создаем жучка и помещаем его в лабиринт
		Bug bug(rand() % MAZE_SIZE, rand() % MAZE_SIZE);

		// Основной цикл программы
		while (true) {
			// Проверяем нахождение жучка на финише
			if (checkWin(bug, maze)) {
				break;
			}

			// Выводим лабиринт на экран
			system("cls");
			printMaze(maze);

			// Перемещаем жучка в зависимости от нажатой клавиши
			switch (_getch()) {
			case 'w':
				bug.move(UP, maze);
				break;
			case 's':
				bug.move(DOWN, maze);
				break;
			case 'a':
				bug.move(LEFT, maze);
				break;
			case 'd':
				bug.move
					break;

			}

			if (maze[bug.getY()][bug.getX()] == FINISH) {
				finished = true;
			}

		}

	}

	system("cls");
	cout << "Поздравляю вы финишировали!" << endl;
	cout << "Хотите попробовать еще раз? [R/Esc]" << endl;

}
