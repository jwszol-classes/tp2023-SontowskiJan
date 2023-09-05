#pragma once
#include <vector>
#include "PietroWinda.h"
class ZbiorPieterWindy
{
public:
	std::vector<PietroWinda*> ZbiorPieter;
	void dodajPietro(PietroWinda* Pietro);
	PietroWinda* znajdzPietroPoNumerze(int numerPietra);
	void rysuj(Graphics* bufferGraphics);
	~ZbiorPieterWindy();
};