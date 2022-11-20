#pragma once

#include "Jugador.h"
#include "VectorBebes.h"
#include "Coin.h"
#include "VectorCoins.h"
#include "VectorVacunas.h"
#include "VectorEnemigo.h"
#include "Shop.h"
#include "Aliado.h"
#include "HUD.h"

#include "Scoreboard.h"

#include <fstream>
#include <conio.h>
#include <iostream>
#include <string>

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

			tiempoJuego = 0;
			tiempoRestante = 0;
			juegoFuncional = 1;
			juegoTerminado = 0;

			//ObjetosJuego
			jugador = new Jugador();

			vectBebes = new VectorBebes();

			vectCoins = new VectorCoins();

			vectVacunas = new VectorVacunas();

			vectEnemigos= new VectorEnemigo();

			aliadaVelocidad = new Aliadas();
			aliadaAtaque = new Aliadas();
			aliada3 = new Aliadas();

			shop = new Shop();

			interfaz = new HUD();

			//ImagenesJuego
			jugadorImg = gcnew Bitmap("Recursos/Imagenes\\Doctor.png");

			less30MBabyImg = gcnew Bitmap("Recursos/Imagenes\\Bebes.png");
			more30MBabyImg = gcnew Bitmap("Recursos/Imagenes\\BigBabies.png");

			coinImg = gcnew Bitmap("Recursos/Imagenes\\Moneda.png");
			coinImgHUD = gcnew Bitmap("Recursos/Imagenes\\MonedaHUD.png");

			vacunasImg = gcnew Bitmap("Recursos/Imagenes\\Vacuna.png");
			vacunasHUD = gcnew Bitmap("Recursos/Imagenes\\VacunaHUD.png");
			vacunadoHUD = gcnew Bitmap("Recursos/Imagenes\\VacunadoHUD.png");

			BackgroundFacil = gcnew Bitmap("Recursos/Imagenes\\BackgroundFacil.png");
			BackgroundMedio = gcnew Bitmap("Recursos/Imagenes\\BackgroundMedio.jpg");
			BackgroundDificil = gcnew Bitmap("Recursos/Imagenes\\BackgroundDificil.png");

			EnemigoImg = gcnew Bitmap("Recursos/Imagenes\\Enemigo.png");

			Vendedor1Shop = gcnew Bitmap("Recursos/Imagenes\\Vendedor1Shop.png");
			Vendedor2Shop = gcnew Bitmap("Recursos/Imagenes\\Vendedor2Shop.png");

			AliadaRamImg = gcnew Bitmap("Recursos/Imagenes\\Aliada_Ram.png");
			AliadaRemImg = gcnew Bitmap("Recursos/Imagenes\\Aliada_Rem.png");

			//SonidosJuego

			sonidoMenu = gcnew SoundPlayer("Recursos/Musica\\MenuJuego.wav");
			sonidoTienda = gcnew SoundPlayer("Recursos/Musica\\TiendaEntrada.wav");
			MusicaJuegoF = gcnew SoundPlayer("Recursos/Musica\\MusicaJuegoF.wav");
			MusicaJuegoD = gcnew SoundPlayer("Recursos/Musica\\MusicaJuegoD.wav");
		}

		bool getJuegoTerminado() { return this->juegoTerminado; }
		bool getJuegoFuncional() { return this->juegoFuncional; };

		void finalizacionJuego(char estado)
		{
			switch (dificultad)
			{
			case 'F':
				MusicaJuegoF->Stop();
				break;
			case 'M':
				break;
			case 'D':
				MusicaJuegoD->Stop();
				break;
			default:
				break;
			}

			juegoTerminado = 1;
			TiempoRespuesta->Enabled = false;
			TiempoSegundos->Enabled = false;
			ContadorBebes->Enabled = false;
			ContadorMonedas->Enabled = false;
			TiempoHabilidades->Enabled = false;

			Scoreboard^ puntajes = gcnew Scoreboard();
			Juego::Hide();

			puntajes->setDificultad(dificultad);

			if (estado == 'W')
			{
				puntajes->setModo('W');
				puntajes->setPuntaje(tiempoJuego);
			}
			
			if (estado == 'L')
			{
				puntajes->setModo('L');
			}
			puntajes->Show();
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
			delete coinImgHUD;

			delete interfaz; 

			//Datos Tienda
			delete sonidoTienda;
			delete shop;

			//Imagen Background
			delete BackgroundFacil;
			delete BackgroundMedio;
			delete BackgroundDificil;

			//Datos Vacunas
			delete vectVacunas;
			delete vacunasImg;
			delete vacunasHUD;
			delete vacunadoHUD;
				
			//Imagen MamaAntivacuna
			delete vectEnemigos;
			delete EnemigoImg;

			//Delete Tienda
			delete Vendedor1Shop;
			delete Vendedor2Shop;

			delete MusicaJuegoF;
			delete MusicaJuegoD;

			//Datos Aliadas
			delete aliadaVelocidad;
			delete aliadaAtaque;
			delete aliada3;

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
		int tiempoRestante;
		int tiempoJuego;
		bool juegoFuncional;

		//Datos Jugador
		Jugador* jugador;
		Bitmap^ jugadorImg;

		//Datos Bebes
		Bitmap^ less30MBabyImg;
		Bitmap^ more30MBabyImg;
		VectorBebes* vectBebes;

		HUD * interfaz;

		//Datos Monedas
		Coin* coin;
		VectorCoins* vectCoins;
		Bitmap^ coinImg;
		Bitmap^ coinImgHUD;

		//Datos Tienda
		
		SoundPlayer^ sonidoMenu;
		SoundPlayer^ sonidoTienda;
		SoundPlayer^ MusicaJuegoF;
		SoundPlayer^ MusicaJuegoD;

		//Imagen Background
		Bitmap^ BackgroundFacil;
		Bitmap^ BackgroundMedio;
		Bitmap^ BackgroundDificil;

		//Datos Vacunas
		VectorVacunas* vectVacunas;
		Bitmap^ vacunasImg;
		Bitmap^ vacunasHUD;
		Bitmap^ vacunadoHUD;

		//Imagen MamaAntivacuna
		VectorEnemigo* vectEnemigos;
		Bitmap^ EnemigoImg;
		
		//Datos Aliadas
		
		Aliadas* aliadaVelocidad;
		Aliadas* aliadaAtaque;
		Aliadas* aliada3;
		Bitmap^ AliadaRemImg;
		Bitmap^ AliadaRamImg;

		Shop* shop;
		Bitmap^ Vendedor1Shop;
		Bitmap^ Vendedor2Shop;
		
	private: System::Windows::Forms::Timer^ TiempoSegundos;
	private: System::Windows::Forms::Timer^ ContadorBebes;
	private: System::Windows::Forms::Timer^ TiempoHabilidades;
private: System::Windows::Forms::Label^ label_Timer;
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
			this->label_Timer = (gcnew System::Windows::Forms::Label());
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
			// label_Timer
			// 
			this->label_Timer->AutoSize = true;
			this->label_Timer->Enabled = false;
			this->label_Timer->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Timer->Location = System::Drawing::Point(698, 68);
			this->label_Timer->Name = L"label_Timer";
			this->label_Timer->Size = System::Drawing::Size(0, 19);
			this->label_Timer->TabIndex = 0;
			// 
			// Juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1160, 800);
			this->Controls->Add(this->label_Timer);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Juego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Juego";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Juego::Juego_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Juego::Juego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TiempoRespuesta_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Buffer
		Graphics^ gr = this->CreateGraphics();
		BufferedGraphicsContext^ bc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bg = bc->Allocate(gr, this->ClientRectangle);

		bg->Graphics->Clear(Color::LightSeaGreen);

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
		vectEnemigos->mostrar(bg->Graphics, EnemigoImg);
		jugador->mostrar(bg->Graphics, jugadorImg, 8, 9, 1.5, 1.5);
		
		if (aliadaVelocidad->getEtapas() == 'I' || aliadaVelocidad->getEtapas() == 'U') aliadaVelocidad->mostrar(bg->Graphics, AliadaRamImg, 4, 3, 1.5, 1.5);
		if (aliadaAtaque->getEtapas() == 'I' || aliadaAtaque->getEtapas() == 'U')  aliadaAtaque->mostrar(bg->Graphics, AliadaRemImg, 4, 3, 1.5, 1.5);
		if (aliada3->getEtapas() == 'I' || aliada3->getEtapas() == 'U')  aliada3->mostrar(bg->Graphics, AliadaRemImg, 4, 3, 1.5, 1.5);

		//Mecanicas Juego
				
			//Movimiento Objetos
			vectBebes->mover();
			vectCoins->mover(bg->Graphics, coinImg);
			vectVacunas->mover();
			
			if (aliadaVelocidad->getEtapas() == 'I' || aliadaVelocidad->getEtapas() == 'U') aliadaVelocidad->movimientoPosicionJugador(jugador->getX(), jugador->getY());
			if (aliadaAtaque->getEtapas() == 'I' || aliadaAtaque->getEtapas() == 'U') aliadaAtaque->movimientoPosicionJugador(jugador->getX(), jugador->getY());
			if (aliada3->getEtapas() == 'I' || aliada3->getEtapas() == 'U') aliada3->movimientoPosicionJugador(jugador->getX(), jugador->getY());
			
			//Colisiones

			for (int i = 0; i < vectCoins->getN(); i++)
			{
				if (jugador->getRectangle().IntersectsWith(vectCoins->getRectangleCertainPosicion(i))) 
				{
					vectCoins->coinAtrapada(i);
					jugador->setDinero(jugador->getDinero() + 1);
				}
			}

			
			//Aliada 1
			if (jugador->getRectangle().IntersectsWith(aliadaVelocidad->getRectangle()) && aliadaVelocidad->getEtapas() == 'I')
			{
				if (aliadaVelocidad->getEtapas() == 'I')
				{
					jugador->setDx(jugador->getDx() + 5);
					jugador->setDy(jugador->getDy() + 5);
					aliadaVelocidad->setContador(0);
				}
				aliadaVelocidad->setEtapas('U');
			}
			
			//Aliada 2
			if (jugador->getRectangle().IntersectsWith(aliadaAtaque->getRectangle()) && aliadaAtaque->getEtapas() == 'I')
			{
				if (aliadaAtaque->getEtapas() == 'I')
				{
					aliadaAtaque->setContador(0);
				}
				aliadaAtaque->setEtapas('U');
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
								vectVacunas->setCombo(0);
							}
						}
						else if(dificultad == 'M' || dificultad == 'D')
						{
							if (vectEnemigos->getRectangleCertainPosicion(j).IntersectsWith(vectVacunas->getRectangleCertainPosicion(i)))
							{
								vectVacunas->vacunaUsada(i);
								vectVacunas->setCombo(0);
							}
						}
						
					}
					for (int j = 0; j < vectBebes->getN(); j++)
					{
						if (vectBebes->getRectangleCertainPosicion(j).IntersectsWith(vectVacunas->getRectangleCertainPosicion(i)))
						{
							vectVacunas->vacunaUsada(i);
							vectBebes->Vacunado(j);
							vectVacunas->setCombo(vectVacunas->getCombo() + 1);
						}
					}
				}
			}

			if (vectVacunas->getCombo() == 5)
			{
				jugador->setDinero(jugador->getDinero() + 1);
				vectVacunas->setCombo(0);
			}

		//Eliminacion Objetos
		vectCoins->eliminar();
		vectBebes->eliminar();
		vectVacunas->eliminar();

		//HUD

		if (jugador->getRectangle().IntersectsWith(shop->getRectangleShop()))
		{
			switch (dificultad)
			{
			case 'F':
				shop->mostrar(bg->Graphics, Vendedor2Shop, coinImgHUD, vacunasHUD, jugador->getDinero(),jugador->getMunicion(),sonidoTienda);
				break;
			case 'M':
				shop->mostrar(bg->Graphics, Vendedor1Shop, coinImgHUD, vacunasHUD, jugador->getDinero(), jugador->getMunicion(),sonidoTienda);
				break;
			case 'D':
				shop->mostrar(bg->Graphics, Vendedor1Shop, coinImgHUD, vacunasHUD, jugador->getDinero(), jugador->getMunicion(), sonidoTienda);
				break;

			default:
				break;
			}
		}
		else
		{

			if (shop->getJugadorAtStore() == 'I')
			{
				shop->setJugadorAtStore('N');
				switch (dificultad)
				{
				case 'F':
					MusicaJuegoF->Load();
					MusicaJuegoF->Play();
					break;
				case 'M':
					break;
				case 'D':
					MusicaJuegoD->Load();
					MusicaJuegoD->Play();
					break;
				default:
					break;
				}
			}
			interfaz->mostrarDinero(bg->Graphics, coinImgHUD, jugador->getDinero());
			interfaz->mostrarVacunas(bg->Graphics, vacunasHUD, jugador->getMunicion());
			interfaz->mostrarTiempoRestante(bg->Graphics, tiempoRestante, tiempoJuego);
			interfaz->mostrarVacunados(bg->Graphics, vacunadoHUD, dificultad, vectBebes->getBebesVacunados(), vectBebes->getTotalBebes());

			if (aliadaAtaque->getEtapas() == 'C') { aliadaAtaque->mostrarTiempoCooldown(bg->Graphics, aliadaAtaque->getContadorEtapaC(), aliadaAtaque->getContador(), AliadaRemImg, 980, 700); }
			if (aliadaVelocidad->getEtapas() == 'C') { aliadaVelocidad->mostrarTiempoCooldown(bg->Graphics, aliadaVelocidad->getContadorEtapaC(), aliadaVelocidad->getContador(), AliadaRamImg, 1060, 700); }
		}

		bg->Render(gr);
		delete bc, bg, gr;
	}

	private: System::Void Juego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

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
			if (aliadaVelocidad->getEtapas() == 'L')
			{
				aliadaVelocidad->setEtapas('I');
				aliadaVelocidad->setContador(0);
 			}
			break;
		case Keys::X:
			if (aliadaAtaque->getEtapas() == 'L')
			{
				aliadaAtaque->setEtapas('I');
				aliadaAtaque->setContador(0);
			}
			break;

		//Tienda Jugador
		case Keys::C:
			//Aqui se especifica el costo las vacunas
			if ((jugador->getRectangle().IntersectsWith(shop->getRectangleShop())) && (jugador->getDinero() >= shop->getCostoVacunas()))
			{
				jugador->setDinero(jugador->getDinero() - shop->getCostoVacunas());
				jugador->setMunicion(jugador->getMunicion() + shop->getCantidadVacunas());
			}
			break;

		//Disparo Vacunas
		case Keys::Space:
			if(jugador->getMunicion() > 0)
			{
				jugador->setMunicion(jugador->getMunicion() - 1);
  				vectVacunas->agregar(jugador->getMunicion(), jugador->getX(), jugador->getY(), (20 + (aliadaAtaque->getEtapas() == 'U') * 40), (30 + (aliadaAtaque->getEtapas() == 'U') * 40), jugador->getIndexWidth());
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
		if (vectBebes->getTotalBebesGenerados() < vectBebes->getTotalBebes()) vectBebes->agregar();
	}
	
