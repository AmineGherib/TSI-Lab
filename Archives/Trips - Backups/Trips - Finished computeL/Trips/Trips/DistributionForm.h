#pragma once
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <random>
#include <msclr\marshal_cppstd.h>
#include "AttractiveForm.h"

static std::vector<std::vector<double> > t;
static std::vector<std::vector<double> > H;
static std::vector<std::vector<double> > X;

static bool filledt = false, filledH = false, filledX = false;

namespace Trips {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DistributionForm
	/// </summary>
	public ref class DistributionForm : public System::Windows::Forms::Form
	{
	public:
		DistributionForm(void)
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
		~DistributionForm()
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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  filePathAttractiveness;
	private: System::Windows::Forms::TextBox^  filePathHourly;
	private: System::Windows::Forms::TextBox^  filePathInterzonal;
	private: System::Windows::Forms::Button^  findDirectory;
	private: System::Windows::Forms::Button^  findDirectoryHourly;
	private: System::Windows::Forms::Button^  findDirectoryAttractiveness;
	private: System::Windows::Forms::Button^  displayInterzonalMatrix;
	private: System::Windows::Forms::Button^  displayHourlyMatrix;
	private: System::Windows::Forms::Button^  displayAttractiveVariables;



	private: System::Windows::Forms::Button^  computeL;
	private: System::Windows::Forms::Button^  computeM;
	private: System::Windows::Forms::Button^  computeH;
	private: System::Windows::Forms::Button^  next;

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
		this->TabControl = (gcnew System::Windows::Forms::TabControl());
		this->light = (gcnew System::Windows::Forms::TabPage());
		this->lightDataGrid = (gcnew System::Windows::Forms::DataGridView());
		this->medium = (gcnew System::Windows::Forms::TabPage());
		this->mediumDataGrid = (gcnew System::Windows::Forms::DataGridView());
		this->heavy = (gcnew System::Windows::Forms::TabPage());
		this->heavyDataGrid = (gcnew System::Windows::Forms::DataGridView());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->filePathAttractiveness = (gcnew System::Windows::Forms::TextBox());
		this->filePathHourly = (gcnew System::Windows::Forms::TextBox());
		this->filePathInterzonal = (gcnew System::Windows::Forms::TextBox());
		this->findDirectory = (gcnew System::Windows::Forms::Button());
		this->findDirectoryHourly = (gcnew System::Windows::Forms::Button());
		this->findDirectoryAttractiveness = (gcnew System::Windows::Forms::Button());
		this->displayInterzonalMatrix = (gcnew System::Windows::Forms::Button());
		this->displayHourlyMatrix = (gcnew System::Windows::Forms::Button());
		this->displayAttractiveVariables = (gcnew System::Windows::Forms::Button());
		this->computeL = (gcnew System::Windows::Forms::Button());
		this->computeM = (gcnew System::Windows::Forms::Button());
		this->computeH = (gcnew System::Windows::Forms::Button());
		this->next = (gcnew System::Windows::Forms::Button());
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
		this->TabControl->Location = System::Drawing::Point(12, 113);
		this->TabControl->Name = L"TabControl";
		this->TabControl->SelectedIndex = 0;
		this->TabControl->Size = System::Drawing::Size(536, 378);
		this->TabControl->TabIndex = 4;
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
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(19, 23);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(139, 13);
		this->label1->TabIndex = 5;
		this->label1->Text = L"Interzonal travel times matrix";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(19, 48);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(124, 13);
		this->label2->TabIndex = 6;
		this->label2->Text = L"Hourly distribution of trips";
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Location = System::Drawing::Point(19, 75);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(175, 13);
		this->label3->TabIndex = 7;
		this->label3->Text = L"Destination Attractiveness variables";
		// 
		// filePathAttractiveness
		// 
		this->filePathAttractiveness->Location = System::Drawing::Point(200, 72);
		this->filePathAttractiveness->Name = L"filePathAttractiveness";
		this->filePathAttractiveness->Size = System::Drawing::Size(170, 20);
		this->filePathAttractiveness->TabIndex = 8;
		// 
		// filePathHourly
		// 
		this->filePathHourly->Location = System::Drawing::Point(200, 45);
		this->filePathHourly->Name = L"filePathHourly";
		this->filePathHourly->Size = System::Drawing::Size(170, 20);
		this->filePathHourly->TabIndex = 9;
		// 
		// filePathInterzonal
		// 
		this->filePathInterzonal->Location = System::Drawing::Point(200, 20);
		this->filePathInterzonal->Name = L"filePathInterzonal";
		this->filePathInterzonal->Size = System::Drawing::Size(170, 20);
		this->filePathInterzonal->TabIndex = 10;
		// 
		// findDirectory
		// 
		this->findDirectory->Location = System::Drawing::Point(385, 20);
		this->findDirectory->Name = L"findDirectory";
		this->findDirectory->Size = System::Drawing::Size(29, 19);
		this->findDirectory->TabIndex = 11;
		this->findDirectory->Text = L"...";
		this->findDirectory->UseVisualStyleBackColor = true;
		this->findDirectory->Click += gcnew System::EventHandler(this, &DistributionForm::findDirectory_Click);
		// 
		// findDirectoryHourly
		// 
		this->findDirectoryHourly->Location = System::Drawing::Point(385, 45);
		this->findDirectoryHourly->Name = L"findDirectoryHourly";
		this->findDirectoryHourly->Size = System::Drawing::Size(29, 19);
		this->findDirectoryHourly->TabIndex = 12;
		this->findDirectoryHourly->Text = L"...";
		this->findDirectoryHourly->UseVisualStyleBackColor = true;
		this->findDirectoryHourly->Click += gcnew System::EventHandler(this, &DistributionForm::findDirectoryHourly_Click);
		// 
		// findDirectoryAttractiveness
		// 
		this->findDirectoryAttractiveness->Location = System::Drawing::Point(385, 72);
		this->findDirectoryAttractiveness->Name = L"findDirectoryAttractiveness";
		this->findDirectoryAttractiveness->Size = System::Drawing::Size(29, 19);
		this->findDirectoryAttractiveness->TabIndex = 13;
		this->findDirectoryAttractiveness->Text = L"...";
		this->findDirectoryAttractiveness->UseVisualStyleBackColor = true;
		this->findDirectoryAttractiveness->Click += gcnew System::EventHandler(this, &DistributionForm::findDirectoryAttractiveness_Click);
		// 
		// displayInterzonalMatrix
		// 
		this->displayInterzonalMatrix->Location = System::Drawing::Point(420, 18);
		this->displayInterzonalMatrix->Name = L"displayInterzonalMatrix";
		this->displayInterzonalMatrix->Size = System::Drawing::Size(38, 23);
		this->displayInterzonalMatrix->TabIndex = 14;
		this->displayInterzonalMatrix->Text = L"view";
		this->displayInterzonalMatrix->UseVisualStyleBackColor = true;
		this->displayInterzonalMatrix->Click += gcnew System::EventHandler(this, &DistributionForm::displayInterzonalMatrix_Click);
		// 
		// displayHourlyMatrix
		// 
		this->displayHourlyMatrix->Location = System::Drawing::Point(420, 43);
		this->displayHourlyMatrix->Name = L"displayHourlyMatrix";
		this->displayHourlyMatrix->Size = System::Drawing::Size(38, 23);
		this->displayHourlyMatrix->TabIndex = 15;
		this->displayHourlyMatrix->Text = L"view";
		this->displayHourlyMatrix->UseVisualStyleBackColor = true;
		this->displayHourlyMatrix->Click += gcnew System::EventHandler(this, &DistributionForm::displayHourlyMatrix_Click);
		// 
		// displayAttractiveVariables
		// 
		this->displayAttractiveVariables->Location = System::Drawing::Point(420, 70);
		this->displayAttractiveVariables->Name = L"displayAttractiveVariables";
		this->displayAttractiveVariables->Size = System::Drawing::Size(38, 23);
		this->displayAttractiveVariables->TabIndex = 16;
		this->displayAttractiveVariables->Text = L"view";
		this->displayAttractiveVariables->UseVisualStyleBackColor = true;
		this->displayAttractiveVariables->Click += gcnew System::EventHandler(this, &DistributionForm::displayAttractiveVariables_Click);
		// 
		// computeL
		// 
		this->computeL->Location = System::Drawing::Point(473, 38);
		this->computeL->Name = L"computeL";
		this->computeL->Size = System::Drawing::Size(75, 23);
		this->computeL->TabIndex = 17;
		this->computeL->Text = L"Compute L";
		this->computeL->UseVisualStyleBackColor = true;
		this->computeL->Click += gcnew System::EventHandler(this, &DistributionForm::computeL_Click);
		// 
		// computeM
		// 
		this->computeM->Location = System::Drawing::Point(473, 63);
		this->computeM->Name = L"computeM";
		this->computeM->Size = System::Drawing::Size(75, 23);
		this->computeM->TabIndex = 18;
		this->computeM->Text = L"Compute M";
		this->computeM->UseVisualStyleBackColor = true;
		// 
		// computeH
		// 
		this->computeH->Location = System::Drawing::Point(473, 90);
		this->computeH->Name = L"computeH";
		this->computeH->Size = System::Drawing::Size(75, 23);
		this->computeH->TabIndex = 19;
		this->computeH->Text = L"Compute H";
		this->computeH->UseVisualStyleBackColor = true;
		// 
		// next
		// 
		this->next->Location = System::Drawing::Point(507, 9);
		this->next->Name = L"next";
		this->next->Size = System::Drawing::Size(41, 23);
		this->next->TabIndex = 20;
		this->next->Text = L"next";
		this->next->UseVisualStyleBackColor = true;
		this->next->Click += gcnew System::EventHandler(this, &DistributionForm::next_Click);
		// 
		// DistributionForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(560, 503);
		this->Controls->Add(this->next);
		this->Controls->Add(this->computeH);
		this->Controls->Add(this->computeM);
		this->Controls->Add(this->computeL);
		this->Controls->Add(this->displayAttractiveVariables);
		this->Controls->Add(this->displayHourlyMatrix);
		this->Controls->Add(this->displayInterzonalMatrix);
		this->Controls->Add(this->findDirectoryAttractiveness);
		this->Controls->Add(this->findDirectoryHourly);
		this->Controls->Add(this->findDirectory);
		this->Controls->Add(this->filePathInterzonal);
		this->Controls->Add(this->filePathHourly);
		this->Controls->Add(this->filePathAttractiveness);
		this->Controls->Add(this->label3);
		this->Controls->Add(this->label2);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->TabControl);
		this->Name = L"DistributionForm";
		this->Text = L"DistributionForm";
		this->TabControl->ResumeLayout(false);
		this->light->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lightDataGrid))->EndInit();
		this->medium->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mediumDataGrid))->EndInit();
		this->heavy->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->heavyDataGrid))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();

			}
