#include "Symulator.h"

Symulator::Symulator(int OknoX, int OknoY) : OknoX{ OknoX }, OknoY{ OknoY }
	{
		Szyb = new SzybWindy(OknoX);
		Kabina = new KabinaWindy(this);
		ZbiorPasazerow = new ZbiorPasazerowWindy();
		bialy = new Color(255, 255, 255, 255);
	}

	void Symulator::update() {

		Kabina->update();
		ZbiorPasazerow->update();

	};
	void Symulator::rysuj(Graphics* bufferGraphics)
	{
		
		bufferGraphics->Clear(*bialy);
		Kabina->rysuj(bufferGraphics);
		Szyb->rysuj(bufferGraphics);
		ZbiorPieter.rysuj(bufferGraphics);
		ZbiorPasazerow->rysuj(bufferGraphics);
		
	}
	Symulator::~Symulator()
	{
		delete Szyb;
		delete Kabina;
		delete ZbiorPasazerow;
		delete bialy;
	}