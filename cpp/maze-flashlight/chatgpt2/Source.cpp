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
		if (_getwche() == 33) {
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
			maze[y][x] = SPACE;
			x = newX;
			y = newY;
			maze[y][x] = BUG;
		}
		else {
			if (flashlight) {
				cout << "Невозможно переместиться в этом направлении!" << endl;
			}
			else {
				cout << char(SOUND_CODE);
			}

		}

	}

};

// Функция для вывода лабиринта на экран
void printMaze(vector<vector<char>>& maze) {
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
}

// Функция для генерации случайного лабиринта с помощью алгоритма Прима
void generateMaze(vector<vector<char>>& maze) {
	// Заполняем лабиринт стенами
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			maze[i][j] = WALL;
		}
	}

	// Создаем список стен
	vector<pair<int, int>> walls;

	// Выбираем случайную ячейку и помечаем ее как часть лабиринта
	int x = rand() % MAZE_SIZE;
	int y = rand() % MAZE_SIZE;
	maze[y][x] = SPACE;

	// Добавляем стены этой ячейки в список
	if (x > 0) walls.push_back({ y, x - 1 });
	if (x < MAZE_SIZE - 1) walls.push_back({ y, x + 1 });
	if (y > 0) walls.push_back({ y - 1, x });
	if (y < MAZE_SIZE - 1) walls.push_back({ y + 1, x });

	// Пока есть стены в списке
	while (!walls.empty()) {
		// Выбираем случайную стену из списка
		int index = rand() % walls.size();
		int wallX = walls[index].second;
		int wallY = walls[index].first;

		// Удаляем стену из списка
		walls.erase(walls.begin() + index);

		// Если только одна из двух ячеек, разделенных этой стеной, является частью лабиринта
		if (maze[wallY][wallX] == WALL) {
			vector<pair<int, int>> neighbors; // Список соседних ячеек

			// Находим соседние ячейки
			if (wallX > 0) neighbors.push_back({ wallY, wallX - 1 });
			if (wallX < MAZE_SIZE - 1) neighbors.push_back({ wallY, wallX + 1 });
			if (wallY > 0) neighbors.push_back({ wallY - 1, wallX });
			if (wallY < MAZE_SIZE - 1) neighbors.push_back({ wallY + 1, wallX });

			int count = 0; // Количество соседних ячеек, являющихся частью лабиринта
			for (auto& neighbor : neighbors) {
				if (maze[neighbor.first][neighbor.second] == SPACE) {
					count++;
				}
			}

			if (count == 1) {
				// Делаем стену частью лабиринта
				maze[wallY][wallX] = SPACE;

				// Добавляем стены соседних ячеек в список
				for (auto& neighbor : neighbors) {
					if (maze[neighbor.first][neighbor.second] == WALL) {
						walls.push_back(neighbor);
					}
				}
			}

		}

	}

	// Выбираем случайную ячейку для финиша и помечаем ее символом финиша
	int finishX = rand() % MAZE_SIZE;
	int finishY = rand() % MAZE_SIZE;
	while (maze[finishY][finishX] != SPACE) {
		finishX = rand() % MAZE_SIZE;
		finishY = rand() % MAZE_SIZE;
	}
	maze[finishY][finishX] = FINISH;
}

int main() {
	srand(time(NULL)); // Инициализируем генератор случайных чисел

	vector<vector<char>> maze(MAZE_SIZE); // Создаем вектор для хранения лабиринта

	generateMaze(maze); // Генерируем лабиринт

	Bug bug(0, 0); // Создаем жучка с начальными координатами (0, 0)

	maze[bug.getY()][bug.getX()] = BUG; // Помещаем жучка в лабиринт

	bool finished = false; // Флаг завершения игры

	while (!finished) {
		system("cls"); // Очищаем экран 
		printMaze(maze); // Выводим лабиринт на экран 
		bug.toggleFlashlight(); // Проверяем нажатие клавиши F для включения или выключения фонарика 

		if (_kbhit()) {
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
				bug.move(RIGHT, maze);
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
