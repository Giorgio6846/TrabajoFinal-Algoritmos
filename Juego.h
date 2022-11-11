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
			
			//ObjetosJuego
			jugador = new Jugador();

			vectBebes = new VectorBebes();

			vectCoins = new VectorCoins();

			vectVacunas = new VectorVacunas();

			vectEnemigos= new VectorOshawott();

			aliada1 = new Aliadas();
			aliada2 = new Aliadas();
			aliada3 = new Aliadas();

			shop = new Shop();

			//ImagenesJuego
			jugadorImg = gcnew Bitmap("Recursos/Imagenes\\Doctor.png");

			less30MBabyImg = gcnew Bitmap("Recursos/Imagenes\\Bebes.png");
			more30MBabyImg = gcnew Bitmap("Recursos/Imagenes\\BigBabies.png");

			coinImg = gcnew Bitmap("Recursos/Imagenes\\Monedas.png");
			
			vacunasImg = gcnew Bitmap("Recursos/Imagenes\\Vacuna.png");

			BackgroundFacil = gcnew Bitmap("Recursos/Imagenes\\BackgroundFacil.png");
			BackgroundMedio = gcnew Bitmap("Recursos/Imagenes\\BackgroundMedio.jpg");
			BackgroundDificil = gcnew Bitmap("Recursos/Imagenes\\BackgroundDificil.jpg");

			OshawottImg = gcnew Bitmap("Recursos/Imagenes\\Oshawott.png");

			AliadaRam = gcnew Bitmap("Recursos/Imagenes\\Aliada_Ram.png");
			AliadaRem = gcnew Bitmap("Recursos/Imagenes\\Aliada_Rem.png");

			//SonidosJuego

			player = gcnew SoundPlayer("Recursos/Musica\\TiendaEntrada.wav");
		}

		bool getJuegoTerminado() { return this->juegoTerminado; }

		void reiniciarJuego()
		{
			juegoTerminado = 0;
			dificultad = 'F';

			vectBebes->reiniciar();
			vectEnemigos->reiniciar();
			vectCoins->reiniciar();
			vectVacunas->reiniciar();
		}

		void setDificultad(char dificultad)
		{
			this->dificultad = dificultad;
			
			this->vectEnemigos->iniciar(dificultad);

			switch (dificultad)
			{
			case 'F':				
				//Modifica el tiempo del juego dependiendo de la dificultad;
				this->TiempoSegundos->Interval = 2000;
				this->ContadorBebes->Interval = 1800;
				this->ContadorMonedas->Interval = 1600;
				this->TiempoHabilidades->Interval = 1000;
				this->jugador->setMunicion(15);
				break;
			case 'M':
				//Modifica el tiempo del juego dependiendo de la dificultad;
				this->TiempoSegundos->Interval = 2000;
				this->ContadorBebes->Interval = 1300;
				this->ContadorMonedas->Interval = 1800;
				this->TiempoHabilidades->Interval = 1000;
				this->jugador->setMunicion(10);
				break;
			case 'D':
				//Modifica el tiempo del juego dependiendo de la dificultad;
				this->TiempoSegundos->Interval = 2000;
				this->ContadorBebes->Interval = 1300;
				this->ContadorMonedas->Interval = 1800;
				this->TiempoHabilidades->Interval = 1000;
				this->jugador->setMunicion(5);
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
			delete jugador;
			delete jugadorImg;

			//Datos Bebes
			delete less30MBabyImg;
			delete more30MBabyImg;
			delete vectBebes;

			//Datos Monedas
			delete coin;
			delete vectCoins;
			delete coinImg;

			//Datos Tienda
			delete player;

			//Imagen Background
			delete BackgroundFacil;
			delete BackgroundMedio;
			delete BackgroundDificil;

			//Datos Vacunas
			delete vectVacunas;
			delete vacunasImg;

			//Imagen MamaAntivacuna
			delete vectEnemigos;
			delete OshawottImg;

			//Datos Aliadas
			delete aliada1;
			delete aliada2;
			delete aliada3;

			//Datos Tienda
			delete shop;

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
		//Opciones Juego
		bool juegoTerminado;
		char dificultad;

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

		Aliadas* aliada1;
		Aliadas* aliada2;
		Aliadas* aliada3;

		//Datos Tienda
		Shop* shop;

	private: System::Windows::Forms::Timer^ TiempoSegundos;
	private: System::Windows::Forms::Timer^ ContadorBebes;
private: System::Windows::Forms::Timer^ TiempoHabilidades;

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
			this->TiempoHabilidades = (gcnew System::Windows::Forms::Timer(this->components));
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
			// TiempoHabilidades
			// 
			this->TiempoHabilidades->Enabled = true;
			this->TiempoHabilidades->Interval = 1000;
			this->TiempoHabilidades->Tick += gcnew System::EventHandler(this, &Juego::TiempoHabilidades_Tick);
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

		switch (dificultad)
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
		vectVacunas->mostrar(bg->Graphics, vacunasImg);
		vectBebes->mostrar(bg->Graphics, less30MBabyImg, more30MBabyImg);
		vectEnemigos->mostrar(bg->Graphics, OshawottImg);
		jugador->mostrar(bg->Graphics, jugadorImg, 8, 9, 1.5, 1.5);
		
		if (aliada1->getEstaDisponible()) aliada1->mostrar(bg->Graphics, AliadaRam, 4, 3, 1.5, 1.5);
		if (aliada2->getEstaDisponible()) aliada2->mostrar(bg->Graphics, AliadaRem, 4, 3, 1.5, 1.5);
		if (aliada3->getEstaDisponible()) aliada3->mostrar(bg->Graphics, AliadaRem, 4, 3, 1.5, 1.5);

		//Mecanicas Juego
		
			//Movimiento Objetos
			vectBebes->mover();
			vectCoins->mover(bg->Graphics, coinImg);
			vectVacunas->mover();

			if (aliada1->getEstaDisponible()) aliada1->movimientoPosicionJugador(jugador->getX(), jugador->getY());
			if (aliada2->getEstaDisponible()) aliada2->movimientoPosicionJugador(jugador->getX(), jugador->getY());
			if (aliada3->getEstaDisponible()) aliada3->movimientoPosicionJugador(jugador->getX(), jugador->getY());

			//Colisiones

			for (int i = 0; i < vectCoins->getN(); i++)
			{
				if (jugador->getRectangle().IntersectsWith(vectCoins->getRectangleCertainPosicion(i))) vectCoins->coinAtrapada(i);
			}
			
			//Aliados: Aliada 1 es Velocidad Movimiento y Aliada 2 es Velocidad Ataque
			if (jugador->getRectangle().IntersectsWith(aliada1->getRectangle()) && aliada1->getEstaDisponible())
			{
				if (aliada1->getContador() <= 5)
				{
					jugador->setDx(aliada1->getValorAceleracionAnteriorDX() + 10);
					jugador->setDy(aliada1->getValorAceleracionAnteriorDY() + 10);
				}
				else
				{
					jugador->setDx(aliada1->getValorAceleracionAnteriorDX());
					jugador->setDy(aliada1->getValorAceleracionAnteriorDY());
					aliada1->setEstaDisponible(0);
				}
			}
			if (jugador->getRectangle().IntersectsWith(aliada2->getRectangle()) && aliada2->getEstaDisponible())
			{
				if (aliada2->getContador() <= 5)
				{
						
				}
				else
				{
					aliada2->setEstaDisponible(0);
				}
			}

			if (vectVacunas-> getN() != 0)
			{
				for (int i = 0; i < vectVacunas->getN(); i++)
				{
					for (int j = 0; j < vectEnemigos->getN(); j++)
					{
						if (vectEnemigos->mirandoJugador(j) && dificultad == 'F')
						{
							if (vectEnemigos->getRectangleCertainPosicion(j).IntersectsWith(vectVacunas->getRectangleCertainPosicion(i)))
							{
								vectVacunas->vacunaUsada(i);
							}
						}
						else if(dificultad == 'M' || dificultad == 'D')
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
		vectCoins->eliminar();
		vectBebes->eliminar();
		vectVacunas->eliminar();

		//HUD

		if (jugador->getRectangle().IntersectsWith(shop->getRectangleShop()))
		{

		}
		else
		{
			vectCoins->mostrarCantidadMonedasObtenidasText(bg->Graphics);
			vectBebes->mostrarPorcentajeBebesVacunadosYNoVacunados(bg->Graphics);
			jugador->mostrarMunicion(bg->Graphics);
		}

		//Juego Finalizado
		

		bg->Render(gr);

		delete bc, bg, gr;
	}

	private: System::Void Juego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		int costoVacunas = 5;

		switch (e->KeyCode)
		{

		//Movimiento Jugador

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

		//Invocacion Aliados
		case Keys::Z:
			if (aliada1->getEstaDisponible() == 0)
			{
				aliada1->inicio();
				aliada1->setValorAceleracionAnteriorDX(jugador->getDx());
				aliada1->setValorAceleracionAnteriorDY(jugador->getDy());
				aliada1->setContador(0);
				aliada1->setEstaDisponible(1);
			}
			break;
		case Keys::X:
			if (aliada2->getEstaDisponible() == 0)
			{
				aliada2->inicio();
				aliada2->setValorAceleracionAnteriorDX(jugador->getDx());
				aliada2->setValorAceleracionAnteriorDY(jugador->getDy());
				aliada2->setContador(0);
				aliada2->setEstaDisponible(1);
			}
			break;

		//Tienda Jugador
		case Keys::C:
			//Aqui se especifica el costo las vacunas
			if ((jugador->getRectangle().IntersectsWith(shop->getRectangleShop())) && (vectCoins->getDineroObtenido() >= costoVacunas))
			{
				vectCoins->setDineroObtenido(vectCoins->getDineroObtenido() - costoVacunas);
				jugador->setMunicion(jugador->getMunicion() + 5);
			}
			break;


		//Disparo Vacunas
		case Keys::Space:
			if(jugador->getMunicion() > 0)
			{
				jugador->setMunicion(jugador->getMunicion() - 1);
  				vectVacunas->agregar(jugador->getMunicion(), jugador->getX(), jugador->getY(), 20, 30, jugador->getIndexWidth());
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
		if (rand() % 101 > 50)	vectBebes->agregar();
	}
	
private: System::Void ContadorMonedas_Tick(System::Object^ sender, System::EventArgs^ e) {
	//Agrega dos monedas por segundo
	vectCoins->agregar();
}
private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void TiempoHabilidades_Tick(System::Object^ sender, System::EventArgs^ e) 
{
	if (aliada1->getEstaDisponible()) aliada1->setContador(aliada1->getContador() + 1);
	if (aliada2->getEstaDisponible()) aliada2->setContador(aliada2->getContador() + 1);
}
};
}