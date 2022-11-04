#pragma once
using namespace System;
using namespace System :: Drawing;
#include <iostream>

#define ScreenWidth 960
#define ScreenHeight 800

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

	int OpcionCaracterHeight;
	int OpcionCaracterWidth;

	int Height;
	int Width;

public:
	Caracter() {
		//Screen : 960 * 800
		this->x = 0;
		this->y = 0;
		this->dx = 5;
		this->dy = 5;
		this->indexHeight = 0;
		this->indexWidth = 0;
		this->OpcionCaracterHeight = 0;
		this->OpcionCaracterWidth = 0;
	};
	~Caracter() {};

	int getx() { return this->x; }
	int gety() { return this->y; }

	int getdx() { return this->dx; }
	int getdy() { return this->dy; }

	int getAncho() { return Width; }
	int getAlto() { return Height; }

	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }

	void setdx(int dx) { this->dx = dx; }
	void setdy(int dy) { this->dy = dy; }

	virtual void mover(Direccion direccion) {}

	void mostrar(Graphics^ gr, Bitmap^ imagen, int cantHeight, int cantWidth, float dimensionAncho, float dimensionAlto) {
	
		this->Width = imagen->Width / cantWidth;
		this->Height = imagen->Height / cantHeight;

		Rectangle Porcion = Rectangle((indexHeight + OpcionCaracterHeight) * Width, (indexWidth + OpcionCaracterWidth) * Height, Width, Height);

		//Rectangle porcion = Rectangle((indexHeight + OpcionCaracterHeight) * Height, (indexWidth + OpcionCaracterWidth) * Width, Width, Height);
		Rectangle areaSprite = Rectangle(x, y, Width * dimensionAncho, Height * dimensionAlto);
		gr->DrawImage(imagen, areaSprite, Porcion, GraphicsUnit::Pixel);
	}

};

