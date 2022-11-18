#pragma once

#include <fstream>
#include <conio.h>
#include <iostream>
#include <string>

#include <vector>

using namespace std;

/*
Modos:
V = Este modo funciona para visualizar los anteriores puntajes realizados
W = Este modo funciona para cuando el jugador ha ganado la partida este permite que se pueda escribir su nombre en la tabla de ganadores
L = Este modo funciona cuando el jugador ha perdido la partida

modoEscritura:
S = Este permite que el jugador escriba su nombre en la lista y ya se inserto su tiempo en la lista 
N = Este no permite al jugador escribir su nombre en la lista
F = El jugador ya escribio su nombre en la lista

modoTecla:
U = La tecla presionada ha sido la tecla direccional Arriba
D = La tecla presionada ha sido la tecla direccional Abajo
E = La tecla presionada ha sido la tecla Enter

*/

struct datosPuestos {
	char nombre[4];
	int tiempoRealizado;
}datosJugador, datos;

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
			arrDatos = new vector <datosPuestos*>;
			modo = 'A';
			modoEscritura = 'A';
			dificultad = 'F';
			modoTecla = 'A';
			posJugador = 0;
			posChar = 0;
			posLetra = 'A';

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//;
			lecturaDatos();
		}

		void setPuntaje(int tiempo, char dificultad)
		{
			this->dificultad = dificultad;
			datosJugador.tiempoRealizado = tiempo;
			verificacionJugadorGanador();
		}

		void setModo(char modo)
		{
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
					dificultad = 'M';
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
					dificultad = 'M';
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

			switch (dificultad)
			{
			case 'F':
				lecturaScoreboard.open("Recursos/Texto\\ScoreboardF.lvdf", ios::in | ios::binary);
				break;
			case 'M':
				lecturaScoreboard.open("Recursos/Texto\\ScoreboardM.lvdf", ios::in | ios::binary);
				break;
			case 'D':
				lecturaScoreboard.open("Recursos/Texto\\ScoreboardD.lvdf", ios::in | ios::binary);
				break;
			default:
				break;
			}

			if (lecturaScoreboard.is_open())
			{
				for (int i = 0; i < 15; i++)
				{
					lecturaScoreboard.seekg(0 * sizeof(datos), ios::beg);
					lecturaScoreboard.read((char*)&datos, sizeof(datosPuestos));
					arrDatos->push_back(&datos);
				}
				lecturaScoreboard.close();
			}
		}

		void verificacionJugadorGanador()
		{
			for (int i = 2; i < arrDatos->size(); i++)
			{
				if (datosJugador.tiempoRealizado < (arrDatos->at(i)->tiempoRealizado))
				{
					arrDatos->insert(arrDatos->begin() + i, &datosJugador);
					modoEscritura = 'S';
					posJugador = i;
				}
				else
				{
					modoEscritura = 'N';
				}
			}
		}

		void escrituraDatos()
		{
			ofstream escrituraScoreboard;

			switch (dificultad)
			{
			case 'F':
				escrituraScoreboard.open("Recursos/Texto\\ScoreboardF.lvdf", ios::out | ios::binary);
				break;
			case 'M':
				escrituraScoreboard.open("Recursos/Texto\\ScoreboardM.lvdf", ios::out | ios::binary);
				break;
			case 'D':
				escrituraScoreboard.open("Recursos/Texto\\ScoreboardD.lvdf", ios::out | ios::binary);
				break;
			default:
				break;
			}

			for (int i = 0; i < 15; i++)
			{
				escrituraScoreboard.write((const char*)&arrDatos->at(i), sizeof(datosPuestos));
			}
		}

		void escrituraNombre()
		{
			if (modoTecla == 'E') posChar = posChar + 1;
			else if (modoTecla == 'U') posLetra = char(int(posLetra) + 1);
			else if (modoTecla == 'D') posLetra = char(int(posLetra) - 1);

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
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Scoreboard()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		char modo;
		char modoEscritura;
		char modoTecla;
		char dificultad;
		int posJugador;
		int posChar;
		char posLetra;
		vector <datosPuestos*>* arrDatos;

	private: System::Windows::Forms::Timer^ TiempoRespuesta;
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
			this->SuspendLayout();
			// 
			// TiempoRespuesta
			// 
			this->TiempoRespuesta->Enabled = true;
			this->TiempoRespuesta->Tick += gcnew System::EventHandler(this, &Scoreboard::TiempoRespuesta_Tick);
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
			}
			break;
		case Keys::Right:
			if (modo == 'V')
			{
				alternarDificultad('R');
			}
			break;
		case Keys::Up:
			if(modo == 'S') modoTecla = 'U';
			break;
		case Keys::Down:
			if(modo == 'S') modoTecla = 'D';
			break;
		case Keys::Enter:
			if(modo == 'S') modoTecla = 'E';
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

		System::Drawing::Font^ Title = gcnew System::Drawing::Font("Small Fonts", 40);
		SolidBrush^ TitleColor = gcnew SolidBrush(Color::White);

		
		switch (modo)
		{
		case 'V':
			bg->Graphics->DrawString("Scoreboard", Title, TitleColor, 100, 100);
			break;
		case 'W':
			bg->Graphics->DrawString("YOU WIN", Title, TitleColor, 100, 100);
			if (modoEscritura == 'S')
			{
				("Felicidades ha conseguido tiempo record. INSERTE SU NOMBRE", Title, TitleColor, 100, 150);
				escrituraNombre();
			}
			if (posChar == 3) modoEscritura = 'F';
			break;
		case 'L':
			bg->Graphics->DrawString("YOU LOSE", Title, TitleColor, 100, 100);
			break;
		default:
			break;
		}
		
		System::Drawing::Font^ MessageScreen = gcnew System::Drawing::Font("Small Fonts", 13);
		SolidBrush^ MessageScreenColor = gcnew SolidBrush(Color::White);

		System::Drawing::Font^ Body = gcnew System::Drawing::Font("Small Fonts", 13);
		SolidBrush^ BodyColor = gcnew SolidBrush(Color::White);

		for (int i = 0; i < 15; i++)
		{
			if (i + 1 <= 9)
			{
				bg->Graphics->DrawString(Convert::ToString(i + 1) + "   " + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[0])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[1])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[2])) + "  " + Convert::ToString(arrDatos->at(i)->tiempoRealizado), Body, BodyColor, 200, 200 + i * 30);
			}
			if (i + 1 >= 10)
			{
				bg->Graphics->DrawString(Convert::ToString(i + 1) + "  " + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[0])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[1])) + Convert::ToString(Convert::ToChar(arrDatos->at(i)->nombre[2])) + "  " + Convert::ToString(arrDatos->at(i)->tiempoRealizado), Body, BodyColor, 200, 200 + i * 30);
			}
		}

		bg->Render(gr);
		delete bc, bg, gr;
	}
	private: System::Void Scoreboard_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}

