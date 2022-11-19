#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Media;

/*
jugadorAtStore
N = 'No esta en la tienda'
I = 'Ha ingreso a la tienda'
*/

class Shop
{
public:
	Shop();
	~Shop();

	void mostrar(Graphics^ gr, Bitmap^ Vendedor, Bitmap^ Moneda, Bitmap^ Vacuna, int jugadorDinero, int jugadorVacunas, SoundPlayer ^ sonido);

	Rectangle getRectangleShop(){ return Rectangle(860, 0, 100, 90); }

	char getJugadorAtStore() { return this->jugadorAtStore; }
	void setJugadorAtStore(int jugadorAtStore) { this->jugadorAtStore = jugadorAtStore; }

	int getCostoVacunas() { return this->costoVacunas; }
	void setCostoVacunas(int costoVacunas) { this->costoVacunas = costoVacunas; }

	int getCantidadVacunas() { return this->cantidadVacunas; }
	void setCantidadVacunas(int cantidadVacunas) { this->cantidadVacunas = cantidadVacunas; }

	void sonidoTienda(SoundPlayer^ sonido);

private:
	char jugadorAtStore;
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

void Shop::sonidoTienda(SoundPlayer^ sonido)
{
	if (jugadorAtStore == 'N')
	{
		jugadorAtStore = 'I';
		/*
		sonido->Load();
		sonido->Play();
		*/
	}
}

void Shop :: mostrar(Graphics^ gr, Bitmap^ Vendedor, Bitmap ^ Moneda, Bitmap ^ Vacuna, int jugadorDinero, int jugadorVacunas, SoundPlayer ^ sonido)
{
	int* posXHUD = new int(975);
	int* posYHUD = new int(60);

	Font^ myFont = gcnew Font("Times new Roman", 30);
	Font^ myFont2 = gcnew Font("Times new Roman", 16);

	Rectangle ImagenMoneda = Rectangle(0, 0, Moneda->Size.Width, Moneda->Size.Height);
	Rectangle ImagenMonedaTransformada = Rectangle(*posXHUD + 80, *posYHUD + 145, Moneda->Size.Width * 0.18, Moneda->Size.Height * 0.18);

	Rectangle ImagenVacuna = Rectangle(0, 0, Vacuna->Size.Width, Vacuna->Size.Height);
	Rectangle ImagenVacunaTransformada = Rectangle(*posXHUD+55, *posYHUD + 30, Vacuna->Size.Width * 0.6, Vacuna->Size.Height * 0.6);

	gr->DrawString("TIENDA", myFont, Brushes::White, *posXHUD+5, *posYHUD -55);

	gr->DrawString("Presiona la tecla ' C '", myFont2, Brushes::White, *posXHUD-6, *posYHUD+260);

	gr->DrawImage(Vendedor, 960, 350, Vendedor->Size.Width, Vendedor->Size.Height);

	gr->DrawImage(Vacuna, ImagenVacunaTransformada, ImagenVacuna, GraphicsUnit::Pixel);
	gr->DrawString(Convert::ToString(cantidadVacunas), myFont, Brushes::White, *posXHUD + 75, *posYHUD + 40);

	gr->DrawImage(Moneda, ImagenMonedaTransformada, ImagenMoneda, GraphicsUnit::Pixel);
	gr->DrawString(Convert::ToString(costoVacunas), myFont, Brushes::White, *posXHUD + 42, *posYHUD + 142);

	sonidoTienda(sonido);

	delete posYHUD, posXHUD;
}