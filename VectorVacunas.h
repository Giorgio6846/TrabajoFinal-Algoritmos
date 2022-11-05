#pragma once

#include "Vacuna.h"
#include <vector>

using namespace std;

class VectorVacunas
{
public:
	VectorVacunas();
	~VectorVacunas();

	void agregarVacunas(int municion, int xJugador, int yJugador, int dxJugador, int dyJugador,int direccion);
	void moverVacunas();
	void mostrarVacunas(Graphics^ gr, Bitmap^ imagen);
	void eliminarVacunas();

private:
	vector<Vacuna*>* arrVacunas;
};

VectorVacunas::VectorVacunas()
{
	arrVacunas = new vector <Vacuna*>();
}

VectorVacunas::~VectorVacunas()
{
}

void VectorVacunas::mostrarVacunas(Graphics ^ gr, Bitmap ^ imagen)
{
	for (int i = 0; i < arrVacunas->size(); i++)
	{
		arrVacunas->at(i)->mostrar(gr, imagen, 1,1, 0.03,0.03);
	}
}
void VectorVacunas::eliminarVacunas()
{
	for (int i = 0; i < arrVacunas->size(); i++)
	{
		if (arrVacunas->at(i)->getContador() >= 5)
		{
			arrVacunas->erase(arrVacunas->begin() + i);
		}
	}
}

void VectorVacunas::moverVacunas()
{
	for (int i = 0; i < arrVacunas->size(); i++)
	{
		arrVacunas->at(i)->mover();
		arrVacunas->at(i)->setContador();
	}
}

void VectorVacunas::agregarVacunas(int municion, int xJugador, int yJugador, int dxJugador, int dyJugador, int direccion)
{
	arrVacunas->push_back(new Vacuna(xJugador, yJugador, dxJugador, dyJugador, direccion));
}