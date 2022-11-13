#pragma once
#include "Oshawott.h"
#include <vector>
using namespace std;


class VectorOshawott
{
public:
	VectorOshawott(char dificultad)
	{
		arrOshawott = new vector <Oshawott*>();


	};

	Rectangle getRectangleCertainPosicion(int i) { return arrOshawott->at(i)->getRectangle(arrOshawott->at(i)->getX(), arrOshawott->at(i)->getY()); }

	int getN() { return arrOshawott->size(); }

	bool mirandoJugador(int pos) { return arrOshawott->at(pos)->getIndexWidth() == 3; }

	void mostrar(Graphics^ gr, Bitmap^ imagen) {
		for (int i = 0; i < arrOshawott->size(); i++)
		{
			arrOshawott->at(i)->mover();
			arrOshawott->at(i)->mostrar(gr, imagen, 4, 4, 1, 1);
		}
	}

	void agregarOshawott(char dificultad) {

		switch (dificultad)
		{
		case 'F':
			cantidad = 4;
			break;
		case 'M':
			cantidad = 6;
			break;
		case 'D':
			cantidad = 8;
			break;
		default:
			break;
		}

		if (arrOshawott->size() == 0)
		{
			for (int i = 0; i < cantidad; i++)
			{
				arrOshawott->push_back(new Oshawott);
			}
		}
		
	}

	~VectorOshawott() 
	{

		arrOshawott->clear();
	};

private:
	int cantidad;
	vector<Oshawott*>* arrOshawott;
};
