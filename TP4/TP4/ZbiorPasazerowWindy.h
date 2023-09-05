#pragma once
#include <vector>
#include "PasazerWindy.h"
class PasazerWindy;
class ZbiorPasazerowWindy
{
public:
	std::vector<PasazerWindy*> ZbiorPasazerow;
	void dodajPasazera(PasazerWindy* Pasazer);
	void rysuj(Graphics* bufferGraphics);
	void update();
	void usunOznaczonychPasazerow();
	~ZbiorPasazerowWindy();
};