#pragma once
#include "Caracter.h"

class Jugador : public Caracter
{
public:
	Jugador() {
		dinero = 0;

		x = 10;
		y = 50;

		opcionCaracterHeight = 3 * (rand() % 3);
		opcionCaracterWidth = 4 * (rand() % 2);

		EntidadAreaIzqSupX = 40;
		EntidadAreaIzqSupY = 30;
		EntidadAreaDerInfX = 915;
		EntidadAreaDerInfY = 135;
	};
	~Jugador(){}

   	virtual Rectangle getRectangle() { return Rectangle(x + 6, y, DimensionWidth - 12, DimensionHeight); }

	int getIndexWidth() { return this->indexWidth - opcionCaracterWidth; }

	int getMunicion() { return this->municion; }
	void setMunicion(int municion) { this->municion = municion; }

	void mostrarMunicion(Graphics ^ gr)
	{
		Font^ myFont = gcnew Font("Times new Roman", 15);
		gr->DrawString("Vacunas Restantes " + municion, myFont, Brushes::Black, 960,100);
	}

	/*
	void mostrarMensajeHabilidad(Graphics^ gr, Bitmap ) {
		int *posX = 100;
		int *posY = 100;


		Font^ myFont = gcnew Font("Times new Roman", 15);

		gr->DrawString("Aliado 1: X", myFont, Brushes::Black, 960, 130);
		gr->DrawString("Aliado 2: Z", myFont, Brushes::Black, 960, 150);

		delete posX, posY;
	}
	*/
	int getDinero() { return this->dinero; }
	void setDinero(int dinero) { this->dinero = dinero; }

	void mostrarVacunas(Graphics^ gr, Bitmap^ Vacuna)
	{
		int* posXHUD = new int(975);
		int* posYHUD = new int(120);

		Font^ myFont = gcnew Font("Times new Roman", 35);

		Rectangle Imagen = Rectangle(0, 0, Vacuna->Size.Width, Vacuna->Size.Height);
		Rectangle ImagenTransformada = Rectangle(*posXHUD, *posYHUD, Vacuna->Size.Width * 0.6, Vacuna->Size.Height * 0.6);

		gr->DrawImage(Vacuna, ImagenTransformada, Imagen, GraphicsUnit::Pixel);
		gr->DrawString(Convert::ToString(municion), myFont, Brushes::White, *posXHUD + 30, *posYHUD+5);

		delete posYHUD, posXHUD;
	}

	void mostrarDinero(Graphics^ gr,Bitmap ^ Coin)
	{
		int *posXHUD = new int(975);
		int *posYHUD = new int(20);

		Font^ myFont = gcnew Font("Times new Roman", 30);
		
		Rectangle Imagen = Rectangle(0, 0, Coin->Size.Width, Coin->Size.Height);
		Rectangle ImagenTransformada = Rectangle(*posXHUD, *posYHUD, Coin->Size.Width * 0.18, Coin->Size.Height * 0.18);

		gr->DrawImage(Coin, ImagenTransformada, Imagen, GraphicsUnit::Pixel);
		gr->DrawString(Convert::ToString(dinero), myFont, Brushes::White, *posXHUD + 45, *posYHUD-3);

		delete posYHUD, posXHUD;
	}

	/*
	void atShop(Graphics^ gr, SoundPlayer ^ player) {
		
		Font^ myFont = gcnew Font("Times new Roman", 15);
	
		
			gr->DrawString("Estás en la tienda:", myFont, Brushes::Black, 670, 35);
			gr->DrawString("Pulse X para comprar munición", myFont, Brushes::Black, 600, 60);
			

			if (y >= 50 && x >= 830) y = 55;
			else if (x >= 820 && y <= 56) x = 819;
	
		
			if (jugadorAtStore == 0)
			{
				jugadorAtStore = 1;
				player->Load();
				player->PlaySync();
			}
			else jugadorAtStore == 0;
	}
	*/
	
private: 
	int municion;
	int dinero;
};
