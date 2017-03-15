#pragma once
#include <iostream>
#include "OptTask.h"
#include "FishPopulation.h"
namespace FishSchoolSearchApp {

	using namespace System;
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
	public:
		MyForm(void)
		{
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
	private: System::Windows::Forms::Label^  _dimensionLabel;
	protected:
	private: System::Windows::Forms::NumericUpDown^  _dimension;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  _aimFunction;
	private: System::Windows::Forms::Button^  _oneIterationButton;
	private: System::Windows::Forms::Button^  _hundrIterationsButton;
	private: System::Windows::Forms::Button^  _startButton;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RichTextBox^  _resultTextBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  _populSize;
	private: System::Windows::Forms::NumericUpDown^  _iterationCount;
	private: System::Windows::Forms::Label^  label4;

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
			this->_dimensionLabel = (gcnew System::Windows::Forms::Label());
			this->_dimension = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->_aimFunction = (gcnew System::Windows::Forms::ComboBox());
			this->_oneIterationButton = (gcnew System::Windows::Forms::Button());
			this->_hundrIterationsButton = (gcnew System::Windows::Forms::Button());
			this->_startButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->_resultTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->_populSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->_iterationCount = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_dimension))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_populSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_iterationCount))->BeginInit();
			this->SuspendLayout();
			// 
			// _dimensionLabel
			// 
			this->_dimensionLabel->AutoSize = true;
			this->_dimensionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->_dimensionLabel->Location = System::Drawing::Point(12, 61);
			this->_dimensionLabel->Name = L"_dimensionLabel";
			this->_dimensionLabel->Size = System::Drawing::Size(145, 17);
			this->_dimensionLabel->TabIndex = 0;
			this->_dimensionLabel->Text = L"Размерность задачи";
			// 
			// _dimension
			// 
			this->_dimension->Location = System::Drawing::Point(163, 61);
			this->_dimension->Name = L"_dimension";
			this->_dimension->Size = System::Drawing::Size(65, 20);
			this->_dimension->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->label1->Location = System::Drawing::Point(15, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Целевая функция";
			// 
			// _aimFunction
			// 
			this->_aimFunction->FormattingEnabled = true;
			this->_aimFunction->Location = System::Drawing::Point(162, 19);
			this->_aimFunction->Name = L"_aimFunction";
			this->_aimFunction->Size = System::Drawing::Size(121, 21);
			this->_aimFunction->TabIndex = 3;
			// 
			// _oneIterationButton
			// 
			this->_oneIterationButton->Location = System::Drawing::Point(18, 352);
			this->_oneIterationButton->Name = L"_oneIterationButton";
			this->_oneIterationButton->Size = System::Drawing::Size(124, 23);
			this->_oneIterationButton->TabIndex = 4;
			this->_oneIterationButton->Text = L"Одна итерация";
			this->_oneIterationButton->UseVisualStyleBackColor = true;
			// 
			// _hundrIterationsButton
			// 
			this->_hundrIterationsButton->Location = System::Drawing::Point(18, 391);
			this->_hundrIterationsButton->Name = L"_hundrIterationsButton";
			this->_hundrIterationsButton->Size = System::Drawing::Size(124, 23);
			this->_hundrIterationsButton->TabIndex = 5;
			this->_hundrIterationsButton->Text = L"100 итераций";
			this->_hundrIterationsButton->UseVisualStyleBackColor = true;
			// 
			// _startButton
			// 
			this->_startButton->Location = System::Drawing::Point(18, 435);
			this->_startButton->Name = L"_startButton";
			this->_startButton->Size = System::Drawing::Size(124, 23);
			this->_startButton->TabIndex = 6;
			this->_startButton->Text = L"До останова";
			this->_startButton->UseVisualStyleBackColor = true;
			this->_startButton->Click += gcnew System::EventHandler(this, &MyForm::_startButton_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->_resultTextBox);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(393, 331);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(255, 141);
			this->panel1->TabIndex = 7;
			// 
			// _resultTextBox
			// 
			this->_resultTextBox->Location = System::Drawing::Point(7, 21);
			this->_resultTextBox->Name = L"_resultTextBox";
			this->_resultTextBox->ReadOnly = true;
			this->_resultTextBox->Size = System::Drawing::Size(245, 107);
			this->_resultTextBox->TabIndex = 1;
			this->_resultTextBox->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 4);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Результат";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->label3->Location = System::Drawing::Point(15, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(106, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Размер косяка";
			// 
			// _populSize
			// 
			this->_populSize->Location = System::Drawing::Point(163, 99);
			this->_populSize->Name = L"_populSize";
			this->_populSize->Size = System::Drawing::Size(65, 20);
			this->_populSize->TabIndex = 9;
			// 
			// _iterationCount
			// 
			this->_iterationCount->Location = System::Drawing::Point(163, 148);
			this->_iterationCount->Name = L"_iterationCount";
			this->_iterationCount->Size = System::Drawing::Size(65, 20);
			this->_iterationCount->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->label4->Location = System::Drawing::Point(15, 148);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(116, 17);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Число итераций";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 484);
			this->Controls->Add(this->_iterationCount);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->_populSize);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->_startButton);
			this->Controls->Add(this->_hundrIterationsButton);
			this->Controls->Add(this->_oneIterationButton);
			this->Controls->Add(this->_aimFunction);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->_dimension);
			this->Controls->Add(this->_dimensionLabel);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_dimension))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_populSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_iterationCount))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void _startButton_Click(System::Object^  sender, System::EventArgs^  e) {
		int dim = int(_dimension->Value);
		int populSize = int(_populSize->Value);
		int iterCount = int(_iterationCount->Value);
		OptTask& task = OptTask::getTask(dim, "DejongOptTask");
		FishPopulation population(task, populSize, 50, 10);
		for (int i = 0; i < iterCount; i++)
			population.swimmingIteration();
		double result = population.getRecord();
		std::cout << result << std::endl;
	}
};
}
