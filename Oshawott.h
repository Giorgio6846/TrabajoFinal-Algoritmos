#pragma once
#include "Caracter.h"

class Oshawott : public Caracter
{
public:
	Oshawott(){
		indexWidth = 3;
		indexHeight = 0;
		y = 235;
		x = rand()%ScreenWidth;
		dx = 10;
	};

	void mover() {
		x += dx;
		if (x + dx + Width > ScreenWidth) dx *= -1;
		else if (x + dx < 0) dx *= -1;
	}
	
	~Oshawott(){};

private:

};

