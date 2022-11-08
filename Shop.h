#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Media;

class Shop
{
public:
	Shop();
	~Shop();

	void mostrar(Graphics^ gr, SoundPlayer^ player);

	int getJugadorAtStore() { return this->jugadorAtStore; }
	void setJugadorAtStore(int jugadorAtStore) { this->jugadorAtStore = jugadorAtStore; }

private:
	int jugadorAtStore;

};

Shop::Shop()
{
}

Shop::~Shop()
{
}

void Shop::mostrar(Graphics^ gr, SoundPlayer^ player)
{
	Font^ myFont = gcnew Font("Times new Roman", 15);

	gr->DrawString("Estás en la tienda:", myFont, Brushes::Black, 670, 35);
	gr->DrawString("Pulse X para comprar munición", myFont, Brushes::Black, 600, 60);

	if (jugadorAtStore == 0)
	{
		jugadorAtStore = 1;
		player->Load();
		player->PlaySync();
	}
	else jugadorAtStore = 0;
}