#pragma once

#include "Vacuna.h"
#include <vector>

using namespace std;

class VectorVacunas
{
public:
	VectorVacunas();
	~VectorVacunas();

	void agregar(int municion, int xJugador, int yJugador, int dxJugador, int dyJugador,int direccion);
	void mover();
	void mostrar(Graphics^ gr, Bitmap^ imagen);
	void eliminar();

	int getVacunasUsadas() { return vacunasUsadas; }

	Rectangle getRectangleCertainPosicion(int i) { return arrVacunas->at(i)->getRectangle(arrVacunas->at(i)->getX(), arrVacunas->at(i)->getY()); }
	Rectangle getRectangleAreaUsableCertainPosicion(int i) { return arrVacunas->at(i)->getRectangleAreaUsable(); }

	int getN() { return arrVacunas->size(); }

	void setCombo(int combo) { this->combo = combo; }
	int getCombo() { return this->combo; }

	void vacunaUsada(int pos) { arrVacunas->at(pos)->setEstaGastada(); }
private:
	vector<Vacuna*>* arrVacunas;
	int vacunasUsadas;
	int combo;
};

VectorVacunas::VectorVacunas()
{
	arrVacunas = new vector <Vacuna*>();
	vacunasUsadas = 0;
	combo = 0;
}

VectorVacunas::~VectorVacunas()
{
	arrVacunas->clear();
}

void VectorVacunas::mostrar(Graphics ^ gr, Bitmap ^ imagen)
{
	for (int i = 0; i < arrVacunas->size(); i++)
	{
		arrVacunas->at(i)->mostrar(gr, imagen, 4,1, 0.028,0.028);
	}
}

void VectorVacunas::eliminar()
{
	for (int i = 0; i < arrVacunas->size(); i++)
	{
		if ((arrVacunas->at(i)->getContador() >= 5 || arrVacunas->at(i)->getEstaGastada()) || arrVacunas->at(i)->getRectangle(arrVacunas->at(i)->getX(), arrVacunas->at(i)->getY()).IntersectsWith(arrVacunas->at(i)->getRectangleAreaUsable()) == 0)
		{
			if (arrVacunas->at(i)->getRectangle(arrVacunas->at(i)->getX(), arrVacunas->at(i)->getY()).IntersectsWith(arrVacunas->at(i)->getRectangleAreaUsable()) == 0)
			{
				combo = 0;
			}
			arrVacunas->erase(arrVacunas->begin() + i);
		}
	}
}

void VectorVacunas::mover()
{
	for (int i = 0; i < arrVacunas->size(); i++)
	{
		arrVacunas->at(i)->mover();
		arrVacunas->at(i)->setContador();
	}
}



void VectorVacunas::agregar(int municion, int xJugador, int yJugador, int dxVacuna, int dyVacuna, int direccion)
{

	arrVacunas->push_back(new Vacuna(xJugador, yJugador, dxVacuna, dyVacuna, direccion));
	vacunasUsadas++;
}