#pragma once

#include "Bebe.h"
#include <vector>

using namespace std;

class VectorBebes
{
public:
	VectorBebes(char dificultad);
	~VectorBebes();

	void reiniciar();

	void agregar();
	void eliminar();
	void mover();
	void mostrar(Graphics^ gr, Bitmap^ imagenMenor30, Bitmap^ imagenMayor30);

	void agregarMesVida();

	int getTotalBebesGenerados() { return totalBebesGenerados; }

	int getN() { return arrBebes->size(); }

	int getMesVida(int pos) { return arrBebes->at(pos)->getMesVida(); }

	Rectangle getRectangleCertainPosicion(int i) { return arrBebes->at(i)->getRectangle(arrBebes->at(i)->getX(), arrBebes->at(i)->getY()); }

	void Vacunado(int pos) { arrBebes->at(pos)->setEsVacunado(true); }

	void mostrarPorcentajeBebesVacunadosYNoVacunados(Graphics^ gr);

private:

	int EntidadAreaIzqSupX = 0;
	int EntidadAreaIzqSupY = 260;
	int EntidadAreaDerInfX = 959;
	int EntidadAreaDerInfY = 727;

	vector<Bebes*>* arrBebes;

	int totalBebesGenerados;
	int totalBebes;
	float bebesVacunados;
	int bebesNoVacunados;
};

VectorBebes::VectorBebes(char dificultad)
{

	switch (dificultad)
	{
	case 'F': totalBebes = 15;
		break;
	case 'M': totalBebes = 20;
		break;
	default:
		break;
	}

	totalBebes = 15;

	arrBebes = new vector <Bebes*>();
	totalBebesGenerados = 0;
	bebesVacunados = 0;
	bebesNoVacunados = 0;
}

VectorBebes::~VectorBebes()
{
	arrBebes->clear();
}

void VectorBebes::mostrarPorcentajeBebesVacunadosYNoVacunados(Graphics^ gr)
{
	Font^ myFont = gcnew Font("Times new Roman", 15);
	float porcentanje = 0;

	porcentanje = (bebesVacunados /totalBebes) * 100.0;
	int toIntPorcentaje = porcentanje;

	gr->DrawString("Vacunados " + toIntPorcentaje + "%", myFont, Brushes::Black, 960, 40);
	toIntPorcentaje = 100 - toIntPorcentaje;
	gr->DrawString("No vacunados " + toIntPorcentaje + "%", myFont, Brushes::Black, 960, 60);


}

void VectorBebes::mostrar(Graphics^ gr, Bitmap^ imagenMenor30, Bitmap^ imagenMayor30)
{
	for (int i = 0; i < arrBebes->size(); i++)
	{
		if (arrBebes->at(i)->getMesVida() >= 30)
		{
			arrBebes->at(i)->setEsMayor30Meses(1);
		}
		if (arrBebes->at(i)->getEsMayor30Meses())
		{
			arrBebes->at(i)->mostrar(gr, imagenMayor30, 8, 12, 1.5, 1.5);
		}
		else
		{
			arrBebes->at(i)->mostrar(gr, imagenMenor30, 8, 12, 1.5, 1.5);
		}
	}
}


void VectorBebes::mover()
{


	for (int i = 0; i < arrBebes->size(); i++)
	{
		//Movimiento por X y Y
		if (arrBebes->at(i)->getWalking())
		{
			if (abs(arrBebes->at(i)->getY() - arrBebes->at(i)->getDestY()) <= arrBebes->at(i)->getDy())
			{
				arrBebes->at(i)->setDy(rand() % 4 + 2);
			}
			if (arrBebes->at(i)->getY() < arrBebes->at(i)->getDestY())
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
			if (abs(arrBebes->at(i)->getX() - arrBebes->at(i)->getDestX()) < arrBebes->at(i)->getDx())
			{
				arrBebes->at(i)->setDx(rand() % 4 + 2);
			}
			if (arrBebes->at(i)->getX() > arrBebes->at(i)->getDestX())
			{
				arrBebes->at(i)->mover(Izquierda);
			}
			else
			{
				arrBebes->at(i)->mover(Derecha);
			}
		}

		//Define si el bebe finaliza su ruta por la posicion X 

		if (abs(arrBebes->at(i)->getX() - arrBebes->at(i)->getDestX()) <= 10) 
		{
			arrBebes->at(i)->setFinishedWalkingX(1);
			arrBebes->at(i)->setWalking(arrBebes->at(i)->getWalking() == 0);
			/*
			if (arrBebes->at(i)->getWalking() == 0)
			{
				arrBebes->at(i)->setWalking(1);
			}
			*/
		}

		//Define si el bebe finaliza su ruta por la posicion Y

		if (abs(arrBebes->at(i)->getY() - arrBebes->at(i)->getDestY()) <= 10)
		{
			arrBebes->at(i)->setFinishedWalkingY(1);
			arrBebes->at(i)->setWalking(arrBebes->at(i)->getWalking() != 1);
			/*
			if (arrBebes->at(i)->getWalking() == 1)
			{
				arrBebes->at(i)->setWalking(0);
			}
			*/
		}

		//Si el bebe finaliza llega a su destino este se reinicia

		if (arrBebes->at(i)->getFinishedWalkingX() && arrBebes->at(i)->getFinishedWalkingY())
		{
			arrBebes->at(i)->setFinishedWalkingY(0);
			arrBebes->at(i)->setFinishedWalkingX(0);

			arrBebes->at(i)->setWalking(rand()%2);

			arrBebes->at(i)->setDx(rand() % 4 + 2);
			arrBebes->at(i)->setDy(rand() % 4 + 2);

			arrBebes->at(i)->setDestX(rand() % EntidadAreaDerInfX);
			arrBebes->at(i)->setDestY(EntidadAreaIzqSupY + rand() % (EntidadAreaDerInfY - EntidadAreaIzqSupY));
		}
	}
}


void VectorBebes::eliminar()
{
	for (int i = 0; i < arrBebes->size(); i++)
	{
		if (arrBebes->at(i)->getEsVacunado() || arrBebes->at(i)->getMesVida() == 60)
		{
			if (arrBebes->at(i)->getEsVacunado())
			{
				bebesVacunados++;
			}
			if (arrBebes->at(i)->getMesVida() == 60)
			{
				bebesNoVacunados++;
			}
			arrBebes->erase(arrBebes->begin() + i);
		}
	}
}


void VectorBebes::agregar()
{
		totalBebesGenerados++;
		arrBebes->push_back(new Bebes);
}

void VectorBebes::agregarMesVida()
{
	for (int i = 0; i < arrBebes->size(); i++)
	{
		arrBebes->at(i)->add1MesVida();
	}
}
	
void VectorBebes::reiniciar()
{
	//arrBebes->clear();
	bebesNoVacunados = 0;
	bebesVacunados = 0;
}