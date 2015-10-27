#pragma once
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <random>
#include <cmath>
#include <msclr\marshal_cppstd.h>
#include "AttractiveForm.h"

static std::vector<std::vector<long double> > t;
static std::vector<std::vector<long double> > H;
static std::vector<std::vector<long double> > W;
static std::vector<std::vector<long double> > A;
static std::vector<std::vector<long double> > E;
static std::vector<std::vector<long double> > T;

static std::vector<std::vector<long double> > alphaLightMatrix;
static std::vector<std::vector<long double> > alphaMediumMatrix;
static std::vector<std::vector<long double> > alphaHeavyMatrix;

static std::vector<long double> betaLightVector;
static std::vector<long double> betaMediumVector;
static std::vector<long double> betaHeavyVector;

static bool filledt = false, filledH = false, filledW = false;

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
	private: System::Windows::Forms::Button^  loadM;
	private: System::Windows::Forms::Button^  loadL;
	private: System::Windows::Forms::Button^  loadH;

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
		this->loadM = (gcnew System::Windows::Forms::Button());
		this->loadL = (gcnew System::Windows::Forms::Button());
		this->loadH = (gcnew System::Windows::Forms::Button());
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
		this->computeM->Click += gcnew System::EventHandler(this, &DistributionForm::computeM_Click);
		// 
		// computeH
		// 
		this->computeH->Location = System::Drawing::Point(473, 90);
		this->computeH->Name = L"computeH";
		this->computeH->Size = System::Drawing::Size(75, 23);
		this->computeH->TabIndex = 19;
		this->computeH->Text = L"Compute H";
		this->computeH->UseVisualStyleBackColor = true;
		this->computeH->Click += gcnew System::EventHandler(this, &DistributionForm::computeH_Click);
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
		// loadM
		// 
		this->loadM->Location = System::Drawing::Point(253, 98);
		this->loadM->Name = L"loadM";
		this->loadM->Size = System::Drawing::Size(85, 23);
		this->loadM->TabIndex = 21;
		this->loadM->Text = L"Load Medium";
		this->loadM->UseVisualStyleBackColor = true;
		this->loadM->Click += gcnew System::EventHandler(this, &DistributionForm::loadM_Click);
		// 
		// loadL
		// 
		this->loadL->Location = System::Drawing::Point(162, 98);
		this->loadL->Name = L"loadL";
		this->loadL->Size = System::Drawing::Size(85, 23);
		this->loadL->TabIndex = 22;
		this->loadL->Text = L"Load Light";
		this->loadL->UseVisualStyleBackColor = true;
		this->loadL->Click += gcnew System::EventHandler(this, &DistributionForm::loadL_Click);
		// 
		// loadH
		// 
		this->loadH->Location = System::Drawing::Point(344, 97);
		this->loadH->Name = L"loadH";
		this->loadH->Size = System::Drawing::Size(85, 23);
		this->loadH->TabIndex = 23;
		this->loadH->Text = L"Load Heavy";
		this->loadH->UseVisualStyleBackColor = true;
		this->loadH->Click += gcnew System::EventHandler(this, &DistributionForm::loadH_Click);
		// 
		// DistributionForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(560, 503);
		this->Controls->Add(this->loadH);
		this->Controls->Add(this->loadL);
		this->Controls->Add(this->loadM);
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
		this->Text = L"Trip Distribution";
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
/*
Objective: remove a substring from a string
Input: Two templated strings. The substring is const
Output: Nothing.
*/
template<typename T>
void removeSubstrs(std::basic_string<T>& s, const  std::basic_string<T>& p) {
   std::basic_string<T>::size_type n = p.length();

   for (std::basic_string<T>::size_type i = s.find(p);  
	   i != std::basic_string<T>::npos; 
	   i = s.find(p))
      s.erase(i, n);
}
/*
Objective: Find a specific directory
Input: Filepath of a file in target directory
Output: Filepath to directory
*/
std::string findDirect(std::string example)
{	//example is a file in the target directory

	std::string temp = example;
	std::string last_token(example.substr(example.rfind("\\") +1));
	
	removeSubstrs(temp, last_token);
	
	return temp;
}
void checkTabs() {

			if(this->TabControl->SelectedTab->ToString() == "Light") {
					this->loadL->Enabled = true;
					this->loadM->Enabled = false;
					this->loadH->Enabled = false;
			}
			
			else if(this->TabControl->SelectedTab->ToString() == "Medium") {
					this->loadL->Enabled = false;
					this->loadM->Enabled = true;
					this->loadH->Enabled = false;
			}
			else if(this->TabControl->SelectedTab->ToString() == "Heavy") {
					this->loadL->Enabled = false;
					this->loadM->Enabled = false;
					this->loadH->Enabled = true;
			}				
				
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
	
	checkTabs();
	return dProd;
}

