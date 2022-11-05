#pragma once
#include "Oshawott.h"
#include <vector>
using namespace std;


class VectorOshawott
{
public:
	VectorOshawott(int dificultad){

		arrOshawott = new vector< Oshawott*>();

		//dificultad 0 es modo normal

		if (dificultad == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				arrOshawott->push_back(new Oshawott);
			}
		}
	};



	void mostrar(Graphics^ gr, Bitmap^ imagen) {
		for (int i = 0; i < arrOshawott->size(); i++)
		{
			arrOshawott->at(i)->mover();
			arrOshawott->at(i)->mostrar(gr, imagen, 4, 4, 1, 1);
		}
		
	}

	~VectorOshawott() {};

private:

	vector<Oshawott*>* arrOshawott;
};
