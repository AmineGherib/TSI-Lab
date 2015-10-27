#include "GenerationForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int g_main(array<System::String^>^ argv) {
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Trips::GenerationForm form;
	Application::Run(%form);
	return 0;
}