#pragma once
#include "Caracter.h"

class Oshawott : public Caracter
{
public:
	Oshawott(){
		EntidadAreaIzqSupX = 0;
		EntidadAreaIzqSupY = 235;
		EntidadAreaDerInfX = 960;
		EntidadAreaDerInfY = 0;

		y = EntidadAreaIzqSupY;
		x = rand() % EntidadAreaDerInfX;
		dx = ( rand() % 12 ) + 10;
	};

	int getIndexWidth() { return this -> indexWidth; }

	bool mover() 
	{
		if ( ( rand() % 50 ) > 16)
		{
			indexWidth = 3;
			indexHeight += 2;
			if (indexHeight >= 4) indexHeight = 0;
			return true;
		}
		
		else
		{
			if (x + dx + Width >= EntidadAreaDerInfX) { dx *= -1; }
			else if (x + dx < 0) { dx *= -1; }

			if (dx >= 0) 
			{ 
				indexWidth = 2; 
				indexHeight++; 
			}
			else 
			{ 
				indexWidth = 1;  
				indexHeight++; 
			}
			if (indexHeight == 4) indexHeight = 0;
			x += dx;
		}
		
		return false;
	}

	~Oshawott(){};

private:

};

