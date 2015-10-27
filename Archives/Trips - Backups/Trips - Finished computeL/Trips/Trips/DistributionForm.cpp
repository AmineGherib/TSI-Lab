#include "DistributionForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int d_main(array<System::String^>^ argv) {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Trips::DistributionForm form2;
	Application::Run(%form2);
	return 0;
}