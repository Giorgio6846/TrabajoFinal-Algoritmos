#pragma once
#include "Caracter.h"

//Tipo: 0 es curadora y 1 da balas 

using namespace std;

class Aliadas : public Caracter
{
public:
	Aliadas();
	~Aliadas();

	bool getCooldown() { return this->cooldown; }
	void setCooldown(bool cooldown) { this->cooldown = cooldown; }
	 
	void movimientoPosicionJugador(int jugadorX, int jugadorY);
	
	Rectangle getRectangle() { return Rectangle(x, y, DimensionWidth, DimensionHeight); }

	void inicio();

	int getContador() { return this->contador; }
	void setContador(int contador) { this->contador = contador; }

	bool getHabilidadActivada() { return this->habilidadActivada; }
	void setHabilidadActivada(bool habilidadActivada) { this->habilidadActivada = habilidadActivada; }

	void mostrarTiempoRestante(Graphics^ gr, int tiempoTotal, int tiempoRestante, Bitmap ^ Imagen);
private:
	bool walking;
	bool finishedWalkingX;
	bool finishedWalkingY;

	bool cooldown;
	bool habilidadActivada;

	int contador;

	int valorAceleracion;

	int valorAceleracionAnteriorDX;
	int valorAceleracionAnteriorDY;

	
};

Aliadas::Aliadas()
{
	contador = 5;

	habilidadActivada = 0;
	cooldown = 0;

	EntidadAreaIzqSupX = 0;
	EntidadAreaIzqSupY = 20;
	EntidadAreaDerInfX = 930;
	EntidadAreaDerInfY = 135;
}

Aliadas::~Aliadas()
{
}

void Aliadas::mostrarTiempoRestante(Graphics^ gr, int tiempoTotal, int tiempoRestante, Bitmap^ Aliada)
{
	int* posXHUD = new int(960);
	int* posYHUD = new int(500);

	int* angFinal = new int;

	Font^ myFont = gcnew Font("Times new Roman", 35);
	Pen^ pen = gcnew Pen(Color::White,3);

	Rectangle Imagen = Rectangle((Aliada->Size.Width*0)/4, (Aliada->Size.Height*1)/3, Aliada->Size.Width, Aliada->Size.Height);
	Rectangle ImagenTransformada = Rectangle(*posXHUD, *posYHUD, Aliada->Size.Width * 0.5, Aliada->Size.Height * 0.5);

	*angFinal = (tiempoRestante * 360) / tiempoTotal;

	gr->DrawArc(pen,ImagenTransformada, 0, *angFinal);
	gr->DrawImage(Aliada, ImagenTransformada, Imagen, GraphicsUnit::Pixel);
	gr->DrawString(Convert::ToString(tiempoRestante), myFont, Brushes::White, *posXHUD + 50, *posYHUD);
	

	delete posXHUD, posYHUD;
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
