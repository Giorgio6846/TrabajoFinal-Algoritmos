#pragma once

#include "Jugador.h"
#include "VectorBebes.h"
#include "Coin.h"
#include "VectorCoins.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Juego
	/// </summary>
	public ref class Juego : public System::Windows::Forms::Form
	{
	public:
		Juego(void)
		{
			InitializeComponent();
			jugador = new Jugador();
			jugadorImg = gcnew Bitmap("Recursos\\Doctor.png");
			
			vectBebes = new VectorBebes();
			bebeImg = gcnew Bitmap("Recursos\\Bebes.png");

			vectCoins = new VectorCoins();
			coinImg = gcnew Bitmap("Recursos\\Monedas.png");



		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Juego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ TiempoRespuesta;
	protected:

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Jugador* jugador;
		Coin* coin;
		VectorBebes* vectBebes;
		VectorCoins* vectCoins;
		Bitmap^ jugadorImg;
		Bitmap^ bebeImg;
		Bitmap^ coinImg;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->TiempoRespuesta = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// TiempoRespuesta
			// 
			this->TiempoRespuesta->Enabled = true;
			this->TiempoRespuesta->Tick += gcnew System::EventHandler(this, &Juego::TiempoRespuesta_Tick);
			// 
			// Juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"Juego";
			this->Text = L"Juego";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void TiempoRespuesta_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ gr = this->CreateGraphics();
		BufferedGraphicsContext^ bc = BufferedGraphicsManager::Current;

		BufferedGraphics^ bg = bc->Allocate(gr, this->ClientRectangle);
		bg->Graphics->Clear(Color::White);

		Image^ image = Image::FromFile("Recursos\\Campo_de_concentracion.png");
		Form::ClientSize = image->Size;
		bg->Graphics->DrawImage(image, 0, 0, image->Size.Width, image->Size.Height);



		vectBebes->MoverBebes(bg->Graphics);

		jugador->mostrar(bg->Graphics, jugadorImg,8,9, 1.5, 1.5);
		jugador->atShop(bg->Graphics);
		vectBebes->MostrarBebes(bg->Graphics, bebeImg);

		vectCoins->agregarCoin();
		vectCoins->moverCoins(bg->Graphics, coinImg);

		Rectangle a = Rectangle(jugador->getx(), jugador->gety(),jugador->getAncho(), jugador->getAlto());
		Rectangle b = Rectangle(jugador->getx(), jugador->gety(), jugador->getAncho(), jugador->getAlto());

		bg->Render(gr);

		delete bc, bg, gr;
	}
	private: System::Void Juego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		switch (e->KeyCode)
		{
		case Keys::Up:
			jugador->mover(Arriba);
			break;
		case Keys::Down:
			jugador->mover(Abajo);
			break;
		case Keys::Left:
			jugador->mover(Izquierda);
			break;
		case Keys::Right:
			jugador->mover(Derecha);
			break;
		default:
			break;
		}

	}
	};
}