template <typename T>
int filePrintVec(std::vector<T> victor, std::string filename) {
	std::ofstream oFile(filename);

	for(size_t i=0; i < victor.size();++i)
		oFile << victor[i] << std::endl;
	oFile.close();

	checkTabs();
	return 0;
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

	checkTabs();
	file.close();
}

template <typename T>
std::vector<std::vector<T> > transposeMatrix(std::vector<std::vector<T> > matrix) {
	int nRow = matrix[0].size(), nCol = matrix.size();
	std::vector<T> row;

	std::vector<std::vector<T> > transpose;
	for(int i=0; i<nRow;++i) {
		for(int j=0; j<nCol;++j) {
			row.push_back(matrix[j][i]);
		}
		transpose.push_back(row);
		row.clear();
	}
	
	checkTabs();
	return transpose;
}
void calculateT_Light() {
	
	// 3 rows for (AM,PM,OFF) and 3 col for (Light,Medium,Heavy)
	size_t nRow=3, nCol=3;
	long double val;
	bool fail = false;
	std::vector<long double> iter_vec;

	std::ifstream light_peak("light_peak.txt");
	std::ifstream medium_peak("medium_peak.txt");
	std::ifstream heavy_peak("heavy_peak.txt");

	std::vector<std::vector<int> > v;

	std::vector<std::vector<long double> > l_peak; fillMatrix(&l_peak, light_peak, &fail);
	std::vector<std::vector<long double> > m_peak; fillMatrix(&m_peak, medium_peak, &fail);
	std::vector<std::vector<long double> > h_peak; fillMatrix(&h_peak, heavy_peak, &fail);
	
	std::vector<std::vector<long double> > tl_peak = transposeMatrix(l_peak);
	std::vector<std::vector<long double> > tm_peak = transposeMatrix(m_peak);
	std::vector<std::vector<long double> > th_peak = transposeMatrix(h_peak);
	
	for(size_t b = 0; b < betaLightVector().size; ++b) {
		//E = (t, betaLightVector[b]);
		}

	filePrintMatrix(T, "output.txt");
	light_peak.close();
	medium_peak.close();
	heavy_peak.close();
	checkTabs();
}

std::vector<std::vector<long double> > step1(std::vector<std::vector<long double> > matrix, long double betaVal) {
	std::vector<std::vector<long double> > E;
	std::vector<long double> vE;
	long double exponential;
	
	for(size_t i = 0; i < matrix.size(); ++i) {
		for(size_t j = 0; j < matrix[j].size(); ++j){
				exponential = matrix[i][j] * betaVal;
				vE.push_back(exp(exponential));
			}
			E.push_back(vE);
		}
	return E;
	}
std::vector<long double> step2(std::vector<std::vector<long double> > matrix, std::vector<long double> alphaVector) {
	long double power;
	long double prod = 1;
	std::vector<long double> resultV;
	for(size_t i = 0; i < matrix.size(); ++i) {
		for(size_t j = 0; j < matrix[j].size(); ++j){
				power = pow(matrix[i][j], alphaVector[j]);
				prod *= power;
			}
			resultV.push_back(prod);
			prod = 1;
		}
	return resultV;
}

std::vector<std::vector<long double> > step3(std::vector<std::vector<long double> > matrix, std::vector<long double> alphaVector) {
	std::vector<std::vector<long double> > eAlpha;
	std::vector<long double> eAlphaV;
	long double val;
	for(size_t i = 0; i < matrix.size(); ++i) {
		for(size_t j = 0; j < matrix[j].size(); ++j){
				val = alphaVector[j] * matrix[i][j];
				eAlphaV.push_back(val);
			}
			eAlpha.push_back(eAlphaV);
		}
	return eAlpha;
	}
std::vector<long double> step4(std::vector<std::vector<long double> > matrix) {
	//sum the rows
	long double sum = 0;
	std::vector<long double> vSum;
	for(size_t i = 0; i < matrix.size(); ++i) {
		for(size_t j = 0; j < matrix[j].size(); ++j){
				sum += matrix[i][j];
			}
			vSum.push_back(sum);
			sum = 0;	
		}
	return vSum;
}

