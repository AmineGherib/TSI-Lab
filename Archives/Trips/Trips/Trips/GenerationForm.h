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
#include "DistributionForm.h"
std::vector<std::vector<double> > matrix;

namespace Trips {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GenerationForm
	/// </summary>
	public ref class GenerationForm : public System::Windows::Forms::Form
	{
	public:
		GenerationForm(void)
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
		~GenerationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  filePath;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  findDirectory;









	private: System::Windows::Forms::Button^  next;
	private: System::Windows::Forms::Button^  computeLight;





	private: System::Windows::Forms::TabPage^  heavy;
	private: System::Windows::Forms::DataGridView^  heavyDataGrid;
	private: System::Windows::Forms::TabPage^  medium;
	private: System::Windows::Forms::DataGridView^  mediumDataGrid;
	private: System::Windows::Forms::TabPage^  light;
	private: System::Windows::Forms::DataGridView^  lightDataGrid;

	private: System::Windows::Forms::TabControl^  TabControl;
	private: System::Windows::Forms::Button^  loadHeavy;
	private: System::Windows::Forms::Button^  loadMedium;
	private: System::Windows::Forms::Button^  loadLight;
	private: System::Windows::Forms::Button^  computeMedium;
	private: System::Windows::Forms::Button^  computeHeavy;
	private: System::Windows::Forms::Button^  viewMatrix;


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
		this->filePath = (gcnew System::Windows::Forms::TextBox());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->findDirectory = (gcnew System::Windows::Forms::Button());
		this->next = (gcnew System::Windows::Forms::Button());
		this->computeLight = (gcnew System::Windows::Forms::Button());
		this->heavy = (gcnew System::Windows::Forms::TabPage());
		this->heavyDataGrid = (gcnew System::Windows::Forms::DataGridView());
		this->medium = (gcnew System::Windows::Forms::TabPage());
		this->mediumDataGrid = (gcnew System::Windows::Forms::DataGridView());
		this->light = (gcnew System::Windows::Forms::TabPage());
		this->lightDataGrid = (gcnew System::Windows::Forms::DataGridView());
		this->TabControl = (gcnew System::Windows::Forms::TabControl());
		this->loadHeavy = (gcnew System::Windows::Forms::Button());
		this->loadMedium = (gcnew System::Windows::Forms::Button());
		this->loadLight = (gcnew System::Windows::Forms::Button());
		this->computeMedium = (gcnew System::Windows::Forms::Button());
		this->computeHeavy = (gcnew System::Windows::Forms::Button());
		this->viewMatrix = (gcnew System::Windows::Forms::Button());
		this->heavy->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->heavyDataGrid))->BeginInit();
		this->medium->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mediumDataGrid))->BeginInit();
		this->light->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lightDataGrid))->BeginInit();
		this->TabControl->SuspendLayout();
		this->SuspendLayout();
		// 
		// filePath
		// 
		this->filePath->Location = System::Drawing::Point(126, 12);
		this->filePath->Name = L"filePath";
		this->filePath->Size = System::Drawing::Size(163, 20);
		this->filePath->TabIndex = 0;
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(13, 15);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(107, 13);
		this->label1->TabIndex = 1;
		this->label1->Text = L"Zoned variables Files";
		// 
		// findDirectory
		// 
		this->findDirectory->Location = System::Drawing::Point(295, 10);
		this->findDirectory->Name = L"findDirectory";
		this->findDirectory->Size = System::Drawing::Size(25, 23);
		this->findDirectory->TabIndex = 2;
		this->findDirectory->Text = L"...";
		this->findDirectory->UseVisualStyleBackColor = true;
		this->findDirectory->Click += gcnew System::EventHandler(this, &GenerationForm::findDirectory_Click);
		// 
		// next
		// 
		this->next->Location = System::Drawing::Point(469, 10);
		this->next->Name = L"next";
		this->next->Size = System::Drawing::Size(75, 23);
		this->next->TabIndex = 4;
		this->next->Text = L"Next";
		this->next->UseVisualStyleBackColor = true;
		this->next->Click += gcnew System::EventHandler(this, &GenerationForm::next_Click);
		// 
		// computeLight
		// 
		this->computeLight->Location = System::Drawing::Point(427, 38);
		this->computeLight->Name = L"computeLight";
		this->computeLight->Size = System::Drawing::Size(117, 23);
		this->computeLight->TabIndex = 5;
		this->computeLight->Text = L"Compute Light";
		this->computeLight->UseVisualStyleBackColor = true;
		this->computeLight->Click += gcnew System::EventHandler(this, &GenerationForm::computeLight_Click);
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
		// TabControl
		// 
		this->TabControl->Controls->Add(this->light);
		this->TabControl->Controls->Add(this->medium);
		this->TabControl->Controls->Add(this->heavy);
		this->TabControl->Location = System::Drawing::Point(12, 113);
		this->TabControl->Name = L"TabControl";
		this->TabControl->SelectedIndex = 0;
		this->TabControl->Size = System::Drawing::Size(536, 378);
		this->TabControl->TabIndex = 3;
		// 
		// loadHeavy
		// 
		this->loadHeavy->Location = System::Drawing::Point(263, 70);
		this->loadHeavy->Name = L"loadHeavy";
		this->loadHeavy->Size = System::Drawing::Size(83, 23);
		this->loadHeavy->TabIndex = 8;
		this->loadHeavy->Text = L"Load Heavy";
		this->loadHeavy->UseVisualStyleBackColor = true;
		this->loadHeavy->Click += gcnew System::EventHandler(this, &GenerationForm::loadHeavy_Click);
		// 
		// loadMedium
		// 
		this->loadMedium->Location = System::Drawing::Point(174, 70);
		this->loadMedium->Name = L"loadMedium";
		this->loadMedium->Size = System::Drawing::Size(83, 23);
		this->loadMedium->TabIndex = 7;
		this->loadMedium->Text = L"Load Medium";
		this->loadMedium->UseVisualStyleBackColor = true;
		this->loadMedium->Click += gcnew System::EventHandler(this, &GenerationForm::loadMedium_Click);
		// 
		// loadLight
		// 
		this->loadLight->Location = System::Drawing::Point(85, 70);
		this->loadLight->Name = L"loadLight";
		this->loadLight->Size = System::Drawing::Size(83, 23);
		this->loadLight->TabIndex = 6;
		this->loadLight->Text = L"Load Light";
		this->loadLight->UseVisualStyleBackColor = true;
		this->loadLight->Click += gcnew System::EventHandler(this, &GenerationForm::loadLight_Click);
		// 
		// computeMedium
		// 
		this->computeMedium->Location = System::Drawing::Point(427, 70);
		this->computeMedium->Name = L"computeMedium";
		this->computeMedium->Size = System::Drawing::Size(117, 23);
		this->computeMedium->TabIndex = 9;
		this->computeMedium->Text = L"Compute Medium";
		this->computeMedium->UseVisualStyleBackColor = true;
		this->computeMedium->Click += gcnew System::EventHandler(this, &GenerationForm::computeMedium_Click);
		// 
		// computeHeavy
		// 
		this->computeHeavy->Location = System::Drawing::Point(427, 99);
		this->computeHeavy->Name = L"computeHeavy";
		this->computeHeavy->Size = System::Drawing::Size(117, 23);
		this->computeHeavy->TabIndex = 10;
		this->computeHeavy->Text = L"Compute Heavy";
		this->computeHeavy->UseVisualStyleBackColor = true;
		this->computeHeavy->Click += gcnew System::EventHandler(this, &GenerationForm::computeHeavy_Click);
		// 
		// viewMatrix
		// 
		this->viewMatrix->Location = System::Drawing::Point(326, 10);
		this->viewMatrix->Name = L"viewMatrix";
		this->viewMatrix->Size = System::Drawing::Size(40, 23);
		this->viewMatrix->TabIndex = 11;
		this->viewMatrix->Text = L"View";
		this->viewMatrix->UseVisualStyleBackColor = true;
		// 
		// GenerationForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(560, 503);
		this->Controls->Add(this->viewMatrix);
		this->Controls->Add(this->computeHeavy);
		this->Controls->Add(this->computeMedium);
		this->Controls->Add(this->loadHeavy);
		this->Controls->Add(this->loadMedium);
		this->Controls->Add(this->loadLight);
		this->Controls->Add(this->computeLight);
		this->Controls->Add(this->next);
		this->Controls->Add(this->TabControl);
		this->Controls->Add(this->findDirectory);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->filePath);
		this->Name = L"GenerationForm";
		this->Text = L"Trip Generation";
		this->heavy->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->heavyDataGrid))->EndInit();
		this->medium->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mediumDataGrid))->EndInit();
		this->light->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lightDataGrid))->EndInit();
		this->TabControl->ResumeLayout(false);
		this->ResumeLayout(false);
		this->PerformLayout();

			}
