#pragma once

#include "Jugador.h"
#include "VectorBebes.h"
#include "Coin.h"
#include "VectorCoins.h"
#include "VectorVacunas.h"
#include "VectorOshawott.h"
#include "Shop.h"
#include "Aliado.h"

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

			temporizador = 0;

			//ObjetosJuego
			jugador = new Jugador();

			vectBebes = new VectorBebes();

			vectCoins = new VectorCoins();

			vectVacunas = new VectorVacunas();

			vectEnemigos= new VectorOshawott();

			aliadaVelocidad = new Aliadas();
			aliadaAtaque = new Aliadas();
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
			BackgroundDificil = gcnew Bitmap("Recursos/Imagenes\\BackgroundDificil.png");

			OshawottImg = gcnew Bitmap("Recursos/Imagenes\\Oshawott.png");

			Tienda1Img = gcnew Bitmap("Recursos/Imagenes\\Tienda1.png");
			Tienda2Img = gcnew Bitmap("Recursos/Imagenes\\Tienda2.png");

			AliadaRamImg = gcnew Bitmap("Recursos/Imagenes\\Aliada_Ram.png");
			AliadaRemImg = gcnew Bitmap("Recursos/Imagenes\\Aliada_Rem.png");

			//SonidosJuego

			player = gcnew SoundPlayer("Recursos/Musica\\TiendaEntrada.wav");
		}

		bool getJuegoTerminado() { return this->juegoTerminado; }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Juego()
		{
			if (appFinalizada)
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

				//Delete Tienda
				delete Tienda1Img;
				delete Tienda2Img;

				//Datos Aliadas
				delete aliadaVelocidad;
				delete aliadaAtaque;
				delete aliada3;

				//Datos Tienda
				delete shop;
			}

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
		int temporizador;
		bool appFinalizada;

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

		Bitmap^ AliadaRemImg;
		Bitmap^ AliadaRamImg;

		Bitmap^ Tienda1Img;
		Bitmap^ Tienda2Img;

		Aliadas* aliadaVelocidad;
		Aliadas* aliadaAtaque;
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
		
		if (aliadaVelocidad->getEstaDisponible()) aliadaVelocidad->mostrar(bg->Graphics, AliadaRamImg, 4, 3, 1.5, 1.5);
		if (aliadaAtaque->getEstaDisponible()) aliadaAtaque->mostrar(bg->Graphics, AliadaRemImg, 4, 3, 1.5, 1.5);
		if (aliada3->getEstaDisponible()) aliada3->mostrar(bg->Graphics, AliadaRemImg, 4, 3, 1.5, 1.5);

		//Mecanicas Juego

		vectEnemigos->agregarOshawott(dificultad);
				
			//Movimiento Objetos
			vectBebes->mover();
			vectCoins->mover(bg->Graphics, coinImg);
			vectVacunas->mover();

			if (aliadaVelocidad->getEstaDisponible()) aliadaVelocidad->movimientoPosicionJugador(jugador->getX(), jugador->getY());
			if (aliadaAtaque->getEstaDisponible()) aliadaAtaque->movimientoPosicionJugador(jugador->getX(), jugador->getY());
			if (aliada3->getEstaDisponible()) aliada3->movimientoPosicionJugador(jugador->getX(), jugador->getY());

			//Colisiones

			for (int i = 0; i < vectCoins->getN(); i++)
			{
				if (jugador->getRectangle().IntersectsWith(vectCoins->getRectangleCertainPosicion(i))) vectCoins->coinAtrapada(i);
			}
			
			//Aliada 1
			if (jugador->getRectangle().IntersectsWith(aliadaVelocidad->getRectangle()) && aliadaVelocidad->getEstaDisponible())
			{
				if (aliadaVelocidad->getHabilidadActivada() == 0)
				{
					jugador->setDx(jugador->getDx() + 5);
					jugador->setDy(jugador->getDy() + 5);
					aliadaVelocidad->setContador(15);
				}
				aliadaVelocidad->setHabilidadActivada(1);
			}
			
			//Aliada 2
			if (jugador->getRectangle().IntersectsWith(aliadaAtaque->getRectangle()) && aliadaAtaque->getEstaDisponible())
			{
				aliadaAtaque->setContador(15);
				aliadaAtaque->setHabilidadActivada(1);
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
			shop->mostrar(bg->Graphics, player, Tienda1Img, Tienda2Img);
		}
		else
		{
			vectCoins->mostrarCantidadMonedasObtenidasText(bg->Graphics);
			vectBebes->mostrarPorcentajeBebesVacunadosYNoVacunados(bg->Graphics, dificultad);
			jugador->mostrarMunicion(bg->Graphics);
			jugador->mostrarMensajeHabilidad(bg->Graphics);
		}

		//Juego Finalizado

		if (vectBebes->getPorcentaje() <= 5) {

			TiempoRespuesta->Enabled = false;
			TiempoSegundos->Enabled = false;
			ContadorBebes->Enabled = false;
			ContadorMonedas->Enabled = false;
			TiempoHabilidades->Enabled = false;

			MessageBox::Show("You Win");
			fstream scoreboard;
			fstream finalScoreboard;
			scoreboard.open("Recursos/Texto\\scoreboard.lvdf", ios::out);
			if (scoreboard.is_open())
			{
				scoreboard << temporizador << endl;
				scoreboard << vectCoins->getTotalMonedasObtenidas() << endl;
				scoreboard << vectVacunas->getVacunasUsadas() << endl;
				scoreboard << dificultad << endl;
				scoreboard.close();
			}

			finalScoreboard.open("Recursos/Texto\\scoreboard.lvdf", ios::app);
			if (finalScoreboard.is_open())
			{
				finalScoreboard << temporizador << endl;
				finalScoreboard << vectCoins->getTotalMonedasObtenidas() << endl;
				finalScoreboard << vectVacunas->getVacunasUsadas() << endl;
				finalScoreboard << dificultad << endl;
				finalScoreboard.close();
			}
		}
		
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
			if (aliadaVelocidad->getContador() >= 5 && aliadaVelocidad->getEstaDisponible() == 0)
			{
				aliadaVelocidad->setEstaDisponible(1);
				aliadaVelocidad->setContador(0);
				aliadaVelocidad->inicio();
			}
			break;
		case Keys::X:
			if (aliadaAtaque->getContador() >= 5 && aliadaVelocidad -> getEstaDisponible() == 0)
			{
				aliadaAtaque->setEstaDisponible(1);
				aliadaAtaque->setContador(0);
				aliadaAtaque->inicio();
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
  				vectVacunas->agregar(jugador->getMunicion(), jugador->getX(), jugador->getY(), (20 + aliadaAtaque->getHabilidadActivada() * 40), (30 + aliadaAtaque->getHabilidadActivada() * 40), jugador->getIndexWidth());
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
		if (vectBebes->getTotalBebesGenerados() < 30 && dificultad == 'F') vectBebes->agregar();
		else if (vectBebes->getTotalBebesGenerados() < 50 && dificultad == 'D') vectBebes->agregar();

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
	}

	switch (dificultad)
	{
	case 'F':
		//Modifica el tiempo del juego dependiendo de la dificultad;
		this->TiempoSegundos->Interval = 2000;
		this->ContadorBebes->Interval = 1300;
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

private: System::Void TiempoHabilidades_Tick(System::Object^ sender, System::EventArgs^ e)
{
	aliadaAtaque->setContador(aliadaAtaque->getContador() + 1);
	aliadaVelocidad->setContador(aliadaVelocidad->getContador() + 1);

	if (aliadaVelocidad->getContador() == 20 && aliadaVelocidad->getEstaDisponible())
	{
		if (aliadaVelocidad->getHabilidadActivada())
		{
			jugador->setDx(jugador->getDx() - 5);
			jugador->setDy(jugador->getDy() - 5);
		}
		aliadaVelocidad->setHabilidadActivada(0);
		aliadaVelocidad->setEstaDisponible(0);
		aliadaVelocidad->setContador(0);
	}

	if (aliadaAtaque->getContador() == 20 && aliadaAtaque->getEstaDisponible())
	{
		aliadaAtaque->setHabilidadActivada(0);
		aliadaAtaque->setEstaDisponible(0);
		aliadaAtaque->setContador(0);
	}

	//Este if sirve para que el tiempo no inicie desde el menú principal
	if (vectBebes->getN() != 0) temporizador++;
	
	
	if (temporizador == 120 && vectBebes->getPorcentaje() >= 5)
	{
		TiempoRespuesta->Enabled = false;
		TiempoSegundos->Enabled = false;
		ContadorBebes->Enabled = false;
		ContadorMonedas->Enabled = false;
		TiempoHabilidades->Enabled = false;
		MessageBox::Show("Game over");
		fstream scoreboard;
		fstream finalScoreboard;

		scoreboard.open("Recursos/Texto\\aux_scoreboard.lvdf", ios::out);
		if (scoreboard.is_open())
		{
			scoreboard << temporizador << endl;
			scoreboard << vectCoins->getTotalMonedasObtenidas() << endl;
			scoreboard << vectVacunas->getVacunasUsadas() << endl;
			scoreboard << dificultad << endl;
			scoreboard.close();
		}

		finalScoreboard.open("Recursos/Texto\\scoreboard.lvdf", ios::app);
		if (finalScoreboard.is_open())
		{
			finalScoreboard << temporizador << endl;
			finalScoreboard << vectCoins->getTotalMonedasObtenidas() << endl;
			finalScoreboard << vectVacunas->getVacunasUsadas() << endl;
			finalScoreboard << dificultad << endl;
			finalScoreboard.close();
		}
	}
}
};
}