#pragma once
#include "Caracter.h"

#define MonedaAreaIzqSupX 0
#define MonedaAreaIzqSupY 0
#define MonedaAreaDerInfX 959
#define MonedaAreaDerInfY 182

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

