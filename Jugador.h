#pragma once
#include "Caracter.h"

#define RangePlayerHeight 151

class Jugador : public Caracter
{
public:
	Jugador() {

		x = rand() % ScreenWidth;
		y = rand() % RangePlayerHeight;

		OpcionCaracterHeight = 3 * rand() % 3;
		OpcionCaracterWidth = 4 * rand() % 2;
	};
	~Jugador(){}



	void atShop(Graphics^ gr) {
		
		Font^ myFont = gcnew Font("Times new Roman", 15);


		if (this->x > 870)
		{
			gr->DrawString("Estás en la tienda:", myFont, Brushes::Black, 670, 50);
			gr->DrawString("Pulse X para comprar munición", myFont, Brushes::Black, 670, 50);

		}

	}


	void mostrar(Graphics^ gr, Bitmap^ imagen,int cantHeight, int cantWidth) {

		this->Width = imagen->Width / cantWidth;
		this->Height = imagen->Height / cantHeight;

		Rectangle porcion = Rectangle(indexHeight * Height,indexWidth * Width, Width, Height);
		
		if (y >= RangePlayerHeight) y = 150;
		gr->DrawImage(imagen, x, y, porcion, GraphicsUnit::Pixel);
	}

	void mover(Direccion direccion) {
		switch (direccion)
		{
		case Arriba:
			indexWidth = 3 + OpcionCaracterWidth;
			indexHeight++;
				y = y - dy;
			break;
		case Abajo:
			indexWidth = 0 + OpcionCaracterWidth;
			indexHeight++;
			if (y + dy< RangePlayerHeight)
			{
				y = y + dy;
			}
			break;
		case Izquierda:
			indexWidth = 1 + OpcionCaracterWidth;
			indexHeight++;
			x = x - dx;
			break;
		case Derecha:
			indexWidth = 2 + OpcionCaracterWidth;
			indexHeight++;
				x = x + dx;
			break;
		default: break;
		}
		if (indexHeight == 3 + OpcionCaracterWidth) indexHeight = OpcionCaracterWidth;
	}

};
