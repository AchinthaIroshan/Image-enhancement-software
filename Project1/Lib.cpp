#include "Lib.h"

namespace pes {
	namespace library {

		Lib::Lib()
		{
		}


		Lib::~Lib()
		{
		}

		Mat Lib::GetSharpenImage(Mat im, float value, float sigma)
		{
			CV_Assert(im.type() == CV_32FC3);
			Mat out;
			GaussianBlur(im, out, Size(0, 0), sigma, sigma);
			addWeighted(im, 1 + value, out, -value, 0, out);
			return out;
		}

		Mat Lib::AdjustTemperature(Mat im, double value)
		{
			CV_Assert(im.type() == CV_32FC3);
			CV_Assert(value >= 0 && value <= 2);
			Mat out;
			Mat ch[3];
			split(im, ch);
			pow(ch[0], value, ch[0]);
			pow(ch[2], 2 - value, ch[2]);
			merge(ch, 3, im);
			cvtColor(im, out, COLOR_BGR2HSV);
			split(out, ch);
			pow(ch[1], value, ch[1]);
			merge(ch, 3, im);
			cvtColor(im, out, COLOR_HSV2BGR);
			return out;
		}

		Mat Lib::Vignette(Mat im, int value)
		{
			CV_Assert(im.type() == CV_32FC3);
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
			for (auto i = 0; i < 3; i++)
			{
				multiply(ch[i], kernel, ch[i]);
			}
			merge(ch, 3, im);
			return im;
		}

		Mat Lib::ColorBalance(Mat im, double r, double g, double b)
		{
			CV_Assert(im.type() == CV_32FC3);
			CV_Assert(r >= 0 && r <= 1);
			CV_Assert(g >= 0 && g <= 1);
			CV_Assert(b >= 0 && b <= 1);
			Mat out;
			Mat ch[3];
			split(im, ch);
			double col[3];
			col[2] = r - g / 4 - b / 4;
			col[1] = g - r / 4 - b / 4;
			col[0] = b - r / 4 - g / 4;
			for (auto i = 0; i < 3; i++)
			{
				ch[i] += col[i];
			}
			merge(ch, 3, out);
			return out;
		}

		Mat Lib::AutoCorrect(Mat im, double lim, int sz)
		{
			CV_Assert(im.type() == CV_8UC3);
			Mat out;
			Mat ch[3];
			split(im, ch);
			for (auto i = 0; i < 3; i++)
			{
				//createCLAHE(lim, Size(sz, sz))->apply(ch[i], ch[i]);
				equalizeHist(ch[i], ch[i]);
			}
			merge(ch, 3, out);
			return out;
		}

		Mat Lib::BrightnessAndContrastAuto(Mat src, double clipHistPercent)
		{
			CV_Assert(clipHistPercent >= 0);
			CV_Assert(src.type() == CV_8UC3);

			auto histSize = 256;
			float alpha, beta;
			double minGray = 255, maxGray = 0;

			//to calculate grayscale histogram
			Mat gray;
			cvtColor(src, gray, CV_BGR2GRAY);
			if (clipHistPercent == 0)
			{
				minMaxLoc(gray, &minGray, &maxGray);
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
				while (accumulator[static_cast<unsigned __int64>(minGray)] < clipHistPercent)
					minGray++;

				// locate right cut
				maxGray = histSize - 1;
				while (accumulator[static_cast<unsigned __int64>(maxGray)] >= (max - clipHistPercent))
					maxGray--;
			}

			// current range
			auto inputRange = maxGray - minGray;

			alpha = static_cast<float>((histSize - 1) / inputRange);   // alpha expands current range to histsize range
			beta = static_cast<float>(-minGray * alpha);             // beta shifts current range so that minGray will go to 0

																	 // Apply brightness and contrast normalization
																	 // convertTo operates with saurate_cast
			Mat dst;
			src.convertTo(dst, -1, alpha, beta);

			// restore alpha channel from source 
			if (dst.type() == CV_8UC4)
			{
				int from_to[] = { 3, 3 };
				mixChannels(&src, 4, &dst, 1, from_to, 1);
			}
			return dst;
		}

		Mat Lib::ShadowRecovery(Mat input_image, double alpha)  // Input is 32 bit floating array
		{
			Mat modifier;
			cvtColor(input_image, modifier, CV_BGR2GRAY);  // Take Gray image
			Mat thresholdedImageUp;
			threshold(modifier, thresholdedImageUp, LOWER_SHADOW_LEVEL, 1.0, THRESH_TOZERO); // Treshold - up
			Mat thresholdedImageDown;
			threshold(thresholdedImageUp, thresholdedImageDown, UPPER_SHADOW_LEVEL, 1.0, THRESH_TOZERO_INV); // Treshold - down
			Mat tripleChannelAdder;
			cvtColor(thresholdedImageDown, tripleChannelAdder, CV_GRAY2BGR);
			return (input_image + alpha * tripleChannelAdder);
		}

		Mat Lib::HighlightRecovery(Mat input_image, double alpha)  // Input is 32 bit floating array
		{
			Mat modifier;
			cvtColor(input_image, modifier, CV_BGR2GRAY);  // Take Gray image
			Mat thresholdedImageUp;
			threshold(modifier, thresholdedImageUp, LOWER_HIGHLIGHT_LEVEL, 1.0, THRESH_TOZERO); // Treshold - up
			Mat thresholdedImageDown;
			threshold(thresholdedImageUp, thresholdedImageDown, UPPER_HIGHLIGHT_LEVEL, 1.0, THRESH_TOZERO_INV); // Treshold - down
			Mat tripleChannelAdder;
			cvtColor(thresholdedImageDown, tripleChannelAdder, CV_GRAY2BGR);
			return (input_image + alpha * tripleChannelAdder);
		}

		Mat Lib::Crop(Mat src, cv::Point topLeft, double _height, double _width)
		{
			return src(cv::Rect(topLeft, cv::Size(_height, _width)));
		}

		Mat Lib::ContrastAdjustment(Mat src, double value)
		{
			return value * src;
		}
	}
}

