#include "Classes.h"

extern string GetFName(string ptext);
extern int GetValueInt(string ptext);

CManager::CManager() : ofigury(NULL), ncount(0), ounions(0), nunion(0) {};
CManager::~CManager() {
	for (int i = 0; i < ncount; i++) delete ofigury[i];
	free(ofigury);
	for (int i = 0; i < nunion; i++) delete ounions[i];
	free(ounions);
};

int CManager::AddFigure(CFigure* pFigure) {
	if (pFigure == NULL) return -1;

	ofigury = (CFigure**)realloc(ofigury, sizeof(CFigure*) * (++ncount));
	ofigury[ncount - 1] = pFigure;
	return ncount - 1;
}

int CManager::Count() { return ncount; }

void CManager::Draw() {			// нарисовать все объекты класса
	for (int i = 0; i < ncount; i++) ofigury[i]->Draw();
}

CFigure* CManager::GetFigure(int pid) {
	for (int i = 0; i < ncount; i++) {
		if (ofigury[i]->ID() == pid) return ofigury[i];
	}
	return NULL;
}


CFigure* CManager::operator[](int index) {
	if (index < 0 || index >= ncount) return NULL;
	return ofigury[index];
}

CUnion* CManager::GetUnion(int index) {
	if (index < 0 || index >= nunion) return 0;
	return ounions[index];
}

int CManager::AddUnion(CUnion* punion) {
	ounions = (CUnion**)realloc(ounions, sizeof(CUnion) * (++nunion));
	ounions[nunion - 1] = punion;
	return nunion - 1;
}

int CManager::AddUnion(CFigure* pf1, CFigure* pf2) {
	if (pf1 == NULL || pf2 == NULL) return -1;
	nunion++;
	ounions = (CUnion**)realloc(ounions, sizeof(CUnion) * (nunion));
	ounions[nunion - 1] = new CUnion(pf1, pf2);
	return nunion - 1;
}

void CManager::Draw(int pid) {			// отрисовка по идентификатору
	CFigure* fig = GetFigure(pid);
	if (fig != NULL) fig->Draw();
}

void CManager::Draw(string pclass) {	// отрисовка фигур класса
	for (int i = 0; i < ncount; i++)
		if (ofigury[i]->GetName() == pclass) ofigury[i]->Draw();
}

void CManager::DrawGraph() {			// отрисовка фигур и линий соединения
	for (int i = 0; i < nunion; i++) ounions[i]->Draw();
	Draw();
}

void CManager::Load(string pfile) {
	ifstream fin(pfile, ios::beg);
	string sline{}, sname{};
	CFigure* figure = 0, * figure2 = 0;
	CUnion* ounion = 0;
	while (fin) {
		getline(fin, sline);
		sname = GetFName(sline);
		figure = 0;
		ounion = 0;
		if (sname.compare("CRectangle") == 0) figure = new CRectangle;
		if (sname.compare("CTriangle") == 0) figure = new CTriangle;
		if (sname.compare("CEllipse") == 0) figure = new CEllipse;
		if (sname.compare("CUnion") == 0) ounion = new CUnion;
		if (figure != 0) {
			while (fin && sname.compare("end") != 0) {
				fin >> sline;
				sname = GetFName(sline);
				if (sname.compare("id") == 0) figure->SetId(GetValueInt(sline)); else
					if (sname.compare("x") == 0) figure->X(GetValueInt(sline)); else
						if (sname.compare("y") == 0) figure->Y(GetValueInt(sline)); else
							if (sname.compare("width") == 0) figure->Width(GetValueInt(sline)); else
								if (sname.compare("height") == 0) figure->Height(GetValueInt(sline)); else
									if (sname.compare("bcolor") == 0) figure->BrushColor(GetValueInt(sline)); else
										if (sname.compare("pcolor") == 0) figure->PenColor(GetValueInt(sline)); else
											if (sname.compare("end") == 0) AddFigure(figure);
			}
		}

		if (ounion != 0) {
			while (fin && sname.compare("end") != 0) {
				fin >> sline;
				sname = GetFName(sline);
				if (sname.compare("figura1") == 0) {
					int nid = GetValueInt(sline);
					figure = this->GetFigure(nid);
					ounion->SetFigure1(figure);
				}
				else
					if (sname.compare("figura2") == 0) {
						int nid = GetValueInt(sline);
						figure2 = this->GetFigure(nid);
						ounion->SetFigure2(figure2);
					}
					else
						if (sname.compare("width") == 0) ounion->SetWidth(GetValueInt(sline)); else
							if (sname.compare("color") == 0) ounion->SetColor(GetValueInt(sline)); else

								if (sname.compare("end") == 0 && figure != 0 && figure2 != 0) this->AddUnion(ounion);
			}
		}
	}
}

void CManager::Save(string pfile) {
	ofstream fout(pfile);
	if (!fout) return;					// если файл открыт с ошибкой или не смог открыться, то выход из метода

	for (int i = 0; i < ncount; i++) {	// сохранение всех объектов CFigure
		CFigure* figure = ofigury[i];
		if (figure == NULL) continue;
		fout << figure->GetName() << endl;
		fout << "id=" << figure->GetId() << endl;
		fout << "x=" << figure->X() << endl;
		fout << "y=" << figure->Y() << endl;
		fout << "width=" << figure->Width() << endl;
		fout << "height=" << figure->Height() << endl;
		fout << "bcolor=" << figure->BrushColor() << endl;
		fout << "pcolor=" << figure->PenColor() << endl;
		fout << "end\n";
	}

	for (int i = 0; i < nunion; i++) {	// сохранение всех линий
		CUnion* ounion = GetUnion(i);
		fout << ounion->GetName() << endl;
		fout << "figura1=" << ounion->GetFigure1()->ID() << endl;
		fout << "figura2=" << ounion->GetFigure2()->ID() << endl;
		fout << "width=" << ounion->GetWidth() << endl;
		fout << "color=" << ounion->GetColor() << endl;
		fout << "end\n";
	}
	fout.close();
}