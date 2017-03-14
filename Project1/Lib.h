#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace library {

	using namespace cv;
	using namespace std;

	class Lib
	{
	public:
		~Lib();
		static Mat GetSharpenImage(Mat im, float value, float sigma);
		static Mat AdjustTemperature(Mat im, double value);
		static Mat Vignette(Mat im, int value = 200);
		static Mat ColorBalance(Mat im, double r, double g, double b);
		static Mat AutoCorrect(Mat im, double lim = 2, int sz = 30);
		static Mat BrightnessAndContrastAuto(Mat src, double clipHistPercent = 0);
	private:
		Lib();

	};

}

