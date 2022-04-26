#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <list>
#include "Pantalla.h"
#include "Escenario.h"
#include "Carro.h"
#include "Enemigos.h"

using namespace std;

void iniciarPantalla();
list<Escenario*> crearEscenarioVia();
list<Escenario*> crearEscenarioIzq();
list<Escenario*> crearEscenarioDer();
list<Enemigos*> crearListEnemigos();

int main()
{
	bool gameover = false;
	bool aumentar = false;
	int limitePuntaje = 2000;
	int score = 0;
	float aumento = 1;
	Carro miCarro(20, 40, 3);
	
	iniciarPantalla();

	//lista de la via
	list<Escenario*> listaVia = crearEscenarioVia();
	list<Escenario*>::iterator iterVia;

	//lista del escenario izquierda
	list<Escenario*> listIzq = crearEscenarioIzq();
	list<Escenario*>::iterator iterIzq;
	
	//lista del escenario derecha
	list<Escenario*> listDer = crearEscenarioDer();
	list<Escenario*>::iterator iterDer;
	
	//lista de enemigos
	list<Enemigos*> listEnemigos = crearListEnemigos();
	list<Enemigos*>::iterator iterEnem;
	
	//ciclo del juego
	while(gameover != true)
	{	
		miCarro.mover();
		int i = 0;
		iterVia=listaVia.begin();
		iterIzq=listIzq.begin();
		iterDer=listDer.begin();
		
		for(iterVia=listaVia.begin(); iterVia!=listaVia.end(); iterVia++)
		{
			(*iterVia) -> via();
		}

		for(iterIzq=listIzq.begin(); iterIzq!=listIzq.end(); iterIzq++)
		{
			(*iterIzq) -> lateralIzq();
		}

		for(iterDer=listDer.begin(); iterDer!=listDer.end(); iterDer++)
		{
			(*iterDer) -> lateralDere();
		}

		for(iterEnem = listEnemigos.begin(); iterEnem!=listEnemigos.end(); iterEnem++)
		{
			
			(*iterEnem) -> moverEnemigo();
			(*iterEnem) -> colision(miCarro);
			
			if ((*iterEnem) -> getY() == 45)
			{
				score = score + 100;
				miCarro.setScore(score);
			}
			
			if (score >= limitePuntaje)
			{
				limitePuntaje += 1000;
				(*iterEnem) -> setVelocidad(1);
			}
		}
		if(miCarro.getVidas() == 0)
		{
			system("cls");
			gameover = true;
		}
		Sleep(10);
	}
	
	pantalla.gotoxy(35, 20);printf("HI-SCORE: %d", score);
	pantalla.gotoxy(36, 22);printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
	system("pause");
	return 0;

}

list<Escenario*> crearEscenarioVia()
{
	list<Escenario*> listaVia;
	int j = 2;
	for(int i = 0; i < 9; i++)
	{
		listaVia.push_back(new Escenario(30, j));
		j = j + 5;
	}
	return listaVia;
}

list<Escenario*> crearEscenarioIzq()
{
	list<Escenario*> escDer;
	int j = 2;
	for(int i = 0; i < 3; i++)
	{
		escDer.push_back(new Escenario(30, i + j));
		j += 6;
	}
	return escDer;
}

list<Escenario*> crearEscenarioDer()
{
	list<Escenario*> escIzq;
	int j = 2;
	for(int i = 0; i < 4; i++)
	{
		escIzq.push_back(new Escenario(30, i + j));
		j += 6;
	}
	return escIzq;
}

list<Enemigos*> crearListEnemigos()
{
	list<Enemigos*> listEnemigos;
	for(int i = 0; i < 3; i++)
	{
		Enemigos* enemigo = new Enemigos(rand() % 26  + 15, (rand() % 40  + 3) + 5);
		enemigo->setVelocidad(rand() % 1);
		listEnemigos.push_back(enemigo);

	}
	return listEnemigos;
}

void iniciarPantalla()
{
	system("color 4f");
	Pantalla pantalla;
	pantalla.ajustarVentana(80, 50);
	pantalla.ocultarCursor();
	pantalla.marco();
}