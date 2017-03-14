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


//[System::STAThread]
int main(int argc, char** argv)
{
	/*Application::EnableVisualStyles();
	Application::DoEvents();
	Application::Run(gcnew MainForm);*/

	Mat image;
	image = imread("../../im3.jpg", IMREAD_COLOR); // Read the file

	resize(image, image, cv::Size(400, 400));

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
	createTrackbar("crop"			  , "input window", &slider, 200, Crop);
	createTrackbar("Contrast"		  , "input window", &slider, 200, Contrast);

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
	imshow("output window", Lib::ShadowRecovery(globalInput, ((value - 100) / 100.0))); // Show our image inside it.
}

void highlightRecovery(int value, void*)
{
	imshow("output window", Lib::HighlightRecovery(globalInput, ((value - 100) / 100.0))); // Show our image inside it.
}

void Crop(int value, void*)
{
	imshow("output window", Lib::Crop(globalInput, cv::Point(20, 40), 200, 200)); // Show our image inside it.
}

void Contrast(int value, void*)
{
	imshow("output window", Lib::ContrastAdjustment(globalInput, (value)/100.0)); // Show our image inside it.
}