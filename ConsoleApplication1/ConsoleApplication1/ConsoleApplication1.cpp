#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

double alpha; //Contrast Handle
int beta;  //Brightness Handle
Mat image;
Mat new_image;
int sliderC = 50;
int sliderB = 50;

//new_image(i, j) = alpha*image(i, j) + beta

void Brightness(int sliderB, void* userData) {
	sliderC = *(static_cast<int*>(userData));
	alpha = sliderC / 50.0;
	beta = sliderB - 50;
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			for (int c = 0; c < 3; c++) {
				new_image.at<Vec3b>(y, x)[c] =
					saturate_cast<uchar>(alpha*(image.at<Vec3b>(y, x)[c]) + beta);
			}
		}
	}
}
void Contrast(int sliderC, void* userData) {
	sliderC = *(static_cast<int*>(userData));
	alpha = sliderC / 50.0;
	beta = sliderB - 50;
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			for (int c = 0; c < 3; c++) {
				new_image.at<Vec3b>(y, x)[c] =
					saturate_cast<uchar>(alpha*(image.at<Vec3b>(y, x)[c]) + beta);
			}
		}
	}
}



int main(int argc, char** argv)
{
	image = imread("C:/Users/User/Pictures/test.jpeg");
	if (!image.data)
	{
		cout << "Error Loading Image" << endl;
		return -1;
	}
	new_image = Mat::zeros(image.size(), image.type());

	namedWindow("Contrast and Brightness Adjust", 1);


	createTrackbar("Brigtness", "Contrast and Brightness Adjust", &sliderC, 100, Brightness, &sliderB);
	createTrackbar("Contrast", "Contrast and Brightness Adjust", &sliderB, 100, Contrast, &sliderC);






	while (true)
	{

		//show the brightness and contrast adjusted image
		imshow("Contrast and Brightness Adjust", new_image);

		// Wait until user press some key for 50ms
		int iKey = waitKey(50);

		if (iKey == 27) //ESC
		{
			break;
		}
	}
	return 0;
}


