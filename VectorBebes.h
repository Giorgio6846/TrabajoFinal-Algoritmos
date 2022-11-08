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

	int getMesVida(int pos) { return arrBebes->at(pos)->getMesVida(); }

	void mostrarBebes(Graphics^ gr, Bitmap^ imagenMenor30, Bitmap^ imagenMayor30);

	Rectangle getRectangleCertainPosicion(int i) { return arrBebes->at(i)->getRectangle(arrBebes->at(i)->getX(), arrBebes->at(i)->getY()); }

	//int getX(int pos) { return arrBebes->at(pos)->getX(); }
	//int getY(int pos) { return arrBebes->at(pos)->getY(); }

	//int getAncho(int pos) { return arrBebes->at(pos)->getAncho(); }
	//int getAlto(int pos) { return arrBebes->at(pos)->getAlto(); }

	void Vacunado(int pos) { arrBebes->at(pos)->setEsVacunado(true); }

	void mostrarPorcentajeBebesVacunadosYNoVacunados(Graphics^ gr);

private:

	int EntidadAreaIzqSupX = 0;
	int EntidadAreaIzqSupY = 260;
	int EntidadAreaDerInfX = 959;
	int EntidadAreaDerInfY = 727;

	vector<Bebes*>* arrBebes;

	int bebesVacunados;
	int bebesNoVacunados;
};

VectorBebes::VectorBebes()
{
	arrBebes = new vector <Bebes*>();

	bebesVacunados = 0;
	bebesNoVacunados = 0;
}

VectorBebes::~VectorBebes()
{
	delete[]arrBebes; 
}

void VectorBebes::mostrarPorcentajeBebesVacunadosYNoVacunados(Graphics^ gr)
{
	Font^ myFont = gcnew Font("Times new Roman", 15);
	int porcentanje = 0;
	if ((arrBebes->size() + bebesNoVacunados + bebesNoVacunados) != 0)
	{
		porcentanje = (bebesVacunados) * 100 / (arrBebes->size() + bebesNoVacunados + bebesVacunados);
	}
	gr->DrawString("Vacunados " + porcentanje + "%", myFont, Brushes::Black, 960, 40);
	porcentanje = 100 - porcentanje;
	gr->DrawString("No vacunados " + porcentanje + "%", myFont, Brushes::Black, 960, 80);


}

void VectorBebes::mostrarBebes(Graphics^ gr, Bitmap^ imagenMenor30, Bitmap^ imagenMayor30)
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
	//	arrBebes->at(pos)->mostrar(gr, imagen, 8, 12, 1.5, 1.5); 
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
			if (arrBebes->at(i)->getWalking() == 0)
			{
				arrBebes->at(i)->setWalking(1);
			}
		}

		//Define si el bebe finaliza su ruta por la posicion Y

		if (abs(arrBebes->at(i)->getY() - arrBebes->at(i)->getDestY()) <= 10)
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

			arrBebes->at(i)->setDx(rand() % 4 + 2);
			arrBebes->at(i)->setDy(rand() % 4 + 2);

			arrBebes->at(i)->setDestX(rand() % EntidadAreaDerInfX);
			arrBebes->at(i)->setDestY(EntidadAreaIzqSupY + rand() % (EntidadAreaDerInfY - EntidadAreaIzqSupY));
		}
	}
}


void VectorBebes::eliminarBebes()
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
