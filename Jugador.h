#pragma once
#include "Caracter.h"

class Jugador : public Caracter
{
public:
	Jugador() {
		dinero = 0;

		x = 10;
		y = 50;

		opcionCaracterHeight = 3 * (rand() % 3);
		opcionCaracterWidth = 4 * (rand() % 2);

		EntidadAreaIzqSupX = 40;
		EntidadAreaIzqSupY = 30;
		EntidadAreaDerInfX = 915;
		EntidadAreaDerInfY = 135;
	};
	~Jugador(){}

   	virtual Rectangle getRectangle() { return Rectangle(x + 6, y, DimensionWidth - 12, DimensionHeight); }

	int getIndexWidth() { return this->indexWidth - opcionCaracterWidth; }

	int getMunicion() { return this->municion; }
	void setMunicion(int municion) { this->municion = municion; }

	int getDinero() { return this->dinero; }
	void setDinero(int dinero) { this->dinero = dinero; }
	
private: 
	int municion;
	int dinero;
};
