#pragma once

using namespace System :: Drawing;

enum Direccion{Arriba, Abajo, Izquierda,Derecha};

class Model
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
	Model();
	~Model();

	int getx() { return this->x; }
	int gety() { return this->y; }

	int getdx() { return this->dx; }
	int getdy() { return this->dy; }

	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }

	void setdx(int dx) { this->dx = dx; }
	void setdy(int dy) { this->dy = dy; }

	virtual void mover(Graphics ^ gr,Direccion direccion){}
	virtual void mostrar(Graphics^ gr, Bitmap ^imagen){}
};

Model::Model()
{
}

Model::~Model()
{
}