#pragma once

#include "Jugador.h"
#include "Caracter"

using namespace std;

class Vacuna : public Caracter
{
public:
	Vacuna(int x, int y, int dx, int dy);
	~Vacuna();

	void mover(Direccion direccion);
	
private:

};

Vacuna::Vacuna(int x, int y, int dx, int dy) : Caracter()
{
	this->x = x;
	this->y = y;

	this->dx = dx;
	this->dy = dy;
}

void Vacuna :: mover(Direccion direccion)
{
	switch (direccion)
	{
	case Arriba:
		y = y - dy;
		break;
	case Abajo:
		y = y + dy;
		break;
	case Izquierda:
		x = x - dx;
		break;
	case Derecha:
		x = x + dx;
		break;
	default:
		break;
	}
}

Vacuna::~Vacuna()
{
}