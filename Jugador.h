#pragma once
#include "Caracter.h"
#include "Jugador.h"

/*
JugadorAreaIzqSupX
JugadorAreaIzqSupY
JugadorAreaDerInfX
JugadorAreaDerInfY

Rectangulo en donde el jugador solo se puede mover
No se ha usado el tamaño de la ventana porque este se va a agrandar para poner la interfaz del juego
*/

#define JugadorAreaIzqSupX 0
#define JugadorAreaIzqSupY 0
#define JugadorAreaDerInfX 930
#define JugadorAreaDerInfY 135


class Jugador : public Caracter
{
public:
	Jugador() {

		x = rand() % JugadorAreaDerInfX;
		y = rand() % JugadorAreaDerInfY;

		//Arreglar Opcion Bebe
		//OpcionCaracterHeight = 3 * (rand() % 3);
		//OpcionCaracterWidth = 4 * (rand() % 2);

		OpcionCaracterHeight = 3 * rand() % 3;
		OpcionCaracterWidth = 4 * rand() % 2;
	};
	~Jugador(){}



	void atShop(Graphics^ gr, SoundPlayer ^ player) {
		
		Font^ myFont = gcnew Font("Times new Roman", 15);

		if (this->x > 870)
		{
			gr->DrawString("Estás en la tienda:", myFont, Brushes::Black, 670, 35);
			gr->DrawString("Pulse X para comprar munición", myFont, Brushes::Black, 670, 50);
						
			/*
			Musica Tienda
			player->Load();
			player->PlaySync();
			*/
		}
	}

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
			if (y + dy< JugadorAreaDerInfY)
			{
				y = y + dy;
			}
			break;
		case Izquierda:
			indexWidth = 1 + OpcionCaracterWidth;
			indexHeight++;
			x = x - dx;
			break;
		case Derecha:
			indexWidth = 2 + OpcionCaracterWidth;
			indexHeight++;
			if (x + dx < JugadorAreaDerInfX)
			{
				x = x + dx;
			}
			break;
		default: break;
		}
		if (indexHeight == 3 + OpcionCaracterWidth)
		{
			indexHeight = OpcionCaracterWidth;
		}
	}

	int getMunicion() { return this->municion; }
	void setMunicion(int municion) { this->municion = municion; }

private: 
	int municion;

};
