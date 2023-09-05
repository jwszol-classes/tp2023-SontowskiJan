#pragma once
#include "framework.h"
class SzybWindy
{
public:
	Rect* wymiary = nullptr;
	const int szerokosc_szybu_windy = 400;
	const int y_szybu_windy = 30;
	const int wysokosc_szybu_windy = 660;
	SzybWindy(int OknoX);
	void rysuj(Graphics* bufferGraphics);
	~SzybWindy();
};