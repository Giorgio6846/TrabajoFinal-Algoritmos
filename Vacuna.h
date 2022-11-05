#pragma once

#include "Jugador.h"
#include "Caracter.h"

using namespace std;

class Vacuna : public Caracter
{
public:
	Vacuna(int x, int y, int dx, int dy, int direccion);
	~Vacuna();

	int getContador() { return this->contador; }
	void setContador() { this->contador = contador + 1; }

	void mover();
	void mostrar(Graphics^ gr, Bitmap^ imagen, int cantHeight, int cantWidth, float dimensionAncho, float dimensionAlto);
	
private:
	int direccion;
	int contador;
};

Vacuna::Vacuna(int x, int y, int dx, int dy, int direccion) : Caracter()
{
	this->x = x;
	this->y = y;

	this->dx = dx;
	this->dy = dy;

	this->direccion = direccion;
}

void Vacuna::mostrar(Graphics^ gr, Bitmap^ imagen, int cantHeight, int cantWidth, float dimensionAncho, float dimensionAlto) 
{
	this->Width = imagen->Width / cantWidth;
	this->Height = imagen->Height / cantHeight;

	Rectangle Porcion = Rectangle((indexHeight) * Width, (indexWidth) * Height, Width, Height);

	Rectangle areaSprite = Rectangle(x - 5, y - 5, Width * dimensionAncho, Height * dimensionAlto);
	gr->DrawImage(imagen, areaSprite, Porcion, GraphicsUnit::Pixel);	
}

void Vacuna :: mover()
{
	switch (direccion)
	{
	case 3:
		y = y - dy;
		indexWidth = 1;
		break;
	case 0:
		y = y + dy;
		indexWidth = 0;
		break;
	case 1:
		x = x - dx;
		indexWidth = 2;
		break;
	case 2:
		x = x + dx;
		indexWidth = 3;
		break;
	default:
		break;
	}
}

Vacuna::~Vacuna()
{
}