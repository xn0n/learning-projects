#pragma once

namespace MyPractice {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Input
	/// </summary>
	public ref class Input : public System::Windows::Forms::Form
	{
	public:
		Input(void)
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
		~Input()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ l_Info;
	protected:

	private: System::Windows::Forms::TextBox^ tb_Input;

	private: System::Windows::Forms::Button^ b_OK;
	private: System::Windows::Forms::Button^ b_Cancel;
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
			this->l_Info = (gcnew System::Windows::Forms::Label());
			this->tb_Input = (gcnew System::Windows::Forms::TextBox());
			this->b_OK = (gcnew System::Windows::Forms::Button());
			this->b_Cancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// l_Info
			// 
			this->l_Info->AutoSize = true;
			this->l_Info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->l_Info->Location = System::Drawing::Point(12, 9);
			this->l_Info->Name = L"l_Info";
			this->l_Info->Size = System::Drawing::Size(136, 18);
			this->l_Info->TabIndex = 0;
			this->l_Info->Text = L"Введите данные";
			this->l_Info->Click += gcnew System::EventHandler(this, &Input::label1_Click);
			// 
			// tb_Input
			// 
			this->tb_Input->Location = System::Drawing::Point(15, 30);
			this->tb_Input->Name = L"tb_Input";
			this->tb_Input->Size = System::Drawing::Size(570, 22);
			this->tb_Input->TabIndex = 1;
			// 
			// b_OK
			// 
			this->b_OK->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->b_OK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b_OK->Location = System::Drawing::Point(30, 103);
			this->b_OK->Name = L"b_OK";
			this->b_OK->Size = System::Drawing::Size(123, 33);
			this->b_OK->TabIndex = 2;
			this->b_OK->Text = L"Принять";
			this->b_OK->UseVisualStyleBackColor = true;
			// 
			// b_Cancel
			// 
			this->b_Cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->b_Cancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b_Cancel->Location = System::Drawing::Point(228, 103);
			this->b_Cancel->Name = L"b_Cancel";
			this->b_Cancel->Size = System::Drawing::Size(139, 33);
			this->b_Cancel->TabIndex = 3;
			this->b_Cancel->Text = L"Отклонить";
			this->b_Cancel->UseVisualStyleBackColor = true;
			this->b_Cancel->Click += gcnew System::EventHandler(this, &Input::b_Cancel_Click);
			// 
			// Input
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(597, 152);
			this->Controls->Add(this->b_Cancel);
			this->Controls->Add(this->b_OK);
			this->Controls->Add(this->tb_Input);
			this->Controls->Add(this->l_Info);
			this->Name = L"Input";
			this->Text = L"Ввод входных параметров";
			this->Load += gcnew System::EventHandler(this, &Input::Input_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void b_Cancel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Input_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	public:
		String^ GetText(){return tb_Input->Text;}
	};
}
