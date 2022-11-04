#pragma once
#include "Caracter.h"

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

