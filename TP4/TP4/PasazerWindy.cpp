#include "PasazerWindy.h"
#include <string>
PasazerWindy::PasazerWindy(int pietro_aktualne, int pietro_docelowe, Symulator* SymulatorPtr) : pietro_aktualne{ pietro_aktualne }, pietro_docelowe{ pietro_docelowe }, SymulatorPtr{SymulatorPtr}
{
	PietroWinda* tmpPietro = SymulatorPtr->ZbiorPieter.znajdzPietroPoNumerze(pietro_aktualne);
	this->y_pasazera = tmpPietro->y_pietra - wysokosc_pasazera;
	this->numer_w_kolejce_pietro = tmpPietro->wez_numer_kolejki();
	if (tmpPietro->czy_po_prawej == true)
	{
		this->x_pasazera = 908 + (this->numer_w_kolejce_pietro - tmpPietro->aktualny_numer_kolejki)*50;
	}
	else
	{
		this->x_pasazera = 420 - (this->numer_w_kolejce_pietro - tmpPietro->aktualny_numer_kolejki) * 50;
	}
	this->x_docelowy = this->x_pasazera;
}
void PasazerWindy::rysuj(Graphics* bufferGraphics)
{
	Pen* myPen2 = new Pen(Color(69, 25, 25, 217), 5);
	bufferGraphics->DrawRectangle(myPen2, x_pasazera, y_pasazera - 5, szerokosc_pasazera, wysokosc_pasazera);
	FontFamily   fontFamily(L"Arial");
	Font         font(&fontFamily, 20, FontStyleBold, UnitPoint);
	RectF        rectF(x_pasazera, y_pasazera - 5, szerokosc_pasazera, wysokosc_pasazera);
	SolidBrush   solidBrush(Color(255, 0, 0, 255));
	std::wstring tmpWstring(std::to_wstring(pietro_docelowe));
	const wchar_t* tmpWchar = tmpWstring.c_str();
	bufferGraphics->DrawString(tmpWchar, 2, &font, rectF, NULL, &solidBrush);
	delete myPen2;
}
void PasazerWindy::update()
{

	KabinaWindy* tmpKabina = SymulatorPtr->Kabina;
	
	if (czy_jest_w_windzie == true)
	{
		y_pasazera = tmpKabina->aktualna_pozycja+45;
	}


	if ((tmpKabina->czy_w_ruchu == false) && (tmpKabina->aktualne_pietro == pietro_aktualne) && (czy_idzie_do_windy == false))
	{
		if (pietro_docelowe == pietro_aktualne)
		{
			if (SymulatorPtr->ZbiorPieter.znajdzPietroPoNumerze(pietro_docelowe)->czy_po_prawej)
			{
				x_docelowy = 10000;
			}
			else
			{
				x_docelowy = -10000;
			}
			czy_wychodzi_z_windy = true;
			czy_jest_w_windzie = false;
			tmpKabina->usun_pasazera_z_kabiny(this);
		}
		else
		{
			if ((tmpKabina->czy_winda_pelna() == false))
			{
				x_docelowy = tmpKabina->wymiary->X + tmpKabina->wymiary->Width / 2;
				czy_idzie_do_windy = true;
				SymulatorPtr->ZbiorPieter.znajdzPietroPoNumerze(pietro_aktualne)->aktualny_numer_kolejki++;
				pietro_aktualne = pietro_docelowe;
			}
			
		}
		
	}



	PietroWinda* tmpPietro = SymulatorPtr->ZbiorPieter.znajdzPietroPoNumerze(pietro_aktualne);
	if ((czy_wychodzi_z_windy == true) && (x_pasazera < 500 || x_pasazera > 1000))
	{
		czy_wychodzi_z_windy = false;
		czy_wyszedl_z_windy = true;
	}

	if (czy_wyszedl_z_windy == false)
	{
		if ((czy_wychodzi_z_windy == false) && (czy_idzie_do_windy == false) && (czy_jest_w_windzie == false))
		{
			if (tmpPietro->czy_po_prawej == true)
			{
				this->x_docelowy = 908 + (this->numer_w_kolejce_pietro - tmpPietro->aktualny_numer_kolejki) * 50;
			}
			else
			{
				this->x_docelowy = 420 - (this->numer_w_kolejce_pietro - tmpPietro->aktualny_numer_kolejki) * 50;
			}
		}
	}
	
	
	if ((czy_wyszedl_z_windy == true) && (x_pasazera < 50 || x_pasazera > 1000))
	{
		oznaczony_do_usuniecia = true;
	}


	int tmpoffset = 0;
	int offset = 5;
	int zmienna = x_docelowy - x_pasazera;
	if (std::abs(zmienna) < 5 && std::abs(zmienna) > 0)
	{
		tmpoffset = zmienna;
	}
	else if (zmienna < 0)
	{
		tmpoffset = -offset;
	}
	else if (zmienna > 0)
	{
		tmpoffset = offset;
	}
	else
	{
		tmpoffset = 0;
		if (czy_idzie_do_windy == true)
		{
			czy_idzie_do_windy = false;
			czy_jest_w_windzie = true;
			tmpKabina->pasazerowe_w_kabinie.push_back(this);
		}
	}

	x_pasazera = x_pasazera + tmpoffset;


}
PasazerWindy::~PasazerWindy()
{

}