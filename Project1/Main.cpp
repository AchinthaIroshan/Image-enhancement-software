#include <iostream>
#include <filesystem>
#include "MainForm.h"

using namespace std;
using namespace cv;
using namespace pes::view;


[System::STAThread]
int main(int argc, char** argv)
{
	Application::EnableVisualStyles();
	Application::DoEvents();
	Application::Run(gcnew MainForm);
	return 0;
}
