#pragma once

#include <fstream>
#include <conio.h>
#include <iostream>
#include <string>

#include <vector>

#include "VectorBebes.h"

#define CantidadMaxima 10

using namespace std;

/*
Modos:
V = Este modo funciona para visualizar los anteriores puntajes realizados
W = Este modo funciona para cuando el jugador ha ganado la partida este permite que se pueda escribir su nombre en la tabla de ganadores
L = Este modo funciona cuando el jugador ha perdido la partida

modoEscritura:
S = Permite que el jugador ponga el nombre en la lista
N = No permite al jugador que ponga su nombre en la lista
F = El jugador ya puso su nombre en la lista
G = Archiva ya aha sido guardado

modoTecla:
U = La tecla presionada ha sido la tecla direccional Arriba
D = La tecla presionada ha sido la tecla direccional Abajo
E = La tecla presionada ha sido la tecla Enter

*/

struct datosPuestos {
	char nombre[4];
	int tiempoRealizado;
}datosJugador, datosLectura,datosEscritura;

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Scoreboard
	/// </summary>
	public ref class Scoreboard : public System::Windows::Forms::Form
	{
	public:
		Scoreboard(void)
		{
			vectBebes = new VectorBebes;

			less30MBabyImg = gcnew Bitmap("Recursos/Imagenes\\Bebes.png");
			more30MBabyImg = gcnew Bitmap("Recursos/Imagenes\\BigBabies.png");

			sonidoWin = gcnew SoundPlayer("Recursos/Musica\\YouWin.wav");
			sonidoLose = gcnew SoundPlayer("Recursos/Musica\\YouLose.wav");


			arrDatos = new vector <datosPuestos*>;
			modo = 'A';
			modoEscritura = 'A';
			dificultad = 'F';
			modoTecla = 'A';
			posJugador = 0;
			posChar = 0;
			posLetra = 'A';

			vectBebes->setTotalMesVida(30);

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//;
			lecturaDatos();
		}

		void setPuntaje(int tiempo)
		{
			datosJugador.tiempoRealizado = tiempo;
			datosJugador.nombre[0] = 'A';
			datosJugador.nombre[1] = 'A';
			datosJugador.nombre[2] = 'A';
			this -> modoEscritura = verificacionJugadorGanador();
		}

		void setDificultad(char dificultad) 
		{
			this->dificultad = dificultad;
			arrDatos->clear();
			lecturaDatos();
		}

		void setModo(char modo)
		{
			if (modo == 'W') 
			{
				sonidoWin->Load();
				sonidoWin->Play();
			}
			if (modo == 'L') 
			{
				sonidoLose->Load();
				sonidoLose->Play();
			}

			this->modo = modo;
		}

		void alternarDificultad(char direccion)
		{
			if (direccion == 'L')
			{
				switch (dificultad)
				{
				case 'F':
					dificultad = 'D';
					break;
				case 'M':
					dificultad = 'F';
					break;
				case 'D':
					dificultad = 'F';
					break;
				default:
					break;
				}
			}
			if (direccion == 'R')
			{
				switch (dificultad)
				{
				case 'F':
					dificultad = 'D';
					break;
				case 'M':
					dificultad = 'D';
					break;
				case 'D':
					dificultad = 'F';
					break;
				default:
					break;
				}
			}
		}

		void lecturaDatos()
		{
			ifstream lecturaScoreboard;
			string lineaArchivo;

			switch (dificultad)
			{
			case 'F':
				lecturaScoreboard.open("Recursos/Texto\\ScoreboardF.lvdf", ios::in);
				break;
			case 'M':
				lecturaScoreboard.open("Recursos/Texto\\ScoreboardM.lvdf", ios::in);
				break;
			case 'D':
				lecturaScoreboard.open("Recursos/Texto\\ScoreboardD.lvdf", ios::in);
				break;
			default:
				break;
			}

			if (lecturaScoreboard.is_open())
			{
				for (int i = 0; !lecturaScoreboard.eof(); i++)
				{
					lecturaScoreboard  >> datosEscritura.nombre >> datosEscritura.tiempoRealizado;
					if (datosEscritura.nombre[0] != char(0))
					{
						arrDatos->push_back(new datosPuestos());
						arrDatos->at(arrDatos->size() - 1)->nombre[0] = datosEscritura.nombre[0];
						arrDatos->at(arrDatos->size() - 1)->nombre[1] = datosEscritura.nombre[1];
						arrDatos->at(arrDatos->size() - 1)->nombre[2] = datosEscritura.nombre[2];
						arrDatos->at(arrDatos->size() - 1)->nombre[3] = datosEscritura.nombre[3];
						arrDatos->at(arrDatos->size() - 1)->tiempoRealizado = datosEscritura.tiempoRealizado;
					}
				}

			}
			lecturaScoreboard.close();
		}

		char verificacionJugadorGanador()
		{
			if (arrDatos->size() == 0)
			{
				arrDatos->push_back(&datosJugador);
				posJugador = 0;
				return 'S';
			}
			if (arrDatos->size() > 0)
			{
				for (int i = 0; i < arrDatos->size(); i++)
				{
					if (datosJugador.tiempoRealizado < (arrDatos->at(i)->tiempoRealizado))
					{
						arrDatos->insert(arrDatos->begin() + i, &datosJugador);
						if (arrDatos->size() > CantidadMaxima)
						{
							arrDatos->pop_back();
						}
						posJugador = i;
						return 'S';
					}
				}
				return 'N';
			}
			return 'N';
		}

		void escrituraDatos()
		{
			ofstream escrituraScoreboard;

			int tiempoTemporal;
			char nombreTemporal[4];

			switch (dificultad)
			{
			case 'F':
				escrituraScoreboard.open("Recursos/Texto\\ScoreboardF.lvdf", ios::out);
				break;
			case 'M':
				escrituraScoreboard.open("Recursos/Texto\\ScoreboardM.lvdf", ios::out);
				break;
			case 'D':
				escrituraScoreboard.open("Recursos/Texto\\ScoreboardD.lvdf", ios::out);
				break;
			default:
				break;
			}

			for (int i = 0; i < arrDatos->size(); i++)
			{
				datosEscritura.tiempoRealizado = arrDatos->at(i)->tiempoRealizado;
				datosEscritura.nombre[0] = arrDatos->at(i)->nombre[0];
				datosEscritura.nombre[1] = arrDatos->at(i)->nombre[1];
				datosEscritura.nombre[2] = arrDatos->at(i)->nombre[2];
				datosEscritura.nombre[3] = arrDatos->at(i)->nombre[3];

				escrituraScoreboard << datosEscritura.nombre << " " << datosEscritura.tiempoRealizado << endl;

			}
			escrituraScoreboard.close();
		}

		char escrituraNombre()
		{
			if (posChar == 3) return 'F';

			switch (modoTecla)
			{
			case 'E':
				posChar = posChar + 1;
				modoTecla = 'A';
				break;
			case 'U':
				posLetra = char(int(posLetra) + 1);
				modoTecla = 'A';
				break;
			case 'D':
				posLetra = char(int(posLetra) - 1);
				modoTecla = 'A';
				break;
			default:
				break;
			}
			
			if (int(posLetra) == 64) posLetra = char(90);
			if (int(posLetra) == 91) posLetra = char(65);

			switch (posChar)
			{
			case 0:
				arrDatos->at(posJugador)->nombre[0] = posLetra;
				break;
			case 1:
				arrDatos->at(posJugador)->nombre[1] = posLetra;
				break;
			case 2:
				arrDatos->at(posJugador)->nombre[2] = posLetra;
				break;

			default:
				break;
			}
			return 'S';
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Scoreboard()
		{
			arrDatos->clear();

			delete less30MBabyImg;
			delete more30MBabyImg;
			delete vectBebes;

			delete sonidoWin;
			delete sonidoLose;

			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Bitmap^ less30MBabyImg;
		Bitmap^ more30MBabyImg;
		VectorBebes* vectBebes;

		SoundPlayer^ sonidoWin;
		SoundPlayer^ sonidoLose;

		char modo;
		char modoEscritura;
		char modoTecla;
		char dificultad;
		int posJugador;
		int posChar;
		char posLetra;
		vector <datosPuestos*>* arrDatos;

	private: System::Windows::Forms::Timer^ TiempoRespuesta;
private: System::Windows::Forms::Timer^ TiempoBebe;
private: System::Windows::Forms::Timer^ EliminarBebes;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->TiempoRespuesta = (gcnew System::Windows::Forms::Timer(this->components));
			this->TiempoBebe = (gcnew System::Windows::Forms::Timer(this->components));
			this->EliminarBebes = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// TiempoRespuesta
			// 
			this->TiempoRespuesta->Enabled = true;
			this->TiempoRespuesta->Interval = 250;
			this->TiempoRespuesta->Tick += gcnew System::EventHandler(this, &Scoreboard::TiempoRespuesta_Tick);
			// 
			// TiempoBebe
			// 
			this->TiempoBebe->Enabled = true;
			this->TiempoBebe->Interval = 1500;
			this->TiempoBebe->Tick += gcnew System::EventHandler(this, &Scoreboard::TiempoBebe_Tick);
			// 
			// EliminarBebes
			// 
			this->EliminarBebes->Interval = 5000;
			this->EliminarBebes->Tick += gcnew System::EventHandler(this, &Scoreboard::EliminarBebes_Tick);
			// 
			// Scoreboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 800);
			this->Name = L"Scoreboard";
			this->Text = L"Scoreboard";
			this->Load += gcnew System::EventHandler(this, &Scoreboard::Scoreboard_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Scoreboard::Scoreboard_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Scoreboard_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Left:
			if (modo == 'V')
			{
				alternarDificultad('L');
				arrDatos->clear();
				lecturaDatos();
			}
			break;
		case Keys::Right:
			if (modo == 'V')
			{
				alternarDificultad('R');
				arrDatos->clear();
				lecturaDatos();
			}
			break;
		case Keys::Up:
			if(modoEscritura == 'S') modoTecla = 'U';
			break;
		case Keys::Down:
			if(modoEscritura == 'S') modoTecla = 'D';
			break;
		case Keys::Enter:
			if(modoEscritura == 'S') modoTecla = 'E';
			break;

		default:
			break;
		}
	}
	private: System::Void TiempoRespuesta_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ gr = this->CreateGraphics();
		BufferedGraphicsContext^ bc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bg = bc->Allocate(gr, this->ClientRectangle);
		bg->Graphics->Clear(Color::Black);

		System::Drawing::Font^ Title = gcnew System::Drawing::Font("Imprint MT Shadow", 40);
		SolidBrush^ TitleColor = gcnew SolidBrush(Color::White);

		System::Drawing::Font^ MessageScreen = gcnew System::Drawing::Font("Imprint MT Shadow", 13);
		SolidBrush^ MessageScreenColor = gcnew SolidBrush(Color::White);

		System::Drawing::Font^ Body = gcnew System::Drawing::Font("Imprint MT Shadow", 20);
		SolidBrush^ BodyColor = gcnew SolidBrush(Color::White);

		switch (dificultad)
		{
		case 'F':
			break;
		case 'D':
			break;
		default:
			break;
		}


		switch (modo)
		{
		case 'V':
			if (dificultad == 'F') 	bg->Graphics->DrawString("Scoreboard FACIL", Title, TitleColor, 250, 50);
			if (dificultad == 'D') 	bg->Graphics->DrawString("Scoreboard DIFICIL", Title, TitleColor, 250, 50);
			break;
		case 'W':
			bg->Graphics->DrawString("YOU WIN", Title, TitleColor, 400, 50);
			if (modoEscritura == 'S')
			{
				bg->Graphics->DrawString("Felicidades ha conseguido tiempo record.\n" + "\tINSERTE SU NOMBRE\n" + "SU PARTIDA NO HA SIDO GUARDADA", MessageScreen, MessageScreenColor, 380, 120);
				modoEscritura = escrituraNombre();
			}
			if (modoEscritura == 'F')
			{
				escrituraDatos();
				modoEscritura = 'G';
				arrDatos->clear();
				lecturaDatos();
			}
			if (modoEscritura == 'G')
			{
				bg->Graphics->DrawString("Felicidades ha conseguido tiempo record." + "\n" + "SU PARTIDA YA HA SIDO GUARDADA", MessageScreen, MessageScreenColor, 380, 120);
			}
			break;
		case 'L':
			bg->Graphics->DrawString("YOU LOSE", Title, TitleColor, 400, 50);
			break;
		default:
			break;
		}
	
		switch (modo)
		{
		case 'V':
			for (int i = 0; i < arrDatos->size(); i++)
			{
				if (i + 1 <= 9)
				{
					bg->Graphics->DrawString(Convert::ToString(i + 1) + ".    " + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[0])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[1])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[2])) + "  " + Convert::ToString(arrDatos->at(i)->tiempoRealizado), Body, BodyColor, 300, 200 + i * 40);
				}
				if (i + 1 >= 10)
				{
					bg->Graphics->DrawString(Convert::ToString(i + 1) + ".  " + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[0])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[1])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[2])) + "  " + Convert::ToString(arrDatos->at(i)->tiempoRealizado), Body, BodyColor, 300, 200 + i * 40);
				}
			}
			break;
		case 'W':
			vectBebes->eliminar();
			vectBebes->mostrar(bg->Graphics, less30MBabyImg, more30MBabyImg);
			vectBebes->mover();
			for (int i = 0; i < arrDatos->size(); i++)
			{
				if (i + 1 <= 9)
				{
					bg->Graphics->DrawString(Convert::ToString(i + 1) + ".    " + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[0])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[1])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[2])) + "  " + Convert::ToString(arrDatos->at(i)->tiempoRealizado), Body, BodyColor, 450, 200 + i * 40);
				}
				if (i + 1 >= 10)
				{
					bg->Graphics->DrawString(Convert::ToString(i + 1) + ".  " + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[0])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[1])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[2])) + "  " + Convert::ToString(arrDatos->at(i)->tiempoRealizado), Body, BodyColor, 450, 200 + i * 40);
				}
			}
			break;
		case 'L':
			for (int i = 0; i < arrDatos->size(); i++)
			{
				if (i + 1 <= 9)
				{
					bg->Graphics->DrawString(Convert::ToString(i + 1) + ".    " + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[0])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[1])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[2])) + "  " + Convert::ToString(arrDatos->at(i)->tiempoRealizado), Body, BodyColor, 450, 200 + i * 40);
				}
				if (i + 1 >= 10)
				{
					bg->Graphics->DrawString(Convert::ToString(i + 1) + ".  " + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[0])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[1])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[2])) + "  " + Convert::ToString(arrDatos->at(i)->tiempoRealizado), Body, BodyColor, 450, 200 + i * 40);
				}
			}
			break;
		default:
			break;
		}
		
		bg->Render(gr);
		delete bc, bg, gr;
	}
	private: System::Void Scoreboard_Load(System::Object^ sender, System::EventArgs^ e) {
		if (modoEscritura == 'F')
		{
			escrituraDatos();
			modoEscritura = 'G';
		}
	}
	private: System::Void TiempoBebe_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (modo == 'W')
		{
			vectBebes->agregarMesVida();
			vectBebes->agregar();
		}
	}
private: System::Void EliminarBebes_Tick(System::Object^ sender, System::EventArgs^ e) {
}
};
}

