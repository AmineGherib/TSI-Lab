#pragma once
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

namespace Trips {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AttractiveForm
	/// </summary>
	public ref class AttractiveForm : public System::Windows::Forms::Form
	{
	public:
		AttractiveForm(void)
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
		~AttractiveForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  TabControl;
	protected: 
	private: System::Windows::Forms::TabPage^  light;
	private: System::Windows::Forms::DataGridView^  lightDataGrid;
	private: System::Windows::Forms::TabPage^  medium;
	private: System::Windows::Forms::DataGridView^  mediumDataGrid;
	private: System::Windows::Forms::TabPage^  heavy;
	private: System::Windows::Forms::DataGridView^  heavyDataGrid;
	private: System::Windows::Forms::Button^  compute;




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
			this->TabControl = (gcnew System::Windows::Forms::TabControl());
			this->light = (gcnew System::Windows::Forms::TabPage());
			this->lightDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->medium = (gcnew System::Windows::Forms::TabPage());
			this->mediumDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->heavy = (gcnew System::Windows::Forms::TabPage());
			this->heavyDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->compute = (gcnew System::Windows::Forms::Button());
			this->TabControl->SuspendLayout();
			this->light->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lightDataGrid))->BeginInit();
			this->medium->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mediumDataGrid))->BeginInit();
			this->heavy->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->heavyDataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// TabControl
			// 
			this->TabControl->Controls->Add(this->light);
			this->TabControl->Controls->Add(this->medium);
			this->TabControl->Controls->Add(this->heavy);
			this->TabControl->Location = System::Drawing::Point(12, 45);
			this->TabControl->Name = L"TabControl";
			this->TabControl->SelectedIndex = 0;
			this->TabControl->Size = System::Drawing::Size(536, 378);
			this->TabControl->TabIndex = 10;
			// 
			// light
			// 
			this->light->Controls->Add(this->lightDataGrid);
			this->light->Location = System::Drawing::Point(4, 22);
			this->light->Name = L"light";
			this->light->Padding = System::Windows::Forms::Padding(3);
			this->light->Size = System::Drawing::Size(528, 352);
			this->light->TabIndex = 0;
			this->light->Text = L"Light";
			this->light->UseVisualStyleBackColor = true;
			// 
			// lightDataGrid
			// 
			this->lightDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->lightDataGrid->Location = System::Drawing::Point(6, 6);
			this->lightDataGrid->Name = L"lightDataGrid";
			this->lightDataGrid->Size = System::Drawing::Size(516, 340);
			this->lightDataGrid->TabIndex = 0;
			// 
			// medium
			// 
			this->medium->Controls->Add(this->mediumDataGrid);
			this->medium->Location = System::Drawing::Point(4, 22);
			this->medium->Name = L"medium";
			this->medium->Padding = System::Windows::Forms::Padding(3);
			this->medium->Size = System::Drawing::Size(528, 352);
			this->medium->TabIndex = 1;
			this->medium->Text = L"Medium";
			this->medium->UseVisualStyleBackColor = true;
			// 
			// mediumDataGrid
			// 
			this->mediumDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->mediumDataGrid->Location = System::Drawing::Point(6, 6);
			this->mediumDataGrid->Name = L"mediumDataGrid";
			this->mediumDataGrid->Size = System::Drawing::Size(516, 340);
			this->mediumDataGrid->TabIndex = 0;
			// 
			// heavy
			// 
			this->heavy->Controls->Add(this->heavyDataGrid);
			this->heavy->Location = System::Drawing::Point(4, 22);
			this->heavy->Name = L"heavy";
			this->heavy->Padding = System::Windows::Forms::Padding(3);
			this->heavy->Size = System::Drawing::Size(528, 352);
			this->heavy->TabIndex = 2;
			this->heavy->Text = L"Heavy";
			this->heavy->UseVisualStyleBackColor = true;
			// 
			// heavyDataGrid
			// 
			this->heavyDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->heavyDataGrid->Location = System::Drawing::Point(6, 6);
			this->heavyDataGrid->Name = L"heavyDataGrid";
			this->heavyDataGrid->Size = System::Drawing::Size(516, 340);
			this->heavyDataGrid->TabIndex = 0;
			// 
			// compute
			// 
			this->compute->Location = System::Drawing::Point(252, 16);
			this->compute->Name = L"compute";
			this->compute->Size = System::Drawing::Size(75, 23);
			this->compute->TabIndex = 9;
			this->compute->Text = L"Compute";
			this->compute->UseVisualStyleBackColor = true;
			this->compute->Click += gcnew System::EventHandler(this, &AttractiveForm::compute_Click);
			// 
			// AttractiveForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(560, 435);
			this->Controls->Add(this->TabControl);
			this->Controls->Add(this->compute);
			this->Name = L"AttractiveForm";
			this->Text = L"Attractiveness Variables";
			this->TabControl->ResumeLayout(false);
			this->light->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lightDataGrid))->EndInit();
			this->medium->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mediumDataGrid))->EndInit();
			this->heavy->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->heavyDataGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void compute_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
