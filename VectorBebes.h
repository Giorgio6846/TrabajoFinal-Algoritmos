#pragma once

#include "Bebes.h"
#include <vector>

using namespace std;

class VectorBebes
{
public:
	VectorBebes();
	~VectorBebes();

	void agregarBebes();
	void eliminarBebes();
	void MoverBebes(Graphics^ gr);
	void MostrarBebes(Graphics^ gr, Bitmap^ imagen);

private:
	vector<Bebes*>* arrBebes;
};

VectorBebes::VectorBebes()
{
	arrBebes = new vector <Bebes*>();
}

VectorBebes::~VectorBebes()
{
	delete[]arrBebes; 
}

void VectorBebes::MostrarBebes(Graphics ^ gr, Bitmap ^ imagen)
{
	for (int i = 0; i < arrBebes->size(); i++)
	{
		arrBebes->at(i)->mostrar(gr, imagen, 8, 12);
	}
}

void VectorBebes::MoverBebes(Graphics ^ gr)
{
	for (int i = 0; i < arrBebes->size(); i++)
	{
		if (rand() % 2)
		{
			if (arrBebes->at(i)->getx() - arrBebes->at(i)->getdx() < 0)
			{
				arrBebes->at(i)->mover(Derecha);
			}
			arrBebes->at(i)->mover(Izquierda);
		}
		else
		{
			if (arrBebes->at(i)->getx() + arrBebes->at(i)->getdx() > gr->VisibleClipBounds.Width)
			{
				arrBebes->at(i)->mover(Izquierda);
			}
				arrBebes->at(i)->mover(Derecha);
		}
	}
}

void VectorBebes::agregarBebes()
{
	Bebes* bebe;

	bebe = new Bebes();
	arrBebes->push_back(bebe);
}

void VectorBebes::eliminarBebes()
{
	for (int i = 0; i < arrBebes->size(); i++)
	{
		if (arrBebes->at(i)->getesVacunado())
		{
			arrBebes->erase(arrBebes->begin() + i);
		}
	}
}