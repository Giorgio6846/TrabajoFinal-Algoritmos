#pragma once
#include "Caracter.h"

class Jugador : public Caracter
{
public:
	Jugador() {



	};
	~Jugador();

	void mostrar(Graphics^ gr, Bitmap^ imagen) {

		this->Width = imagen->Width / 9;
		this->Height = imagen->Height / 8;

		Rectangle porcion = Rectangle(indexHeight * Width, indexWidth * Height, Width, Height);
		
		gr->DrawImage(imagen, x, y, porcion, GraphicsUnit::Pixel);

	}


private:

};

