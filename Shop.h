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
	int* posXHUD = new int(975);
	int* posYHUD = new int(60);

	Font^ myFont = gcnew Font("Times new Roman", 30);
	Font^ myFont2 = gcnew Font("Times new Roman", 16);

	Rectangle ImagenMoneda = Rectangle(0, 0, Moneda->Size.Width, Moneda->Size.Height);
	Rectangle ImagenMonedaTransformada = Rectangle(*posXHUD + 80, *posYHUD + 145, Moneda->Size.Width * 0.18, Moneda->Size.Height * 0.18);

	Rectangle ImagenVacuna = Rectangle(0, 0, Vacuna->Size.Width, Vacuna->Size.Height);
	Rectangle ImagenVacunaTransformada = Rectangle(*posXHUD+40, *posYHUD + 30, Vacuna->Size.Width * 0.6, Vacuna->Size.Height * 0.6);

	Rectangle ImagenVacuna2 = Rectangle(0, 0, Vacuna->Size.Width, Vacuna->Size.Height);
	Rectangle ImagenVacunaTransformada2 = Rectangle(*posXHUD + 50, *posYHUD + 30, Vacuna->Size.Width * 0.6, Vacuna->Size.Height * 0.6);

	gr->DrawString("TIENDA", myFont, Brushes::White, *posXHUD+5, *posYHUD -55);

	gr->DrawString("Presiona la tecla ' C '", myFont2, Brushes::White, *posXHUD-6, *posYHUD+255);

	gr->DrawImage(Vendedor, 960, 350, Vendedor->Size.Width, Vendedor->Size.Height);

	if (cantidadVacunas<10) {
		gr->DrawImage(Vacuna, ImagenVacunaTransformada2, ImagenVacuna2, GraphicsUnit::Pixel);
		gr->DrawString("x" + Convert::ToString(cantidadVacunas), myFont, Brushes::White, *posXHUD + 75, *posYHUD + 39);
	}
	else {
		gr->DrawImage(Vacuna, ImagenVacunaTransformada, ImagenVacuna, GraphicsUnit::Pixel);
		gr->DrawString("x" + Convert::ToString(cantidadVacunas), myFont, Brushes::White, *posXHUD + 65, *posYHUD + 39);
	}
	gr->DrawImage(Moneda, ImagenMonedaTransformada, ImagenMoneda, GraphicsUnit::Pixel);
	gr->DrawString(Convert::ToString(costoVacunas), myFont, Brushes::White, *posXHUD + 42, *posYHUD + 142);

	delete posYHUD, posXHUD;
}