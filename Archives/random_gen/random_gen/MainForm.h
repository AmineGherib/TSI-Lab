#pragma 
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <algorithm>
#include <iomanip>
#include <msclr\marshal_cppstd.h>

std::string findDirectory(std::string);

namespace random_gen {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  butNumChoices;
	protected: 

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  butNumReducedChoices;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  filePath;
	private: System::Windows::Forms::Button^  fileChoose;
	private: System::Windows::Forms::Button^  compute;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->butNumChoices = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->butNumReducedChoices = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->filePath = (gcnew System::Windows::Forms::TextBox());
			this->fileChoose = (gcnew System::Windows::Forms::Button());
			this->compute = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(177, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Provide the total number of choices:";
			// 
			// butNumChoices
			// 
			this->butNumChoices->Location = System::Drawing::Point(220, 15);
			this->butNumChoices->Name = L"butNumChoices";
			this->butNumChoices->Size = System::Drawing::Size(103, 20);
			this->butNumChoices->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(137, 26);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Provide the total number of \r\nreduced choices:";
			// 
			// butNumReducedChoices
			// 
			this->butNumReducedChoices->Location = System::Drawing::Point(220, 52);
			this->butNumReducedChoices->Name = L"butNumReducedChoices";
			this->butNumReducedChoices->Size = System::Drawing::Size(103, 20);
			this->butNumReducedChoices->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Select the input file";
			// 
			// filePath
			// 
			this->filePath->Location = System::Drawing::Point(12, 110);
			this->filePath->Name = L"filePath";
			this->filePath->Size = System::Drawing::Size(197, 20);
			this->filePath->TabIndex = 5;
			// 
			// fileChoose
			// 
			this->fileChoose->Location = System::Drawing::Point(220, 107);
			this->fileChoose->Name = L"fileChoose";
			this->fileChoose->Size = System::Drawing::Size(103, 23);
			this->fileChoose->TabIndex = 6;
			this->fileChoose->Text = L"Choose file";
			this->fileChoose->UseVisualStyleBackColor = true;
			this->fileChoose->Click += gcnew System::EventHandler(this, &MainForm::fileChoose_Click);
			// 
			// compute
			// 
			this->compute->Location = System::Drawing::Point(12, 136);
			this->compute->Name = L"compute";
			this->compute->Size = System::Drawing::Size(311, 23);
			this->compute->TabIndex = 7;
			this->compute->Text = L"Generate the randomized choices";
			this->compute->UseVisualStyleBackColor = true;
			this->compute->Click += gcnew System::EventHandler(this, &MainForm::compute_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 165);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(311, 23);
			this->progressBar1->TabIndex = 8;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(332, 199);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->compute);
			this->Controls->Add(this->fileChoose);
			this->Controls->Add(this->filePath);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->butNumReducedChoices);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->butNumChoices);
			this->Controls->Add(this->label1);
			this->Name = L"MainForm";
			this->Text = L"Random Generator of Choices";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void fileChoose_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
					 openFileDialog1->ShowDialog();
				 this->filePath->Text = openFileDialog1->FileName;
				 
			 }

	private: System::Void compute_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(this->progressBar1->Value != 0) // Reset the progress bar.
			   	this->progressBar1->Value = 0;
			
			 if(this->butNumChoices->Text == "") {
				MessageBox::Show("You must enter the number of choices", "Notification");
				return;
			 }
			 if(this->butNumReducedChoices->Text == "") {
				MessageBox::Show("You must enter the number of reduced choices", "Notification");
				return;
			 }
			 if(this->filePath->Text == "") {
				MessageBox::Show("You must enter a file path", "Notification");
				return;			 
			 }
/****************************************************************************************************************************************************************************/
			 std::string dir, output;
			
			 //Convert "System::String^" to "string"
			 std::string input =msclr::interop::marshal_as<std::string>(this->filePath->Text);
			 
			 dir = findDirectory(input);
			 output = dir + "output.txt";
			 
			 std::ifstream iFile(input);
			 std::ofstream oFile(output);

			 int num_of_lines=0; 
			 std::string line;
			 while(std::getline(iFile, line)) ++num_of_lines;
			 
			 iFile.clear(); 
			 iFile.seekg(0, std::ios::beg); //Reset file pointer to the beginning of the file

/****************************************************************************************************************************************************************************/
			 int numChoices = Convert::ToInt32(this->butNumChoices->Text);
			 int numReducedChoices = Convert::ToInt32(this->butNumReducedChoices->Text);
			 
			 std::vector<int> obsID(num_of_lines); 
			 std::vector<int> choiceID(num_of_lines);
			 int i = 0;
			 
			 int a, b;
			 for(;iFile >> a >> b && i < num_of_lines; i++) {
				obsID[i] = a;
				choiceID[i] = b;

				if (iFile.fail()) { //In the case that the input file contains an error
					MessageBox::Show("The input file contains a invalid character. Check the input file and try again","Notification");
					return;
				}
			 }

/****************************************************************************************************************************************************************************/
			 int max = *max_element(choiceID.begin(), choiceID.end());
			 if(numChoices < max) {
				MessageBox::Show("The total number of choices is not larger or equal than the maximum element of the second column. Try again", "Notification");
				return;			 
			 }

			 if(numReducedChoices > numChoices) {
				MessageBox::Show("The number of reduced choices cannot be greater than the number of choices. Try again", "Notification");
				return;			 
			 }

/****************************************************************************************************************************************************************************/
			 Random^ randObj = gcnew Random; //Random object with an auto-generated seed
			 int flag, r;
			 std::vector<int> memory(numReducedChoices); //a record of all random numbers generated
			 
			 for(i = 0; i < num_of_lines ; i++) {
				
				flag = 1;
				oFile << std::setw(3) << obsID[i] << "     " << std::setw(3) << choiceID[i] << "     " << flag <<  std::endl;//The first value of the set is from the input file
																															 //rest is random generated
				for(int d = 0; d < numReducedChoices; d++) memory[d] = 0; //clear memory vector for next iteration

				for(int j=1;j<numReducedChoices;j++) {
					flag = 0;	
					r = randObj->Next(1, numChoices);

					//Condition 1: The random number must be different from the first element(flag = 1)
					//Condition 2: All random numbers must be different from eachother
					if( (r != choiceID[i]) && (!check(memory, r, numReducedChoices)) )
					{
						oFile << std::setw(3) << obsID[i] << "     " << std::setw(3) << r << "     " << flag << std::endl;
						memory[j-1] = r; //save value to memory to continue checking
					}
					else
						j--; //If the random number does not satisfy these conditions, decrement the iterating integer by one
							 //It will be re-incremented. This way, we can keep randomizing until we have a original number
				}
			 }
			 this->timer1->Start();

			 iFile.close();
			 oFile.close();
		 }
/*
Objective: Find a specific directory
Input: Filepath of a file in target directory
Output: Filepath to directory
*/
std::string findDirectory(std::string example)
{	//example is a file in the target directory

	std::string temp = example;
	std::string last_token(example.substr(example.rfind("\\") +1));
	
	removeSubstrs(temp, last_token);
	
	return temp;
}
/*
Objective: Check if a number is in a array
Input: A vector and a variable of same type to search
Output: Returns true if n is found, false if not
*/
template<typename D>
int check(std::vector<D> a, D n, D size)
{   
    for(int i = 0; i < size; i++) {
		if(a[i] == n) {
			return 1;
		}
	}
	return 0;
}
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

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 this->progressBar1->Increment(15);
		 }
};
}

