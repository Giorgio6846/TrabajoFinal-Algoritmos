#pragma once
using namespace System;
using namespace System :: Drawing;
using namespace System :: Media;

#include <iostream>

enum Direccion{Arriba, Abajo, Izquierda,Derecha};

/*
x,y = Posiciones del caracter basados en la posicion del mapa
dx, dx = Velocidades del caracter
indexHeight, indexWidth = Posicion basado en sprite basado de la opcion elegida
OpcionCaracterHeight,OpcionCaracterWidth = Sprite elegido
Height, Width = Tamaño de la imagen
*/

class Caracter
{
protected:
	int x;
	int y;

	int dx;
	int dy;
	
	int indexHeight;
	int indexWidth;

	int opcionCaracterHeight;
	int opcionCaracterWidth;

	int Height;
	int Width;

	int EntidadAreaIzqSupX;
	int EntidadAreaIzqSupY;
	int EntidadAreaDerInfX;
	int EntidadAreaDerInfY;

	int DimensionWidth;
	int DimensionHeight;

public:
	Caracter();
	~Caracter();

	virtual void mostrar(Graphics^ gr, Bitmap^ imagen, int cantHeight, int cantWidth, float dimensionAncho, float dimensionAlto);
	virtual void mover(Direccion direccion);
	virtual Rectangle getRectangle() { return Rectangle(x, y, DimensionWidth, DimensionHeight); }

	int getX() { return this->x; }
	void setX(int x) { this->x = x; }

	int getDx() { return this->dx; }
	void setDx(int dx) { this->dx = dx; }

	int getY() { return this->y; }
	void setY(int y) { this->y = y; }

	int getDy() { return this->dy; }
	void setDy(int dy) { this->dy = dy; }

	int getAncho() { return this -> Width; }
	int getAlto() { return this -> Height; }

	int getOpcionCaracterHeight() { return this->opcionCaracterHeight; }
	int getOpcionCaracterWidth() { return this->opcionCaracterWidth; }
};

Caracter :: Caracter() {
	//Screen : 960 * 800
	this->x = 0;
	this->y = 0;
	this->dx = 5;
	this->dy = 5;
	this->indexHeight = 0;
	this->indexWidth = 0;
	this->opcionCaracterHeight = 0;
	this->opcionCaracterWidth = 0;
};

Caracter :: ~Caracter() 
{
}

void Caracter::mostrar(Graphics^ gr, Bitmap^ imagen, int cantHeight, int cantWidth, float dimensionAncho, float dimensionAlto) {
	this->Width = imagen->Width / cantWidth;
	this->Height = imagen->Height / cantHeight;

	this->DimensionHeight = Height * dimensionAlto;
	this->DimensionWidth = Width * dimensionAncho;

	Rectangle Porcion = Rectangle(indexHeight * Width, indexWidth * Height, Width, Height);
	Rectangle areaSprite = Rectangle(x, y, Width * dimensionAncho, Height * dimensionAlto);
	
	Pen^ pen = gcnew Pen(Color::Red, 2);
	gr->DrawRectangle(pen, getRectangle());


	gr->DrawImage(imagen, areaSprite, Porcion, GraphicsUnit::Pixel);
}

void Caracter :: mover(Direccion direccion) {
	switch (direccion)
	{
	case Arriba:
		indexWidth = 3 + opcionCaracterWidth;
		indexHeight++;
		if (y - dy >= EntidadAreaIzqSupY) y = y - dy;
		break;
	case Abajo:
		indexWidth = 0 + opcionCaracterWidth;
		indexHeight++;
		if (y + dy <= EntidadAreaDerInfY) y += dy;
		break;
	case Izquierda:
		indexWidth = 1 + opcionCaracterWidth;
		indexHeight++;
		if (x - dx >= EntidadAreaIzqSupX) x -= dx;
		break;
	case Derecha:
		indexWidth = 2 + opcionCaracterWidth;
		indexHeight++;
		if (x + dx <= EntidadAreaDerInfX) x += dx;
		break;
	default: break;
	}

	if (indexHeight == 3 + opcionCaracterHeight) indexHeight = opcionCaracterHeight;

}