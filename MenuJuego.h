#pragma once
#include "Juego.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuJuego
	/// </summary>
	public ref class MenuJuego : public System::Windows::Forms::Form
	{
	public:
		MenuJuego(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			gr = this->CreateGraphics();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuJuego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		Graphics^ gr;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(341, 509);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(222, 93);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Play";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuJuego::button1_Click);
			// 
			// MenuJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(900, 600);
			this->Controls->Add(this->button1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MenuJuego";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MenuJuego";
			this->Load += gcnew System::EventHandler(this, &MenuJuego::MenuJuego_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MenuJuego::MenuJuego_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MenuJuego_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Juego^ juego = gcnew Juego();
		juego->Show();
	}
	private: System::Void MenuJuego_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Image^ Fondo = Image::FromFile("Recursos/Imagenes\\FondoMenu.png");
		gr->DrawImage(Fondo, 0, 0, 900, 600);
	}
	};
}
