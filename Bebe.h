#pragma once 

#include "Caracter.h"

/*
mesVida = La cantidad de meses que el bebe tiene. Este dura 2 segundos, cantidad maxima de meses es 60 meses
esVacunado = El bebe es vacunado o no
destX, destY = Para darles algo de vida a los bebes estos van a cualquier destino del mapa
FinishedWalkingX, FinishedWalkingY = Si el bebe ha llegado a la posicion X o Y de la posicion destinada
Walking = Decision del bebe para caminar por la por X o Y primero.  1 = Ruta por Y, 0 Ruta por X.
*/

//cantWidth 12
//cantHeight 8
class Bebes : public Caracter
{
public:
	Bebes();
	~Bebes();

	int  getMesVida() { return this->mesVida; }
	void add1MesVida() { this->mesVida = mesVida + 1; }

	int  getDestX() { return this->destX; }
	void setDestX(int destX) { this->destX = destX; }

	int  getDestY() { return this->destY; }
	void setDestY(int destY) { this->destY = destY; }

	bool getFinishedWalkingX() { return this->finishedWalkingX; }
	void setFinishedWalkingX(bool FinishedWalkingX) { this->finishedWalkingX = FinishedWalkingX; }

	bool getFinishedWalkingY() { return this->finishedWalkingY; }
	void setFinishedWalkingY(bool FinishedWalkingY) { this->finishedWalkingY = FinishedWalkingY; }

	bool getWalking() { return this->walking; }
	void setWalking(bool Walking) { this->walking = Walking; }

	bool getEsVacunado() { return this->esVacunado; }
	void setEsVacunado(bool esVacunado) { this->esVacunado = esVacunado; }

	bool getEsMayor30Meses() { return this->esMayor30Meses; }
	void setEsMayor30Meses(bool esMayor30Meses) { this->esMayor30Meses = esMayor30Meses; }

	Rectangle getRectangle(int x, int y) {
		if (esMayor30Meses == 0)
		{
			return Rectangle(x + 8, y + 8, DimensionWidth - 14, DimensionHeight - 6);
		}
		return Rectangle(x + 8, y + 8, DimensionWidth - 12, DimensionHeight - 7);
	}

	//void mover(Direccion direccion);

protected:
	int mesVida;
	bool esVacunado;

	int destX;
	int destY;

	bool walking;
	bool esMayor30Meses;

	bool finishedWalkingX;
	bool finishedWalkingY;

	int caracterWidth;
	int caracterHeight;
};

Bebes::Bebes() {

	EntidadAreaIzqSupX = 0;
	EntidadAreaIzqSupY = 280;
	EntidadAreaDerInfX = 930;
	EntidadAreaDerInfY = 727;

	x = rand() % EntidadAreaDerInfX;
	y = EntidadAreaIzqSupY + rand() % (EntidadAreaDerInfY - EntidadAreaIzqSupY);

	dx = rand() % 4 + 2;
	dy = rand() % 4 + 2;

	esVacunado = false;

	opcionCaracterHeight = 3 * (rand() % 4);
	opcionCaracterWidth = 4 * (rand() % 2);

	indexHeight = 0 + opcionCaracterHeight;

	esMayor30Meses = 0;

	mesVida = rand() % 12;

	walking = rand() % 2;

	destX = rand() % EntidadAreaDerInfX;
	destY = EntidadAreaIzqSupY + rand() % (EntidadAreaDerInfY - EntidadAreaIzqSupY);

};
Bebes:: ~Bebes()
{
}

/*
void Bebes :: mover(Direccion direccion) {


	switch (direccion)
	{
	case Arriba:
		indexWidth = 3 + opcionCaracterWidth;
		indexHeight++;
		y = y - dy;
		break;
	case Abajo:
		indexWidth = 0 + opcionCaracterWidth;
		indexHeight++;
		y = y + dy;
		break;
	case Izquierda:
		indexWidth = 1 + opcionCaracterWidth;
		indexHeight++;
		x = x - dx;
		break;
	case Derecha:
		indexWidth = 2 + opcionCaracterWidth;
		indexHeight++;
		x = x + dx;
		break;
	default:
		break;
	}

	if (indexHeight == 3 + opcionCaracterHeight) indexHeight = opcionCaracterHeight;

}

*/
