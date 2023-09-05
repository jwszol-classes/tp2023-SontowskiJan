#include "ZbiorPieterWindy.h"

	void ZbiorPieterWindy::dodajPietro(PietroWinda* Pietro)
	{
		ZbiorPieter.push_back(Pietro);
	}
	PietroWinda* ZbiorPieterWindy::znajdzPietroPoNumerze(int numerPietra)
	{
		for (int i = 0; i < ZbiorPieter.size(); i++)
		{
			PietroWinda* aktulnePietro = ZbiorPieter[i];
			if (aktulnePietro->numer_pietra == numerPietra)
			{
				return aktulnePietro;
			}
		}
		return nullptr;
	}
	void ZbiorPieterWindy::rysuj(Graphics* bufferGraphics)
	{
		for (int i = 0; i < ZbiorPieter.size(); i++)
		{
			ZbiorPieter[i]->rysuj(bufferGraphics);
		}
	}
	ZbiorPieterWindy::~ZbiorPieterWindy()
	{
		for (int i = 0; i < ZbiorPieter.size(); i++)
		{
			delete ZbiorPieter[i];
		}
	}