#pragma endregion
	private: System::Void findDirectory_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
					 openFileDialog1->ShowDialog();
				 this->filePath->Text = openFileDialog1->FileName;

				std::string path =msclr::interop::marshal_as<std::string>(this->filePath->Text);
				if(path=="") return;
				
				std::ifstream file(path);

				bool fail = false;
				
				
				fillMatrix(&matrix, file, &fail);
				if(fail) return;
				fillGrids(matrix, path);
		}
	private: System::Void next_Click(System::Object^  sender, System::EventArgs^  e) {		
			DistributionForm^distForm = gcnew DistributionForm();
			distForm->ShowDialog();			
		}
	
	template <typename T>
	void fillGrids(std::vector<std::vector<T> > matrix, std::string path) {	 
			DataSet^ firstDataSet = gcnew DataSet();
			DataSet^ secondDataSet = gcnew DataSet();
			DataSet^ thirdDataSet = gcnew DataSet();
			
			std::string line, fstLine;
			std::ifstream iFile(path);
		
			if(iFile.good()) std::getline(iFile, fstLine);
			int numWords = word_count(fstLine);

			firstDataSet->Tables->Add("Light Grid");
			firstDataSet->Tables["Light Grid"]->Columns->Add("Variables");

			secondDataSet->Tables->Add("Medium Grid");
			secondDataSet->Tables["Medium Grid"]->Columns->Add("Variables");

			thirdDataSet->Tables->Add("Heavy Grid");
			thirdDataSet->Tables["Heavy Grid"]->Columns->Add("Variables");
			
			int cellValue=0;
			for(int i = 0; i < numWords+1; i++)  {
				if(i==0) 
					{
					firstDataSet->Tables["Light Grid"]->Columns->Add("ZoneID");
					secondDataSet->Tables["Medium Grid"]->Columns->Add("ZoneID");
					thirdDataSet->Tables["Heavy Grid"]->Columns->Add("ZoneID");
					}
				else if(i==1) 
					{
					firstDataSet->Tables["Light Grid"]->Columns->Add("TotJobs");
					secondDataSet->Tables["Medium Grid"]->Columns->Add("TotJobs");
					thirdDataSet->Tables["Heavy Grid"]->Columns->Add("TotJobs");
					}
				else if( (i+1) % 2 != 0 ){
					cellValue++;
					firstDataSet->Tables["Light Grid"]->Columns->Add("TypeA"+cellValue);
					secondDataSet->Tables["Medium Grid"]->Columns->Add("TypeA"+cellValue);
					thirdDataSet->Tables["Heavy Grid"]->Columns->Add("TypeA"+cellValue);
					}
				else {
					firstDataSet->Tables["Light Grid"]->Columns->Add("TypeB"+cellValue);
					secondDataSet->Tables["Medium Grid"]->Columns->Add("TypeB"+cellValue);
					thirdDataSet->Tables["Heavy Grid"]->Columns->Add("TypeB"+cellValue);
					
				}
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
			
			iFile.close();
		}

template <class T>
T vDotProduct(std::vector<T> v1, std::vector<T> v2) {
	if(v1.size() != v2.size()) {
		MessageBox::Show("Invalid dimensions for vector dot product.", "Notification");
		return 0;
	}	
	T dProd=0;

	for(size_t i=0; i < v1.size(); ++i) 
		dProd += v1[i] * v2[i];
	
	return dProd;
}

template <typename T>
std::vector<T> PEAK(std::vector<std::vector<T> > data, std::vector<T> peak) {
	std::vector<T> results;
	T value;
	
	for(size_t i=0; i < data.size(); ++i) {	
		value = vDotProduct(data[i], peak);
		results.push_back(value);
	}
	return results;
}
size_t word_count(std::string s) 
	{
	return s.empty() ? 0 : std::count_if(std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(isspace))), std::unique(s.begin(), s.end()), std::ptr_fun<int, int>(isspace))+isspace(*s.rbegin());
	}
