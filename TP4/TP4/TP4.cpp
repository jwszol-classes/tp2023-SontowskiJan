#include "framework.h"
#include "TP4.h"
#include <cmath>
#include <vector>
#include "Symulator.h"
HWND hWnd;
const int FloorH = 126;
const int OknoX = 1366;
const int OknoY = 768;
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void Update(HWND hWnd, Rect* Winda);

class Symulator;
class ZbiorPieterWindy;
Symulator* SymulatorPtr = nullptr;

Bitmap* bufferScreen;
Graphics* bufferGraphics;


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, PWSTR pwCmdArgs, int nCmdShow)
{
	
	SymulatorPtr = new Symulator(OknoX,OknoY);
	SymulatorPtr->ZbiorPieter.dodajPietro(new PietroWinda(0, 171 + 4 * FloorH, 0));
	SymulatorPtr->ZbiorPieter.dodajPietro(new PietroWinda(1, 171 + 3 * FloorH, 1));
	SymulatorPtr->ZbiorPieter.dodajPietro(new PietroWinda(2, 171 + 2 * FloorH, 0));
	SymulatorPtr->ZbiorPieter.dodajPietro(new PietroWinda(3, 171 + 1 * FloorH, 1));
	SymulatorPtr->ZbiorPieter.dodajPietro(new PietroWinda(4, 171, 0));
	
	const wchar_t* Nazwa_klasy = L"Klasa okna";
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	WNDCLASS ok = {};
	ok.hInstance = hInstance;
	ok.lpszClassName = Nazwa_klasy;
	ok.lpfnWndProc = WindowProc;
	ok.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	


	RegisterClass(&ok);
	hWnd = CreateWindow(
		Nazwa_klasy,
		L"okno",
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
		CW_USEDEFAULT, CW_USEDEFAULT,
		OknoX, OknoY,
		NULL,
		NULL,
		hInstance,
		NULL);
	SetTimer(hWnd, ID_TIMER1, 16, NULL);

	ShowWindow(hWnd, nCmdShow);


	MSG wiadomosc;



	while (GetMessage(&wiadomosc, NULL, 0, 0) > 0)
	{
		TranslateMessage(&wiadomosc);
		DispatchMessage(&wiadomosc);

	}

	GdiplusShutdown(gdiplusToken);
	delete SymulatorPtr;
}
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	RECT prostokat;
	GetClientRect(hWnd, &prostokat);
	int screenWidth = prostokat.right;
	int screenHeight = prostokat.bottom;
	
	
	Color* bialy;
	bialy = new Color(255, 255, 255, 255);
	PAINTSTRUCT ps;
	HDC hdc;
	Pen* myPen;
	Graphics* myGraphics;



	switch (uMsg)
	{

	case WM_ERASEBKGND:
		return TRUE;
	case WM_CREATE:
	{
	
		CreateWindow(L"BUTTON", L"1", WS_VISIBLE | WS_CHILD, 40, 600, 30, 30, hWnd, (HMENU)ID_BUTTON01, NULL, NULL);
		CreateWindow(L"BUTTON", L"2", WS_VISIBLE | WS_CHILD, 40, 600 - 30, 30, 30, hWnd, (HMENU)ID_BUTTON02, NULL, NULL);
		CreateWindow(L"BUTTON", L"3", WS_VISIBLE | WS_CHILD, 40, 600 - (30 * 2), 30, 30, hWnd, (HMENU)ID_BUTTON03, NULL, NULL);
		CreateWindow(L"BUTTON", L"4", WS_VISIBLE | WS_CHILD, 40, 600 - (30 * 3), 30, 30, hWnd, (HMENU)ID_BUTTON04, NULL, NULL);

		CreateWindow(L"BUTTON", L"0", WS_VISIBLE | WS_CHILD, OknoX - 70, 474, 30, 30, hWnd, (HMENU)ID_BUTTON10, NULL, NULL);
		CreateWindow(L"BUTTON", L"2", WS_VISIBLE | WS_CHILD, OknoX - 70, 474 - 30, 30, 30, hWnd, (HMENU)ID_BUTTON12, NULL, NULL);
		CreateWindow(L"BUTTON", L"3", WS_VISIBLE | WS_CHILD, OknoX - 70, 474 - (30 * 2), 30, 30, hWnd, (HMENU)ID_BUTTON13, NULL, NULL);
		CreateWindow(L"BUTTON", L"4", WS_VISIBLE | WS_CHILD, OknoX - 70, 474 - (30 * 3), 30, 30, hWnd, (HMENU)ID_BUTTON14, NULL, NULL);

		CreateWindow(L"BUTTON", L"0", WS_VISIBLE | WS_CHILD, 40, 338, 30, 30, hWnd, (HMENU)ID_BUTTON20, NULL, NULL);
		CreateWindow(L"BUTTON", L"1", WS_VISIBLE | WS_CHILD, 40, 338 - 30, 30, 30, hWnd, (HMENU)ID_BUTTON21, NULL, NULL);
		CreateWindow(L"BUTTON", L"3", WS_VISIBLE | WS_CHILD, 40, 338 - (30 * 2), 30, 30, hWnd, (HMENU)ID_BUTTON23, NULL, NULL);
		CreateWindow(L"BUTTON", L"4", WS_VISIBLE | WS_CHILD, 40, 338 - (30 * 3), 30, 30, hWnd, (HMENU)ID_BUTTON24, NULL, NULL);

		CreateWindow(L"BUTTON", L"0", WS_VISIBLE | WS_CHILD, OknoX - 70, 222, 30, 30, hWnd, (HMENU)ID_BUTTON30, NULL, NULL);
		CreateWindow(L"BUTTON", L"1", WS_VISIBLE | WS_CHILD, OknoX - 70, 222 - 30, 30, 30, hWnd, (HMENU)ID_BUTTON31, NULL, NULL);
		CreateWindow(L"BUTTON", L"2", WS_VISIBLE | WS_CHILD, OknoX - 70, 222 - (30 * 2), 30, 30, hWnd, (HMENU)ID_BUTTON32, NULL, NULL);
		CreateWindow(L"BUTTON", L"4", WS_VISIBLE | WS_CHILD, OknoX - 70, 222 - (30 * 3), 30, 30, hWnd, (HMENU)ID_BUTTON34, NULL, NULL);

		CreateWindow(L"BUTTON", L"0", WS_VISIBLE | WS_CHILD, 40, 171 - 75, 30, 30, hWnd, (HMENU)ID_BUTTON40, NULL, NULL);
		CreateWindow(L"BUTTON", L"1", WS_VISIBLE | WS_CHILD, 40, (171 - 75) - 30, 30, 30, hWnd, (HMENU)ID_BUTTON41, NULL, NULL);
		CreateWindow(L"BUTTON", L"2", WS_VISIBLE | WS_CHILD, 40, (171 - 75) - (30 * 2), 30, 30, hWnd, (HMENU)ID_BUTTON42, NULL, NULL);
		CreateWindow(L"BUTTON", L"3", WS_VISIBLE | WS_CHILD, 40, (171 - 75) - (30 * 3), 30, 30, hWnd, (HMENU)ID_BUTTON43, NULL, NULL);
		bufferScreen = new Bitmap(screenWidth, screenHeight);
		bufferGraphics = Graphics::FromImage(bufferScreen);
		break;
	}
	case WM_COMMAND:
	{
			if (LOWORD(wParam) == ID_BUTTON01)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(0, 1, SymulatorPtr));
			}
			if ( LOWORD(wParam) == ID_BUTTON02)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(0, 2, SymulatorPtr));
			}
			if ( LOWORD(wParam) == ID_BUTTON03)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(0, 3, SymulatorPtr));
			}
			if (LOWORD(wParam) == ID_BUTTON04)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(0, 4, SymulatorPtr));
			}
			if (LOWORD(wParam) == ID_BUTTON10)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(1, 0, SymulatorPtr));
			}
			if (LOWORD(wParam) == ID_BUTTON12)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(1, 2, SymulatorPtr));
			}
			if (LOWORD(wParam) == ID_BUTTON13)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(1, 3, SymulatorPtr));
			}
			if (LOWORD(wParam) == ID_BUTTON14)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(1, 4, SymulatorPtr));
			}
			if (LOWORD(wParam) == ID_BUTTON20)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(2, 0, SymulatorPtr));
			}
			if (LOWORD(wParam) == ID_BUTTON21)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(2, 1, SymulatorPtr));
			}
			if ( LOWORD(wParam) == ID_BUTTON23 )
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(2, 3, SymulatorPtr));

			}
			if (LOWORD(wParam) == ID_BUTTON24)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(2, 4, SymulatorPtr));
			}
			if (LOWORD(wParam) == ID_BUTTON30)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(3, 0, SymulatorPtr));
			}
			if (LOWORD(wParam) == ID_BUTTON31)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(3, 1, SymulatorPtr));

			}
			if (LOWORD(wParam) == ID_BUTTON32)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(3, 2, SymulatorPtr));
			}
			if (LOWORD(wParam) == ID_BUTTON34)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(3, 4, SymulatorPtr));
			}
			if (LOWORD(wParam) == ID_BUTTON40)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(4, 0, SymulatorPtr));
			}
			if (LOWORD(wParam) == ID_BUTTON41)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(4, 1, SymulatorPtr));
			}
			if ( LOWORD(wParam) == ID_BUTTON42)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(4, 2, SymulatorPtr));
			}
			if (LOWORD(wParam) == ID_BUTTON43)
			{
				SymulatorPtr->ZbiorPasazerow->dodajPasazera(new PasazerWindy(4, 3, SymulatorPtr));
			}



		break;
	}
	case WM_PAINT:

	{

		hdc = BeginPaint(hWnd, &ps);
		myGraphics = new Graphics(hdc);		
		SymulatorPtr->rysuj(bufferGraphics);
		myGraphics->DrawImage(bufferScreen, 0, 0, screenWidth, screenHeight);
		delete myGraphics;
		EndPaint(hWnd, &ps);
		break;
	}

	case WM_TIMER:
	{
		switch (wParam)
		{
		case ID_TIMER1:
		{

			SymulatorPtr->update();
			RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
			break;

		}
		}

		break;
	}

	case WM_CLOSE:
	{
		
		KillTimer(hWnd, ID_TIMER1);
		PostQuitMessage(0);
		delete bufferScreen;
		delete bufferGraphics;
		break;
	}

	}
	delete bialy;
	return DefWindowProc(hWnd, uMsg, wParam, lParam);


}


