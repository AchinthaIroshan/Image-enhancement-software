#include <iostream>
#include <filesystem>
#include "Lib.h"
#include "MainForm.h"

using namespace std;
using namespace cv;
using namespace pes::library;
using namespace pes::view;


int main(int argc, char** argv)
{
	Application::Run(gcnew MainForm);

	/*Mat image;
	image = imread("../../im1.jpg", IMREAD_COLOR); // Read the file

	if (!image.data) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	image.convertTo(image, CV_32FC3, 1/255.0);

	namedWindow("input window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("input window", image); // Show our image inside it.

	namedWindow("output window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("output window", Lib::AdjustTemperature(image.clone(), 1.2)); // Show our image inside it.

	waitKey(0); // Wait for a keystroke in the window*/
	return 0;
}
