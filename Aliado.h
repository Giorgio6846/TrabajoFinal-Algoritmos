#pragma once
#include "Caracter.h"

/*
Etapas: 
L el aliado esta libre es decir puede ser invocado en cualquier momento
I el aliado a sido invocado mediante las teclas
U el aliado despues de haber sido invocado ha tenido contacto con el jugador
C el aliado despues de haber tenido contacto con el jugador o haber esperado 15 segundos tiene un cooldown de 5 segundos
*/

using namespace std;

class Aliadas : public Caracter
{
public:
	Aliadas();
	~Aliadas();

	void movimientoPosicionJugador(int jugadorX, int jugadorY);
	
	Rectangle getRectangle() { return Rectangle(x, y, DimensionWidth, DimensionHeight); }

	void inicio();

	int getContador() { return this->contador; }
	void setContador(int contador) { this->contador = contador; }

	char getEtapas() { return this->etapas; }
	void setEtapas(char etapas) { this->etapas = etapas; }

	void mostrarTiempoCooldown(Graphics^ gr, int tiempoTotal, int tiempoRestante, Bitmap^ Aliada, int posXHUD, int posYHUD);

private:
	bool walking;
	bool finishedWalkingX;
	bool finishedWalkingY;

	char etapas;
	int contador;

	int valorAceleracion;

	int valorAceleracionAnteriorDX;
	int valorAceleracionAnteriorDY;

	
};

Aliadas::Aliadas()
{
	contador = 5;

	etapas = 'L';

	EntidadAreaIzqSupX = 0;
	EntidadAreaIzqSupY = 20;
	EntidadAreaDerInfX = 930;
	EntidadAreaDerInfY = 135;
}

Aliadas::~Aliadas()
{
}

void Aliadas::mostrarTiempoCooldown(Graphics^ gr, int tiempoTotal, int tiempoRestante, Bitmap^ Aliada, int posXHUD, int posYHUD)
{
	int* angFinal = new int;

	Font^ myFont = gcnew Font("Times new Roman", 35);
	Pen^ pen = gcnew Pen(Color::White,3);

	Rectangle Imagen = Rectangle(((Aliada->Size.Width / 3) * 1), ((Aliada->Size.Height / 4) * 0), Aliada->Size.Width/3, Aliada->Size.Height/4);
	Rectangle ImagenTransformada = Rectangle(posXHUD, posYHUD, Aliada->Size.Width * 0.6, Aliada->Size.Height * 0.6);

	*angFinal = (tiempoRestante * 360) / tiempoTotal;

	gr->DrawImage(Aliada, ImagenTransformada, Imagen, GraphicsUnit::Pixel);
	gr->DrawString(Convert::ToString(tiempoRestante), myFont, Brushes::White, posXHUD + 10, posYHUD + 10);
	gr->DrawArc(pen, ImagenTransformada, 0, *angFinal);

	delete angFinal;
}


void Aliadas::inicio()
{
	x = EntidadAreaIzqSupX + rand() % (EntidadAreaDerInfX - EntidadAreaIzqSupX);
	y = EntidadAreaIzqSupY + rand() % (EntidadAreaDerInfY - EntidadAreaIzqSupY);
}

void Aliadas::movimientoPosicionJugador(int jugadorX, int jugadorY)
{
	finishedWalkingX = x == jugadorX;
	finishedWalkingY = y == jugadorY;


	if (finishedWalkingX == 0 && finishedWalkingY == 0)
	{
		walking = rand() % 2;
	}
	else
	{
		if (finishedWalkingX == 1) walking = 1;
		if (finishedWalkingY == 1) walking = 0;
	}

	if (walking)
	{
		if (abs(y - jugadorY) <= dy) dy = rand() % 10 + 2;
		if (y < jugadorY) mover(Abajo);
		else mover(Arriba);
	}
	else
	{
		if (abs(x - jugadorX) <= dx) dx = rand() % 10 + 2;
		if (x > jugadorX) mover(Izquierda);
		else mover(Derecha);
	}
}
