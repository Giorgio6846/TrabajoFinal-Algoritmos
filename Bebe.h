#pragma once 

#include "Caracter.h"

#define RangeBabyHeight 277
//cantWidth 12
//cantHeight 8
class Bebes : public Caracter
{
public:
	Bebes() {

		x = rand() % ScreenWidth;
		y = RangeBabyHeight + rand() % (ScreenHeight - RangeBabyHeight);

		dx = rand() % 10;

		esVacunado = false;

		OpcionCaracterHeight = 3 * rand() % 4;
		OpcionCaracterWidth = 4 * rand() % 2;

	};
	~Bebes(){};

	bool getesVacunado() { return this->esVacunado; }
	void setesVacunado(bool esVacunado) { this->esVacunado = esVacunado; }


	void mover(Direccion direccion) {
		switch (direccion)
		{
		case Izquierda:
			indexWidth = 1 + OpcionCaracterWidth;
			indexHeight++;
			x -= dx;
			break;
		case Derecha:
			indexWidth = 2 + OpcionCaracterWidth;
			indexHeight++;
			x += dx;
			break;
		default:
			break;
		}

		if (indexHeight == 3 + OpcionCaracterWidth) indexHeight = OpcionCaracterWidth;

	}

private:
	int mesVida;
	bool esVacunado;
};
