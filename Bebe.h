#pragma once 

#include "Caracter.h"

#define RangeBabyHeight 277

/*
mesVida = La cantidad de meses que el bebe tiene. Este dura 2 segundos, cantidad maxima de meses es 60 meses
esVacunado = El bebe es vacunado o no
*/

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

		OpcionCaracterHeight = 3 * (rand() % 4);
		OpcionCaracterWidth = 4 * (rand() % 2);

		mesVida = rand() % 30;

	};
	~Bebes(){};

	int getmesVida() { return this->mesVida; }
	bool getesVacunado() { return this->esVacunado; }
	void setesVacunado(bool esVacunado) { this->esVacunado = esVacunado; }


	void mover(Direccion direccion) {
		switch (direccion)
		{
		case Izquierda:
			indexHeight = 1 + OpcionCaracterHeight;
			indexWidth++;
			x -= dx;
			break;
		case Derecha:
			indexHeight = 2 + OpcionCaracterHeight;
			indexWidth++;
			x += dx;
			break;
		default:
			break;
		}

		if (indexWidth == 3 + OpcionCaracterWidth)
		{
			indexWidth = OpcionCaracterWidth;
		}
	}

private:
	int mesVida;
	bool esVacunado;
};
