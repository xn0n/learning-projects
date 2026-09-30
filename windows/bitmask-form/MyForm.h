#pragma once
#include <stdlib.h>
#include "Input.h"

namespace MyPractice {
	ref class Input;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ menu;
	private: System::Windows::Forms::ToolStripMenuItem^ маскаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ семестрToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ сведенияОПрограммистеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ лабораторнаяРабота1ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ лабораторнаяРабота2ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ лабораторнаяРабота3ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ лабораторнаяРабота4ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ лабиринтToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ рекурсияИГрафикToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ сортировкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ шифрованиеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ классыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходИзPracticeToolStripMenuItem;
	private: System::Windows::Forms::Panel^ p_Title;
	private: System::Windows::Forms::Panel^ p_Output;
	private: System::Windows::Forms::TextBox^ tb_Title;
	private: System::Windows::Forms::ListBox^ lb_Output;
















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
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->маскаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->семестрToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сведенияОПрограммистеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->лабораторнаяРабота1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->лабораторнаяРабота2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->лабораторнаяРабота3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->лабораторнаяРабота4ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->лабиринтToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->рекурсияИГрафикToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сортировкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->шифрованиеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->классыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходИзPracticeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->p_Title = (gcnew System::Windows::Forms::Panel());
			this->tb_Title = (gcnew System::Windows::Forms::TextBox());
			this->p_Output = (gcnew System::Windows::Forms::Panel());
			this->lb_Output = (gcnew System::Windows::Forms::ListBox());
			this->menu->SuspendLayout();
			this->p_Title->SuspendLayout();
			this->p_Output->SuspendLayout();
			this->SuspendLayout();
			// 
			// menu
			// 
			this->menu->Font = (gcnew System::Drawing::Font(L"Montserrat", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->маскаToolStripMenuItem,
					this->семестрToolStripMenuItem, this->лабиринтToolStripMenuItem, this->рекурсияИГрафикToolStripMenuItem, this->сортировкаToolStripMenuItem,
					this->шифрованиеToolStripMenuItem, this->классыToolStripMenuItem, this->выходИзPracticeToolStripMenuItem
			});
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->Padding = System::Windows::Forms::Padding(11, 2, 0, 2);
			this->menu->Size = System::Drawing::Size(1155, 32);
			this->menu->TabIndex = 3;
			this->menu->Text = L"menumain";
			this->menu->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::menu_ItemClicked);
			// 
			// маскаToolStripMenuItem
			// 
			this->маскаToolStripMenuItem->Name = L"маскаToolStripMenuItem";
			this->маскаToolStripMenuItem->Size = System::Drawing::Size(81, 28);
			this->маскаToolStripMenuItem->Text = L"Маска";
			// 
			// семестрToolStripMenuItem
			// 
			this->семестрToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->сведенияОПрограммистеToolStripMenuItem,
					this->лабораторнаяРабота1ToolStripMenuItem, this->лабораторнаяРабота2ToolStripMenuItem, this->лабораторнаяРабота3ToolStripMenuItem,
					this->лабораторнаяРабота4ToolStripMenuItem
			});
			this->семестрToolStripMenuItem->Name = L"семестрToolStripMenuItem";
			this->семестрToolStripMenuItem->Size = System::Drawing::Size(113, 28);
			this->семестрToolStripMenuItem->Text = L"1 семестр";
			// 
			// сведенияОПрограммистеToolStripMenuItem
			// 
			this->сведенияОПрограммистеToolStripMenuItem->Name = L"сведенияОПрограммистеToolStripMenuItem";
			this->сведенияОПрограммистеToolStripMenuItem->Size = System::Drawing::Size(343, 28);
			this->сведенияОПрограммистеToolStripMenuItem->Text = L"Сведения о программисте";
			// 
			// лабораторнаяРабота1ToolStripMenuItem
			// 
			this->лабораторнаяРабота1ToolStripMenuItem->Name = L"лабораторнаяРабота1ToolStripMenuItem";
			this->лабораторнаяРабота1ToolStripMenuItem->Size = System::Drawing::Size(343, 28);
			this->лабораторнаяРабота1ToolStripMenuItem->Text = L"Лабораторная работа №1";
			// 
			// лабораторнаяРабота2ToolStripMenuItem
			// 
			this->лабораторнаяРабота2ToolStripMenuItem->Name = L"лабораторнаяРабота2ToolStripMenuItem";
			this->лабораторнаяРабота2ToolStripMenuItem->Size = System::Drawing::Size(343, 28);
			this->лабораторнаяРабота2ToolStripMenuItem->Text = L"Лабораторная работа №2";
			// 
			// лабораторнаяРабота3ToolStripMenuItem
			// 
			this->лабораторнаяРабота3ToolStripMenuItem->Name = L"лабораторнаяРабота3ToolStripMenuItem";
			this->лабораторнаяРабота3ToolStripMenuItem->Size = System::Drawing::Size(343, 28);
			this->лабораторнаяРабота3ToolStripMenuItem->Text = L"Лабораторная работа №3";
			// 
			// лабораторнаяРабота4ToolStripMenuItem
			// 
			this->лабораторнаяРабота4ToolStripMenuItem->Name = L"лабораторнаяРабота4ToolStripMenuItem";
			this->лабораторнаяРабота4ToolStripMenuItem->Size = System::Drawing::Size(343, 28);
			this->лабораторнаяРабота4ToolStripMenuItem->Text = L"Лабораторная работа №4";
			// 
			// лабиринтToolStripMenuItem
			// 
			this->лабиринтToolStripMenuItem->Name = L"лабиринтToolStripMenuItem";
			this->лабиринтToolStripMenuItem->Size = System::Drawing::Size(116, 28);
			this->лабиринтToolStripMenuItem->Text = L"Лабиринт";
			// 
			// рекурсияИГрафикToolStripMenuItem
			// 
			this->рекурсияИГрафикToolStripMenuItem->Name = L"рекурсияИГрафикToolStripMenuItem";
			this->рекурсияИГрафикToolStripMenuItem->Size = System::Drawing::Size(202, 28);
			this->рекурсияИГрафикToolStripMenuItem->Text = L"Рекурсия и график";
			// 
			// сортировкаToolStripMenuItem
			// 
			this->сортировкаToolStripMenuItem->Name = L"сортировкаToolStripMenuItem";
			this->сортировкаToolStripMenuItem->Size = System::Drawing::Size(135, 28);
			this->сортировкаToolStripMenuItem->Text = L"Сортировка";
			// 
			// шифрованиеToolStripMenuItem
			// 
			this->шифрованиеToolStripMenuItem->Name = L"шифрованиеToolStripMenuItem";
			this->шифрованиеToolStripMenuItem->Size = System::Drawing::Size(148, 28);
			this->шифрованиеToolStripMenuItem->Text = L"Шифрование";
			// 
			// классыToolStripMenuItem
			// 
			this->классыToolStripMenuItem->Name = L"классыToolStripMenuItem";
			this->классыToolStripMenuItem->Size = System::Drawing::Size(92, 28);
			this->классыToolStripMenuItem->Text = L"Классы";
			// 
			// выходИзPracticeToolStripMenuItem
			// 
			this->выходИзPracticeToolStripMenuItem->Name = L"выходИзPracticeToolStripMenuItem";
			this->выходИзPracticeToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
			this->выходИзPracticeToolStripMenuItem->Size = System::Drawing::Size(188, 28);
			this->выходИзPracticeToolStripMenuItem->Text = L"Выход из Practice";
			this->выходИзPracticeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выходИзPracticeToolStripMenuItem_Click);
			// 
			// p_Title
			// 
			this->p_Title->Controls->Add(this->tb_Title);
			this->p_Title->Dock = System::Windows::Forms::DockStyle::Top;
			this->p_Title->Location = System::Drawing::Point(0, 32);
			this->p_Title->Margin = System::Windows::Forms::Padding(4);
			this->p_Title->Name = L"p_Title";
			this->p_Title->Size = System::Drawing::Size(1155, 125);
			this->p_Title->TabIndex = 4;
			this->p_Title->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// tb_Title
			// 
			this->tb_Title->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->tb_Title->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tb_Title->Enabled = false;
			this->tb_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_Title->Location = System::Drawing::Point(0, 0);
			this->tb_Title->Margin = System::Windows::Forms::Padding(4);
			this->tb_Title->Multiline = true;
			this->tb_Title->Name = L"tb_Title";
			this->tb_Title->Size = System::Drawing::Size(1155, 125);
			this->tb_Title->TabIndex = 0;
			this->tb_Title->Text = L"Здесь пишем задания или описание задачи";
			// 
			// p_Output
			// 
			this->p_Output->Controls->Add(this->lb_Output);
			this->p_Output->Dock = System::Windows::Forms::DockStyle::Left;
			this->p_Output->Location = System::Drawing::Point(0, 157);
			this->p_Output->Margin = System::Windows::Forms::Padding(4);
			this->p_Output->Name = L"p_Output";
			this->p_Output->Size = System::Drawing::Size(362, 589);
			this->p_Output->TabIndex = 5;
			this->p_Output->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::p_Output_Paint);
			// 
			// lb_Output
			// 
			this->lb_Output->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lb_Output->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lb_Output->FormattingEnabled = true;
			this->lb_Output->ItemHeight = 22;
			this->lb_Output->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->lb_Output->Location = System::Drawing::Point(0, 0);
			this->lb_Output->Margin = System::Windows::Forms::Padding(4);
			this->lb_Output->Name = L"lb_Output";
			this->lb_Output->Size = System::Drawing::Size(362, 589);
			this->lb_Output->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1155, 746);
			this->Controls->Add(this->p_Output);
			this->Controls->Add(this->p_Title);
			this->Controls->Add(this->menu);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Моя программа выполнена в период практики";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Activated += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			this->p_Title->ResumeLayout(false);
			this->p_Title->PerformLayout();
			this->p_Output->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		ClearForNewTask();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void выходИзPracticeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		exit(0);
	}
	private: System::Void menu_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void p_Output_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

	}
	public:
		void ClearForNewTask()
		{
			tb_Title->Text = "Выберите пункт меню для решения задачи.";
			tb_Title->Enabled = false;
			lb_Output->Items->Clear();
		}

	private: System::Void maskaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ClearForNewTask();
		tb_Title->Text = "Вывести числа удовлетворяющие маске. \r\nДаны 20 элементов. Ввести маску. Вывести результат.\n";
		System::Windows::Forms::DialogResult result;

		Input^ f_input = gcnew Input();
		result = f_input->ShowDialog();
		if (f_input->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ sRes = f_input->GetText();
			if (sRes == "") return;

			int nRes = Convert::ToInt32(sRes);
			int nNumber, nCount = 0;
			for (int i = 0; i < 20; i++) {
				nNumber = rand();
				if ((nNumber & nRes) == nRes) {
					lb_Output->Items->Add(nNumber);
					nCount++;
				}
			}
			tb_Title->AppendText("\r\n В список было добавлено " + Convert::ToString(nCount) + " чисел, удовлетворяющих условию (маске) ");

		}
		else {
			f_input->Close();
			return;
		}
	}
	};
}
