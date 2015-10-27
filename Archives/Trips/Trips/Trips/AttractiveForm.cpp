#include "AttractiveForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int a_main(array<System::String^>^ argv) {
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Trips::AttractiveForm form3;
	Application::Run(%form3);
	return 0;
}