template <typename T>
void filePrintMatrix(std::vector<std::vector<T> > M, std::string filename) {
	std::ofstream file(filename);
	
	/*
	file << std::setw(8) << "AM" << "\t";
	file << std::setw(8) << "PM" << "\t";
	file << std::setw(8) << "OFF" << "\t";
	file << std::endl;
	*/
	for(size_t i=0; i < M.size(); ++i) {
		for(size_t j=0; j < M[0].size(); ++j)
			file << std::setw(8) << M[i][j] << "\t";
		file << std::endl;
		}
	file.close();
}

template <typename T>
std::vector<std::vector<T> > transposeMatrix(std::vector<std::vector<T> > matrix) {
	int nRow = matrix[0].size(), nCol = matrix.size();

	std::vector<std::vector<T> > transpose(nRow, std::vector<T>(nCol));
	for(int i=0; i<nRow;++i) {
		for(int j=0; j<nCol;++j) {
			transpose[i][j] = matrix[j][i];
		}
	}
	return transpose;
}

private: System::Void computeHeavy_Click(System::Object^  sender, System::EventArgs^  e) {
			 std::vector<double> AM_PEAK;
			 std::vector<double> PM_PEAK;
			 std::vector<double> OFF_PEAK;
			
			 String^ System_String;
			 std::string value;
			 double dValue;
			 
			 for(int i = 1; i < (this->heavyDataGrid->ColumnCount); ++i) {
				 if(!(this->heavyDataGrid->Rows[0]->Cells[i]->Value)) return;
				 System_String = this->heavyDataGrid->Rows[0]->Cells[i]->Value->ToString();
				 value = msclr::interop::marshal_as<std::string>(System_String);
				 dValue = std::stod(value);
				 AM_PEAK.push_back(dValue);
				 }
			 for(int X = 1; X < (this->heavyDataGrid->ColumnCount); ++X) {
				 if(!(this->heavyDataGrid->Rows[1]->Cells[X]->Value)) return;
				 System_String = this->heavyDataGrid->Rows[1]->Cells[X]->Value->ToString();
				 value = msclr::interop::marshal_as<std::string>(System_String);
				 dValue = std::stod(value);
				 PM_PEAK.push_back(dValue);
				 }
			 for(int K = 1; K < (this->heavyDataGrid->ColumnCount); ++K) {
				 if(!(this->heavyDataGrid->Rows[2]->Cells[K]->Value)) return;
				 System_String = this->heavyDataGrid->Rows[2]->Cells[K]->Value->ToString();
				 value = msclr::interop::marshal_as<std::string>(System_String);
				 dValue = std::stod(value);
				 OFF_PEAK.push_back(dValue);
				 }

			 std::vector<double> rAM_PEAK = PEAK(matrix, AM_PEAK);
			 std::vector<double> rPM_PEAK = PEAK(matrix, PM_PEAK);
			 std::vector<double> rOFF_PEAK = PEAK(matrix, OFF_PEAK);

			 std::vector<std::vector<double> > outputMatrix;
			 outputMatrix.push_back(rAM_PEAK);
			 outputMatrix.push_back(rPM_PEAK);
			 outputMatrix.push_back(rOFF_PEAK);

			 outputMatrix = transposeMatrix(outputMatrix);

			 filePrintMatrix(outputMatrix, "heavy_peak.txt");
			 
			 MessageBox::Show("Done! File created.","Completion Notice");
			 }

