#pragma once

namespace AlgoritmodeJose {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Resumen de Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		public:

		ref struct Nodo
		{
			String^ info;
			Nodo^ link;
		};

		static Nodo^ PTR = nullptr;
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ListBox^  listBox1;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void mostrar(){
			listBox1->Items->Clear();
			Nodo^ P = gcnew Nodo();
			P=PTR;
			if(PTR == nullptr){
				return;
			}
			do{
				listBox1->Items->Add(P->info);
				P=P->link;
			}while(P != PTR);
		}
		void insertar(){
			Nodo^ p,^q = gcnew Nodo();
			p = PTR;
			q->info = textBox1->Text;
			q->link = PTR;
			if(PTR == nullptr){
				PTR = q;
				PTR->link = PTR;
			}else{
				while(p->link != PTR){
					p = p->link;
				}
				p->link = q;
			}
		}
		void jose(){
			try
			{
				int num, cop;
				//Regex^ regex = gcnew Regex(":d");
				if(Regex::IsMatch(textBox1->Text, "\\d")){
					num = Int32::Parse(textBox1->Text);
				}else
				{
					throw "excepcion del reglamento" ;
				}
				Nodo^ p = gcnew Nodo();
				Nodo^ antp = gcnew Nodo();
				p = PTR;
				while(p->link != p){
					cop = num-1;
					while(cop > 0){
						antp = p;
						p = p->link;
						cop--;
					}
					MessageBox::Show("Salio "+p->info);
					antp->link = p->link;
					p = antp->link;
				}
				PTR = p;
			}catch(char* ex){
				String^ str = gcnew String(ex);
				MessageBox::Show("Se produjo el error \n"+str);
			}
		}
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 60);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(18, 98);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(89, 29);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Ingresar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(18, 144);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(89, 29);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Do";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(125, 5);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(150, 251);
			this->listBox1->TabIndex = 3;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 insertar();
				 mostrar();
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 jose();
			 mostrar();
		 }
};
}

