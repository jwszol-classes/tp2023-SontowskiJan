#pragma once

class Symulator;
#include "framework.h"
#include "Symulator.h"
class PasazerWindy
{
public:
	int pietro_docelowe;
	int wysokosc_pasazera = 80;
	int szerokosc_pasazera = 40;
	int y_pasazera;
	int x_pasazera;
	int x_docelowy;
	static const int waga_pasazera = 70;
	int pietro_aktualne;
	bool czy_idzie_do_windy = false;
	bool czy_jest_w_windzie = false;
	bool czy_wychodzi_z_windy = false;
	bool czy_wyszedl_z_windy = false;
	int numer_w_kolejce_pietro = 0;
	bool oznaczony_do_usuniecia = false;
	Symulator* SymulatorPtr = nullptr;
	PasazerWindy(int pietro_aktualne, int pietro_docelowe, Symulator* SymulatorPtr);
	void rysuj(Graphics* bufferGraphics);
	void update();
	~PasazerWindy();
};
