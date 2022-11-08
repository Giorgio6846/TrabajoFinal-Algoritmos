#pragma once

#include "Jugador.h"
#include "VectorBebes.h"
#include "Coin.h"
#include "VectorCoins.h"
#include "VectorVacunas.h"
#include "VectorOshawott.h"
#include "Shop.h"
#include "Aliado.h"

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
			less30MBabyImg = gcnew Bitmap("Recursos/Imagenes\\Bebes.png");
			more30MBabyImg = gcnew Bitmap("Recursos/Imagenes\\BigBabies.png");

			vectCoins = new VectorCoins();
			coinImg = gcnew Bitmap("Recursos/Imagenes\\Monedas.png");

			vectVacunas = new VectorVacunas();
			vacunasImg = gcnew Bitmap("Recursos/Imagenes\\Vacuna.png");

			player = gcnew SoundPlayer("Recursos/Musica\\TiendaEntrada.wav");

			BackgroundFacil = gcnew Bitmap("Recursos/Imagenes\\BackgroundFacil.png");
			BackgroundMedio = gcnew Bitmap("Recursos/Imagenes\\BackgroundMedio.jpg");
			BackgroundDificil = gcnew Bitmap("Recursos/Imagenes\\BackgroundDificil.jpg");


			OshawottImg = gcnew Bitmap("Recursos/Imagenes\\Oshawott.png");
		
			aliadas = new Aliadas();
			AliadaRam = gcnew Bitmap("Recursos/Imagenes\\Aliada_Ram.png");
			AliadaRem = gcnew Bitmap("Recursos/Imagenes\\Aliada_Rem.png");

			shop = new Shop();
		}

		void setDificultad(char Dificultad)
		{
			this->Dificultad = Dificultad;
			
			switch (Dificultad)
			{
			case 'F':
				delete BackgroundMedio, BackgroundDificil;
				
				//Modifica el tiempo del juego dependiendo de la dificultad;
				vectEnemigos = new VectorOshawott('F');
				this->TiempoRespuesta->Interval = 100;
				this->TiempoSegundos->Interval = 2000;
				this->ContadorBebes->Interval = 1800;
				this->ContadorMonedas->Interval = 1600;
				this->jugador->setMunicion(10);
				break;
			case 'M':
				delete BackgroundFacil, BackgroundDificil;

				//Modifica el tiempo del juego dependiendo de la dificultad;
				vectEnemigos = new VectorOshawott('M');
				this->TiempoRespuesta->Interval = 100;
				this->TiempoSegundos->Interval = 2000;
				this->ContadorBebes->Interval = 1500;
				this->ContadorMonedas->Interval = 1600;
				this->jugador->setMunicion(5);
				break;
			case 'D':
				delete BackgroundFacil, BackgroundMedio;
				
				//Modifica el tiempo del juego dependiendo de la dificultad;
				vectEnemigos = new VectorOshawott('D');
				this->TiempoRespuesta->Interval = 100;
				this->TiempoSegundos->Interval = 2000;
				this->ContadorBebes->Interval = 1500;
				this->ContadorMonedas->Interval = 1600;
				this->jugador->setMunicion(1);
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
		Bitmap^ less30MBabyImg;
		Bitmap^ more30MBabyImg;
		VectorBebes* vectBebes;

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
		
		//Datos Aliadas

		Bitmap^ AliadaRem;
		Bitmap^ AliadaRam;
		Aliadas* aliadas;

		//Datos Tienda
		Shop* shop;

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
			Form::ClientSize.Width = BackgroundFacil->Size.Width + 200;
			Form::ClientSize.Height = BackgroundFacil->Size.Height + 200;

			bg->Graphics->DrawImage(BackgroundFacil, 0, 0, BackgroundFacil->Size.Width, BackgroundFacil->Size.Height);

			break;
		case 'M':
			Form::ClientSize.Width = BackgroundMedio->Size.Width + 200;
			Form::ClientSize.Height = BackgroundMedio->Size.Height + 200;
			
			bg->Graphics->DrawImage(BackgroundMedio, 0, 0, BackgroundMedio->Size.Width, BackgroundMedio->Size.Height);

			break;
		case 'D':
			Form::ClientSize.Width = BackgroundDificil->Size.Width + 200;
			Form::ClientSize.Height = BackgroundDificil->Size.Height + 200;
			
			bg->Graphics->DrawImage(BackgroundDificil, 0, 0, BackgroundDificil->Size.Width, BackgroundDificil->Size.Height);

			break;
		default:
			break;
		}

		//Trazado
		vectBebes->mostrarBebes(bg->Graphics, less30MBabyImg, more30MBabyImg);
		vectEnemigos->mostrar(bg->Graphics, OshawottImg);
		jugador->mostrar(bg->Graphics, jugadorImg, 8, 9, 1.5, 1.5);
		vectVacunas->mostrarVacunas(bg->Graphics, vacunasImg);


		//Mecanicas Juego
		
		//Movimiento Objetos
		vectBebes->moverBebes(bg->Graphics);
		vectCoins->moverCoins(bg->Graphics, coinImg);
		vectVacunas->moverVacunas();

		//Colisiones

		for (int i = 0; i < vectCoins->getN(); i++)
		{
			if (jugador->getRectangle().IntersectsWith(vectCoins->getRectangleCertainPosicion(i))) vectCoins->coinAtrapada(i);
		}
		
		
		if (vectVacunas-> getN() != 0)
		{
			for (int i = 0; i < vectVacunas->getN(); i++)
			{
				for (int j = 0; j < vectEnemigos->getN(); j++)
				{
					if (vectEnemigos->mirandoJugador(j) && Dificultad == 'F')
					{
						if (vectEnemigos->getRectangleCertainPosicion(j).IntersectsWith(vectVacunas->getRectangleCertainPosicion(i)))
						{
							vectVacunas->vacunaUsada(i);
						}
					}
					else if(Dificultad == 'M' && Dificultad == 'D')
					{
						if (vectEnemigos->getRectangleCertainPosicion(j).IntersectsWith(vectVacunas->getRectangleCertainPosicion(i)))
						{
							vectVacunas->vacunaUsada(i);
						}
					}
					
				}
				for (int j = 0; j < vectBebes->getN(); j++)
				{
					if (vectBebes->getRectangleCertainPosicion(j).IntersectsWith(vectVacunas->getRectangleCertainPosicion(i)))
					{
						vectVacunas->vacunaUsada(i);
						vectBebes->Vacunado(j);
					}
				}
			}
		}

		//Eliminacion Objetos
		vectCoins->eliminarCoins();
		vectBebes->eliminarBebes();
		vectVacunas->eliminarVacunas();


		//Graficos
		//HUD

		if (shop->getJugadorAtStore())
		{

		}
		else
		{
			vectCoins->mostrarCantidadMonedasObtenidasText(bg->Graphics);
			vectBebes->mostrarPorcentajeBebesVacunadosYNoVacunados(bg->Graphics);
		}

		//jugador->mostrarMunicion(bg->Graphics);

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
			if (vectVacunas ->getN() < jugador->getMunicion())
			{
  				vectVacunas->agregarVacunas(jugador->getMunicion(), jugador->getX(), jugador->getY(), 20, 30, jugador->getIndexWidth());
			}
			break;

		default:
			break;
		}

	}

	private: System::Void TiempoSegundos_Tick(System::Object^ sender, System::EventArgs^ e) {
		vectBebes->agregarMesVida();
	}
	
	private: System::Void ContadorBebes_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (rand() % 101 > 50)
		{
			vectBebes->agregarBebes();
		}
	}
	
private: System::Void ContadorMonedas_Tick(System::Object^ sender, System::EventArgs^ e) {
	//Agrega dos monedas por segundo
	vectCoins->agregarCoin();
}
private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e) {
}

};
}