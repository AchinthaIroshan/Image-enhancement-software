#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cmath>

#define UPPER_SHADOW_LEVEL 0.24
#define LOWER_SHADOW_LEVEL 0.05
#define UPPER_HIGHLIGHT_LEVEL 0.9999
#define LOWER_HIGHLIGHT_LEVEL 0.6500

namespace pes {
	namespace library {

		using namespace cv;
		using namespace std;

		class Lib
		{
		public:
			~Lib();
			static Mat GetSharpenImage(Mat im, int value, float sigma = 3);
			static Mat AdjustTemperature(Mat im, int value);
			static Mat Vignette(Mat im, int value = 200);
			static Mat ColorBalance(Mat im, int r, int g, int b);
			//static Mat AutoCorrect(Mat im, int lim = 2, int sz = 30);
			static Mat BrightnessAndContrastAuto(Mat src, double clipHistPercent = 1.5);
			static Mat ShadowRecovery(Mat input_image, int alpha);
			static Mat HighlightRecovery(Mat input_image, int alpha);
			static Mat ContrastAdjustment(Mat src, int value);
			static Mat SaturationAdjustment(Mat src, int value);
			static Mat ExposureAdjustment(Mat src, int value);

			static Mat histogram(Mat src);
			static Mat noiseRed_NormalizedFilter(Mat src, int KernalSize);
			static Mat noiseRed_GaussianFilter(Mat src, int KernalSize);
			static Mat noiseRed_MedianFilter(Mat src, int KernalSize);
			static Mat noiseRed_bilateralFilter(Mat src, int KernalSize);
			static Mat redHistogram(Mat src);
			static Mat greenHistogram(Mat src);
			static Mat blueHistogram(Mat src);
			static Mat rgbHistogram(Mat src);
		private:
			Lib();

		};

	}
}

