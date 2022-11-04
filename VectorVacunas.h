#pragma once

#include "Vacuna.h"

using namespace std;

class VectorVacunas
{
public:
	VectorVacunas();
	~VectorVacunas();

	void agregarVacunas(int municion, int xJugador, int yJugador, int dxJugador, int dyJugador);
	void moverVacunas();
	void mostrarVacunas();
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
void VectorVacunas::mostrarVacunas()
{
	for (int i = 0; i < arrVacunas->size(); i++)
	{

	}
}
void VectorVacunas::eliminarVacunas()
{
	for (int i = 0; i < arrVacunas->size(); i++)
	{

	}
}

void VectorVacunas::moverVacunas()
{
	for (int i = 0; i < arrVacunas->size(); i++)
	{

	}
}

void VectorVacunas::agregarVacunas(int municion, int xJugador, int yJugador, int dxJugador, int dyJugador, Direccion direccion)
{
	if (arrVacunas->size() <= municion)
	{
		arrVacunas->push_back(new Vacuna(xJugador, yJugador, dxJugador, dyJugador, Direccion));
	}
}