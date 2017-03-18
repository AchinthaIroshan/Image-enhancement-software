#include "Lib.h"

namespace pes {
	namespace library {

		Lib::Lib()
		{
		}


		Lib::~Lib()
		{
		}

		Mat Lib::GetSharpenImage(Mat im, int value_in, float sigma) // -100 <= value_in <=100
		{
			double value = value_in / 100.0;
			CV_Assert(im.type() == CV_32FC3);
			Mat out;
			GaussianBlur(im, out, Size(0, 0), sigma, sigma);
			addWeighted(im, 1 + value, out, -value, 0, out);
			return out;
		}

		Mat Lib::AdjustTemperature(Mat im, int value_in) // -100 <= value_in <=100
		{
			double value = value_in / 170.0 + 1.0;
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

		Mat Lib::Vignette(Mat im_in, int value_in) // 0 <= value_in <=100
		{
			Mat im = im_in;
			int value = 1200 - 10 * value_in;
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

		Mat Lib::ColorBalance(Mat im, int r_in, int g_in, int b_in) // -100 <= value_in <=100
		{
			double r = r_in / 180.0, g = g_in / 180.0, b = b_in / 180.0;
			CV_Assert(im.type() == CV_32FC3);
			CV_Assert(r >= -1 && r <= 1);
			CV_Assert(g >= -1 && g <= 1);
			CV_Assert(b >= -1 && b <= 1);
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

		/*Mat Lib::AutoCorrect(Mat im, int lim_in, int sz_in)
		{
			double lim;
			int sz;
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
		}*/

		Mat Lib::BrightnessAndContrastAuto(Mat src, double clipHistPercent)
		{
			CV_Assert(clipHistPercent >= 0);
			src.convertTo(src, CV_8UC3, 255.0);
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
			dst.convertTo(dst, CV_32FC3, 1.0 / 255.0);
			return dst;
		}

		Mat Lib::ShadowRecovery(Mat input_image, int value_in) // - 100 <= value_in <= 100
		{
			double alpha = (value_in) / 100.0;
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

		Mat Lib::HighlightRecovery(Mat input_image, int value_in)  // - 100 <= value_in <= 100
		{
			double alpha = (value_in) / 100.0;
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
			/*			if (_height > src.rows)
						{
							_height = src.rows;
						}

						if (_width > src.cols)
						{
							_width = src.cols;
						}*/

			return src(cv::Rect(topLeft, cv::Size(_height, _width)));
		}

		Mat Lib::ContrastAdjustment(Mat src, int value_in) // -100 <= value_in <= 100
		{
			return ((value_in + 100) / 100.0) * src;
		}

		Mat Lib::SaturationAdjustment(Mat src, int value_in) // - 100 <= value_in <= 100
		{
			double value = (value_in) / 100.0;
			cv::Mat HSV_Image;
			cv::cvtColor(src, HSV_Image, CV_BGR2HSV);
			vector<Mat> channels(3);
			cv::split(HSV_Image, channels);
			channels.at(1) = value + channels.at(1);
			cv::Mat reconstructed_Image;
			cv::merge(channels, reconstructed_Image);
			cv::cvtColor(reconstructed_Image, reconstructed_Image, CV_HSV2BGR);
			return reconstructed_Image;
		}

		Mat Lib::noiseRed_NormalizedFilter(Mat src, int KernalSize) {
			Mat dst;
			int i = KernalSize/15 + 1;
			blur(src, dst, Size(i, i), Point(-1, -1));
			return dst;
		}

		Mat Lib::noiseRed_GaussianFilter(Mat src, int KernalSize) {
			Mat dst;
			int i = 2 * (KernalSize / 30) + 1;
			GaussianBlur(src, dst, Size(i, i), 0, 0);
			//sigma x and y : Writing 0 implies that sigma x and y is calculated using kernel size
			return dst;
		}

		Mat Lib::noiseRed_MedianFilter(Mat src, int KernalSize) {
			Mat dst;
			int i = 2 * (KernalSize / 30) + 3;
			medianBlur(src, dst, i);
			return dst;
		}

		Mat Lib::noiseRed_bilateralFilter(Mat src, int KernalSize) {
			Mat dst;
			double i = KernalSize / 15.0 + 1.0;
			bilateralFilter(src, dst, i, i * 2, i / 2);
			return dst;
		}

		Mat Lib::redHistogram(Mat src)
		{
			Mat bgr[3];
			split(src, bgr);
			Mat hist = Lib::histogram(bgr[2]);

			return hist;
		}

		Mat Lib::greenHistogram(Mat src)
		{
			Mat bgr[3];
			split(src, bgr);
			Mat hist = Lib::histogram(bgr[1]);

			return hist;
		}

		Mat Lib::blueHistogram(Mat src)
		{
			Mat bgr[3];
			split(src, bgr);
			Mat hist = Lib::histogram(bgr[0]);

			return hist;

		}

		Mat Lib::histogram(Mat src) {
			int histogram[256] = { 0 };

			for (int y = 0; y < src.rows; y++) {
				for (int x = 0; x < src.cols; x++) {
					histogram[(int)src.at<uchar>(y, x)]++;
				}
			}

			int hist_wd = 512;
			int hist_ht = 400;

			int bin_wd = cvRound((double)hist_wd / 256);

			Mat histIm(hist_ht, hist_wd, CV_8UC1, Scalar(255, 255, 255));

			int max = histogram[0];

			for (int i = 0; i < 255; i++) {
				if (histogram[i] > max) {
					max = histogram[i];
				}
			}

			//normalize the histogrm values from 0 to number of rows

			for (int i = 0; i < 255; i++) {
				histogram[i] = ((double)histogram[i] / max)*src.rows;
			}

			for (int i = 0; i < 255; i++) {
				line(histIm, Point(bin_wd*(i), hist_ht), Point(bin_wd*(i), hist_ht - histogram[i]), Scalar(0, 0, 0));
			}

			return histIm;


		}

		Mat Lib::rgbHistogram(Mat src) {

			Mat gryScale;
			cvtColor(src, gryScale, CV_RGB2GRAY);
			Mat hist = Lib::histogram(gryScale);
			return hist;
		}

		Mat Lib::ExposureAdjustment(Mat src, int value_in) // 0 <= value_in <= 100
		{
			double value = (value_in) / 100.0;
			cv::Mat HLS_Image;
			cv::cvtColor(src, HLS_Image, CV_BGR2HLS);
			vector<Mat> channels(3);
			cv::split(HLS_Image, channels);
			channels.at(1) = channels.at(1) * pow(2, value);
			cv::Mat reconstructed_Image;
			cv::merge(channels, reconstructed_Image);
			cv::cvtColor(reconstructed_Image, reconstructed_Image, CV_HLS2BGR);
			return reconstructed_Image;
		}

		double Lib::CalculateColorTemperature(Mat src) // 0 <= value_in <= 100
		{
			cv::Mat XYZ_Image;
			cv::cvtColor(src, XYZ_Image, CV_BGR2XYZ);
			vector<Mat> channels(3);
			cv::split(XYZ_Image, channels);
			Mat sum = channels.at(0) + channels.at(1) + channels.at(2);
			Mat x; divide(channels.at(0), sum, x); x = x - 0.3320;
			Mat y; divide(channels.at(1), sum, y); y = 0.1858 - y;
			Mat n; divide(x, y, n);
			Mat n3, n2; cv::pow(n, 3, n3); cv::pow(n, 2, n2);
			Mat CCT = 449 * n3 + 3525 * n2 + 6823.3 * n + 5520.33;
			double min, max; cv::minMaxLoc(CCT, &min, &max);
			return (min + max) / 2;
		}

		System::String^ Lib::metaData(System::String^ address) {

			System::Drawing::Image^ image = gcnew System::Drawing::Bitmap(address);

			cli::array<System::Drawing::Imaging::PropertyItem^>^ propItems = image->PropertyItems;


			int count = 0;

			System::Collections::IEnumerator^ pEnum = propItems->GetEnumerator();

			System::String^ metaData = "Meta data of the image \n";

			while (pEnum->MoveNext()) {

				System::Drawing::Imaging::PropertyItem^ propItem = safe_cast<System::Drawing::Imaging::PropertyItem^>(pEnum->Current);


				System::String^ propItemNum = System::String::Format("Property Item {0} \n", count);

				metaData = System::String::Concat(metaData, propItemNum);

				System::String^ propID = System::String::Format("   ID: 0x{0} \n", propItem->Id.ToString("x"));

				metaData = System::String::Concat(metaData, propID);

				System::String^ proptype = System::String::Format("   type: {0} \n", propItem->Type);
				metaData = System::String::Concat(metaData, proptype);

				System::String^ proplength = System::String::Format("   length: {0} bytes \n", propItem->Len);

				metaData = System::String::Concat(metaData, proplength);

				count += 1;

			}
			return metaData;

		}
	}
}

