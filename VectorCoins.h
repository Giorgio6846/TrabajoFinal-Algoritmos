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

	int getDineroObtenido() { return *contadorMonedas; }
	void setDineroObtenido(int coins) { *contadorMonedas = coins; }

	void agregar(){ arrCoin->push_back(new Coin); }

	void mover(Graphics^ gr, Bitmap^ imagen) 
	{
		for (int i = 0; i < arrCoin->size(); i++)
		{
			arrCoin->at(i)->mostrar(gr, imagen, 1, 6, 0.2, 0.2);
			arrCoin->at(i)->mover();
		}
	}

	void coinAtrapada(int pos) 
	{ 
		arrCoin->erase(arrCoin->begin() + pos); *contadorMonedas = *contadorMonedas+1; 
	}

	void mostrarCantidadMonedasObtenidasText(Graphics^ gr) 
	{
		Font^ myFont = gcnew Font("Times new Roman", 15);

		if (*contadorMonedas == 1 ) gr->DrawString("Tienes: " + *contadorMonedas + " moneda", myFont, Brushes::Black, 960, 5);
		else gr->DrawString("Tienes: " + *contadorMonedas + " monedas", myFont, Brushes::Black, 960, 5);
	}

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

	void reiniciar()
	{
		//arrCoin->clear();
		//*contadorMonedas = 0;
	}

private:
	vector<Coin*>* arrCoin;
	int * contadorMonedas;

	int EntidadAreaIzqSupX;
	int EntidadAreaIzqSupY;
	int EntidadAreaDerInfX;
	int EntidadAreaDerInfY;
};

VectorCoins::VectorCoins() 
{
	arrCoin = new vector <Coin*>();
	contadorMonedas = new int;
	*contadorMonedas = 0;

	EntidadAreaIzqSupX = 15;
	EntidadAreaIzqSupY = 0;
	EntidadAreaDerInfX = 959;
	EntidadAreaDerInfY = 195;
}

VectorCoins::~VectorCoins() 
{ 
	arrCoin->clear();
};