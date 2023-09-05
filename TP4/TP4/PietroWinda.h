#pragma once
#include "framework.h"

class PietroWinda
{
public:
	int numer_pietra;
	int szerokosc_pietra = 437;
	bool czy_po_prawej;
	int wysokosc_pietra = 126;
	int y_pietra;
	int x_pietra = 0;
	int aktualny_numer_kolejki = 0;
	int dostepny_numer_kolejki = 0;
	PietroWinda(int numer_pietra, int y_pietra, bool czy_po_prawej);
	int wez_numer_kolejki();
	void rysuj(Graphics* bufferGraphics);
};