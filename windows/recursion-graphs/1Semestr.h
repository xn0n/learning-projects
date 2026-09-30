#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "MyFunction.h"
#include <locale.h>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <string>


namespace MyPractica {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyFormInput
	/// </summary>
	public ref class MyFormInput : public System::Windows::Forms::Form
	{
	public:
		MyFormInput(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyFormInput()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ l_Text;
	private: System::Windows::Forms::TextBox^ tb_Text;
	private: System::Windows::Forms::Button^ b_OK;
	private: System::Windows::Forms::Button^ b_Cancel;
	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->l_Text = (gcnew System::Windows::Forms::Label());
			this->tb_Text = (gcnew System::Windows::Forms::TextBox());
			this->b_OK = (gcnew System::Windows::Forms::Button());
			this->b_Cancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// l_Text
			// 
			this->l_Text->AutoSize = true;
			this->l_Text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->l_Text->Location = System::Drawing::Point(231, 9);
			this->l_Text->Name = L"l_Text";
			this->l_Text->Size = System::Drawing::Size(164, 22);
			this->l_Text->TabIndex = 0;
			this->l_Text->Text = L"Введите данные";
			// 
			// tb_Text
			// 
			this->tb_Text->Location = System::Drawing::Point(16, 49);
			this->tb_Text->Name = L"tb_Text";
			this->tb_Text->Size = System::Drawing::Size(562, 20);
			this->tb_Text->TabIndex = 1;
			// 
			// b_OK
			// 
			this->b_OK->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->b_OK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b_OK->Location = System::Drawing::Point(111, 186);
			this->b_OK->Name = L"b_OK";
			this->b_OK->Size = System::Drawing::Size(105, 31);
			this->b_OK->TabIndex = 2;
			this->b_OK->Text = L"Принять";
			this->b_OK->UseVisualStyleBackColor = true;
			// 
			// b_Cancel
			// 
			this->b_Cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->b_Cancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b_Cancel->Location = System::Drawing::Point(391, 186);
			this->b_Cancel->Name = L"b_Cancel";
			this->b_Cancel->Size = System::Drawing::Size(112, 31);
			this->b_Cancel->TabIndex = 3;
			this->b_Cancel->Text = L"Отменить";
			this->b_Cancel->UseVisualStyleBackColor = true;
			// 
			// MyFormInput
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(616, 235);
			this->Controls->Add(this->b_Cancel);
			this->Controls->Add(this->b_OK);
			this->Controls->Add(this->tb_Text);
			this->Controls->Add(this->l_Text);
			this->Name = L"MyFormInput";
			this->Text = L"1 семестр";
			this->Load += gcnew System::EventHandler(this, &MyFormInput::MyFormInput_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyFormInput_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
#pragma once

namespace MyForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyFormInput
	/// </summary>
	public ref class MyFormInput : public System::Windows::Forms::Form
	{
	public:
		MyFormInput(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyFormInput()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ввод данных";
			this->textBox1->Location = System::Drawing::Point(12, 30);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(436, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyFormInput::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyFormInput::textBox1_KeyPress);
			this->button1->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button1->Location = System::Drawing::Point(129, 93);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Принять";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyFormInput::button1_Click);
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button2->Location = System::Drawing::Point(265, 93);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(463, 130);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyFormInput";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"MyFormInput";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: String^ GetText() { return textBox1->Text; }
	public: void SetLable(String^ ptext) { this->label1->Text = ptext; }

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		switch (e->KeyChar) {
		case 13: {
			DialogResult = System::Windows::Forms::DialogResult::OK;
			Close();
		}break;
		}
	}
	};
}
