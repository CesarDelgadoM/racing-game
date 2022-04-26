#include <stdio.h>
#include <windows.h>
#include <conio.h>

class Pantalla
{
	public:
		void gotoxy(int _x, int _y);
		void ocultarCursor();
		void marco();
		bool ajustarVentana(int ancho, int alto);
};

void Pantalla::gotoxy(int _x, int _y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = _x;
	dwPos.Y = _y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void Pantalla::ocultarCursor()
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 100;
	cci.bVisible = false;
	SetConsoleCursorInfo(hCon, &cci);
}

bool Pantalla::ajustarVentana(int ancho, int alto)
{
	_COORD cordenada;
	cordenada.X = ancho;
	cordenada.Y = alto;
	_SMALL_RECT rect;
	rect.Top = 0;
	rect.Left = 0;
	rect.Right = ancho - 1;
	rect.Bottom = alto - 1;
	//obtenemos el HANDLE de la consola
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	//ajustamos el BUFFER al nuevo tamanio
	SetConsoleScreenBufferSize(hCon, cordenada);
	//cambiamos el tamanio de la consola
	SetConsoleWindowInfo(hCon, true, &rect);
	return true;
}

void Pantalla::marco()
{
	gotoxy(1, 1);printf("%c", 201);	
	//lineas Horizontales
	for(int i = 2; i < 58; i++)
	{
		gotoxy(i, 1);printf("%c", 205);
		gotoxy(i, 49);printf("%c", 205);
	}
	gotoxy(58, 1);printf("%c", 187);
	//lineas Verticales
	for(int i = 2; i < 49; i++)
	{
		gotoxy(1, i);printf("%c", 186);
		gotoxy(58, i);printf("%c", 186);
		gotoxy(14, i);printf("%c", 179);
		gotoxy(45, i);printf("%c", 179);
	}
	gotoxy(1, 49);printf("%c", 200);
	gotoxy(58, 49);printf("%c", 188);
}
