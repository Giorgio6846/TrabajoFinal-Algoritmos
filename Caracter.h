#pragma once
using namespace System;
using namespace System :: Drawing;
#include <iostream>

enum Direccion{Arriba, Abajo, Izquierda,Derecha};

class Caracter
{
protected:
	int x;
	int y;

	int dx;
	int dy;
	
	int indexHeight;
	int indexWidth;

	int Height;
	int Width;

public:
	Caracter() {
		//Screen : 960 * 800
		this->x = rand() % 960;
		this->y = 50;
		this->dx = this->dy = 5;
		this->indexHeight = this->indexWidth = 0;
	};
	~Caracter() {};

	int getx() { return this->x; }
	int gety() { return this->y; }

	int getdx() { return this->dx; }
	int getdy() { return this->dy; }

	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }

	void setdx(int dx) { this->dx = dx; }
	void setdy(int dy) { this->dy = dy; }

	virtual void mover(Graphics ^ gr,Direccion direccion){}
	void mostrar(Graphics^ gr, Bitmap^ imagen){}
};

