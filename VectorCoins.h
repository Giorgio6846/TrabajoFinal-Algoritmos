#pragma once
#include "Coin.h"
#include <vector>

using namespace std;

class VectorCoins
{
public:
	VectorCoins() {

		arrCoin = new vector <Coin*>();
	};
	~VectorCoins(){delete[]arrCoin;
	};

	void agregarCoin(){arrCoin->push_back(new Coin);}

	void moverCoins(Graphics^ gr, Bitmap^ imagen) {

		for (int i = 0; i < arrCoin->size(); i++)
		{
			arrCoin->at(i)->mostrar(gr, imagen, 1, 6, 0.2, 0.2);
			arrCoin->at(i)->mover();
		}
	}

	void coinAtrapada(int pos) {
		arrCoin->erase(arrCoin->begin() + pos);
	}

	void eliminarCoins()
	{
		for (int i = 0; i < arrCoin->size(); i++)
		{
			if (arrCoin->at(i) -> gety() > MonedaAreaDerInfY)
			{
				arrCoin->erase(arrCoin->begin() + i);
			}
		}
	}

	int getN() { return arrCoin->size(); }

	int getX(int pos) {return arrCoin->at(pos)->getx();}
	int getY(int pos) { return arrCoin->at(pos)->gety(); }

	int getAncho(int pos) { return arrCoin->at(pos)->getAncho(); }
	int getAlto(int pos) { return arrCoin->at(pos)->getAlto(); }
	


private:
	vector<Coin*>* arrCoin;
};
