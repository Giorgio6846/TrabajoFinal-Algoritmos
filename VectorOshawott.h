#pragma once
#include "Oshawott.h"
#include <vector>
using namespace std;


class VectorOshawott
{
public:
	VectorOshawott(char dificultad){

		arrOshawott = new vector< Oshawott*>();

		cantidad = new int;

		switch (dificultad)
		{
		case 'F':
			*cantidad = 4;
			break;
		case 'M':
			*cantidad = 8;
			break;
		case 'D':
			*cantidad = 12;
			break;
		default:
			break;
		}

		for (int i = 0; i <= *cantidad; i++)
		{
			arrOshawott->push_back(new Oshawott());
		}
	};

	int getX(int pos) { return arrOshawott->at(pos)->getX(); }
	int getY(int pos) { return arrOshawott->at(pos)->getY(); }

	Rectangle getRectangleCertainPosicion(int i) { return arrOshawott->at(i)->getRectangle(arrOshawott->at(i)->getX(), arrOshawott->at(i)->getY()); }

	int getAncho(int pos) { return arrOshawott->at(pos)->getAncho(); }
	int getAlto(int pos) { return arrOshawott->at(pos)->getAlto(); }
	int getN() { return arrOshawott->size(); }

	bool mirandoJugador(int pos) { return arrOshawott->at(pos)->getIndexWidth() == 3; }

	void mostrar(Graphics^ gr, Bitmap^ imagen) {
		for (int i = 0; i < arrOshawott->size(); i++)
		{
			arrOshawott->at(i)->mover();
			arrOshawott->at(i)->mostrar(gr, imagen, 4, 4, 1, 1);
		}
	}

	~VectorOshawott() 
	{
		arrOshawott->clear();
		
		*cantidad = 0;
		delete cantidad;
	};

private:
	int* cantidad;
	vector<Oshawott*>* arrOshawott;
};
