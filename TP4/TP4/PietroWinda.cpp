#include "framework.h"
#include "PietroWinda.h"

PietroWinda::PietroWinda(int numer_pietra, int y_pietra, bool czy_po_prawej) : numer_pietra{ numer_pietra }, y_pietra{ y_pietra }, czy_po_prawej{ czy_po_prawej }
	{
		if (czy_po_prawej == true)
		{
			x_pietra = 888;
		}
		else
		{
			x_pietra = 40;
		}
	}
	void PietroWinda::rysuj(Graphics* bufferGraphics)
	{
		Pen* myPen2 = new Pen(Color(69, 25, 25, 217), 5);
		bufferGraphics->DrawLine(myPen2, x_pietra, y_pietra, x_pietra + szerokosc_pietra, y_pietra);
		delete myPen2;
	}
	int PietroWinda::wez_numer_kolejki()
	{
		int tmp_dostepny_numer_kolejki = dostepny_numer_kolejki;
		this->dostepny_numer_kolejki = dostepny_numer_kolejki + 1;
		return tmp_dostepny_numer_kolejki;
	}