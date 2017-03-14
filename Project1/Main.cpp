#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <filesystem>

#define UPPER_SHADOW_LEVEL 0.24
#define LOWER_SHADOW_LEVEL 0.05
#define UPPER_HIGHLIGHT_LEVEL 0.9999
#define LOWER_HIGHLIGHT_LEVEL 0.6500

using namespace cv;
using namespace std;

Mat globalInput;


Mat GetSharpenImage(Mat im, float value, float sigma);
Mat AdjustTemperature(Mat im, double value);
Mat Vignette(Mat im, int value=200);
Mat ColorBalance(Mat im, double r, double g, double b);
Mat AutoCorrect(Mat im, double lim=2, int sz=30);
Mat BrightnessAndContrastAuto(Mat src, double clipHistPercent = 0);
Mat shadowRecovery(Mat input_image, double alpha);
Mat highlightRecovery(Mat input_image, double alpha);
void generateOutput(int, void*);

int main(int argc, char** argv)
{
	Mat image;
	image = imread("im2.JPG", IMREAD_COLOR); // Read the file

	
	if (!image.data) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	//cout << "Image loading completed. Enter alpha value: "; double alpha; cin >> alpha;

	image.convertTo(image, CV_32FC3, 1/255.0);
	globalInput = image;
	int slider = 100;

	namedWindow("input window", WINDOW_AUTOSIZE); // Create a window for display.
	createTrackbar("lever", "input window", &slider, 200, generateOutput);
	imshow("input window", image); // Show our image inside it.

	namedWindow("output window", WINDOW_AUTOSIZE); // Create a window for display.
	
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}

void generateOutput(int value, void*)
{
	imshow("output window", shadowRecovery(globalInput, ((value - 100)/100.0))); // Show our image inside it.
}

Mat shadowRecovery(Mat input_image, double alpha)  // Input is 32 bit floating array
{
	//cout << "Alpha: " << alpha << endl;
	Mat modifier;
	cvtColor(input_image, modifier, CV_BGR2GRAY);  // Take Gray image
	Mat thresholdedImageUp;
	threshold(modifier, thresholdedImageUp, LOWER_SHADOW_LEVEL, 1.0, THRESH_TOZERO); // Treshold - up
	Mat thresholdedImageDown;
	threshold(thresholdedImageUp, thresholdedImageDown, UPPER_SHADOW_LEVEL, 1.0, THRESH_TOZERO_INV); // Treshold - down
	//imshow("tt", thresholdedImageDown); waitKey(0);
	Mat tripleChannelAdder;
	cvtColor(thresholdedImageDown, tripleChannelAdder, CV_GRAY2BGR);
	//imshow("temp", input_image + alpha * tripleChannelAdder); cin.get();
	return (input_image + alpha * tripleChannelAdder);
}

Mat highlightRecovery(Mat input_image, double alpha)  // Input is 32 bit floating array
{
	//cout << "Alpha: " << alpha << endl;
	Mat modifier;
	cvtColor(input_image, modifier, CV_BGR2GRAY);  // Take Gray image
	Mat thresholdedImageUp;
	threshold(modifier, thresholdedImageUp, LOWER_HIGHLIGHT_LEVEL, 1.0, THRESH_TOZERO); // Treshold - up
	Mat thresholdedImageDown;
	threshold(thresholdedImageUp, thresholdedImageDown, UPPER_HIGHLIGHT_LEVEL, 1.0, THRESH_TOZERO_INV); // Treshold - down
																									 //imshow("tt", thresholdedImageDown); waitKey(0);
	Mat tripleChannelAdder;
	cvtColor(thresholdedImageDown, tripleChannelAdder, CV_GRAY2BGR);
	//imshow("temp", input_image + alpha * tripleChannelAdder); cin.get();
	return (input_image + alpha * tripleChannelAdder);
}

Mat GetSharpenImage(Mat im, float value, float sigma)
{
	Mat out;
	GaussianBlur(im, out, Size(0, 0), sigma, sigma);
	addWeighted(im, 1 + value, out, -value, 0, out);
	return out;
}

