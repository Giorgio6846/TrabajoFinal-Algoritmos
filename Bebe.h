#pragma once 

#include "Caracter.h"

#define BebeAreaIzqSupX 0
#define BebeAreaIzqSupY 277
#define BebeAreaDerInfX 959
#define BebeAreaDerInfY 727

/*
BebeAreaIzqSupX
BebeAreaIzqSupY
BebeAreaDerInfX
BebeAreaDerInfY

Rectangulo en donde el jugador solo se puede mover
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
	Bebes() {

		x = rand() % BebeAreaDerInfX;
		y = BebeAreaIzqSupY + rand() % (BebeAreaDerInfY - BebeAreaIzqSupY);

		dx = rand() % 4 + 2;
		dy = rand() % 4 + 2;

		esVacunado = false;

		//Arreglar Opcion Bebe
		//OpcionCaracterHeight = 3 * (rand() % 4);
		//OpcionCaracterWidth = 4 * (rand() % 2);

		OpcionCaracterHeight = 3 * rand() % 4;
		OpcionCaracterWidth = 4 * rand() % 2;

		mesVida = rand() % 30;

		Walking = rand() % 2;

		destX = rand() % BebeAreaDerInfX;
		destY = BebeAreaIzqSupY + rand() % (BebeAreaDerInfY - BebeAreaIzqSupY);
	};
	~Bebes(){};

	int getmesVida() { return this->mesVida; }
	
	int getdestX() { return this->destX; }
	void setdestX(int destX) { this->destX = destX; }

	int getdestY() { return this->destY; }
	void setdestY(int destY) { this->destY = destY; }

	bool getFinishedWalkingX() { return this->FinishedWalkingX; }
	void setFinishedWalkingX(bool FinishedWalkingX) { this->FinishedWalkingX = FinishedWalkingX; }

	bool getFinishedWalkingY() { return this->FinishedWalkingY; }
	void setFinishedWalkingY(bool FinishedWalkingY) { this->FinishedWalkingY = FinishedWalkingY; }

	bool getWalking() { return this->Walking; }
	void setWalking(bool Walking) { this->Walking = Walking; }

	bool getesVacunado() { return this->esVacunado; }
	void setesVacunado(bool esVacunado) { this->esVacunado = esVacunado; }

	void mover(Direccion direccion) {
		switch (direccion)
		{
		case Arriba:
			indexWidth = 3 + OpcionCaracterWidth;
			indexHeight++;
			y = y - dy;
			break;
		case Abajo:
			indexWidth = 0 + OpcionCaracterWidth;
			indexHeight++;
			y = y + dy;
			break;
		case Izquierda:
			indexWidth = 1 + OpcionCaracterWidth;
			indexHeight++;
			x = x - dx;
			break;
		case Derecha:
			indexWidth = 2 + OpcionCaracterWidth;
			indexHeight++;
			x = x + dx;
			break;
		default:
			break;
		}

		if (indexHeight == 3 + OpcionCaracterWidth)
		{
			indexHeight = OpcionCaracterWidth;
		}
	}

private:
	int mesVida;
	bool esVacunado;

	int destX;
	int destY;

	bool Walking;

	bool FinishedWalkingX;
	bool FinishedWalkingY;
};
