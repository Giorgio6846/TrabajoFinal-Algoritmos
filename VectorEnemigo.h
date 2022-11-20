#pragma once
#include "Enemigo.h"
#include <vector>
using namespace std;


class VectorEnemigo
{
public:
	VectorEnemigo()
	{
		arrEnemigo = new vector <Enemigo*>();


	};

	Rectangle getRectangleCertainPosicion(int i) { return arrEnemigo->at(i)->getRectangle(arrEnemigo->at(i)->getX(), arrEnemigo->at(i)->getY()); }

	int getN() { return arrEnemigo->size(); }

	bool mirandoJugador(int pos) { return arrEnemigo->at(pos)->getIndexWidth() == 3; }

	void mostrar(Graphics^ gr, Bitmap^ imagen) {
		for (int i = 0; i < arrEnemigo->size(); i++)
		{
			arrEnemigo->at(i)->mover();
			arrEnemigo->at(i)->mostrar(gr, imagen, 4, 4, 1, 1);
		}
	}

	void agregarEnemigo(int cantidad) {
		if (arrEnemigo->size() == 0)
		{
			for (int i = 0; i < cantidad; i++)
			{
				arrEnemigo->push_back(new Enemigo);
			}
		}
		
	}

	~VectorEnemigo() 
	{

		arrEnemigo->clear();
	};

private:
	int cantidad;
	vector<Enemigo*>* arrEnemigo;
};
