#include <iostream>
#include <filesystem>
#include "Lib.h"
#include "MainForm.h"

using namespace std;
using namespace cv;
using namespace pes::library;
using namespace pes::view;

Mat globalInput;

void GetSharpenImage(int value, void*);
void shadowRecovery(int value, void*);
void highlightRecovery(int value, void*);
void Crop(int value, void*);
void Contrast(int value, void*);
void SaturationAdjust(int value, void*);
void ExposureAdjust(int value, void*);


[System::STAThread]
int main(int argc, char** argv)
{
	Application::EnableVisualStyles();
	Application::DoEvents();
	Application::Run(gcnew MainForm);
	return 0;
}
