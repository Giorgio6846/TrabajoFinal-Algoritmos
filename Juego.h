#pragma once

#include "Jugador.h"
#include "VectorBebes.h"
#include "Coin.h"
#include "VectorCoins.h"
#include "VectorVacunas.h"
#include "Oshawott.h"

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
			bigBabyImg = gcnew Bitmap("Recursos/Imagenes\\BigBabies.png");

			vectCoins = new VectorCoins();
			coinImg = gcnew Bitmap("Recursos/Imagenes\\Monedas.png");

			vectVacunas = new VectorVacunas();
			vacunasImg = gcnew Bitmap("Recursos/Imagenes\\Vacuna.png");

			player = gcnew SoundPlayer("Recursos/Musica\\TiendaEntrada.wav");

			Background = gcnew Bitmap("Recursos/Imagenes\\Campo_de_concentracion.png");

			enemigo = new Oshawott();
			mamaAntiVacunaImg = gcnew Bitmap("Recursos/Imagenes\\Oshawott.png");
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
		Bitmap^ bigBabyImg;

		//Datos Monedas
		Coin* coin;
		VectorCoins* vectCoins;
		Bitmap^ coinImg;

		//Datos Tienda
		SoundPlayer^ player;
		
		//Imagen Background
		Bitmap^ Background;

		//Datos Vacunas
		VectorVacunas* vectVacunas;
		Bitmap^ vacunasImg;

		//Imagen MamaAntivacuna
		Oshawott* enemigo;
		Bitmap^ mamaAntiVacunaImg;
		

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
			this->ClientSize = System::Drawing::Size(960, 800);
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
		Form::ClientSize = Background->Size;
		bg->Graphics->DrawImage(Background, 0, 0, Background->Size.Width, Background->Size.Height);

		//Mecanicas Juego
			
		vectCoins->monedasObtenidasText(bg->Graphics);

		
		//Eliminacion Objetos
		vectCoins->eliminarCoins();
		vectBebes->eliminarBebes();

			//Movimiento Objetos
		vectBebes->moverBebes(bg->Graphics);
		vectCoins->moverCoins(bg->Graphics, coinImg);
		vectVacunas->moverVacunas();
		enemigo->mover();

		//Graficos
		enemigo->mostrar(bg->Graphics, mamaAntiVacunaImg, 4, 4, 1, 1);
		jugador->mostrar(bg->Graphics, jugadorImg,8,9, 1.5, 1.5);
		vectVacunas->mostrarVacunas(bg->Graphics, vacunasImg);
		jugador->atShop(bg->Graphics,player);

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
			switch (jugador->getOpcionCaracterWidth() - jugador->getOpcionCaracterHeight())
			{
			case 0:
				vectVacunas->agregarVacunas(jugador->getMunicion(), jugador->getX(), jugador->getY(), 20, 30, jugador->getIndexWidth());
				break;																									
			case 1:																										
				vectVacunas->agregarVacunas(jugador->getMunicion(), jugador->getX(), jugador->getY(), 20, 30, jugador->getIndexWidth());
				break;																									
			case 2:																										
				vectVacunas->agregarVacunas(jugador->getMunicion(), jugador->getX(), jugador->getY(), 20, 30, jugador->getIndexWidth());
				break;																									
			case 3:																										
				vectVacunas->agregarVacunas(jugador->getMunicion(), jugador->getX(), jugador->getY(), 20, 30, jugador->getIndexWidth());
				break;

			default:
				break;
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