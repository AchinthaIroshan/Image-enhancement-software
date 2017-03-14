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

//[System::STAThread]
int main(int argc, char** argv)
{
	/*Application::EnableVisualStyles();
	Application::DoEvents();
	Application::Run(gcnew MainForm);*/

	Mat image;
	image = imread("../../im2.jpg", IMREAD_COLOR); // Read the file

	if (!image.data) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	image.convertTo(image, CV_32FC3, 1/255.0);

	namedWindow("input window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("input window", image); // Show our image inside it.

	globalInput = image;
	int slider = 100;

	createTrackbar("GetSharpenImage"  , "input window", &slider, 200, GetSharpenImage);
	createTrackbar("shadowRecovery"   , "input window", &slider, 200, shadowRecovery);
	createTrackbar("highlightRecovery", "input window", &slider, 200, highlightRecovery);

	namedWindow("output window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("output window", globalInput);

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}

void GetSharpenImage(int value, void*)
{
	imshow("output window", Lib::GetSharpenImage(globalInput, ((value - 100) / 100.0), 0.1)); // Show our image inside it.
}
void shadowRecovery(int value, void*)
{
	imshow("output window", Lib::shadowRecovery(globalInput, ((value - 100) / 100.0))); // Show our image inside it.
}
void highlightRecovery(int value, void*)
{
	imshow("output window", Lib::highlightRecovery(globalInput, ((value - 100) / 100.0))); // Show our image inside it.
}
