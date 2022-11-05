#pragma once
#include "Caracter.h"
#include "Jugador.h"

/*
JugadorAreaIzqSupX
JugadorAreaIzqSupY
JugadorAreaDerInfX
JugadorAreaDerInfY

Rectangulo en donde el jugador solo se puede mover
No se ha usado el tama�o de la ventana porque este se va a agrandar para poner la interfaz del juego

jugadorAtStore = Si el jugador entra a la tienda; no entra a la tienda y; recien va a entrar;
0 = No esta en la tienda
1 = Esta en la tienda
*/

#define JugadorAreaIzqSupX 0
#define JugadorAreaIzqSupY 0
#define JugadorAreaDerInfX 930
#define JugadorAreaDerInfY 135


class Jugador : public Caracter
{
public:
	Jugador() {

		x = 10;
		y = 50;

		//Arreglar Opcion Bebe
		//opcionCaracterHeight = 3 * (rand() % 3);
		//opcionCaracterWidth = 4 * (rand() % 2);

		opcionCaracterHeight = 3 * rand() % 3;
		opcionCaracterWidth = 4 * rand() % 2;
	};
	~Jugador(){}

	int getjugadorAtStore() { return this->jugadorAtStore; }
	void setjugadorAtStore(int jugadorAtStore) { this->jugadorAtStore = jugadorAtStore; }

	int getIndexWidth() { return this->indexWidth - opcionCaracterWidth; }

	void atShop(Graphics^ gr, SoundPlayer ^ player) {
		
		Font^ myFont = gcnew Font("Times new Roman", 15);
	
		
			gr->DrawString("Est�s en la tienda:", myFont, Brushes::Black, 670, 35);
			gr->DrawString("Pulse X para comprar munici�n", myFont, Brushes::Black, 600, 60);
			

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

	void mover(Direccion direccion) {
		switch (direccion)
		{
		case Arriba:
			indexWidth = 3 + opcionCaracterWidth;
			indexHeight++;
			if (y - dy > JugadorAreaIzqSupY)
			{
				y = y - dy;
			}
			break;
		case Abajo:
			indexWidth = 0 + opcionCaracterWidth;
			indexHeight++;
			if (y + dy< JugadorAreaDerInfY)
			{
				y = y + dy;
			}
			break;
		case Izquierda:
			indexWidth = 1 + opcionCaracterWidth;
			indexHeight++;
			x = x - dx;
			break;
		case Derecha:
			indexWidth = 2 + opcionCaracterWidth;
			indexHeight++;
			if (x + dx < JugadorAreaDerInfX)
			{
				x = x + dx;
			}
			break;
		default: break;
		}

		if (indexHeight == 3 + opcionCaracterWidth) indexHeight = opcionCaracterWidth;

	}

	int getMunicion() { return this->municion; }
	void setMunicion(int municion) { this->municion = municion; }

private: 
	int municion;
	int jugadorAtStore;
};
