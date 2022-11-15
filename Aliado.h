#pragma once
#include "Caracter.h"

//Tipo: 0 es curadora y 1 da balas 

using namespace std;

class Aliadas : public Caracter
{
public:
	Aliadas();
	~Aliadas();

	bool getEstaDisponible() { return this->estaDisponible; }
	void setEstaDisponible(bool estaDisponible) { this->estaDisponible = estaDisponible; }
	 
	void movimientoPosicionJugador(int jugadorX, int jugadorY);
	
	Rectangle getRectangle() { return Rectangle(x, y, DimensionWidth, DimensionHeight); }

	void inicio();

	int getContador() { return this->contador; }
	void setContador(int contador) { this->contador = contador; }

	bool getHabilidadActivada() { return this->habilidadActivada; }
	void setHabilidadActivada(bool habilidadActivada) { this->habilidadActivada = habilidadActivada; }


private:
	bool walking;
	bool finishedWalkingX;
	bool finishedWalkingY;

	bool estaDisponible;
	bool habilidadActivada;

	int contador;

	int valorAceleracion;

	int valorAceleracionAnteriorDX;
	int valorAceleracionAnteriorDY;

	
};

Aliadas::Aliadas()
{
	contador = 5;

	habilidadActivada = 0;
	estaDisponible = 0;

	EntidadAreaIzqSupX = 0;
	EntidadAreaIzqSupY = 20;
	EntidadAreaDerInfX = 930;
	EntidadAreaDerInfY = 135;
}

Aliadas::~Aliadas()
{
}

void Aliadas::inicio()
{
	x = EntidadAreaIzqSupX + rand() % (EntidadAreaDerInfX - EntidadAreaIzqSupX);
	y = EntidadAreaIzqSupY + rand() % (EntidadAreaDerInfY - EntidadAreaIzqSupY);
}

void Aliadas::movimientoPosicionJugador(int jugadorX, int jugadorY)
{
	finishedWalkingX = x == jugadorX;
	finishedWalkingY = y == jugadorY;


	if (finishedWalkingX == 0 && finishedWalkingY == 0)
	{
		walking = rand() % 2;
	}
	else
	{
		if (finishedWalkingX == 1) walking = 1;
		if (finishedWalkingY == 1) walking = 0;
	}

	if (walking)
	{
		if (abs(y - jugadorY) <= dy) dy = rand() % 10 + 2;
		if (y < jugadorY) mover(Abajo);
		else mover(Arriba);
	}
	else
	{
		if (abs(x - jugadorX) <= dx) dx = rand() % 10 + 2;
		if (x > jugadorX) mover(Izquierda);
		else mover(Derecha);
	}
}
