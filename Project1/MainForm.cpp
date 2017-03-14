#include "MainForm.h"
#include <msclr\marshal_cppstd.h>
#include <iostream>

namespace pes {
	namespace view {
		using namespace cv;

		Mat im;
		Mat im2;

		System::Void MainForm::DrawCvImage(const Mat cvImage)
		{
			// only color images are supported
			assert(cvImage.type() == CV_8UC3);

			if ((pictureBox->Image == nullptr) || (pictureBox->Width != cvImage.cols) || (pictureBox->Height != cvImage.rows))
			{
				pictureBox->Width = cvImage.cols;
				pictureBox->Height = cvImage.rows;
				pictureBox->Image = gcnew System::Drawing::Bitmap(cvImage.cols, cvImage.rows);
			}

			// Create System::Drawing::Bitmap from cv::Mat
			System::Drawing::Bitmap^ bmpImage = gcnew Bitmap(
				cvImage.cols, cvImage.rows, cvImage.step,
				System::Drawing::Imaging::PixelFormat::Format24bppRgb,
				System::IntPtr(cvImage.data)
			);

			// Draw Bitmap over a PictureBox
			Graphics^ g = Graphics::FromImage(pictureBox->Image);

			g->DrawImage(bmpImage, 0, 0, cvImage.cols, cvImage.rows);
			pictureBox->Refresh();

			delete g;
		}

		System::Void MainForm::openButton_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				im = imread(msclr::interop::marshal_as<std::string>(openFileDialog->FileName), IMREAD_COLOR);
				if (!im.data) // Check for invalid input
				{
					MessageBox::Show(this, "Cannot open or find the image!!", "Open Image - PES", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return System::Void();
				}
			}
			im2 = im.clone();
			DrawCvImage(im);
		}


		System::Void MainForm::originalImageCheckBox_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
		{
			if(originalImageCheckBox->Checked)
			{
				DrawCvImage(im);
			}else
			{
				DrawCvImage(im2);
			}
		}
	}
}
