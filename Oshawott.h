#pragma once
#include "Caracter.h"

class Oshawott : public Caracter
{
public:
	Oshawott(){
		EntidadAreaIzqSupX = 0;
		EntidadAreaIzqSupY = 235;
		EntidadAreaDerInfX = 930;
		EntidadAreaDerInfY = 0;

		opcionCaracterHeight = 0;
		opcionCaracterWidth = 0;

		y = EntidadAreaIzqSupY;
		x = rand() % EntidadAreaDerInfX;
		dx = ( rand() % 12 ) + 10;
	};

	int getIndexWidth() { return this -> indexWidth; }

	Rectangle getRectangle(int x, int y) { return Rectangle(x + 18, y + 28, DimensionWidth - 35, DimensionHeight - 30);}


	void mover() 
	{
		if ((rand() % 101) > 32)
		{
			indexWidth = 1;
			indexHeight += 1;
			
			if (indexHeight == 4) { indexHeight = 0; }
		}
		
		/*
		if ( ( rand() % 50 ) > 16)
		{
			indexWidth = 1;
			indexHeight += 2;
			if (indexHeight >= 4) indexHeight = 0;
			return true;
		}
		*/
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
	}



	~Oshawott(){};

private:

};

