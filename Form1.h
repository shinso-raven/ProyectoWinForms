#pragma once
#include <ctime>
#include <cstdlib>


namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	/// 
	/// 
	public struct Point {
		float x;
		float y;
	};


	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			std::srand(std::time(0));

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Timer^ elTImer;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::ComponentModel::IContainer^ components;
	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->elTImer = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(-4, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1200, 680);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// elTImer
			// 
			this->elTImer->Enabled = true;
			this->elTImer->Interval = 500;
			this->elTImer->Tick += gcnew System::EventHandler(this, &Form1::elTImer_Tick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(995, 22);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(129, 22);
			this->textBox1->TabIndex = 1;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1262, 673);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		int sizeX = 1200, sizeY = 680;
		int contador = 0;

		

	private: Point calculateMidpoint(const Point& punto1, const Point& punto2) {
		return { (punto1.x + punto2.x) / 2, (punto1.y + punto2.y) / 2 };
	}


	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		// Definir los vértices del triángulo
		Point vertex1 = { 200.f, 400.f };
		Point vertex2 = { 400.f, 100.f };
		Point vertex3 = { 600.f, 400.f };
		Point exteriorPoint = { 400.f, 500.f };


		///COLORES
		System::Drawing::Graphics^ g = e->Graphics;

		System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Yellow, 2);

		DrawPoint(g, pen, vertex1.x, vertex1.y);
		pen = gcnew System::Drawing::Pen(System::Drawing::Color::Cyan, 2);

		DrawPoint(g, pen, vertex2.x, vertex2.y);
		pen = gcnew System::Drawing::Pen(System::Drawing::Color::Green, 2);
		DrawPoint(g, pen, vertex3.x, vertex3.y);
		pen = gcnew System::Drawing::Pen(System::Drawing::Color::Red, 2);
		DrawPoint(g, pen, exteriorPoint.x, exteriorPoint.y);
	
	}
	private: System::Void DrawPoint(System::Drawing::Graphics^ g, System::Drawing::Pen^ pen, int x, int y)
	{
		// Dibujar un círculo en la posición especificada
		g->DrawEllipse(pen, x, y, 5, 5);
	}

		   
		   // Dibujar puntos en posiciones específicas
	private: System::Void Form1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		
	}
	private: System::Void elTImer_Tick(System::Object^ sender, System::EventArgs^ e) {

		// Definir los vértices del triángulo
		Point vertex1 = { 200.f, 400.f };
		Point vertex2 = { 400.f, 100.f };
		Point vertex3 = { 600.f, 400.f };

		///COLORES
		System::Drawing::Graphics^ g;
		g = pictureBox1->CreateGraphics();

		System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Yellow, 2);


		// Punto exterior inicial
		CppCLRWinFormsProject::Point exteriorPoint = { 400.f, 500.f };

		// Bucle principal
		for (int i = 0; i < 1000; ++i) {
			contador++;

			this->textBox1->Text = contador.ToString();
			// Lanzar el dado y mover el punto exterior según el resultado
			int diceResult = std::rand() % 3 + 1;
			if (diceResult == 1) {
				exteriorPoint = calculateMidpoint(exteriorPoint, vertex1);
				pen = gcnew System::Drawing::Pen(System::Drawing::Color::Yellow, 2);
			}
			else if (diceResult == 2) {
				exteriorPoint = calculateMidpoint(exteriorPoint, vertex2);
				pen = gcnew System::Drawing::Pen(System::Drawing::Color::Cyan, 2);

			}
			else {
				exteriorPoint = calculateMidpoint(exteriorPoint, vertex3);
				pen = gcnew System::Drawing::Pen(System::Drawing::Color::Green, 2);

			}

			// Imprimir los resultados

			// Definir el color y el tamaño de los puntos


			DrawPoint(g, pen, exteriorPoint.x, exteriorPoint.y);
		}

		this->elTImer->Enabled = true;
	}
};


}
