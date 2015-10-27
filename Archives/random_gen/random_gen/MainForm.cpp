#include "MainForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]

 int main(array<System::String^>^ argv) {
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	FreeConsole();

	random_gen::MainForm form;
	Application::Run(%form);
	return 0;
}