std::vector<std::vector<long double> > step5(std::vector<std::vector<long double> > matrix, std::vector<long double> vector) {
		//Divide each element of matrix by elements of vector
		std::vector<std::vector<long double> > resultP;
		std::vector<long double> vResultP;
		long double val;

		for(size_t i = 0; i < matrix.size(); ++i) {
			for(size_t j = 0; j < matrix[j].size(); ++j){
					val = matrix[i][j]/vector[j];
					vResultP.push_back(val);
				}
			resultP.push_back(vResultP);
		}
	return resultP;
}

std::vector<std::vector<long double> > step6(std::vector<std::vector<long double> > matrix, std::vector<long double> oVector) {
	std::vector<std::vector<long double> > Op;
	std::vector<long double> OpV;
	long double val;
	
	for(size_t i = 0; i < matrix.size(); ++i) {
		for(size_t j = 0; j < matrix[j].size(); ++j){
				val = oVector[j] * matrix[i][j];
				OpV.push_back(val);
			}
			Op.push_back(OpV);
		}
	return Op;
	}



private: System::Void findDirectory_Click(System::Object^  sender, System::EventArgs^  e) {
				OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
				         openFileDialog1->ShowDialog();
				 this->filePathInterzonal->Text = openFileDialog1->FileName;

				 std::string input =msclr::interop::marshal_as<std::string>(this->filePathInterzonal->Text);
				 std::ifstream iFile(input);
				 bool fail = false;

				 fillMatrix(&t, iFile, &fail);

				 if(t.size() != t[0].size()) {
					 MessageBox::Show("Unequal number of columns and rows. Modify the file or try another one","Notification");
					 t.clear();
					 return;
			 	 }

				 filledt = true;
				 if(filledt && filledH && filledW)
					 fillGrids();
				checkTabs();		
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
				 
				 if(filledt && filledH && filledW)
					 fillGrids();
				 checkTabs();
			 }
private: System::Void findDirectoryAttractiveness_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
				 openFileDialog1->ShowDialog();
				 this->filePathAttractiveness->Text = openFileDialog1->FileName;

				 std::string input =msclr::interop::marshal_as<std::string>(this->filePathAttractiveness->Text);
				 std::ifstream iFile(input);
				 bool fail = false;

				 fillMatrix(&W, iFile, &fail);  

				 if(W.size() != t.size()) {
					MessageBox::Show("Invalid number of rows. It must be the same as the interzonal matrix. Fix error and try again","Notification"); 
					return;
				}
				
				 filledW = true;

				 if(filledt && filledH && filledW)
					 fillGrids();
				 checkTabs();
			 }
void fillMatrix(std::vector<std::vector<long double> >* data, std::ifstream& file, bool *fail) {
		
	if(!file.is_open()) {
		MessageBox::Show("Error! File is closed.","Error Message");
			*fail = true; return;
	}
		while(file) {
			std::string line;
			if(!getline(file, line)) break;
			std::istringstream ss(line);
			std::vector<long double> row;
			
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
					long double value = std::stod(svalue);	
					row.push_back(value);
					tok = strtok(NULL, " \t");
				}
					data->push_back(row);
			}	
		}
		checkTabs();
	}
void fillGrids() {
			 DataSet^ firstDataSet = gcnew DataSet();
			 DataSet^ secondDataSet = gcnew DataSet();
			 DataSet^ thirdDataSet = gcnew DataSet();

			 size_t numAlpha = W[0].size();

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
					firstDataSet->Tables["Light Grid"]->Columns->Add("Alpha "+cellValue);
					secondDataSet->Tables["Medium Grid"]->Columns->Add("Alpha "+cellValue);
					thirdDataSet->Tables["Heavy Grid"]->Columns->Add("Alpha "+cellValue);
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
			
			checkTabs();
			}
