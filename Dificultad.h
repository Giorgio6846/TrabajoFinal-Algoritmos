#pragma once
#include "Juego.h"

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

	/// <summary>
	/// Resumen de Dificultad
	/// </summary>
	public ref class Dificultad : public System::Windows::Forms::Form
	{
	public:
		Dificultad(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		void writeDificultad(char dificultad)
		{
			ofstream textDificultad;
			textDificultad.open("Recursos/Texto\\Difficultad.lvdf", ios::out);
			if (textDificultad.is_open())
			{
				textDificultad << dificultad;
				textDificultad.close();
			}
		}

		char getDificultad() { return this->dificultad; }

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Dificultad()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonD;
	private: System::Windows::Forms::Button^ buttonF;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		char dificultad;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonD = (gcnew System::Windows::Forms::Button());
			this->buttonF = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonD
			// 
			this->buttonD->BackColor = System::Drawing::SystemColors::Control;
			this->buttonD->FlatAppearance->BorderSize = 0;
			this->buttonD->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonD->ForeColor = System::Drawing::SystemColors::Desktop;
			this->buttonD->Location = System::Drawing::Point(117, 190);
			this->buttonD->Margin = System::Windows::Forms::Padding(0);
			this->buttonD->Name = L"buttonD";
			this->buttonD->Size = System::Drawing::Size(175, 70);
			this->buttonD->TabIndex = 2;
			this->buttonD->Text = L"DIFÍCIL";
			this->buttonD->UseVisualStyleBackColor = false;
			this->buttonD->Click += gcnew System::EventHandler(this, &Dificultad::buttonD_Click);
			// 
			// buttonF
			// 
			this->buttonF->BackColor = System::Drawing::SystemColors::Control;
			this->buttonF->FlatAppearance->BorderSize = 0;
			this->buttonF->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonF->ForeColor = System::Drawing::SystemColors::Desktop;
			this->buttonF->Location = System::Drawing::Point(117, 92);
			this->buttonF->Margin = System::Windows::Forms::Padding(0);
			this->buttonF->Name = L"buttonF";
			this->buttonF->Size = System::Drawing::Size(175, 70);
			this->buttonF->TabIndex = 1;
			this->buttonF->Text = L"FÁCIL";
			this->buttonF->UseVisualStyleBackColor = false;
			this->buttonF->Click += gcnew System::EventHandler(this, &Dificultad::buttonF_Click);
			// 
			// Dificultad
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(410, 380);
			this->Controls->Add(this->buttonF);
			this->Controls->Add(this->buttonD);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Dificultad";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dificultad";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Dificultad::Dificultad_FormClosing);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonD_Click(System::Object^ sender, System::EventArgs^ e) {
		dificultad = 'D';
		writeDificultad(dificultad);
	}
	private: System::Void buttonF_Click(System::Object^ sender, System::EventArgs^ e) {
		dificultad = 'F';
		writeDificultad(dificultad);
	}
	private: System::Void Dificultad_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		ifstream textDificultad;
		textDificultad.open("Recursos/Texto\\Difficultad.lvdf", ios::in);
		if (textDificultad.is_open())
		{
			if (textDificultad.get() == dificultad)
			{
				textDificultad.close();
				e->Cancel = false;
			}
			else
			{
				e->Cancel = true;
			}
		}
	}
};
}
