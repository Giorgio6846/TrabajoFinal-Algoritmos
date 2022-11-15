#pragma once
#include "Coin.h"
#include <vector>
#include <string>

using namespace std;

class VectorCoins
{
public:
	VectorCoins();
	~VectorCoins();

	int getN() { return arrCoin->size(); }

	Rectangle getRectangleCertainPosicion(int i) { return arrCoin->at(i)->getRectangle(arrCoin->at(i)->getX(), arrCoin->at(i)->getY()); }

	void agregar(){ arrCoin->push_back(new Coin); }

	void mover(Graphics^ gr, Bitmap^ imagen) 
	{
		for (int i = 0; i < arrCoin->size(); i++)
		{
			arrCoin->at(i)->mostrar(gr, imagen, 1, 6, 0.2, 0.2);
			arrCoin->at(i)->mover();
		}
	}

	void coinAtrapada(int pos){	arrCoin->erase(arrCoin->begin() + pos); }

	

	void eliminar()
	{
		for (int i = 0; i < arrCoin->size(); i++)
		{
			if (arrCoin->at(i) -> getY() > EntidadAreaDerInfY)
			{
				arrCoin->erase(arrCoin->begin() + i);
			}
		}
	}

private:
	vector<Coin*>* arrCoin;
	int EntidadAreaIzqSupX;
	int EntidadAreaIzqSupY;
	int EntidadAreaDerInfX;
	int EntidadAreaDerInfY;
};

VectorCoins::VectorCoins() 
{
	arrCoin = new vector <Coin*>();

	EntidadAreaIzqSupX = 15;
	EntidadAreaIzqSupY = 0;
	EntidadAreaDerInfX = 959;
	EntidadAreaDerInfY = 195;
}

VectorCoins::~VectorCoins() 
{ 
	arrCoin->clear();
};