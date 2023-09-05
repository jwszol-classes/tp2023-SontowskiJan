#include "framework.h"
#include "SzybWindy.h"

SzybWindy::SzybWindy(int OknoX)
	{
		wymiary = new Rect((OknoX - szerokosc_szybu_windy) / 2, y_szybu_windy, szerokosc_szybu_windy, wysokosc_szybu_windy);
	}
	void SzybWindy::rysuj(Graphics* bufferGraphics)
	{
		Pen* myPen = new Pen(Color(69, 69, 69, 69), 10);
		bufferGraphics->DrawRectangle(myPen, *wymiary);
		delete myPen;
	}
	SzybWindy::~SzybWindy()
	{
		delete wymiary;
	}