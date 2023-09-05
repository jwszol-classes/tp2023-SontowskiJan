#include "KabinaWindy.h"
#include <chrono>
#include <string>
KabinaWindy::KabinaWindy(Symulator* SymulatorPtr): SymulatorPtr{SymulatorPtr}
{
	wymiary = new Rect(498, 45, 370, 126);
	aktualna_pozycja = wymiary->Y;
}

void KabinaWindy::rysuj(Graphics* bufferGraphics)
{
	Pen* myPen2 = new Pen(Color(69, 25, 25, 217), 5);
	Rect* kopiaWymiary = new Rect(*wymiary);
	kopiaWymiary->Y = aktualna_pozycja;
	bufferGraphics->DrawRectangle(myPen2, *kopiaWymiary);
	FontFamily   fontFamily(L"Arial");
	Font         font(&fontFamily, 20, FontStyleBold, UnitPoint);
	RectF        rectF(950,0,100,100);
	SolidBrush   solidBrush(Color(255, 0, 0, 255));
	std::wstring tmpWstring(std::to_wstring(pasazerowe_w_kabinie.size()*PasazerWindy::waga_pasazera));
	const wchar_t* tmpWchar = tmpWstring.c_str();
	bufferGraphics->DrawString(tmpWchar, 3, &font, rectF, NULL, &solidBrush);
	delete kopiaWymiary;
	delete myPen2;
}
void KabinaWindy::ustawMiejsceDocelowe(int numer_pietra)
{
	this->pietro_docelowe = numer_pietra;
}

void KabinaWindy::usun_pasazera_z_kabiny(PasazerWindy* PasazerPtr)
{
	for (int i = 0; i < pasazerowe_w_kabinie.size(); i++)
	{
		if (pasazerowe_w_kabinie[i] == PasazerPtr)
		{
			pasazerowe_w_kabinie.erase(pasazerowe_w_kabinie.begin() + i);
			return;
		}
	}
}
bool KabinaWindy::czy_winda_pelna()
{
	int waga_pasazerow_ktorzy_sie_licza = 0;
	for (int i = 0; i < SymulatorPtr->ZbiorPasazerow->ZbiorPasazerow.size(); i++)
	{
		PasazerWindy* PasazerTmp = SymulatorPtr->ZbiorPasazerow->ZbiorPasazerow[i];
		if ((PasazerTmp->czy_jest_w_windzie == true) || (PasazerTmp->czy_idzie_do_windy == true))
		{
			waga_pasazerow_ktorzy_sie_licza += PasazerWindy::waga_pasazera;
		}
	}

	if (waga_pasazerow_ktorzy_sie_licza/PasazerWindy::waga_pasazera == maksymalne_obciazenie_windy/PasazerWindy::waga_pasazera)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
void KabinaWindy::update()
{
	bool winda_zatrzymana = false;
	if ( (this->czy_w_ruchu == false) && (pasazerowe_w_kabinie.size() != maksymalne_obciazenie_windy/PasazerWindy::waga_pasazera) )
	{
		std::vector<PasazerWindy*> tmp_zbior_pasazerow_vector = SymulatorPtr->ZbiorPasazerow->ZbiorPasazerow;
		for (int i = 0; i < tmp_zbior_pasazerow_vector.size(); i++)
		{
			if (tmp_zbior_pasazerow_vector[i]->czy_wyszedl_z_windy == false)
			{
				if ((tmp_zbior_pasazerow_vector[i]->czy_wychodzi_z_windy == true) || (tmp_zbior_pasazerow_vector[i]->czy_idzie_do_windy == true) || (tmp_zbior_pasazerow_vector[i]->czy_jest_w_windzie == false) && (tmp_zbior_pasazerow_vector[i]->pietro_aktualne == aktualne_pietro))
				{
					winda_zatrzymana = true;
					break;
				}
			}
			
		}
	}

	if (  (this->czy_w_ruchu == false) && (this->aktualne_pietro != this->pietro_docelowe) && (winda_zatrzymana == false) )
	{
		if (this->pietro_docelowe < this->aktualne_pietro)
		{
			this->aktualne_pietro = this->aktualne_pietro - 1;
		}
		else
		{
			this->aktualne_pietro = this->aktualne_pietro + 1;
		}
		this->aktualne_pietro_y = SymulatorPtr->ZbiorPieter.znajdzPietroPoNumerze(this->aktualne_pietro)->y_pietra - wymiary->Height;
		this->czy_w_ruchu = true;
	}

	int tmpoffset = 0;
	int offset = 5;
	int zmienna = aktualne_pietro_y - aktualna_pozycja;
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
		this->czy_w_ruchu = false;
	}

	aktualna_pozycja = aktualna_pozycja + tmpoffset;
	if ((czy_w_ruchu == false) && (aktualne_pietro == pietro_docelowe))
	{
		if (pasazerowe_w_kabinie.size() != 0)
		{
			pietro_docelowe = pasazerowe_w_kabinie[0]->pietro_docelowe;
		}
		else
		{ 
			bool czy_ktos_idzie_do_windy = false;
			for (int i = 0; i < SymulatorPtr->ZbiorPasazerow->ZbiorPasazerow.size(); i++)
			{
				PasazerWindy* PasazerTmp = SymulatorPtr->ZbiorPasazerow->ZbiorPasazerow[i];
				if (PasazerTmp->czy_idzie_do_windy == true)
				{
					czy_ktos_idzie_do_windy = true;
					break;
				}
			}
			if (czy_ktos_idzie_do_windy == false) 
			{
				for (int i = 0; i < SymulatorPtr->ZbiorPasazerow->ZbiorPasazerow.size(); i++)
				{
					PasazerWindy* PasazerTmp = SymulatorPtr->ZbiorPasazerow->ZbiorPasazerow[i];
					if ((PasazerTmp->czy_idzie_do_windy == false) && (PasazerTmp->czy_wychodzi_z_windy == false) && (PasazerTmp->czy_wyszedl_z_windy == false))
					{
						pietro_docelowe = SymulatorPtr->ZbiorPasazerow->ZbiorPasazerow[i]->pietro_aktualne;
						break;
					}
				}
				if ( (SymulatorPtr->ZbiorPasazerow->ZbiorPasazerow.size() == 0) && (pietro_docelowe != 0) )
				{
					if (oczekuje_na_powrot_na_parter == false)
					{
						oczekuje_na_powrot_na_parter = true;
						poczatek_czekania = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
					}
					else
					{
						long long aktualna_chwila = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
						if (aktualna_chwila - poczatek_czekania >= czas_czekania)
						{
							pietro_docelowe = 0;
							oczekuje_na_powrot_na_parter = false;
						}
					}
				}
				else
				{
					oczekuje_na_powrot_na_parter = false;
				}
			}
		}
	}
	


}
KabinaWindy::~KabinaWindy()
{
	delete wymiary;
}