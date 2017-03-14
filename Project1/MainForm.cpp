#include "MainForm.h"
#include <msclr\marshal_cppstd.h>

namespace pes {
	namespace view {
		using namespace cv;

		System::Void MainForm::drawImage(Mat image)
		{
			System::Drawing::Graphics^ graphics = pictureBox->CreateGraphics();
			System::IntPtr ptr(image.ptr());
			System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(image.cols, image.rows, image.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			System::Drawing::RectangleF rect(0, 0, pictureBox->Width, pictureBox->Height);
			graphics->DrawImage(b, rect);
		}

		System::Void MainForm::openButton_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			if(!im)
			{
				delete im;
			}
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				Mat image = imread(msclr::interop::marshal_as<std::string>(openFileDialog->FileName), IMREAD_COLOR);
				if (image.data) // Check for invalid input
				{
					im = &image;
					namedWindow("input window", WINDOW_AUTOSIZE); // Create a window for display.
					imshow("input window", image); // Show our image inside it.
				}else
				{
					MessageBox::Show(this, "Cannot open or find the image!!", "Open Image - PES", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			if(im)
			{
				drawImage(*im);
			}
		}
	}
}
