#include "MyForm.h"
//#include "Header1.h"

using namespace System;

using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args)

{

    Application::EnableVisualStyles();

    Application::SetCompatibleTextRenderingDefault(false);

    calculator::MyForm form;

    Application::Run(% form);

}