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
	using namespace System::Media;

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
			jugadorImg = gcnew Bitmap("Recursos/Imagenes\\Doctor.png");
			
			vectBebes = new VectorBebes();
			bebeImg = gcnew Bitmap("Recursos/Imagenes\\Bebes.png");

			vectCoins = new VectorCoins();
			coinImg = gcnew Bitmap("Recursos/Imagenes\\Monedas.png");

			player = gcnew SoundPlayer("Recursos/Musica\\TiendaEntrada.wav");

			Background = gcnew Bitmap("Recursos/Imagenes\\Campo_de_concentracion.png");
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
		//Datos Jugador
		Jugador* jugador;
		Bitmap^ jugadorImg;

		//Datos Bebes
		Bitmap^ bebeImg;
		VectorBebes* vectBebes;

		//Datos Monedas
		Coin* coin;
		VectorCoins* vectCoins;

		//Datos Tienda
		SoundPlayer^ player;
		
		//Imagen Background
		Bitmap^ Background;

	private: System::Windows::Forms::Timer^ TiempoSegundos;
	private: System::Windows::Forms::Timer^ ContadorBebes;
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
			this->TiempoSegundos = (gcnew System::Windows::Forms::Timer(this->components));
			this->ContadorBebes = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// TiempoRespuesta
			// 
			this->TiempoRespuesta->Enabled = true;
			this->TiempoRespuesta->Interval = 100;
			this->TiempoRespuesta->Tick += gcnew System::EventHandler(this, &Juego::TiempoRespuesta_Tick);
			// 
			// TiempoSegundos
			// 
			this->TiempoSegundos->Enabled = true;
			this->TiempoSegundos->Interval = 1000;
			this->TiempoSegundos->Tick += gcnew System::EventHandler(this, &Juego::TiempoSegundos_Tick);
			// 
			// ContadorBebes
			// 
			this->ContadorBebes->Enabled = true;
			this->ContadorBebes->Interval = 500;
			this->ContadorBebes->Tick += gcnew System::EventHandler(this, &Juego::ContadorBebes_Tick);
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
		//Buffer
		Graphics^ gr = this->CreateGraphics();
		BufferedGraphicsContext^ bc = BufferedGraphicsManager::Current;

		BufferedGraphics^ bg = bc->Allocate(gr, this->ClientRectangle);
		bg->Graphics->Clear(Color::White);

		//Background Juego
		Form::ClientSize = Background->Size;
		bg->Graphics->DrawImage(Background, 0, 0, Background->Size.Width, Background->Size.Height);

		//Mecanicas Juego
			//Eliminacion Objetos
		vectCoins->eliminarCoins();
		vectBebes->eliminarBebes();

			//Movimiento Objetos
		vectBebes->moverBebes(bg->Graphics);
		vectCoins->moverCoins(bg->Graphics, coinImg);

		//Graficos
		jugador->mostrar(bg->Graphics, jugadorImg,8,9, 1.5, 1.5);
		jugador->atShop(bg->Graphics,player);
		vectBebes->mostrarBebes(bg->Graphics, bebeImg);


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

	private: System::Void TiempoSegundos_Tick(System::Object^ sender, System::EventArgs^ e) {
					
	}
	
	private: System::Void ContadorBebes_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Agrega 1-2 bebes por segundo
		if (rand() % 101 > 50)
		{
			vectBebes->agregarBebes();
		}
		vectCoins->agregarCoin();
	}
	
};
}