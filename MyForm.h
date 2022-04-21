#pragma once
//#include "Header1.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

namespace calculator {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		String^ windir;

	public:
		MyForm(void)
		{			
			
			windir = System::Environment::GetEnvironmentVariable("windir");

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}




	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::CheckBox^ checkBox1;




	protected:


	private:		
		
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::Button^ button1;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			button1->BackColor = System::Drawing::Color::Plum;
			button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			button1->Location = System::Drawing::Point(247, 403);
			button1->Name = L"button1";
			button1->Size = System::Drawing::Size(112, 36);
			button1->TabIndex = 3;
			button1->Text = L"HeapSort";
			button1->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Turquoise;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(378, 403);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 36);
			this->button2->TabIndex = 4;
			this->button2->Text = L"QuickSort";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(260, 268);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(221, 52);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Run Time";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cooper Black", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Navy;
			this->label2->Location = System::Drawing::Point(189, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(400, 82);
			this->label2->TabIndex = 6;
			this->label2->Text = L"LYeaRICS";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Location = System::Drawing::Point(235, 343);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(272, 24);
			this->listBox1->TabIndex = 7;
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::Color::Plum;
			this->trackBar1->LargeChange = 10;
			this->trackBar1->Location = System::Drawing::Point(124, 178);
			this->trackBar1->Maximum = 2015;
			this->trackBar1->Minimum = 1965;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->RightToLeftLayout = true;
			this->trackBar1->Size = System::Drawing::Size(498, 69);
			this->trackBar1->TabIndex = 10;
			this->trackBar1->Value = 1965;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(230, 146);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(297, 29);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Choose a range of years";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::Color::LavenderBlush;
			this->checkBox1->Location = System::Drawing::Point(269, 472);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(192, 24);
			this->checkBox1->TabIndex = 11;
			this->checkBox1->Text = L"Generate Wordcloud\?";
			this->checkBox1->UseVisualStyleBackColor = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(762, 545);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(button1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


		
		
		


	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {		
	
	try {
		System::String^ textFile = System::String::Concat(windir, (L"C:\\test.txt"));
		System::IO::StreamReader^ reader = gcnew  System::IO::StreamReader(textFile);

		int t = 4;
		label3->Text = System::Convert::ToString(t);
	}

	catch (Exception^ e) {
		if (dynamic_cast<FileNotFoundException^>(e))
			MessageBox::Show("File not found");
	}
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
}
};
}
