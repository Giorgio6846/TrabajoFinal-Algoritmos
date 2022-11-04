#pragma once
#include "Caracter.h"

#define MonedaAreaIzqSupX 0
#define MonedaAreaIzqSupY 0
#define MonedaAreaDerInfX 959
#define MonedaAreaDerInfY 170

/*
BebeAreaIzqSupX
BebeAreaIzqSupY
BebeAreaDerInfX
BebeAreaDerInfY

Rectangulo en donde la moneda solo se puede mover
No se ha usado el tamaño de la ventana porque este se va a agrandar para poner la interfaz del juego
*/

class Coin: public Caracter
{
public:
	Coin(){
	x = rand() % ScreenWidth;
	dy = 3;
	};
	~Coin(){};
	
	void mover() {

		y += dy;
		indexHeight++;
		if (indexHeight == 7) indexHeight = 0;

	}

};