private: System::Void computeMedium_Click(System::Object^  sender, System::EventArgs^  e) {
			 std::vector<double> AM_PEAK;
			 std::vector<double> PM_PEAK;
			 std::vector<double> OFF_PEAK;
			
			 String^ System_String;
			 std::string value;
			 double dValue;
			 
			 for(int i = 1; i < (this->mediumDataGrid->ColumnCount); ++i) {
				 if(!(this->mediumDataGrid->Rows[0]->Cells[i]->Value)) return;
				 System_String = this->mediumDataGrid->Rows[0]->Cells[i]->Value->ToString();
				 value = msclr::interop::marshal_as<std::string>(System_String);
				 dValue = std::stod(value);
				 AM_PEAK.push_back(dValue);
				 }
			 for(int X = 1; X < (this->mediumDataGrid->ColumnCount); ++X) {
				 if(!(this->mediumDataGrid->Rows[1]->Cells[X]->Value)) return;
				 System_String = this->mediumDataGrid->Rows[1]->Cells[X]->Value->ToString();
				 value = msclr::interop::marshal_as<std::string>(System_String);
				 dValue = std::stod(value);
				 PM_PEAK.push_back(dValue);
				 }
			 for(int K = 1; K < (this->mediumDataGrid->ColumnCount); ++K) {
				 if(!(this->mediumDataGrid->Rows[2]->Cells[K]->Value)) return;
				 System_String = this->mediumDataGrid->Rows[2]->Cells[K]->Value->ToString();
				 value = msclr::interop::marshal_as<std::string>(System_String);
				 dValue = std::stod(value);
				 OFF_PEAK.push_back(dValue);
				 }

			 std::vector<double> rAM_PEAK = PEAK(matrix, AM_PEAK);
			 std::vector<double> rPM_PEAK = PEAK(matrix, PM_PEAK);
			 std::vector<double> rOFF_PEAK = PEAK(matrix, OFF_PEAK);

			 std::vector<std::vector<double> > outputMatrix;
			 outputMatrix.push_back(rAM_PEAK);
			 outputMatrix.push_back(rPM_PEAK);
			 outputMatrix.push_back(rOFF_PEAK);

			 outputMatrix = transposeMatrix(outputMatrix);

			 filePrintMatrix(outputMatrix, "medium_peak.txt");
			 
			 MessageBox::Show("Done! File created.","Completion Notice");
			 }