private: System::Void ContadorMonedas_Tick(System::Object^ sender, System::EventArgs^ e) {
	//Agrega dos monedas por segundo
	vectCoins->agregar();
}
private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e) {
	ifstream textDificultad;
	textDificultad.open("Recursos/Texto\\Difficultad.lvdf", ios::in);
	if (textDificultad.is_open())
	{
		dificultad = textDificultad.get();
		textDificultad.close();
		if (0 == ((dificultad == 'F' || dificultad == 'M') || dificultad == 'D'))
		{
			this->TiempoRespuesta->Enabled = false;
			this->TiempoSegundos->Enabled = false;
			this->ContadorBebes->Enabled = false;
			this->ContadorMonedas->Enabled = false;
			this->TiempoHabilidades->Enabled = false;

			MessageBox::Show("ERROR ERROR ERROR ERROR ERROR ERROR CHANGE DIFICULTY ERROR ERROR ERROR ERROR ERROR ERROR CHANGE DIFICULTY");
		}
	}

	switch (dificultad)
	{
	case 'F':
		//Modifica el tiempo del juego dependiendo de la dificultad;
		this->TiempoSegundos->Interval = 2000;
		this->ContadorBebes->Interval = 1300;
		this->ContadorMonedas->Interval = 1600;
		this->TiempoHabilidades->Interval = 1000;
		this->tiempoRestante = 180;
		this->jugador->setMunicion(15);
		shop->setCantidadVacunas(10);
		shop->setCostoVacunas(5);
		vectBebes->setTotalBebes(30);
		vectEnemigos->agregarEnemigo(4);

		aliadaAtaque->setContadorEtapaI(20);
		aliadaAtaque->setContadorEtapaU(5);
		aliadaAtaque->setContadorEtapaC(5);

		aliadaVelocidad->setContadorEtapaI(20);
		aliadaVelocidad->setContadorEtapaU(5);
		aliadaVelocidad->setContadorEtapaC(5);

		MusicaJuegoF->Load();
		MusicaJuegoF->Play();
		break;
	case 'M':
		//Modifica el tiempo del juego dependiendo de la dificultad;
		this->TiempoSegundos->Interval = 2000;
		this->ContadorBebes->Interval = 1300;
		this->ContadorMonedas->Interval = 1800;
		this->TiempoHabilidades->Interval = 1000;
		this->tiempoRestante = 180;
		this->jugador->setMunicion(10);
		shop->setCantidadVacunas(5);
		shop->setCostoVacunas(10);
		vectBebes->setTotalBebes(30);
		vectEnemigos->agregarEnemigo(6);
		
		aliadaAtaque->setContadorEtapaI(20);
		aliadaAtaque->setContadorEtapaU(5);
		aliadaAtaque->setContadorEtapaC(5);
		
		aliadaVelocidad->setContadorEtapaI(20);
		aliadaVelocidad->setContadorEtapaU(5);
		aliadaVelocidad->setContadorEtapaC(5);
		break;
	case 'D':
		//Modifica el tiempo del juego dependiendo de la dificultad;
		this->TiempoSegundos->Interval = 3300;
		this->ContadorBebes->Interval = 1800;
		this->ContadorMonedas->Interval = 1600;
		this->TiempoHabilidades->Interval = 1000;
		
		this->tiempoRestante = 200;
		this->jugador->setMunicion(10);

		shop->setCantidadVacunas(8);
		shop->setCostoVacunas(6);
		vectBebes->setTotalBebes(40);
		vectEnemigos->agregarEnemigo(6);
		
		aliadaAtaque->setContadorEtapaI(20);
		aliadaAtaque->setContadorEtapaU(5);
		aliadaAtaque->setContadorEtapaC(8);
		
		aliadaVelocidad->setContadorEtapaI(20);
		aliadaVelocidad->setContadorEtapaU(5);
		aliadaVelocidad->setContadorEtapaC(8);

		MusicaJuegoD->Load();
		MusicaJuegoD->Play();
		break;

	default:
		break;
	}
}

