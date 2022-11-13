#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Media;

class Shop
{
public:
	Shop();
	~Shop();

	void mostrar(Graphics^ gr, SoundPlayer^ player, Bitmap^ tienda1, Bitmap^ tienda2);

	Rectangle getRectangleShop(){ return Rectangle(860, 0, 100, 90); }

	bool getJugadorAtStore() { return this->jugadorAtStore; }
	void setJugadorAtStore(int jugadorAtStore) { this->jugadorAtStore = jugadorAtStore; }

private:
	bool jugadorAtStore;

};

Shop::Shop()
{
}

Shop::~Shop()
{
}

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