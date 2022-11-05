#pragma once

#include "Jugador.h"
#include "VectorBebes.h"
#include "Coin.h"
#include "VectorCoins.h"
#include "VectorVacunas.h"
#include "VectorOshawott.h"

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
		Juego()
		{
			InitializeComponent();
			
			jugador = new Jugador();
			jugadorImg = gcnew Bitmap("Recursos/Imagenes\\Doctor.png");
			
			vectBebes = new VectorBebes();
			bebeImg = gcnew Bitmap("Recursos/Imagenes\\Bebes.png");
			bigBabyImg = gcnew Bitmap("Recursos/Imagenes\\BigBabies.png");

			vectCoins = new VectorCoins();
			coinImg = gcnew Bitmap("Recursos/Imagenes\\Monedas.png");

			vectVacunas = new VectorVacunas();
			vacunasImg = gcnew Bitmap("Recursos/Imagenes\\Vacuna.png");

			player = gcnew SoundPlayer("Recursos/Musica\\TiendaEntrada.wav");

			BackgroundFacil = gcnew Bitmap("Recursos/Imagenes\\BackgroundFacil.png");
			BackgroundMedio = gcnew Bitmap("Recursos/Imagenes\\BackgroundMedio.jpg");
			BackgroundDificil = gcnew Bitmap("Recursos/Imagenes\\BackgroundDificil.jpg");

			vectEnemigos = new VectorOshawott(0);
			OshawottImg = gcnew Bitmap("Recursos/Imagenes\\Oshawott.png");
		}

		void setDificultad(char Dificultad)
		{
			this->Dificultad = Dificultad;
			
			switch (Dificultad)
			{
			case 'F':
				delete BackgroundMedio, BackgroundDificil;
				
				//Modifica el tiempo del juego dependiendo de la dificultad;
				this->TiempoRespuesta->Interval = 100;
				this->TiempoSegundos->Interval = 2000;
				this->ContadorBebes->Interval = 1500;
				this->ContadorMonedas->Interval = 1600;

				break;
			case 'M':
				delete BackgroundFacil, BackgroundDificil;

				//Modifica el tiempo del juego dependiendo de la dificultad;
				this->TiempoRespuesta->Interval = 100;
				this->TiempoSegundos->Interval = 2000;
				this->ContadorBebes->Interval = 1500;
				this->ContadorMonedas->Interval = 1600;

				break;
			case 'D':
				delete BackgroundFacil, BackgroundMedio;
				
				//Modifica el tiempo del juego dependiendo de la dificultad;
				this->TiempoRespuesta->Interval = 100;
				this->TiempoSegundos->Interval = 2000;
				this->ContadorBebes->Interval = 1500;
				this->ContadorMonedas->Interval = 1600;

				break;

			default:
				break;
			}


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
		//Dificultad Juego
		char Dificultad;

		//Datos Jugador
		Jugador* jugador;
		Bitmap^ jugadorImg;

		//Datos Bebes
		Bitmap^ bebeImg;
		VectorBebes* vectBebes;
		Bitmap^ bigBabyImg;

		//Datos Monedas
		Coin* coin;
		VectorCoins* vectCoins;
		Bitmap^ coinImg;

		//Datos Tienda
		SoundPlayer^ player;
		
		//Imagen Background
		Bitmap^ BackgroundFacil;
		Bitmap^ BackgroundMedio;
		Bitmap^ BackgroundDificil;

		//Datos Vacunas
		VectorVacunas* vectVacunas;
		Bitmap^ vacunasImg;

		//Imagen MamaAntivacuna
		VectorOshawott* vectEnemigos;
		Bitmap^ OshawottImg;
		

	private: System::Windows::Forms::Timer^ TiempoSegundos;
	private: System::Windows::Forms::Timer^ ContadorBebes;

	private: System::Windows::Forms::Timer^ ContadorMonedas;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Juego::typeid));
			this->TiempoRespuesta = (gcnew System::Windows::Forms::Timer(this->components));
			this->TiempoSegundos = (gcnew System::Windows::Forms::Timer(this->components));
			this->ContadorBebes = (gcnew System::Windows::Forms::Timer(this->components));
			this->ContadorMonedas = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// TiempoRespuesta
			// 
			this->TiempoRespuesta->Enabled = true;
			this->TiempoRespuesta->Tick += gcnew System::EventHandler(this, &Juego::TiempoRespuesta_Tick);
			// 
			// TiempoSegundos
			// 
			this->TiempoSegundos->Enabled = true;
			this->TiempoSegundos->Interval = 2000;
			this->TiempoSegundos->Tick += gcnew System::EventHandler(this, &Juego::TiempoSegundos_Tick);
			// 
			// ContadorBebes
			// 
			this->ContadorBebes->Enabled = true;
			this->ContadorBebes->Interval = 1500;
			this->ContadorBebes->Tick += gcnew System::EventHandler(this, &Juego::ContadorBebes_Tick);
			// 
			// ContadorMonedas
			// 
			this->ContadorMonedas->Enabled = true;
			this->ContadorMonedas->Interval = 1600;
			this->ContadorMonedas->Tick += gcnew System::EventHandler(this, &Juego::ContadorMonedas_Tick);
			// 
			// Juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1160, 800);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Juego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Juego";
			this->Load += gcnew System::EventHandler(this, &Juego::Juego_Load);
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

		switch (Dificultad)
		{
		case 'F':
			Form::ClientSize = BackgroundFacil->Size;
			bg->Graphics->DrawImage(BackgroundFacil, 0, 0, BackgroundFacil->Size.Width, BackgroundFacil->Size.Height);

			//Mecanicas Juego
			
			vectCoins->monedasObtenidasText(bg->Graphics);
			break;
		case 'M':
			Form::ClientSize = BackgroundMedio->Size;
			bg->Graphics->DrawImage(BackgroundMedio, 0, 0, BackgroundMedio->Size.Width, BackgroundMedio->Size.Height);

			//Mecanicas Juego
			
			vectCoins->monedasObtenidasText(bg->Graphics);
			break;
		case 'D':
			Form::ClientSize = BackgroundDificil->Size;
			bg->Graphics->DrawImage(BackgroundDificil, 0, 0, BackgroundDificil->Size.Width, BackgroundDificil->Size.Height);

			//Mecanicas Juego

			vectCoins->monedasObtenidasText(bg->Graphics);
			break;
		default:
			break;
		}



		//Mecanicas Juego
			
		vectCoins->monedasObtenidasText(bg->Graphics);

		
		//Eliminacion Objetos
		vectCoins->eliminarCoins();
		vectBebes->eliminarBebes();

			//Movimiento Objetos
		vectBebes->moverBebes(bg->Graphics);
		vectCoins->moverCoins(bg->Graphics, coinImg);
		vectVacunas->moverVacunas();

		//Graficos
		vectEnemigos->mostrar(bg->Graphics, OshawottImg);
		jugador->mostrar(bg->Graphics, jugadorImg,8,9, 1.5, 1.5);
		vectVacunas->mostrarVacunas(bg->Graphics, vacunasImg);

		for (int i = 0; i < vectBebes->getN(); i++)
		{
			if (vectBebes->getMesVida(i) <= 30) vectBebes->mostrarBebes(bg->Graphics, bebeImg, i);
			else if(vectBebes->getMesVida(i) > 30) vectBebes->mostrarBebes(bg->Graphics, bigBabyImg, i);
		}
		
		//Colisiones

		Rectangle jugadorR = Rectangle(jugador->getX(), jugador->getY(),jugador->getAncho(), jugador->getAlto());

		for (int i = 0; i < vectCoins->getN(); i++)
		{
			Rectangle monedaR = Rectangle(vectCoins->getX(i), vectCoins->getY(i), vectCoins->getAncho(i)/4, vectCoins->getAlto(i)/4);

			if (jugadorR.IntersectsWith(monedaR)) vectCoins->coinAtrapada(i);
		}


		for (int j = 0; j < vectBebes->getN(); j++)
		{
			Rectangle bebeR = Rectangle(vectBebes->getX(j), vectBebes->getY(j), vectBebes->getAncho(j), vectBebes->getAlto(j));

			for (int i = 0; i < vectVacunas->getN(); i++)
			{
				Rectangle vacunaR = Rectangle(vectVacunas->getX(i), vectVacunas->getY(i), 1,1);
				if (vacunaR.IntersectsWith(bebeR))
				{
					vectVacunas->vacunaUsada(i);
					vectBebes->Vacunado(j);
				}
			}
		}

		for (int j = 0; j < vectEnemigos->getN(); j++)
		{
			Rectangle enemigoR = Rectangle(vectEnemigos->getX(j), vectEnemigos->getY(j), vectEnemigos->getAncho(j)-30, vectEnemigos->getAlto(j));

			for (int i = 0; i < vectVacunas->getN(); i++)
			{
				Rectangle vacunaR = Rectangle(vectVacunas->getX(i), vectVacunas->getY(i), 1, 1);
				if (vacunaR.IntersectsWith(enemigoR) && vectEnemigos->pararVacuna(j))
				{
					vectVacunas->vacunaUsada(i);
				}
			}
		}

		Rectangle tiendaR = Rectangle(860, 5, 100, 50);

		if (jugadorR.IntersectsWith(tiendaR) && jugador->getX() >= 830)
		{
			jugador->atShop(bg->Graphics, player);
		}



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
		case Keys::Space:
			vectVacunas->agregarVacunas(jugador->getMunicion(), jugador->getX(), jugador->getY(), 20, 30, jugador->getIndexWidth());
			break;

		default:
			break;
		}

	}

	private: System::Void TiempoSegundos_Tick(System::Object^ sender, System::EventArgs^ e) {
		vectBebes->agregarMesVida();
	}
	
	private: System::Void ContadorBebes_Tick(System::Object^ sender, System::EventArgs^ e) {
		
			vectBebes->agregarBebes();

	}
	
private: System::Void ContadorMonedas_Tick(System::Object^ sender, System::EventArgs^ e) {
	//Agrega dos monedas por segundo
	vectCoins->agregarCoin();
}
private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e) {
}

};
}