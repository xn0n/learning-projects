#pragma once
#include "Header.h"

typedef enum enCoding {
	CD_Caesar,			// кодирование методом цезаря
	CD_Dynamic,			// метод динамического ключа
	CD_Bit,				// метод бинарного смещения текста
}CODEMODEL, COCOJUMBO;
void Coding();
void Decoding();
void BitCoding(bool pToLeft = true);
void Dynamic();