private: System::Void TiempoHabilidades_Tick(System::Object^ sender, System::EventArgs^ e)
{
	bool juegoTerminado = 0; 

	aliadaAtaque->setContador(aliadaAtaque->getContador() + 1);
	aliadaVelocidad->setContador(aliadaVelocidad->getContador() + 1);

	switch (aliadaVelocidad->getEtapas())
	{
	case 'I':
		if ((aliadaVelocidad->getContador() == aliadaVelocidad->getContadorEtapaI()))
		{
			aliadaVelocidad->setEtapas('C');
			aliadaVelocidad->setContador(0);
		}		
		break;

	case 'U':
		if ((aliadaVelocidad->getContador() == aliadaVelocidad->getContadorEtapaU()))
		{
			aliadaVelocidad->setEtapas('C');
			aliadaVelocidad->setContador(0);

			jugador->setDx(jugador->getDx() - 5);
			jugador->setDy(jugador->getDy() - 5);
		}
		break;

	case 'C':
		if ((aliadaVelocidad->getContador() == aliadaVelocidad->getContadorEtapaC()))
		{
			aliadaVelocidad->setEtapas('L');
			aliadaVelocidad->setContador(0);
		}
		break;

	default:
		break;
	}

	switch (aliadaAtaque->getEtapas())
	{
	case 'I':
		if ((aliadaAtaque->getContador() == aliadaVelocidad->getContadorEtapaI()))
		{
			aliadaAtaque->setEtapas('C');
			aliadaAtaque->setContador(0);
		}
		break;

	case 'U':
		if ((aliadaAtaque->getContador() == aliadaVelocidad->getContadorEtapaU()))
		{
			aliadaAtaque->setEtapas('C');
			aliadaAtaque->setContador(0);
		}
		break;

	case 'C':
		if ((aliadaAtaque->getContador() == aliadaVelocidad->getContadorEtapaC()))
		{
			aliadaAtaque->setEtapas('L');
			aliadaAtaque->setContador(0);
		}

		break;

	default:
		break;
	}

	if ((vectBebes->getBebesVacunados() * 100) / vectBebes->getTotalBebes() >= 95)
	{
		finalizacionJuego('W');
	}
	else if (tiempoJuego == tiempoRestante)
	{
		finalizacionJuego('L');
	}

	//Este if sirve para que el tiempo no inicie desde el menú principal
	tiempoJuego++;
}

private: System::Void Juego_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	switch (dificultad)
	{
	case 'F':
		MusicaJuegoF->Stop();
		sonidoMenu->Play();
		break;
	case 'M':
		break;
	case 'D':
		MusicaJuegoD->Stop();
		sonidoMenu->Play();
		break;
	default:
		break;
	}
}
};
}