#pragma once

#include "Bebe.h"
#include <vector>

using namespace std;

class VectorBebes
{
public:
	VectorBebes();
	~VectorBebes();

	void agregarBebes();
	void eliminarBebes();
	void moverBebes(Graphics^ gr);
	void agregarMesVida();

	int getN() { return arrBebes->size(); }

	int getMesVida(int pos) { return arrBebes->at(pos)->getmesVida(); }

	void mostrarBebes(Graphics^ gr, Bitmap^ imagen, int pos)
	{
		
			arrBebes->at(pos)->mostrar(gr, imagen, 8, 12, 1.5, 1.5);
		
	}



private:
	vector<Bebes*>* arrBebes;};

VectorBebes::VectorBebes()
{
	arrBebes = new vector <Bebes*>();
}

VectorBebes::~VectorBebes()
{
	delete[]arrBebes; 
}




void VectorBebes::moverBebes(Graphics ^ gr)
{
	/*
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
	*/

	for (int i = 0; i < arrBebes->size(); i++)
	{
		//Movimiento por X y Y
		if (arrBebes->at(i)->getWalking())
		{
			if (abs(arrBebes->at(i)->gety() - arrBebes->at(i)->getdestY()) <= arrBebes->at(i)->getdy())
			{
				arrBebes->at(i)->setdy(rand() % 4 + 2);
			}
			if (arrBebes->at(i)->gety() < arrBebes->at(i)->getdestY())
			{
				arrBebes->at(i)->mover(Abajo);
			}
			else
			{
				arrBebes->at(i)->mover(Arriba);
			}
		}
		else
		{
			if (abs(arrBebes->at(i)->getx() - arrBebes->at(i)->getdestX()) < arrBebes->at(i)->getdx())
			{
				arrBebes->at(i)->setdx(rand() % 4 + 2);
			}
			if (arrBebes->at(i)->getx() > arrBebes->at(i)->getdestX())
			{
				arrBebes->at(i)->mover(Izquierda);
			}
			else
			{
				arrBebes->at(i)->mover(Derecha);
			}
		}



		//Define si el bebe finaliza su ruta por la posicion X 

		if (abs(arrBebes->at(i)->getx() - arrBebes->at(i)->getdestX()) <= 10) 
		{
			arrBebes->at(i)->setFinishedWalkingX(1);
			if (arrBebes->at(i)->getWalking() == 0)
			{
				arrBebes->at(i)->setWalking(1);
			}
		}

		//Define si el bebe finaliza su ruta por la posicion Y

		if (abs(arrBebes->at(i)->gety() - arrBebes->at(i)->getdestY()) <= 10)
		{
			arrBebes->at(i)->setFinishedWalkingY(1);
			if (arrBebes->at(i)->getWalking() == 1)
			{
				arrBebes->at(i)->setWalking(0);
			}
		}

		//Si el bebe finaliza llega a su destino este se reinicia

		if (arrBebes->at(i)->getFinishedWalkingX() && arrBebes->at(i)->getFinishedWalkingY())
		{
			arrBebes->at(i)->setFinishedWalkingY(0);
			arrBebes->at(i)->setFinishedWalkingX(0);

			arrBebes->at(i)->setWalking(rand()%2);

			arrBebes->at(i)->setdx(rand() % 4 + 2);
			arrBebes->at(i)->setdy(rand() % 4 + 2);

			arrBebes->at(i)->setdestX(rand() % BebeAreaDerInfX);
			arrBebes->at(i)->setdestY(BebeAreaIzqSupY + rand() % (BebeAreaDerInfY - BebeAreaIzqSupY));
		}
	}
}


void VectorBebes::eliminarBebes()
{
	for (int i = 0; i < arrBebes->size(); i++)
	{
		if (arrBebes->at(i)->getesVacunado())
		{
			arrBebes->erase(arrBebes->begin() + i);
		}
		if (arrBebes->at(i)->getmesVida() == 60)
		{
			arrBebes->erase(arrBebes->begin() + i);
		}
	}
}


void VectorBebes::agregarBebes()
{
		arrBebes->push_back(new Bebes);
}

void VectorBebes::agregarMesVida()
{
	for (int i = 0; i < arrBebes->size(); i++)
	{
		arrBebes->at(i)->add1MesVida();
	}
}
