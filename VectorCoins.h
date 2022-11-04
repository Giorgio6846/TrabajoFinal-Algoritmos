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

private:
	vector<Coin*>* arrCoin;
};
