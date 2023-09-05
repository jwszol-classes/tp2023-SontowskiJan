#include "ZbiorPasazerowWindy.h"
#include <algorithm>
	void ZbiorPasazerowWindy::dodajPasazera(PasazerWindy* Pasazer)
	{
		ZbiorPasazerow.push_back(Pasazer);
	}
	void ZbiorPasazerowWindy::rysuj(Graphics* bufferGraphics)
	{
		for (int i = 0; i < ZbiorPasazerow.size(); i++)
		{
			ZbiorPasazerow[i]->rysuj(bufferGraphics);
		}
	}
	void ZbiorPasazerowWindy::update()
	{
		std::stable_sort(ZbiorPasazerow.begin(), ZbiorPasazerow.end(),
			[](PasazerWindy* a, PasazerWindy* b)
			{
				if( (a->czy_jest_w_windzie == false) && (b->czy_jest_w_windzie == true) )
				{ 
					return true;
				}
				else
				{
					return false;
				}
			}
		);
		for (int i = 0; i < ZbiorPasazerow.size(); i++)
		{
			ZbiorPasazerow[i]->update();
		}
		usunOznaczonychPasazerow();
	}
	void ZbiorPasazerowWindy::usunOznaczonychPasazerow()
	{
		int i = 0;
		while (i < ZbiorPasazerow.size())
		{
			if (ZbiorPasazerow[i]->oznaczony_do_usuniecia == true)
			{
				delete ZbiorPasazerow[i];
				ZbiorPasazerow.erase(ZbiorPasazerow.begin() + i);
			}
			else
			{
				i++;
			}
		}
	}
	
	ZbiorPasazerowWindy::~ZbiorPasazerowWindy()
	{
		for (int i = 0; i < ZbiorPasazerow.size(); i++)
		{
			delete ZbiorPasazerow[i];
		}
	}