#pragma endregion
		private: System::Void findDirectory_Click(System::Object^  sender, System::EventArgs^  e) {
				OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
				         openFileDialog1->ShowDialog();
				 this->filePathInterzonal->Text = openFileDialog1->FileName;

				 std::string input =msclr::interop::marshal_as<std::string>(this->filePathInterzonal->Text);
				 std::ifstream iFile(input);
				 bool fail = false;

				 fillMatrix(&t, iFile, &fail);

				 filledt = true;

				 if(filledt && filledH && filledX)
					 fillGrids();
		}
private: System::Void next_Click(System::Object^  sender, System::EventArgs^  e) {
				 AttractiveForm^attForm = gcnew AttractiveForm();
	   			 attForm->ShowDialog();
			 }
private: System::Void findDirectoryHourly_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
				 openFileDialog1->ShowDialog();
				 this->filePathHourly->Text = openFileDialog1->FileName;

				 std::string input =msclr::interop::marshal_as<std::string>(this->filePathHourly->Text);
				 std::ifstream iFile(input);
				 bool fail = false;

				 fillMatrix(&H, iFile, &fail);  
				 filledH = true;
				 
				 if(filledt && filledH && filledX)
					 fillGrids();
			 }
private: System::Void findDirectoryAttractiveness_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
				 openFileDialog1->ShowDialog();
				 this->filePathAttractiveness->Text = openFileDialog1->FileName;

				 std::string input =msclr::interop::marshal_as<std::string>(this->filePathAttractiveness->Text);
				 std::ifstream iFile(input);
				 bool fail = false;

				 fillMatrix(&X, iFile, &fail);  
				 filledX = true;

				 if(filledt && filledH && filledX)
					 fillGrids();
			 }
