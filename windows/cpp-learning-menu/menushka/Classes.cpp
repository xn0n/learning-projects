#include "Classes.h"

CFigure* GetFigure(CManager& manager) {
	int id = 0;
	cout << "Укажите идентификатор объекта => "; cin >> id;
	return manager.GetFigure(id);
}

void ClassesMenu() {
	UCHAR ch = 0;
	CManager manager;
	CFigure* fig1 = 0, * fig2 = 0;
	int id = 0;
	string sclass{}, sfile{};

	do {
		CLRSCR;
		manager.DrawGraph();

		cout << "    Меню для реализации классов\n\n";
		cout << "1 - Создать объект\n";
		cout << "2 - Изменить свойства объекта\n";
		cout << "3 - Нарисовать объекты\n";
		cout << "4 - Модель родительского класса\n";
		cout << "5 - Соединить линией\n";
		cout << "6 - Загрузить объект\n";
		cout << "7 - Сохранить объект\n";
		cout << "\nДля выхода нажмите клавишу ESC\n\n";

		ch = _getch();
		switch (ch) {
		case '6':
			cout << "Загрузка данных\n";
			cout << "Введите имя файла => "; getline(cin, sfile);
			if (!sfile.empty()) {
				manager.Load(sfile);
			}
			else {
				cout << "Объект не найден!";
				DELAY;
			}
			break;
		case '7':
			cout << "Сохранение данных\n";
			cout << "Введите имя файла => "; getline(cin, sfile);
			if (!sfile.empty()) {
				manager.Save(sfile);
			}
			break;
		case '1':
			cout << "1 - Прямоугольник\n";
			cout << "2 - Треугольник\n";
			cout << "3 - Эллипс\n";
			ch = _getch();
			switch (ch) {
			case '1': fig1 = new CRectangle(300, 350, 75, 62, RGB(255, 255, 0), RGB(255, 255, 255));
				manager.AddFigure(fig1);
				fig1->SetId(manager.Count());
				manager.DrawGraph();
				break;
			case '2': fig1 = new CTriangle(400, 250, 75, 75, RGB(255, 192, 203), RGB(255, 255, 255));
				manager.AddFigure(fig1);
				fig1->SetId(manager.Count());
				manager.DrawGraph();
				break;
			case '3': fig1 = new CEllipse(700, 250, 75, 38, RGB(66, 170, 255), RGB(255, 255, 255));
				manager.AddFigure(fig1);
				fig1->SetId(manager.Count());
				manager.DrawGraph();
				break;
			}
			ch = 0;
			break;
		case '2': ParamMenu(manager); break;
		case '3': ClearScreen();
			cout << "		Меню отрисовки фигур\n\n";
			cout << "1 - Отобразить все фигуры\n";
			cout << "2 - Отобразить фигуру по идентификатору\n";
			cout << "3 - Отобразить фигуру класса\n";
			cout << "4 - Отобразить соединённые фигуры\n";
			ch = _getch();
			ClearScreen();
			switch (ch) {
			case '1': manager.Draw(); break;
			case '2': fig1 = GetFigure(manager);
				if (fig1 == NULL) {
					cout << "Объект по идентификатору не найден!\n"; DELAY;
					break;
				}
				fig1->Draw();
				break;
			case '3':
				cout << "Введите наименование класса => "; cin >> sclass;
				manager.Draw(sclass);
				break;
			case '4':
				manager.DrawGraph();
				DELAY;
				break;
			}
			DELAY;
			break;
		case '5': {
			cout << "Введите идентификатор 1-й фигуры => "; cin >> id;
			fig1 = manager.GetFigure(id);
			cout << "Введите идентификатор 2-й фигуры => "; cin >> id;
			fig2 = manager.GetFigure(id);
			manager.AddUnion(fig1, fig2);
			manager.DrawGraph();
		}
				DELAY;
				break;
		case '4':
			CFigure * fig = GetFigure(manager);
			if (fig == 0) {
				ClearScreen();
				for (int i = 0; i < 16; i++) {
					SetColor(0, i);
					SetCursor(10, 10);
					cout << "! Указатель = NULL. Объект не создан!";
					Sleep(350);
				}
				break;
			}
			cout << "Параметры класса от родителя\n";
			cout << "X = " << fig->Left() << " Y = " << fig->Top() << endl;
			cout << "Width = " << fig->Width() << " Height = " << fig->Height() << endl;
			cout << "X2 = " << fig->Right() << " Y2 = " << fig->Bottom() << endl;
			cout << "BrushColor = " << hex << fig->BrushColor() << "	PenColor = " << fig->PenColor() << endl;

			fig->SetId(32);
			cout << dec << "ID = " << fig->GetId() << endl;
			cout << "Name = " << fig->GetName() << endl;

			cout << "Фигура" << endl;
			fig->CFigure::Draw();
			fig->Draw();
			DELAY;
			break;
		}
	} while (ch != 27);
}

void ParamMenu(CManager& pmanager) {
	int val = 0, cred = 0, cgreen = 0, cblue = 0;
	UCHAR ch = 0;
	CFigure* fig = 0;
	do {
		CLEAR;
		pmanager.DrawGraph();
		cout << "    Меню для изменения свойств классов\n\n";
		cout << "1 - Местоположение объекта\n";
		cout << "2 - Размеры объекта\n";
		cout << "3 - Цвета заливки объекта\n";
		cout << "\nДля выхода нажмите клавишу ESC\n";

		ch = _getch();
		switch (ch) {
		case '1':
			fig = GetFigure(pmanager);
			if (fig == NULL) {
				cout << "Объект по идентификатору не найден!\n";
				break;
			}
			cout << "Введите 0, если параметр не меняется!\n\n";
			cout << "Введите координату X(" << fig->X() << ") = "; cin >> val;
			if (val > 0) fig->X(val);
			cout << "Введите координату Y(" << fig->Y() << ") = "; cin >> val;
			if (val > 0) fig->Y(val);
			fig->Draw();
			pmanager.DrawGraph();
			break;
		case '2':
			fig = GetFigure(pmanager);
			if (fig == NULL) {
				cout << "Объект по идентификатору не найден!\n";
				break;
			}
			cout << "Введите 0, если параметр не меняется!\n\n";
			cout << "Введите ширину(" << fig->Width() << ") = "; cin >> val;
			if (val > 0) fig->Width(val);
			cout << "Введите высоту(" << fig->Height() << ") = "; cin >> val;
			if (val > 0) fig->Height(val);
			fig->Draw();
			pmanager.DrawGraph();
			break;
		case '3':
			fig = GetFigure(pmanager);
			if (fig == NULL) {
				cout << "Объект по идентификатору не найден!\n";
				break;
			}
			cout << "Введите -1, если параметр не меняется!\n\n";
			cout << "Введите цвет фона(" << fig->BrushColor() << ") в формате красный, зелёный, синий = "; cin >> val;
			if (val >= 0) {
				cred = val;
				cin >> cgreen >> cblue;
				fig->BrushColor(RGB(cred, cgreen, cblue));
			}
			cout << "Введите цвет контура(" << fig->PenColor() << ") в формате красный, зелёный, синий = "; cin >> val;
			if (val >= 0) {
				cred = val;
				cin >> cgreen >> cblue;
				fig->PenColor(RGB(cred, cgreen, cblue));
			}
			fig->Draw();
			pmanager.DrawGraph();
			break;
		}
	} while (ch != 27);
}