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
#include <stdlib.h>

namespace MyPractica {

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
	private: System::Windows::Forms::ToolStripMenuItem^ семестрToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ excelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^ лабиринтToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ рекурсияИГрафикToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ сортировкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ шифрованиеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ классыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходИзToolStripMenuItem;
	private: System::Windows::Forms::Panel^ p_Title;
	private: System::Windows::Forms::Panel^ p_Output;
	private: System::Windows::Forms::TextBox^ tb_Title;
	private: System::Windows::Forms::ListBox^ lb_Output;





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
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->семестрToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->excelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->лабиринтToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->рекурсияИГрафикToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сортировкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->шифрованиеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->классыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходИзToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->семестрToolStripMenuItem,
					this->лабиринтToolStripMenuItem, this->рекурсияИГрафикToolStripMenuItem, this->сортировкаToolStripMenuItem, this->шифрованиеToolStripMenuItem,
					this->классыToolStripMenuItem, this->выходИзToolStripMenuItem
			});
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(1319, 28);
			this->menu->TabIndex = 1;
			this->menu->Text = L"menu";
			// 
			// семестрToolStripMenuItem
			// 
			this->семестрToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->excelToolStripMenuItem,
					this->toolStripMenuItem2, this->toolStripMenuItem3, this->toolStripMenuItem4, this->toolStripMenuItem5
			});
			this->семестрToolStripMenuItem->Name = L"семестрToolStripMenuItem";
			this->семестрToolStripMenuItem->Size = System::Drawing::Size(91, 24);
			this->семестрToolStripMenuItem->Text = L"1 семестр";
			this->семестрToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::семестрToolStripMenuItem_Click);
			// 
			// excelToolStripMenuItem
			// 
			this->excelToolStripMenuItem->Name = L"excelToolStripMenuItem";
			this->excelToolStripMenuItem->Size = System::Drawing::Size(278, 26);
			this->excelToolStripMenuItem->Text = L"Сведения о программисте";
			this->excelToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::excelToolStripMenuItem_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(278, 26);
			this->toolStripMenuItem2->Text = L"1(excel)";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem2_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(278, 26);
			this->toolStripMenuItem3->Text = L"2.1";
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(278, 26);
			this->toolStripMenuItem4->Text = L"3.2";
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->Size = System::Drawing::Size(278, 26);
			this->toolStripMenuItem5->Text = L"4";
			// 
			// лабиринтToolStripMenuItem
			// 
			this->лабиринтToolStripMenuItem->Name = L"лабиринтToolStripMenuItem";
			this->лабиринтToolStripMenuItem->Size = System::Drawing::Size(92, 24);
			this->лабиринтToolStripMenuItem->Text = L"Лабиринт";
			// 
			// рекурсияИГрафикToolStripMenuItem
			// 
			this->рекурсияИГрафикToolStripMenuItem->Name = L"рекурсияИГрафикToolStripMenuItem";
			this->рекурсияИГрафикToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->рекурсияИГрафикToolStripMenuItem->Text = L"Рекурсия и график";
			this->рекурсияИГрафикToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::рекурсияИГрафикToolStripMenuItem_Click);
			// 
			// сортировкаToolStripMenuItem
			// 
			this->сортировкаToolStripMenuItem->Name = L"сортировкаToolStripMenuItem";
			this->сортировкаToolStripMenuItem->Size = System::Drawing::Size(106, 24);
			this->сортировкаToolStripMenuItem->Text = L"Сортировка";
			// 
			// шифрованиеToolStripMenuItem
			// 
			this->шифрованиеToolStripMenuItem->Name = L"шифрованиеToolStripMenuItem";
			this->шифрованиеToolStripMenuItem->Size = System::Drawing::Size(116, 24);
			this->шифрованиеToolStripMenuItem->Text = L"Шифрование";
			// 
			// классыToolStripMenuItem
			// 
			this->классыToolStripMenuItem->Name = L"классыToolStripMenuItem";
			this->классыToolStripMenuItem->Size = System::Drawing::Size(73, 24);
			this->классыToolStripMenuItem->Text = L"Классы";
			// 
			// выходИзToolStripMenuItem
			// 
			this->выходИзToolStripMenuItem->Name = L"выходИзToolStripMenuItem";
			this->выходИзToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::X));
			this->выходИзToolStripMenuItem->Size = System::Drawing::Size(163, 24);
			this->выходИзToolStripMenuItem->Text = L"Выход из MyPractica";
			this->выходИзToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выходИзToolStripMenuItem_Click);
			// 
			// p_Title
			// 
			this->p_Title->Controls->Add(this->tb_Title);
			this->p_Title->Dock = System::Windows::Forms::DockStyle::Top;
			this->p_Title->Location = System::Drawing::Point(0, 28);
			this->p_Title->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->p_Title->Name = L"p_Title";
			this->p_Title->Size = System::Drawing::Size(1319, 98);
			this->p_Title->TabIndex = 2;
			// 
			// tb_Title
			// 
			this->tb_Title->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->tb_Title->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tb_Title->Enabled = false;
			this->tb_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_Title->Location = System::Drawing::Point(0, 0);
			this->tb_Title->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tb_Title->Multiline = true;
			this->tb_Title->Name = L"tb_Title";
			this->tb_Title->Size = System::Drawing::Size(1319, 98);
			this->tb_Title->TabIndex = 4;
			this->tb_Title->Text = L"Здесь пишем задание или описание задачи";
			this->tb_Title->TextChanged += gcnew System::EventHandler(this, &MyForm::tb_Title_TextChanged);
			// 
			// p_Output
			// 
			this->p_Output->Controls->Add(this->lb_Output);
			this->p_Output->Dock = System::Windows::Forms::DockStyle::Left;
			this->p_Output->Location = System::Drawing::Point(0, 126);
			this->p_Output->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->p_Output->Name = L"p_Output";
			this->p_Output->Size = System::Drawing::Size(355, 667);
			this->p_Output->TabIndex = 3;
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
			this->lb_Output->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->lb_Output->Name = L"lb_Output";
			this->lb_Output->Size = System::Drawing::Size(355, 667);
			this->lb_Output->TabIndex = 7;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1319, 793);
			this->Controls->Add(this->p_Output);
			this->Controls->Add(this->p_Title);
			this->Controls->Add(this->menu);
			this->MainMenuStrip = this->menu;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"Моя программа выполнена на практике";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Activated += gcnew System::EventHandler(this, &MyForm::MyForm_Activated);
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
	private: System::Void MyForm_Activated(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		ClearForNewTask();
	}
	private: System::Void excelToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		tb_Title->Text = " Программу создал хороший человек, Борлаков Амин, студент группы 1бИТС2.";
	}
private: System::Void выходИзToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	exit(0);
}
	private: System::Void toolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
private: System::Void tb_Title_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
	   public: void ClearForNewTask()
	   {
		   tb_Title->Text = "Выберите пункт меню для решения задачи";
		   lb_Output->Items->Clear();
	   }

private: System::Void семестрToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			
}
private: System::Void рекурсияИГрафикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	ClearForNewTask();
	Recursion();
	onaction = act_RECURSION;
	Refresh();
}
};
}
