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


//[System::STAThread]
int main(int argc, char** argv)
{
	/*Application::EnableVisualStyles();
	Application::DoEvents();
	Application::Run(gcnew MainForm);*/

	Mat image;
	image = imread("../../im2.jpg", IMREAD_COLOR); // Read the file

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
	createTrackbar("colour saturation", "input window", &slider, 200, SaturationAdjust);
	createTrackbar("Exposure		 ", "input window", &slider, 200, ExposureAdjust);

	namedWindow("output window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("output window", globalInput);

	std::cout << "Temperature: " << Lib::CalculateColorTemperature(image)<< " K" << std::endl;
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}

void GetSharpenImage(int value, void*)
{
	imshow("output window", Lib::Vignette(globalInput, value)); // Show our image inside it.
}

void shadowRecovery(int value, void*)
{
	imshow("output window", Lib::ShadowRecovery(globalInput, value)); // Show our image inside it.
}

void highlightRecovery(int value, void*)
{
	imshow("output window", Lib::HighlightRecovery(globalInput, ((value)))); // Show our image inside it.
}

void Crop(int value, void*)
{
	imshow("output window", Lib::Crop(globalInput, cv::Point(20, 40), 380.0, 250.0)); // Show our image inside it.
}

void Contrast(int value, void*)
{
	imshow("output window", Lib::ContrastAdjustment(globalInput, (value))); // Show our image inside it.
}

void SaturationAdjust(int value, void*)
{
	std::cout << "Temperature: " << Lib::CalculateColorTemperature( Lib::SaturationAdjustment(globalInput, (value)) ) << " K" << std::endl;
	imshow("output window", Lib::SaturationAdjustment(globalInput, (value))); // Show our image inside it.
}

void ExposureAdjust(int value, void*)
{
	imshow("output window", Lib::ExposureAdjustment(globalInput, (value))); // Show our image inside it.
}