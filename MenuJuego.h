#pragma once
#include "Juego.h"
#include "Instrucciones.h"
#include "Creditos.h"
#include "Dificultad.h"
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
			dificultadJuego = 'F';

			game = gcnew Juego();
		}
		
		void iniciarJuego()
		{
			game->reiniciarJuego();
			game->setDificultad(dificultadJuego);
			game->Show();
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

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^ btn_SalirJuego;
	private: System::Windows::Forms::Button^ btn_CambiarDificultad;
	private: System::Windows::Forms::Button^ btn_MostrarInstrucciones;
	private: System::Windows::Forms::Button^ btn_MostrarCreditos;
	private: System::Windows::Forms::Button^ btn_InciarJuego;

		   Graphics^ gr;
		   char dificultadJuego;
		   Juego^ game;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuJuego::typeid));
			this->btn_SalirJuego = (gcnew System::Windows::Forms::Button());
			this->btn_CambiarDificultad = (gcnew System::Windows::Forms::Button());
			this->btn_MostrarInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btn_MostrarCreditos = (gcnew System::Windows::Forms::Button());
			this->btn_InciarJuego = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_SalirJuego
			// 
			this->btn_SalirJuego->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btn_SalirJuego->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_SalirJuego->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_SalirJuego->ForeColor = System::Drawing::SystemColors::Control;
			this->btn_SalirJuego->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->btn_SalirJuego->Location = System::Drawing::Point(463, 385);
			this->btn_SalirJuego->Margin = System::Windows::Forms::Padding(0);
			this->btn_SalirJuego->Name = L"btn_SalirJuego";
			this->btn_SalirJuego->Size = System::Drawing::Size(182, 43);
			this->btn_SalirJuego->TabIndex = 5;
			this->btn_SalirJuego->Text = L"SALIR";
			this->btn_SalirJuego->UseVisualStyleBackColor = false;
			this->btn_SalirJuego->Click += gcnew System::EventHandler(this, &MenuJuego::btn_SalirJuego_Click);
			// 
			// btn_CambiarDificultad
			// 
			this->btn_CambiarDificultad->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_CambiarDificultad->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_CambiarDificultad->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_CambiarDificultad->ForeColor = System::Drawing::SystemColors::Control;
			this->btn_CambiarDificultad->Location = System::Drawing::Point(463, 328);
			this->btn_CambiarDificultad->Margin = System::Windows::Forms::Padding(0);
			this->btn_CambiarDificultad->Name = L"btn_CambiarDificultad";
			this->btn_CambiarDificultad->Size = System::Drawing::Size(182, 43);
			this->btn_CambiarDificultad->TabIndex = 4;
			this->btn_CambiarDificultad->Text = L"DIFICULTAD";
			this->btn_CambiarDificultad->UseVisualStyleBackColor = false;
			this->btn_CambiarDificultad->Click += gcnew System::EventHandler(this, &MenuJuego::btn_CambiarDificultad_Click);
			// 
			// btn_MostrarInstrucciones
			// 
			this->btn_MostrarInstrucciones->BackColor = System::Drawing::Color::Red;
			this->btn_MostrarInstrucciones->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_MostrarInstrucciones->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_MostrarInstrucciones->ForeColor = System::Drawing::SystemColors::Control;
			this->btn_MostrarInstrucciones->Location = System::Drawing::Point(246, 328);
			this->btn_MostrarInstrucciones->Margin = System::Windows::Forms::Padding(0);
			this->btn_MostrarInstrucciones->Name = L"btn_MostrarInstrucciones";
			this->btn_MostrarInstrucciones->Size = System::Drawing::Size(182, 43);
			this->btn_MostrarInstrucciones->TabIndex = 2;
			this->btn_MostrarInstrucciones->Text = L"INSTRUCCIONES";
			this->btn_MostrarInstrucciones->UseVisualStyleBackColor = false;
			this->btn_MostrarInstrucciones->Click += gcnew System::EventHandler(this, &MenuJuego::btn_MostrarInstrucciones_Click);
			// 
			// btn_MostrarCreditos
			// 
			this->btn_MostrarCreditos->BackColor = System::Drawing::Color::Blue;
			this->btn_MostrarCreditos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_MostrarCreditos->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_MostrarCreditos->ForeColor = System::Drawing::SystemColors::Control;
			this->btn_MostrarCreditos->Location = System::Drawing::Point(246, 385);
			this->btn_MostrarCreditos->Margin = System::Windows::Forms::Padding(0);
			this->btn_MostrarCreditos->Name = L"btn_MostrarCreditos";
			this->btn_MostrarCreditos->Size = System::Drawing::Size(182, 43);
			this->btn_MostrarCreditos->TabIndex = 3;
			this->btn_MostrarCreditos->Text = L"CRÉDITOS";
			this->btn_MostrarCreditos->UseVisualStyleBackColor = false;
			this->btn_MostrarCreditos->Click += gcnew System::EventHandler(this, &MenuJuego::btn_MostrarCreditos_Click);
			// 
			// btn_InciarJuego
			// 
			this->btn_InciarJuego->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_InciarJuego->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_InciarJuego->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_InciarJuego->ForeColor = System::Drawing::SystemColors::Control;
			this->btn_InciarJuego->Location = System::Drawing::Point(246, 171);
			this->btn_InciarJuego->Margin = System::Windows::Forms::Padding(0);
			this->btn_InciarJuego->Name = L"btn_InciarJuego";
			this->btn_InciarJuego->Size = System::Drawing::Size(399, 139);
			this->btn_InciarJuego->TabIndex = 1;
			this->btn_InciarJuego->Text = L"JUGAR";
			this->btn_InciarJuego->UseVisualStyleBackColor = false;
			this->btn_InciarJuego->Click += gcnew System::EventHandler(this, &MenuJuego::btn_InciarJuego_Click);
			// 
			// MenuJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(900, 600);
			this->Controls->Add(this->btn_MostrarCreditos);
			this->Controls->Add(this->btn_MostrarInstrucciones);
			this->Controls->Add(this->btn_CambiarDificultad);
			this->Controls->Add(this->btn_SalirJuego);
			this->Controls->Add(this->btn_InciarJuego);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MenuJuego";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MenuJuego";
			this->Load += gcnew System::EventHandler(this, &MenuJuego::MenuJuego_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MenuJuego::MenuJuego_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MenuJuego::MenuJuego_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MenuJuego_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_InciarJuego_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		iniciarJuego();
	}
	private: System::Void MenuJuego_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Image^ Fondo = Image::FromFile("Recursos/Imagenes\\FondoMenu.png");
		gr->DrawImage(Fondo, 0, 0, 900, 600);
	}
	private: System::Void btn_SalirJuego_Click(System::Object^ sender, System::EventArgs^ e) {
		exit(0);
	}
private: System::Void btn_CambiarDificultad_Click(System::Object^ sender, System::EventArgs^ e) {
	Dificultad^ dificultad = gcnew Dificultad();
	dificultad->Show();
	dificultadJuego = dificultad->getDificultad();
}
private: System::Void btn_MostrarInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
	Intrucciones^ intrucciones = gcnew Intrucciones();
	intrucciones->Show();
}
private: System::Void btn_MostrarCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
	Creditos^ creditos = gcnew Creditos();
	creditos->Show();
}
private: System::Void MenuJuego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Space)
	{
		iniciarJuego();
	}
}
};
}
