#pragma once
class SzybWindy;
class KabinaWindy;
class ZbiorPasazerowWindy;
#include "SzybWindy.h"
#include "KabinaWindy.h"
#include "ZbiorPieterWindy.h"
#include "ZbiorPasazerowWindy.h"
class Symulator
{
public:
	int OknoX;
	int OknoY;
	SzybWindy* Szyb = nullptr;
	KabinaWindy* Kabina;
	ZbiorPieterWindy ZbiorPieter;
	ZbiorPasazerowWindy* ZbiorPasazerow;
	Color* bialy = nullptr;
	Symulator(int OknoX, int OknoY);

	void update();
	void rysuj(Graphics* bufferGraphics);
	~Symulator();
};