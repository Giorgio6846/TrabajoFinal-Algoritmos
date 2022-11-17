#pragma once

#include <fstream>
#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

/*
Modo:
V = Es para ver el scoreboard del juego, este permite ver de las dos dificultades
W = Muestra el scoreboard de la dificultad selecionada y te permite poner tu nombre
L = Muestra el scoreboard de la dificultad selecionada
*/

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
			tiempo = 0;
			dificultad = 'F';
			modo = 'A';
			modoEscritura = 0;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void setModo(char modo) { this->modo = modo; }
		void setPuntaje(int tiempo, char dificultad)
		{
			this->tiempo = tiempo;
			this->dificultad = dificultad;
		}

		void lecturaPuntajes(Graphics^ gr)
		{
			ifstream lecturaScoreboard;

			int posJugador;
			char nombreJugador[3];
			int tiempoJugador;

			System::Drawing::Font^ MessageScreen = gcnew System::Drawing::Font("Arial Black", 13);
			SolidBrush^ MessageScreenColor = gcnew SolidBrush(Color::White);

			System::Drawing::Font^ Body = gcnew System::Drawing::Font("Arial Black", 13);
			SolidBrush^ BodyColor = gcnew SolidBrush(Color::White);

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
				for (int i = 0; lecturaScoreboard.eof() == 0; i++)
				{
					lecturaScoreboard >> posJugador >> nombreJugador >> tiempoJugador;
					if (tiempo << tiempoJugador && (modo == 'W'))
					{
						gr->DrawString("Felicidades ha conseguido llegar a la lista de puntajes", MessageScreen, MessageScreenColor, 200, 200);
						escritaPuntajeNuevo(i);
					}
					if (posJugador <= 9)
					{
						gr->DrawString(Convert::ToString(posJugador) + "   " + Convert::ToString(Convert::ToChar(nombreJugador[0])) + Convert::ToString(Convert::ToChar(nombreJugador[0])) + Convert::ToString(Convert::ToChar(nombreJugador[0])) + "  " + Convert::ToString(tiempoJugador), Body, BodyColor, 200, 200 + i * 30);
					}
					if (posJugador >= 10)
					{
						gr->DrawString(Convert::ToString(posJugador) + "  " + Convert::ToString(Convert::ToChar(nombreJugador[0])) + Convert::ToString(Convert::ToChar(nombreJugador[0])) + Convert::ToString(Convert::ToChar(nombreJugador[0])) + "  " + Convert::ToString(tiempoJugador), Body, BodyColor, 200, 200 + i * 30);
					}

				}
			}
			lecturaScoreboard.close();
		}

		bool escritaPuntajeNuevo(int pos)
		{
			/*
			ofstream escrituraScoreboard;
			ifstream lecturaScoreboard;
			
			switch (dificultad)
			{
			case 'F':
				escrituraScoreboard.open("ScoreboardF.lvdf", ios::out);
				
				break;
			case 'M':
				escrituraScoreboard.open("ScoreboardM.lvdf", ios::out);
				
				break;
			case 'D':
				escrituraScoreboard.open("ScoreboardD.lvdf", ios::out);
			
				break;
			default:
				break;
			}
			*/
			return 0;
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
		int tiempo;
		char dificultad;
		bool puntajeEscrito;
		bool modoEscritura;

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
			this->TiempoRespuesta->Interval = 500;
			this->TiempoRespuesta->Tick += gcnew System::EventHandler(this, &Scoreboard::TiempoRespuesta_Tick);
			// 
			// Scoreboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 800);
			this->Name = L"Scoreboard";
			this->Text = L"Scoreboard";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Scoreboard::Scoreboard_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void TiempoRespuesta_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ gr = this->CreateGraphics();
		BufferedGraphicsContext^ bc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bg = bc->Allocate(gr, this->ClientRectangle);
		bg->Graphics->Clear(Color::Black);

		System::Drawing::Font^ Title = gcnew System::Drawing::Font("Arial Black", 13);
		SolidBrush^ TitleColor = gcnew SolidBrush(Color::White);

		
		switch (modo)
		{
		case 'V':
			bg->Graphics->DrawString("Scoreboard", Title, TitleColor, 100, 100);

			break;
		case 'W':
			bg->Graphics->DrawString("YOU WIN", Title, TitleColor, 100, 100);

			break;
		case 'L':
			bg->Graphics->DrawString("YOU LOSE", Title, TitleColor, 100, 100);

			break;
		default:
			break;
		}
		lecturaPuntajes(bg->Graphics);

		bg->Render(gr);
		delete gr, bg, bc;
	}

	private: System::Void Scoreboard_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Up:
			if (modoEscritura)
			{

			}
			break;
		case Keys::Down:
			if (modoEscritura)
			{

			}
			break;
		case Keys::Left:
			if (modo == 'V')
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
			break;
		case Keys::Right:
			if (modo == 'V')
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
				}
			}
			break;
		case Keys::Enter:
			if (modoEscritura)
			{

			}
			break;

		default:
			break;
		}
	}
	};
}