private: System::Void displayInterzonalMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void displayHourlyMatrix_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void displayAttractiveVariables_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void computeL_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 std::vector<long double> alphaVector;

			 String^ System_String;
			 std::string value;
			 long double dValue;

					 for(int j = 0; j < 3; j++) {
						 for(int i = 1 ; i < (this->lightDataGrid->ColumnCount); i++) { 
							if(!(this->lightDataGrid->Rows[j]->Cells[i]->Value)) return;
							System_String = this->lightDataGrid->Rows[j]->Cells[i]->Value->ToString();
							value = msclr::interop::marshal_as<std::string>(System_String);
							dValue = std::stod(value);
							if(i==1)
								betaLightVector.push_back(dValue);
							else
								alphaVector.push_back(dValue);
						 }
					alphaLightMatrix.push_back(alphaVector);
					alphaVector.clear();
				}
			calculateT_Light();
			checkTabs();
			}
 private: System::Void computeM_Click(System::Object^  sender, System::EventArgs^  e) {

			 std::vector<long double> alphaVector;

			 String^ System_String;
			 std::string value;
			 long double dValue;

					 for(int j = 0; j < 3; j++) {
						 for(int i = 1 ; i < (this->mediumDataGrid->ColumnCount); i++) { 
							if(!(this->mediumDataGrid->Rows[j]->Cells[i]->Value)) return;
							System_String = this->mediumDataGrid->Rows[j]->Cells[i]->Value->ToString();
							value = msclr::interop::marshal_as<std::string>(System_String);
							dValue = std::stod(value);
							if(i==1)
								betaMediumVector.push_back(dValue);
							else
								alphaVector.push_back(dValue);
						 }
					alphaMediumMatrix.push_back(alphaVector);
					alphaVector.clear();
				}
			calculateT_Light();
			checkTabs();
			 }

private: System::Void computeH_Click(System::Object^  sender, System::EventArgs^  e) {
			 std::vector<long double> alphaVector;

			 String^ System_String;
			 std::string value;
			 long double dValue;

					 for(int j = 0; j < 3; j++) {
						 for(int i = 1 ; i < (this->heavyDataGrid->ColumnCount); i++) { 
							if(!(this->heavyDataGrid->Rows[j]->Cells[i]->Value)) return;
							System_String = this->heavyDataGrid->Rows[j]->Cells[i]->Value->ToString();
							value = msclr::interop::marshal_as<std::string>(System_String);
							dValue = std::stod(value);
							if(i==1) 
								betaHeavyVector.push_back(dValue);
							else
								alphaVector.push_back(dValue);
						}
					alphaHeavyMatrix.push_back(alphaVector);
					alphaVector.clear();
						 }
			calculateT_Light();
			checkTabs();
			 }
private: System::Void loadL_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
					 openFileDialog1->ShowDialog();
				 String^ filepath = openFileDialog1->FileName;
				
				std::string path =msclr::interop::marshal_as<std::string>(filepath);
				if(path=="") return;
				
				std::ifstream file(path);

				bool fail = false;
				std::vector<std::vector<long double> > lightMatrix;
				fillMatrix(&lightMatrix, file, &fail);
				if(fail) return;
				file.close();
				
				if(lightMatrix[0].size() != (W[0].size()+1) ) {
					MessageBox::Show("Invalid Column Dimensions. Fix error and try again.", "Notification");
					lightMatrix.clear();
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
				lightMatrix.clear();
				checkTabs();
	}
private: System::Void loadM_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
					 openFileDialog1->ShowDialog();
				 String^ filepath = openFileDialog1->FileName;
				
				std::string path =msclr::interop::marshal_as<std::string>(filepath);
				if(path=="") return;
				
				std::ifstream file(path);

				bool fail = false;
				std::vector<std::vector<long double> > mediumMatrix;
				fillMatrix(&mediumMatrix, file, &fail);
				if(fail) return;
				file.close();
				
				if(mediumMatrix[0].size() != (W[0].size()+1) ) {
					MessageBox::Show("Invalid Column Dimensions. Fix error and try again.", "Notification");
					mediumMatrix.clear();
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
				mediumMatrix.clear();
				checkTabs();
			 }
private: System::Void loadH_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
					 openFileDialog1->ShowDialog();
				 String^ filepath = openFileDialog1->FileName;
				
				std::string path =msclr::interop::marshal_as<std::string>(filepath);
				if(path=="") return;
				
				std::ifstream file(path);

				bool fail = false;
				std::vector<std::vector<long double> > heavyMatrix;
				fillMatrix(&heavyMatrix, file, &fail);
				if(fail) return;
				file.close();
				
				if(heavyMatrix[0].size() != (W[0].size()+1) ) {
					MessageBox::Show("Invalid Column Dimensions. Fix error and try again.", "Notification");
					heavyMatrix.clear();
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
				heavyMatrix.clear();
				checkTabs();
			 }
};
}
