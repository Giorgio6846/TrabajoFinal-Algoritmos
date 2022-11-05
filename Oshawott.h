#pragma once
#include "Caracter.h"

class Oshawott : public Caracter
{
public:
	Oshawott(){
		indexWidth = 3;
		indexHeight = 0;
		y = 205;
		x = rand()%ScreenWidth;
	};
	
	~Oshawott(){};

private:

};

