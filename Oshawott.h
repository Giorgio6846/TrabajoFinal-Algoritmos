#pragma once
#include "Caracter.h"

class Oshawott : public Caracter
{
public:
	Oshawott(){
		y = 235;
		x = rand()%ScreenWidth;
		dx = (rand()%15) + 10;
	};

	bool mover() {

		if ((rand()%50) > 10)
		{
			indexWidth = 3;
			indexHeight += 2;
			if (indexHeight >= 4) indexHeight = 0;
			return true;
		}
		else
		{
			if (x + dx + Width >= ScreenWidth) { dx *= -1; }
			else if (x + dx < 0) { dx *= -1; }

			if (dx >= 0) { indexWidth = 2; indexHeight++; }
			else { indexWidth = 1;  indexHeight++; }

			if (indexHeight == 4) indexHeight = 0;

			x += dx;
		}
		return false;
	}



	
	
	~Oshawott(){};

private:

};

