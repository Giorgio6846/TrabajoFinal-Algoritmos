#pragma once

class HUD
{
public:
	HUD();
	~HUD();

	void mostrarVacunas(Graphics^ gr, Bitmap^ Vacuna, int municionJugador)
	{
		int* posXHUD = new int(975);
		int* posYHUD = new int(110);

		Font^ myFont = gcnew Font("Times new Roman", 35);

		Rectangle Imagen = Rectangle(0, 0, Vacuna->Size.Width, Vacuna->Size.Height);
		Rectangle ImagenTransformada = Rectangle(*posXHUD, *posYHUD, Vacuna->Size.Width * 0.6, Vacuna->Size.Height * 0.6);

		gr->DrawImage(Vacuna, ImagenTransformada, Imagen, GraphicsUnit::Pixel);
		gr->DrawString(Convert::ToString(municionJugador), myFont, Brushes::White, *posXHUD + 30, *posYHUD + 5);

		delete posYHUD, posXHUD;
	}

	void mostrarDinero(Graphics^ gr, Bitmap^ Coin, int dineroJugador)
	{
		int* posXHUD = new int(975);
		int* posYHUD = new int(20);

		Font^ myFont = gcnew Font("Times new Roman", 30);

		Rectangle Imagen = Rectangle(0, 0, Coin->Size.Width, Coin->Size.Height);
		Rectangle ImagenTransformada = Rectangle(*posXHUD, *posYHUD, Coin->Size.Width * 0.18, Coin->Size.Height * 0.18);

		gr->DrawImage(Coin, ImagenTransformada, Imagen, GraphicsUnit::Pixel);
		gr->DrawString(Convert::ToString(dineroJugador), myFont, Brushes::White, *posXHUD + 45, *posYHUD - 3);

		delete posYHUD, posXHUD;
	}

	void mostrarTiempoRestante(Graphics^ gr, int tiempoTotal, int tiempoActual)
	{
		int* angFinal = new int;
		int* posHUDX = new int(1098);
		int* posHUDY = new int(15);

		Pen^ pen = gcnew Pen(Color::White, 3);

		Rectangle ImagenTransformada = Rectangle(*posHUDX, *posHUDY, 50, 50);

		*angFinal = (tiempoActual * 360) / tiempoTotal;

		if (*angFinal <= 90) { gr->DrawArc(pen, ImagenTransformada, 270, *angFinal); }
		if (*angFinal > 90)
		{
			gr->DrawArc(pen, ImagenTransformada, 270, 90);
			gr->DrawArc(pen, ImagenTransformada, 0, *angFinal - 90);
		}

		System::Drawing::Font^ tipoLetra = gcnew System::Drawing::Font("Arial Black", 12);
		SolidBrush^ pincel = gcnew SolidBrush(Color::White);
		if ((tiempoTotal - tiempoActual) <= 999 && (tiempoTotal - tiempoActual) >= 100) {
			gr->DrawString(Convert::ToString(tiempoTotal - tiempoActual), tipoLetra, pincel, *posHUDX + 5, *posHUDY + 13);
		}
		if ((tiempoTotal - tiempoActual) <= 99 && (tiempoTotal - tiempoActual) >= 10) {
			gr->DrawString(Convert::ToString(tiempoTotal - tiempoActual), tipoLetra, pincel, *posHUDX + 11, *posHUDY + 13);
		}
		if ((tiempoTotal - tiempoActual) <= 9) {
			gr->DrawString(Convert::ToString(tiempoTotal - tiempoActual), tipoLetra, pincel, *posHUDX + 16, *posHUDY + 13);
		}

		delete angFinal;
	}

	void mostrarVacunados(Graphics^ gr, Bitmap^ Vacunados, char dificultad, int bebesVacunados, int totalBebes)
	{
		int* porcentaje = new int;
		int* posXHUD = new int(975);
		int* posYHUD = new int(230);
		
		*porcentaje = (bebesVacunados * 100) / totalBebes;

		Font^ myFont = gcnew Font("Times new Roman", 35);

		Rectangle Imagen = Rectangle(0, 0, Vacunados->Size.Width, Vacunados->Size.Height);
		Rectangle ImagenTransformada = Rectangle(*posXHUD, *posYHUD, Vacunados->Size.Width * 0.6, Vacunados->Size.Height * 0.6);

		gr->DrawImage(Vacunados, ImagenTransformada, Imagen, GraphicsUnit::Pixel);
		gr->DrawString(Convert::ToString(*porcentaje) + "%", myFont, Brushes::White, *posXHUD + 30, *posYHUD + 5);

		delete posYHUD, posXHUD;
	}
private:

};

HUD::HUD()
{
}

HUD::~HUD()
{
}

