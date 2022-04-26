#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define IZQUIERDA 75
#define DERECHA 77
#define ARRIBA 72
#define ABAJO 80

class Carro
{
	private:
		int x;
		int y;
		int danios = 19;
		int velocidad = 5;
		int vidas = 1;
		int score = 0;
	
	public:
		Carro(int _x, int _Y, int vidas);
	
	public:
		void pintar();
		void borrar();
		void mover();
		void chocar();
		void pintarHud();
		void setScore(int score);
		int getX();
		int getY();
		void restarFuel();
		void borrarExplosion();
		int getVidas();
	
	Pantalla posicion;
};

Carro::Carro(int _x, int _y, int _vidas)
{
	x = _x;
	y = _y;
	vidas = _vidas;
}

void Carro::pintar()
{
	posicion.gotoxy(x, y);    printf("  %c  ", 223);
	posicion.gotoxy(x, y + 1);printf("%c%c%c%c%c", 219, 196, 219, 196, 219);
	posicion.gotoxy(x, y + 2);printf("  %c  ", 219);
	posicion.gotoxy(x, y + 3);printf("%c%c%c%c%c", 219, 196, 219, 196, 219);
}

void Carro::borrar()
{
	posicion.gotoxy(x, y);    printf("     ");
	posicion.gotoxy(x, y + 1);printf("     ");
	posicion.gotoxy(x, y + 2);printf("     ");
	posicion.gotoxy(x, y + 3);printf("     ");
}

void Carro::borrarExplosion()
{
	posicion.gotoxy(x, y);    printf("     ");
	posicion.gotoxy(x, y + 1);printf("     ");
	posicion.gotoxy(x, y + 2);printf("     ");
	posicion.gotoxy(x, y + 3);printf("     ");
}

void Carro::mover()
{
	pintarHud();
	if(kbhit())
	{
		char tecla = getch();
		
		borrar();
		
		if (tecla == IZQUIERDA && x > 18)
		{
			x = x - velocidad;
		}
		if (tecla == DERECHA && x + 5 < 42)
		{
			x = x + velocidad;
		}
		if (tecla == ARRIBA && y > 8)
		{
			y = y - velocidad;
		}
		if (tecla == ABAJO && y < 43)
		{
			y = y + velocidad;
		}
	}
	pintar();
}

void Carro::pintarHud()
{	
	posicion.gotoxy(60, 13);printf("--------------------");
	posicion.gotoxy(67, 14);printf("SCORE");
	posicion.gotoxy(67, 15);printf("%d", score);
	posicion.gotoxy(60, 16);printf("--------------------");
	posicion.gotoxy(67, 17);printf("VIDAS");
	posicion.gotoxy(69, 18);printf("%d", vidas);
	posicion.gotoxy(60, 19);printf("--------------------");
	posicion.gotoxy(67, 20);printf("DANIOS ");
	posicion.gotoxy(60, 21);printf("                   ");
	posicion.gotoxy(60, 22);printf("--------------------");
	for (int i = 0; i < danios; i++)
	{
		posicion.gotoxy(60 + i, 21);printf("%c", 219);
	}
}

void Carro::chocar()
{
	if (danios == 0)
	{
		Beep(800, 300);
		Beep(500, 300);
		Beep(300, 300);
		for (int i = 0; i < 6; i++)
		{
			posicion.gotoxy(x, y);    printf(" *** ");
			posicion.gotoxy(x, y + 1);printf("*****");
			posicion.gotoxy(x, y + 2);printf("*****");
			posicion.gotoxy(x, y + 3);printf(" *** ");
			Sleep(100);
			borrarExplosion();
			posicion.gotoxy(x, y);    printf("** **");
			posicion.gotoxy(x, y + 1);printf(" *** ");
			posicion.gotoxy(x, y + 2);printf(" *** ");
			posicion.gotoxy(x, y + 3);printf("** **");
			Sleep(100);
			borrarExplosion();
		}
		vidas--;
		danios = 18;
	}
}

void Carro::setScore(int _score)
{ 
	score = _score;
}

int Carro::getVidas()
{
	return vidas;
}

int Carro::getX()
{
	return x;
}

int Carro::getY()
{
	return y;
}

void Carro::restarFuel()
{
	--danios;
}