private: System::Void computeLight_Click(System::Object^  sender, System::EventArgs^  e) {
			 std::vector<double> AM_PEAK;
			 std::vector<double> PM_PEAK;
			 std::vector<double> OFF_PEAK;
			
			 String^ System_String;
			 std::string value;
			 double dValue;
			 
			 for(int i = 1; i < (this->lightDataGrid->ColumnCount); ++i) {
				 if(!(this->lightDataGrid->Rows[0]->Cells[i]->Value)) return;
				 System_String = this->lightDataGrid->Rows[0]->Cells[i]->Value->ToString();
				 value = msclr::interop::marshal_as<std::string>(System_String);
				 dValue = std::stod(value);
				 AM_PEAK.push_back(dValue);
				 }
			 for(int X = 1; X < (this->lightDataGrid->ColumnCount); ++X) {
				 if(!(this->lightDataGrid->Rows[1]->Cells[X]->Value)) return;
				 System_String = this->lightDataGrid->Rows[1]->Cells[X]->Value->ToString();
				 value = msclr::interop::marshal_as<std::string>(System_String);
				 dValue = std::stod(value);
				 PM_PEAK.push_back(dValue);
				 }
			 for(int K = 1; K < (this->lightDataGrid->ColumnCount); ++K) {
				 if(!(this->lightDataGrid->Rows[2]->Cells[K]->Value)) return;
				 System_String = this->lightDataGrid->Rows[2]->Cells[K]->Value->ToString();
				 value = msclr::interop::marshal_as<std::string>(System_String);
				 dValue = std::stod(value);
				 OFF_PEAK.push_back(dValue);
				 }

			 std::vector<double> rAM_PEAK = PEAK(matrix, AM_PEAK);
			 std::vector<double> rPM_PEAK = PEAK(matrix, PM_PEAK);
			 std::vector<double> rOFF_PEAK = PEAK(matrix, OFF_PEAK);

			 std::vector<std::vector<double> > outputMatrix;
			 outputMatrix.push_back(rAM_PEAK);
			 outputMatrix.push_back(rPM_PEAK);
			 outputMatrix.push_back(rOFF_PEAK);

			 outputMatrix = transposeMatrix(outputMatrix);

			 filePrintMatrix(outputMatrix, "light_peak.txt");
			 
			 MessageBox::Show("Done! File created.","Completion Notice");
}
template <typename T>
int filePrintVec(std::vector<T> victor, std::string filename) {
	std::ofstream oFile(filename);

	for(size_t i=0; i < victor.size();++i)
		oFile << victor[i] << std::endl;
	oFile.close();
	return 0;
}
private: System::Void loadHeavy_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
					 openFileDialog1->ShowDialog();
				 String^ filepath = openFileDialog1->FileName;
				
				std::string path =msclr::interop::marshal_as<std::string>(filepath);
				if(path=="") return;
				
				std::ifstream file(path);

				bool fail = false;
				std::vector<std::vector<double> > heavyMatrix;
				fillMatrix(&heavyMatrix, file, &fail);
				if(fail) return;
				file.close();

				if(matrix[0].size() != heavyMatrix[0].size()) {
					MessageBox::Show("Invalid Column Dimensions. Try different file or fix it.", "Notification");
					return;
					}
				
				std::string standard_string;
				String^ system_value;
				long double val;
				
				for(size_t i = 0; i < heavyMatrix.size(); ++i) {
					for(size_t j = 0; j < heavyMatrix[0].size(); ++j){
						val = heavyMatrix[i][j];
						standard_string = std::to_string(val);
						system_value = gcnew String(standard_string.c_str());
						this->heavyDataGrid->Rows[i]->Cells[j+1]->Value = system_value;
						}
				}
			 }
