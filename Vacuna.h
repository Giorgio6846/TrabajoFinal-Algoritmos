#pragma once

#include "Jugador.h"
#include "Caracter.h"

using namespace std;

class Vacuna : public Caracter
{
public:
	Vacuna(int x, int y, int dx, int dy, int direccion);
	~Vacuna();

	int getContador() { return this->contador; }
	void setContador() { this->contador = contador + 1; }

	Rectangle getRectangle(int x, int y) {
		if (indexWidth == 1 || indexWidth == 0)
		{
			return Rectangle(x + 15, y, DimensionWidth - 30, DimensionHeight);
		}
		return Rectangle(x, y + 15, DimensionWidth, DimensionHeight - 30);
	}


	void mover();

	bool getEstaGastada() { return this->estaGastada; }
	void setEstaGastada() { this->estaGastada = 1; }

private:
	int direccion;
	int contador;
	bool estaGastada;
};

Vacuna::Vacuna(int x, int y, int dx, int dy, int direccion) : Caracter()
{
	EntidadAreaIzqSupX = 0;
	EntidadAreaIzqSupY = 0;
	EntidadAreaDerInfX = 930;
	EntidadAreaDerInfY = 727;

	this->estaGastada = 0;

	this->DimensionHeight = 0.1;
	this->DimensionWidth = 0.1;

	this->x = x;
	this->y = y;

	this->dx = dx;
	this->dy = dy;

	this->direccion = direccion;
}

void Vacuna :: mover()
{
	switch (direccion)
	{
	case 3:
		y = y - dy;
		indexWidth = 1;
		break;
	case 0:
		y = y + dy;
		indexWidth = 0;
		break;
	case 1:
		x = x - dx;
		indexWidth = 2;
		break;
	case 2:
		x = x + dx;
		indexWidth = 3;
		break;
	default:
		break;
	}
}

Vacuna::~Vacuna()
{
}
