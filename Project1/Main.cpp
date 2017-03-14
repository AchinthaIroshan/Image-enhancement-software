#include <iostream>
#include <filesystem>
#include "Lib.h"

using namespace std;
using namespace cv;
using namespace library;

void generateOutput(int value, void*);

Mat globalInput;

int main(int argc, char** argv)
{

	Mat image;
	image = imread("../../im4.jpg", IMREAD_COLOR); // Read the file

	if (!image.data) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	//image.convertTo(image, CV_32FC3, 1/255.0);

	namedWindow("input window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("input window", image); // Show our image inside it.

	globalInput = image;
	int slider = 100;

	createTrackbar("lever", "input window", &slider, 200, generateOutput);

	namedWindow("output window", WINDOW_AUTOSIZE); // Create a window for display.

	//imshow("output window", Lib::BrightnessAndContrastAuto(image, 2)); // Show our image inside it.

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}

void generateOutput(int value, void*)
{
	//imshow("output window", Lib::shadowRecovery(globalInput, ((value - 100) / 100.0))); // Show our image inside it.
}