private: System::Void loadMedium_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
					 openFileDialog1->ShowDialog();
				 String^ filepath = openFileDialog1->FileName;
				
				std::string path =msclr::interop::marshal_as<std::string>(filepath);
				if(path=="") return;
				
				std::ifstream file(path);

				bool fail = false;
				std::vector<std::vector<double> > mediumMatrix;
				fillMatrix(&mediumMatrix, file, &fail);
				if(fail) return;
				file.close();

				if(matrix[0].size() != mediumMatrix[0].size()) {
					MessageBox::Show("Invalid Column Dimensions. Try different file or fix it.", "Notification");
					return;
					}
				
				std::string standard_string;
				String^ system_value;
				long double val;
				
				for(size_t i = 0; i < mediumMatrix.size(); ++i) {
					for(size_t j = 0; j < mediumMatrix[0].size(); ++j){
						val = mediumMatrix[i][j];
						standard_string = std::to_string(val);
						system_value = gcnew String(standard_string.c_str());
						this->mediumDataGrid->Rows[i]->Cells[j+1]->Value = system_value;
						}
				}
			 }
private: System::Void loadLight_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
					 openFileDialog1->ShowDialog();
				 String^ filepath = openFileDialog1->FileName;
				
				std::string path =msclr::interop::marshal_as<std::string>(filepath);
				if(path=="") return;
				
				std::ifstream file(path);

				bool fail = false;
				std::vector<std::vector<double> > lightMatrix;
				fillMatrix(&lightMatrix, file, &fail);
				if(fail) return;
				file.close();

				if(matrix[0].size() != lightMatrix[0].size()) {
					MessageBox::Show("Invalid Column Dimensions. Try different file or fix it.", "Notification");
					return;
					}
				
				std::string standard_string;
				String^ system_value;
				long double val;
				
				for(size_t i = 0; i < lightMatrix.size(); ++i) {
					for(size_t j = 0; j < lightMatrix[0].size(); ++j){
						val = lightMatrix[i][j];
						standard_string = std::to_string(val);
						system_value = gcnew String(standard_string.c_str());
						this->lightDataGrid->Rows[i]->Cells[j+1]->Value = system_value;
						}
				}

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
				tok = strtok(array_s, " \t");
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

};
}