#pragma once
#include "Caracter.h"
#include "Jugador.h"

/*
jugadorAtStore = Si el jugador entra a la tienda; no entra a la tienda y; recien va a entrar;
0 = No esta en la tienda
1 = Esta en la tienda
*/


class Jugador : public Caracter
{
public:
	Jugador() {

		x = 10;
		y = 50;

		opcionCaracterHeight = 3 * (rand() % 3);
		opcionCaracterWidth = 4 * (rand() % 2);

		EntidadAreaIzqSupX = 0;
		EntidadAreaIzqSupY = 0;
		EntidadAreaDerInfX = 930;
		EntidadAreaDerInfY = 135;
	};
	~Jugador(){}

	int getjugadorAtStore() { return this->jugadorAtStore; }
	void setjugadorAtStore(int jugadorAtStore) { this->jugadorAtStore = jugadorAtStore; }

	int getIndexWidth() { return this->indexWidth - opcionCaracterWidth; }

	void atShop(Graphics^ gr, SoundPlayer ^ player) {
		
		Font^ myFont = gcnew Font("Times new Roman", 15);
	
		
			gr->DrawString("Estás en la tienda:", myFont, Brushes::Black, 670, 35);
			gr->DrawString("Pulse X para comprar munición", myFont, Brushes::Black, 600, 60);
			

			if (y >= 50 && x >= 830) y = 55;
			else if (x >= 820 && y <= 56) x = 819;
	
		
			if (jugadorAtStore == 0)
			{
				jugadorAtStore = 1;
				player->Load();
				player->PlaySync();
			}
			else jugadorAtStore == 0;
	}
/*
	void mover(Direccion direccion) {
		switch (direccion)
		{
		case Arriba:
			indexWidth = 3 + opcionCaracterWidth;
			indexHeight++;
			if (y - dy > EntidadAreaIzqSupY)
			{
				y = y - dy;
			}
			break;
		case Abajo:
			indexWidth = 0 + opcionCaracterWidth;
			indexHeight++;
			if (y + dy< EntidadAreaDerInfY)
			{
				y = y + dy;
			}
			break;
		case Izquierda:
			indexWidth = 1 + opcionCaracterWidth;
			indexHeight++;
			if (x - dx > EntidadAreaDerInfX)
			{
				x = x - dx;
			}
			break;
		case Derecha:
			indexWidth = 2 + opcionCaracterWidth;
			indexHeight++;
			if (x + dx < EntidadAreaDerInfX)
			{
				x = x + dx;
			}
			break;
		default: break;
		}

		if (indexHeight == 3 + opcionCaracterHeight) indexHeight = opcionCaracterHeight;

	}
*/
	int getMunicion() { return this->municion; }
	void setMunicion(int municion) { this->municion = municion; }

private: 
	int municion;
	int jugadorAtStore;
};
