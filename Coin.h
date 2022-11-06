#pragma once
#include "Caracter.h"

class Coin: public Caracter
{
public:
	Coin()
	{
		EntidadAreaIzqSupX = 15;
		EntidadAreaIzqSupY = 0;
		EntidadAreaDerInfX = 959;
		EntidadAreaDerInfY = 195;

		x = EntidadAreaIzqSupX + (rand() % EntidadAreaDerInfX - 80);
		dy = 3;
	};

	~Coin(){};
	
	void mover() 
	{
		y += dy;
		indexHeight++;
		if (indexHeight == 4) indexHeight = 1;
	}
};