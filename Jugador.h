#pragma once
#include "Caracter.h"

class Jugador : public Caracter
{
public:
	Jugador() {};
	~Jugador(){};




	void mostrar(Graphics^ gr, Bitmap^ imagen) {

		this->Width = imagen->Width / 9;
		this->Height = imagen->Height / 8;

		Rectangle porcion = Rectangle(indexHeight * Width, indexWidth * Height, Width, Height);
		
		if (y > 151) y = 150;
		gr->DrawImage(imagen, x, y, porcion, GraphicsUnit::Pixel);
	}

	void mover(Direccion direccion) {
		switch (direccion)
		{
		case Arriba:
			indexWidth = 3;
			indexHeight++;
			y -= dy;
			break;
		case Abajo:
			indexWidth = 0;
			indexHeight++;
			y += dy;
			break;
		case Izquierda:
			indexWidth = 1;
			indexHeight++;
			x -= dx;
			break;
		case Derecha:
			indexWidth = 2;
			indexHeight++;
			x += dx;
			break;
		default: break;
		}
		if (indexHeight == 3) indexHeight = 0;
	}

};

