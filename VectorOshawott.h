#pragma once
#include "Oshawott.h"
#include <vector>
using namespace std;


class VectorOshawott
{
public:
	VectorOshawott(char dificultad){

		arrOshawott = new vector< Oshawott*>();

		//dificultad 0 es modo normal

		switch (dificultad)
		{
		case 'F':
			for (int i = 0; i < 4; i++)
			{
				arrOshawott->push_back(new Oshawott);
			}
			break;
		case 'M':
			for (int i = 0; i < 8; i++)
			{
				arrOshawott->push_back(new Oshawott);
			}
			break;
		case 'D':
			for (int i = 0; i < 12; i++)
			{
				arrOshawott->push_back(new Oshawott);
			}
			break;
		default:
			break;
		}
	};

	int getX(int pos) { return arrOshawott->at(pos)->getX(); }
	int getY(int pos) { return arrOshawott->at(pos)->getY(); }

	int getAncho(int pos) { return arrOshawott->at(pos)->getAncho(); }
	int getAlto(int pos) { return arrOshawott->at(pos)->getAlto(); }
	int getN() { return arrOshawott->size(); }


	void mostrar(Graphics^ gr, Bitmap^ imagen) {
		for (int i = 0; i < arrOshawott->size(); i++)
		{
			arrOshawott->at(i)->mover();
			arrOshawott->at(i)->mostrar(gr, imagen, 4, 4, 1, 1);
		}
	}

	bool pararVacuna(int pos) {
		if (arrOshawott->at(pos)->mover() == 1)	return true;
		else return false;
	}


	~VectorOshawott() {};

private:

	vector<Oshawott*>* arrOshawott;
};
