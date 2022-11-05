#pragma once 

#include "Caracter.h"

#define BebeAreaIzqSupX 0
#define BebeAreaIzqSupY 260
#define BebeAreaDerInfX 959
#define BebeAreaDerInfY 727

/*
BebeAreaIzqSupX
BebeAreaIzqSupY
BebeAreaDerInfX
BebeAreaDerInfY
Rectangulo en donde el bebe solo se puede mover
No se ha usado el tamaño de la ventana porque este se va a agrandar para poner la interfaz del juego
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


	void mover(Direccion direccion);

protected:
	int mesVida;
	bool esVacunado;

	int destX;
	int destY;

	bool walking;

	bool finishedWalkingX;
	bool finishedWalkingY;

	int caracterWidth;
	int caracterHeight;
};

Bebes::Bebes() {

	x = rand() % BebeAreaDerInfX;
	y = BebeAreaIzqSupY + rand() % (BebeAreaDerInfY - BebeAreaIzqSupY);

	dx = rand() % 4 + 2;
	dy = rand() % 4 + 2;

	esVacunado = false;

	caracterHeight = 3 * rand() % 4;
	caracterWidth = 4 * rand() % 2;

	indexHeight = 0 + caracterHeight;

	mesVida = rand() % 30;

	walking = rand() % 2;

	destX = rand() % BebeAreaDerInfX;
	destY = BebeAreaIzqSupY + rand() % (BebeAreaDerInfY - BebeAreaIzqSupY);
};
Bebes:: ~Bebes()
{
}

void Bebes :: mover(Direccion direccion) {


	switch (direccion)
	{
	case Arriba:
		indexWidth = 3 + caracterWidth;
		indexHeight++;
		y = y - dy;
		break;
	case Abajo:
		indexWidth = 0 + caracterWidth;
		indexHeight++;
		y = y + dy;
		break;
	case Izquierda:
		indexWidth = 1 + caracterWidth;
		indexHeight++;
		x = x - dx;
		break;
	case Derecha:
		indexWidth = 2 + caracterWidth;
		indexHeight++;
		x = x + dx;
		break;
	default:
		break;
	}


	if (indexHeight == 12) indexHeight = 9;
	if (indexHeight == 9) indexHeight = 6;
	if (indexHeight == 6) indexHeight = 3;
	if (indexHeight == 3) indexHeight = 0;
}