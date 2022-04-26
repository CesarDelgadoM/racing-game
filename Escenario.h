#include <stdio.h>
#include <windows.h>
#include <conio.h>

class Escenario
{
	private:
		int x;
		int y;
		int limitVia = 46;
		int limitEscIzq = 43;
		int limitEscDer = 38;
		int velEscens = 1;
		int velVia = 2;
	public:
		Escenario(int _x, int _y);
	
	public:
		void via();
		void lateralIzq();
		void lateralDere();
		void setVelocidad(int vel);
		int getY();
		int getX();
		
	Pantalla pantalla;
};

Escenario::Escenario(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Escenario::via()
{	
	pantalla.gotoxy(30, y);    printf(" ");
	pantalla.gotoxy(30, y + 1);printf(" ");
	pantalla.gotoxy(30, y + 2);printf(" ");
	y = y + velVia;
	if (y > limitVia)
	{
		y = 2;
	}
	pantalla.gotoxy(30, y);    printf("%c", 219);
	pantalla.gotoxy(30, y + 1);printf("%c", 219);
	pantalla.gotoxy(30, y + 2);printf("%c", 219);
}

void Escenario::lateralIzq()
{
	pantalla.gotoxy(2, y);    printf("          ");
	pantalla.gotoxy(2, y + 1);printf("          ");
	pantalla.gotoxy(2, y + 2);printf("          ");
	pantalla.gotoxy(2, y + 3);printf("          ");
	pantalla.gotoxy(2, y + 4);printf("          ");
	pantalla.gotoxy(2, y + 5);printf("          ");	
	y = y + velEscens;
	if (y > limitEscIzq)
	{
		y = 2;
	}
	pantalla.gotoxy(2, y);    printf("%c%c%c%c%c%c%c%c%c%c", 240, 240, 240, 240, 220, 196, 196, 219, 219, 219);
	pantalla.gotoxy(2, y + 1);printf("%c%c%c%c%c%c%c%c%c%c", 249, 249, 249, 249, 220, 196, 196, 219, 219, 219);
	pantalla.gotoxy(2, y + 2);printf("%c%c%c%c%c%c%c%c%c%c", 249, 249, 249, 240, 220, 196, 196, 219, 219, 219);
	pantalla.gotoxy(2, y + 3);printf("%c%c%c%c%c%c%c%c%c%c", 240, 240, 240, 240, 220, 196, 196, 219, 219, 219);
	pantalla.gotoxy(2, y + 4);printf("%c%c%c%c%c%c%c%c%c%c", 249, 249, 249, 249, 220, 220, 240, 240, 240, 240);
	pantalla.gotoxy(2, y + 5);printf("%c%c%c%c%c%c%c%c%c%c", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196);
}

void Escenario::lateralDere()
{
	pantalla.gotoxy(48, y + 5);printf("          ");
	pantalla.gotoxy(48, y + 6);printf("          ");
	pantalla.gotoxy(48, y + 7);printf("          ");
	pantalla.gotoxy(48, y + 8);printf("          ");
	pantalla.gotoxy(48, y + 9);printf("          ");
	pantalla.gotoxy(48, y + 10);printf("          ");
	y = y + velEscens;
	if (y > limitEscDer)
	{
		y = -3;
	}
	pantalla.gotoxy(48 , y + 5);printf("%c%c%c%c%c%c%c%c%c%c", 238, 249, 249, 249, 240, 240, 240, 42, 240, 42);
	pantalla.gotoxy(48 , y + 6);printf("%c%c%c%c%c%c%c%c%c%c", 238, 249, 249, 240, 240, 240, 240, 240, 240, 42);
	pantalla.gotoxy(48 , y + 7);printf("%c%c%c%c%c%c%c%c%c%c", 249, 220, 220, 249, 240, 240, 240, 240, 240, 42);
	pantalla.gotoxy(48 , y + 8);printf("%c%c%c%c%c%c%c%c%c%c", 249, 220, 220, 220, 240, 240, 240, 240, 240, 42);
	pantalla.gotoxy(48 , y + 9);printf("%c%c%c%c%c%c%c%c%c%c", 238, 220, 220, 220, 240, 240, 220, 240, 240, 42);
	pantalla.gotoxy(48 , y + 10);printf("%c%c%c%c%c%c%c%c%c%c", 240, 240, 240, 240, 240, 240, 240, 240, 240, 42);
}

int Escenario::getY()
{
	return y;
}

int Escenario::getX()
{
	return x;
}

void Escenario::setVelocidad(int vel)
{
	velEscens = vel;
	velVia = vel + 2;
}



