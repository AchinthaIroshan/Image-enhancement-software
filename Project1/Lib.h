#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

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
			static Mat GetSharpenImage(Mat im, float value, float sigma);
			static Mat AdjustTemperature(Mat im, double value);
			static Mat Vignette(Mat im, int value = 200);
			static Mat ColorBalance(Mat im, double r, double g, double b);
			static Mat AutoCorrect(Mat im, double lim = 2, int sz = 30);
			static Mat BrightnessAndContrastAuto(Mat src, double clipHistPercent = 0);
			static Mat shadowRecovery(Mat input_image, double alpha);
			static Mat highlightRecovery(Mat input_image, double alpha);
		private:
			Lib();

		};

	}
}

