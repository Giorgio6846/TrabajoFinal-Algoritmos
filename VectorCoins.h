#pragma once
#include "Coin.h"
#include <vector>
#include <string>

using namespace std;

class VectorCoins
{
public:
	VectorCoins() {

		arrCoin = new vector <Coin*>();
		contadorMonedas = new int;
		*contadorMonedas = 0;
	};
	~VectorCoins(){delete[]arrCoin;};

	void agregarCoin(){arrCoin->push_back(new Coin);}

	void moverCoins(Graphics^ gr, Bitmap^ imagen) {

		for (int i = 0; i < arrCoin->size(); i++)
		{
			arrCoin->at(i)->mostrar(gr, imagen, 1, 6, 0.2, 0.2);
			arrCoin->at(i)->mover();
		}
	}

	void coinAtrapada(int pos) { arrCoin->erase(arrCoin->begin() + pos); *contadorMonedas = *contadorMonedas+1; }

	void monedasObtenidasText(Graphics^ gr) {
		Font^ myFont = gcnew Font("Times new Roman", 15);

		if (*contadorMonedas == 1 ) gr->DrawString("Tienes: " + *contadorMonedas + " moneda", myFont, Brushes::Black, 100, 5);
		else gr->DrawString("Tienes: " + *contadorMonedas + " monedas", myFont, Brushes::Black, 100, 5);
		
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

	int getMonedas() { return *contadorMonedas; }
	


private:

	vector<Coin*>* arrCoin;
	int * contadorMonedas;

};
