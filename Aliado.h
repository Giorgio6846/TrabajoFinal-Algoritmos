#pragma once
#include "Caracter.h"

//Tipo: 0 es curadora y 1 da balas 

class Aliadas : public Caracter
{
public:
	Aliadas();
	~Aliadas();

private:
	bool tipo;
};

Aliadas::Aliadas()
{
	EntidadAreaIzqSupX = 0;
	EntidadAreaIzqSupY = 0;
	EntidadAreaDerInfX = 930;
	EntidadAreaDerInfY = 135;
}

Aliadas::~Aliadas()
{
}