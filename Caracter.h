#pragma once
using namespace System;
using namespace System :: Drawing;
using namespace System :: Media;

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

	int opcionCaracterHeight;
	int opcionCaracterWidth;

	int Height;
	int Width;

public:
	Caracter();
	~Caracter();

	void mostrar(Graphics^ gr, Bitmap^ imagen, int cantHeight, int cantWidth, float dimensionAncho, float dimensionAlto);

	int getX() { return this->x; }
	int getY() { return this->y; }

	int getDx() { return this->dx; }
	int getDy() { return this->dy; }

	int getAncho() { return this -> Width; }
	int getAlto() { return this -> Height; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	void setDx(int dx) { this->dx = dx; }
	void setDy(int dy) { this->dy = dy; }

	int getOpcionCaracterHeight() { return this->opcionCaracterHeight; }
	int getOpcionCaracterWidth() { return this->opcionCaracterWidth; }

	virtual void mover(Direccion direccion) {}
		
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

	Rectangle Porcion = Rectangle((indexHeight + opcionCaracterHeight) * Width, (indexWidth + opcionCaracterWidth) * Height, Width, Height);

	

	//Rectangle porcion = Rectangle((indexHeight + OpcionCaracterHeight) * Height, (indexWidth + OpcionCaracterWidth) * Width, Width, Height);
	Rectangle areaSprite = Rectangle(x, y, Width * dimensionAncho, Height * dimensionAlto);
	gr->DrawImage(imagen, areaSprite, Porcion, GraphicsUnit::Pixel);
}