Mat AdjustTemperature(Mat im, double value)
{
	Mat out;
	Mat ch[3];
	split(im, ch);
	cv::pow(ch[0], value, ch[0]);
	cv::pow(ch[2], 2-value, ch[2]);
	merge(ch, 3, im);
	cvtColor(im, out, COLOR_BGR2HSV);
	split(out, ch);
	cv::pow(ch[1], value, ch[1]);
	merge(ch, 3, im);
	cvtColor(im, out, COLOR_HSV2BGR);
	return out;
}


Mat Vignette(Mat im, int value)
{
	auto kernel_x = getGaussianKernel(im.cols, value, CV_32FC1);
	transpose(kernel_x, kernel_x);
	auto kernel_y = getGaussianKernel(im.rows, value, CV_32FC1);
	Mat kernel = kernel_y * kernel_x;
	normalize(kernel, kernel);
	double min, max;
	minMaxLoc(kernel, &min, &max);
	kernel = kernel / max;
	Mat ch[3];
	split(im, ch);
	for(auto i = 0; i<3; i++)
	{
		multiply(ch[i], kernel, ch[i]);
	}
	merge(ch, 3, im);
	return im;
}

Mat ColorBalance(Mat im, double r, double g, double b)
{
	Mat out;
	Mat ch[3];
	split(im, ch);
	double col[3];
	col[2] = r - g / 4 - b / 4;
	col[1] = g - r / 4 - b / 4;
	col[0] = b - r / 4 - g / 4;
	for(auto i=0;i<3;i++)
	{
		ch[i] += col[i];
	}
	merge(ch, 3, out);
	return out;
}

Mat AutoCorrect(Mat im, double lim, int sz)
{
	Mat out;
	Mat ch[3];
	split(im, ch);
	for(auto i=0;i<3;i++)
	{
		//createCLAHE(lim, Size(sz, sz))->apply(ch[i], ch[i]);
		equalizeHist(ch[i], ch[i]);
	}
	merge(ch, 3, out);
	return out;
}

Mat BrightnessAndContrastAuto(Mat src, double clipHistPercent)
{
	auto histSize = 256;
	float alpha, beta;
	double minGray = 255, maxGray = 0;

	//to calculate grayscale histogram
	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);
	if (clipHistPercent == 0)
	{
		cv::minMaxLoc(gray, &minGray, &maxGray);
	}
	else
	{
		Mat hist; //the grayscale histogram

		float range[] = { 0, 256 };
		const float* histRange = { range };
		auto uniform = true;
		auto accumulate = false;
		calcHist(&gray, 1, nullptr, Mat(), hist, 1, &histSize, &histRange, uniform, accumulate);

		// calculate cumulative distribution from the histogram
		std::vector<float> accumulator(histSize);
		accumulator[0] = hist.at<float>(0);
		for (auto i = 1; i < histSize; i++)
		{
			accumulator[i] = accumulator[i - 1] + hist.at<float>(i);
		}

		// locate points that cuts at required value
		auto max = accumulator.back();
		clipHistPercent *= (max / 100.0); //make percent as absolute
		clipHistPercent /= 2.0; // left and right wings
								// locate left cut
		minGray = 0;
		while (accumulator[minGray] < clipHistPercent)
			minGray++;

		// locate right cut
		maxGray = histSize - 1;
		while (accumulator[maxGray] >= (max - clipHistPercent))
			maxGray--;
	}

	// current range
	auto inputRange = maxGray - minGray;

	alpha = static_cast<float>(histSize - 1) / inputRange;   // alpha expands current range to histsize range
	beta = static_cast<float>(-minGray * alpha);             // beta shifts current range so that minGray will go to 0

										 // Apply brightness and contrast normalization
										 // convertTo operates with saurate_cast
	Mat dst;
	src.convertTo(dst, -1, alpha, beta);

	// restore alpha channel from source 
	if (dst.type() == CV_8UC4)
	{
		int from_to[] = { 3, 3 };
		cv::mixChannels(&src, 4, &dst, 1, from_to, 1);
	}
	return dst;
}
