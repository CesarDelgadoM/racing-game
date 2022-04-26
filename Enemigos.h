#include <stdio.h>
#include <windows.h>
#include <conio.h>

class Enemigos
{
	private:
		int x;
		float y;
		float velocidad = 1;
	
	public:
		Enemigos(int _x, float _y);
		Enemigos();
	
	public:
		void pintarEnemigo();
		void moverEnemigo();
		void borrarEnemigo();
		void colision(class Carro &carro);
		void setVelocidad(float _velocidad);
		void borrarExplocion();
		int getY();
		
	Pantalla posicion;
};

Enemigos::Enemigos(int _x, float _y)
{
	x = _x;
	y = _y;
}

void Enemigos::borrarEnemigo()
{
	posicion.gotoxy(x, y);    printf("     ");
	posicion.gotoxy(x, y + 1);printf("     ");
	posicion.gotoxy(x, y + 2);printf("     ");
	posicion.gotoxy(x, y + 3);printf("     ");
}

void Enemigos::pintarEnemigo()
{
	posicion.gotoxy(x, y);    printf("  %c  ", 223);
	posicion.gotoxy(x, y + 1);printf("%c%c%c%c%c", 219, 196, 219, 196, 219);
	posicion.gotoxy(x, y + 2);printf("  %c  ", 219);
	posicion.gotoxy(x, y + 3);printf("%c%c%c%c%c", 219, 196, 219, 196, 219);
}

void Enemigos::moverEnemigo()
{
	borrarEnemigo();
	y = y + velocidad;
	if(y > 45)
	{
		y = 2;
		x = rand() % 26  + 15;
	}
	pintarEnemigo();
}

void Enemigos::colision(class Carro &carro)
{
	if(x < carro.getX() + 5 && carro.getX() <= x + 5 && carro.getY() - 4 <= y && y - 4 <= carro.getY())
	{
		for (int i = 0; i < 2; i++)
		{
			posicion.gotoxy(x, y);    printf(" *** ");
			posicion.gotoxy(x, y + 1);printf("*****");
			posicion.gotoxy(x, y + 2);printf("*****");
			posicion.gotoxy(x, y + 3);printf(" *** ");
			Sleep(100);
			borrarExplocion();
			posicion.gotoxy(x, y);    printf("** **");
			posicion.gotoxy(x, y + 1);printf(" *** ");
			posicion.gotoxy(x, y + 2);printf(" *** ");
			posicion.gotoxy(x, y + 3);printf("** **");
			Sleep(100);
			borrarExplocion();
		}
		carro.restarFuel();
		carro.chocar();
		carro.pintar();
		borrarEnemigo();
		x = rand() % 26  + 15;
		y = 2;
	}
}

void Enemigos::borrarExplocion()
{
	posicion.gotoxy(x, y);    printf("     ");
	posicion.gotoxy(x, y + 1);printf("     ");
	posicion.gotoxy(x, y + 2);printf("     ");
	posicion.gotoxy(x, y + 3);printf("     ");
}

void Enemigos::setVelocidad(float _velocidad)
{
	velocidad = velocidad + _velocidad;
}

int Enemigos::getY()
{
	return y;
}
