#pragma once
class PasazerWindy;
class Symulator;
#include "framework.h"
#include "Symulator.h"
#include <vector>
class KabinaWindy
{
public:
	int aktualna_pozycja = 0;
	int aktualne_pietro = 4;
	int aktualne_pietro_y = 45;
	int pietro_docelowe = aktualne_pietro;
	int maksymalne_obciazenie_windy = 600;

	bool oczekuje_na_powrot_na_parter = false;
	long long poczatek_czekania = 0;
	long long czas_czekania = 5000;

	std::vector<PasazerWindy*> pasazerowe_w_kabinie;
	void usun_pasazera_z_kabiny(PasazerWindy* PasazerPtr);
	bool czy_w_ruchu = false;
	Symulator* SymulatorPtr = nullptr;
	Rect* wymiary = nullptr;
	KabinaWindy(Symulator* SymulatorPtr);
	bool czy_winda_pelna();
	void rysuj(Graphics* bufferGraphics);
	void ustawMiejsceDocelowe(int numer_pietra);
	void update();
	~KabinaWindy();
};