void fillMatrix(std::vector<std::vector<double> >* data, std::ifstream& file, bool *fail) {
		
	if(!file.is_open()) {
		MessageBox::Show("Error! File is closed.","Error Message");
			*fail = true; return;
	}
		while(file) {
			std::string line;
			if(!getline(file, line)) break;
			std::istringstream ss(line);
			std::vector<double> row;
			
			while(ss) {
				std::string s;
				if(!getline(ss, s)) break;

				int length = s.size();
				char *array_s = new char[length];
				strcpy(array_s, s.c_str());

				char *tok; 
				tok = strtok(array_s," \t");
				while(tok != NULL) {
					const char* contok = tok;
					std::string svalue(contok);
					double value = std::stod(svalue);	
					row.push_back(value);
					tok = strtok(NULL, " \t");
				}
					data->push_back(row);
			}	
		}
	}
void fillGrids() {
			 DataSet^ firstDataSet = gcnew DataSet();
			 DataSet^ secondDataSet = gcnew DataSet();
			 DataSet^ thirdDataSet = gcnew DataSet();

			 size_t numAlpha = X[0].size();

			 firstDataSet->Tables->Add("Light Grid");
			 firstDataSet->Tables["Light Grid"]->Columns->Add("Variables");
			 firstDataSet->Tables["Light Grid"]->Columns->Add("Beta");

			 secondDataSet->Tables->Add("Medium Grid");
			 secondDataSet->Tables["Medium Grid"]->Columns->Add("Variables");
			 secondDataSet->Tables["Medium Grid"]->Columns->Add("Beta");

			 thirdDataSet->Tables->Add("Heavy Grid");
			 thirdDataSet->Tables["Heavy Grid"]->Columns->Add("Variables");
			 thirdDataSet->Tables["Heavy Grid"]->Columns->Add("Beta");

			 int cellValue=0;
			 for(size_t i = 0; i < numAlpha;i++) {
					cellValue++;
					firstDataSet->Tables["Light Grid"]->Columns->Add("Alpha"+cellValue);
					secondDataSet->Tables["Medium Grid"]->Columns->Add("Alpha"+cellValue);
					thirdDataSet->Tables["Heavy Grid"]->Columns->Add("Alpha"+cellValue);
				 }

			firstDataSet->Tables["Light Grid"]->Rows->Add("AM:");
			firstDataSet->Tables["Light Grid"]->Rows->Add("PM:");
			firstDataSet->Tables["Light Grid"]->Rows->Add("offpeak:");
			
			secondDataSet->Tables["Medium Grid"]->Rows->Add("AM:");
			secondDataSet->Tables["Medium Grid"]->Rows->Add("PM:");
			secondDataSet->Tables["Medium Grid"]->Rows->Add("offpeak:");
		
			thirdDataSet->Tables["Heavy Grid"]->Rows->Add("AM:");
			thirdDataSet->Tables["Heavy Grid"]->Rows->Add("PM:");
			thirdDataSet->Tables["Heavy Grid"]->Rows->Add("offpeak:");

			this->lightDataGrid->DataSource = firstDataSet->Tables[0]->DefaultView;
			this->mediumDataGrid->DataSource = secondDataSet->Tables[0]->DefaultView;
			this->heavyDataGrid->DataSource = thirdDataSet->Tables[0]->DefaultView;
			
			}
private: System::Void displayInterzonalMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void displayHourlyMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void displayAttractiveVariables_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void computeL_Click(System::Object^  sender, System::EventArgs^  e) {
			 std::vector<std::vector<double> > alphaMatrix;
			 std::vector<double> betaVector;
			 std::vector<double> alphaVector;

			 String^ System_String;
			 std::string value;
			 double dValue;

			 for(int j = 0; j < 3; j++) {
				 for(int i = 1 ; i < (this->lightDataGrid->ColumnCount); ++i) { 
					if(!(this->lightDataGrid->Rows[j]->Cells[i]->Value)) return;
					System_String = this->lightDataGrid->Rows[j]->Cells[i]->Value->ToString();
					value = msclr::interop::marshal_as<std::string>(System_String);
					dValue = std::stod(value);
					if(i==1)
						betaVector.push_back(dValue);
					else
						alphaVector.push_back(dValue);
				 }
			alphaMatrix.push_back(alphaVector);
			alphaVector.clear();
		}
}
};
}
