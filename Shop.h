#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Media;

class Shop
{
public:
	Shop();
	~Shop();

	void mostrar(Graphics^ gr, Bitmap^ Vendedor, Bitmap^ Moneda, Bitmap^ Vacuna, SoundPlayer^ player, int jugadorDinero, int jugadorVacunas);

	Rectangle getRectangleShop(){ return Rectangle(860, 0, 100, 90); }

	bool getJugadorAtStore() { return this->jugadorAtStore; }
	void setJugadorAtStore(int jugadorAtStore) { this->jugadorAtStore = jugadorAtStore; }

	int getCostoVacunas() { return this->costoVacunas; }
	void setCostoVacunas(int costoVacunas) { this->costoVacunas = costoVacunas; }

	int getCantidadVacunas() { return this->cantidadVacunas; }
	void setCantidadVacunas(int cantidadVacunas) { this->cantidadVacunas = cantidadVacunas; }



private:
	bool jugadorAtStore;
	int costoVacunas;
	int cantidadVacunas;
};

Shop::Shop()
{
	costoVacunas = 0;
	cantidadVacunas = 0;
}

Shop::~Shop()
{
}
/*
void Shop::mostrar(Graphics^ gr, SoundPlayer^ player, Bitmap ^ tienda1, Bitmap ^ tienda2)
{
	gr->DrawImage(tienda1, 960, 0, tienda1->Size.Width, tienda1->Size.Height);

	Font^ myFont = gcnew Font("Times new Roman", 15);

	gr->DrawString("Estás en la tienda:", myFont, Brushes::Black, 670, 35);
	gr->DrawString("Pulse X para comprar munición", myFont, Brushes::Black, 600, 60);

	if (jugadorAtStore == 0)
	{
		jugadorAtStore = 1;
		//player->Load();
		//player->PlaySync();
	}
	else jugadorAtStore = 0;
}
*/

void Shop :: mostrar(Graphics^ gr, Bitmap^ Vendedor, Bitmap ^ Moneda, Bitmap ^ Vacuna, SoundPlayer ^ player, int jugadorDinero, int jugadorVacunas)
{
	int* posXHUD = new int(960);
	int* posYHUD = new int(500);

	Font^ myFont = gcnew Font("Times new Roman", 35);

	Rectangle ImagenVacuna = Rectangle(0, 0, Vacuna->Size.Width, Vacuna->Size.Height);
	Rectangle ImagenVacunaTransformada = Rectangle(*posXHUD, *posYHUD, Vacuna->Size.Width * 0.6, Vacuna->Size.Height * 0.6);

	Rectangle ImagenMoneda = Rectangle(0, 0, Moneda->Size.Width, Moneda->Size.Height);
	Rectangle ImagenMonedaTransformada = Rectangle(*posXHUD, *posYHUD + 100, Moneda->Size.Width * 0.1, Moneda->Size.Height * 0.1);

	gr->DrawImage(Vendedor, 960, 0, Vendedor->Size.Width, Vendedor->Size.Height);

	gr->DrawImage(Vacuna, ImagenVacunaTransformada, ImagenVacuna, GraphicsUnit::Pixel);
	gr->DrawString(Convert::ToString(cantidadVacunas), myFont, Brushes::White, *posXHUD + 50, *posYHUD);

	gr->DrawImage(Moneda, ImagenMonedaTransformada, ImagenMoneda, GraphicsUnit::Pixel);
	gr->DrawString(Convert::ToString(costoVacunas), myFont, Brushes::White, *posXHUD + 50, *posYHUD + 100);

	delete posYHUD, posXHUD;
}