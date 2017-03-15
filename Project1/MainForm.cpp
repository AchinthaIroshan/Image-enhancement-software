#include "MainForm.h"
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include "Lib.h"
#include "FilterModel.h"

namespace pes {
	namespace view {
		using namespace cv;
		using namespace pes::library;
		using namespace pes::model;

		Mat im;
		Mat im2;

		System::Void MainForm::DrawCvImage(const Mat im_)
		{
			// only color images are supported
			Mat cvImage;
			if(im_.type() == CV_8UC3)
			{
				cvImage = im_;
			}else
			{
				im_.convertTo(cvImage, CV_8UC3, 255.0);
			}

			if ((pictureBox->Image == nullptr) || (pictureBox->Width != cvImage.cols) || (pictureBox->Height != cvImage.rows))
			{
				pictureBox->Width = cvImage.cols;
				pictureBox->Height = cvImage.rows;
				pictureBox->Image = gcnew System::Drawing::Bitmap(cvImage.cols, cvImage.rows);
				pictureBox->Left = (this->splitContainer1->Panel1->Width - pictureBox->Width) / 2;
				pictureBox->Top = (this->splitContainer1->Panel1->Height - pictureBox->Height) / 2;
			}

			// Create System::Drawing::Bitmap from cv::Mat
			System::Drawing::Bitmap^ bmpImage = gcnew Bitmap(
				cvImage.cols, cvImage.rows, cvImage.step,
				System::Drawing::Imaging::PixelFormat::Format24bppRgb,
				System::IntPtr(cvImage.data)
			);

			DrawHist(cvImage);

			// Draw Bitmap over a PictureBox
			Graphics^ g = Graphics::FromImage(pictureBox->Image);

			g->DrawImage(bmpImage, 0, 0, cvImage.cols, cvImage.rows);
			pictureBox->Refresh();

			delete g;
		}

		System::Void MainForm::DrawHist(const cv::Mat im__)
		{
			Mat cvImage;
			Mat im_;
			if (im__.type() == CV_8UC3)
			{
				im_ = im__;
			}
			else
			{
				im__.convertTo(im_, CV_8UC3, 255.0);
			}
			if(rRadioButton->Checked)
			{
				cvImage = Lib::redHistogram(im_);
			}else if(gRadioButton->Checked)
			{
				cvImage = Lib::greenHistogram(im_);
			}else if(bRadioButton->Checked)
			{
				cvImage = Lib::blueHistogram(im_);
			}
			resize(cvImage, cvImage, cv::Size(760, 230));
			if ((histPictureBox->Image == nullptr) || (histPictureBox->Width != cvImage.cols) || (histPictureBox->Height != cvImage.rows))
			{
				histPictureBox->Width = cvImage.cols;
				histPictureBox->Height = cvImage.rows;
				histPictureBox->Image = gcnew System::Drawing::Bitmap(cvImage.cols, cvImage.rows);
				histPictureBox->Left = (this->histPanel->Width - histPictureBox->Width) / 2;
				histPictureBox->Top = (this->histPanel->Height - histPictureBox->Height) / 2;
			}

			// Create System::Drawing::Bitmap from cv::Mat
			System::Drawing::Bitmap^ bmpImage = gcnew Bitmap(
				cvImage.cols, cvImage.rows, cvImage.step,
				System::Drawing::Imaging::PixelFormat::Format8bppIndexed,
				System::IntPtr(cvImage.data)
			);

			// Draw Bitmap over a histPictureBox
			Graphics^ g = Graphics::FromImage(histPictureBox->Image);

			g->DrawImage(bmpImage, 0, 0, cvImage.cols, cvImage.rows);
			histPictureBox->Refresh();

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
				im.convertTo(im, CV_32FC3, 1.0 / 255.0);
				im2 = im.clone();
				DrawCvImage(im);
			}
		}


		System::Void MainForm::originalImageCheckBox_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
		{
			if (originalImageCheckBox->Checked)
			{
				DrawCvImage(im);
			}
			else
			{
				DrawCvImage(im2);
			}
		}


		System::Void MainForm::cropImageToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			if (cropImageToolStripMenuItem->BackColor == SystemColors::Control)
			{
				cropImageToolStripMenuItem->BackColor = SystemColors::ControlDark;
				pictureBox->Cursor = System::Windows::Forms::Cursors::Cross;
			}
			else
			{
				cropImageToolStripMenuItem->BackColor = SystemColors::Control;
				pictureBox->Cursor = System::Windows::Forms::Cursors::Arrow;
			}
		}

		System::Void MainForm::pictureBox_MouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
		{
			if (cropImageToolStripMenuItem->BackColor == SystemColors::ControlDark) {
				cropStart = e->Location;
				currentMouse = e->Location;
				isDragging = true;
			}
		}

		System::Void MainForm::pictureBox_MouseUp(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
		{
			if (cropImageToolStripMenuItem->BackColor == SystemColors::ControlDark) {
				isDragging = false;
				cropImageToolStripMenuItem_Click(nullptr, nullptr);
				im2 = Lib::Crop(im2.clone(), cv::Point(cropStart->X, cropStart->Y), Math::Abs(currentMouse->X - cropStart->X), Math::Abs(currentMouse->Y - cropStart->Y));
				DrawCvImage(im2);
			}
		}

		System::Void MainForm::pictureBox_MouseMove(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
		{
			if (cropImageToolStripMenuItem->BackColor == SystemColors::ControlDark && isDragging) {
				currentMouse = e->Location;
				pictureBox->Invalidate();
				pictureBox->Update();
			}
		}

		System::Void MainForm::pictureBox_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
		{
			if (cropImageToolStripMenuItem->BackColor == SystemColors::ControlDark && isDragging)
			{
				Pen^ p = gcnew Pen(Color::Black, 2);
				e->Graphics->DrawRectangle(p, cropStart->X, cropStart->Y, Math::Abs(currentMouse->X - cropStart->X), Math::Abs(currentMouse->Y - cropStart->Y));
			}
		}

		System::Void MainForm::adjustTempuratureToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
		{
			filterList->Items->Add(gcnew FilterModel(0, 1, 0, 0));
		}

		System::Void MainForm::filterList_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e)
		{
			selectedModel = static_cast<FilterModel^>(filterList->SelectedItem);
			selectedModel->InitializeView(controllerModel, 0);
		}

		System::Void MainForm::label1TrackBar_Scroll(System::Object ^ sender, System::EventArgs ^ e)
		{
			if(selectedModel)
			{
				selectedModel->UpdateView(controllerModel, 1);
				performFiltering();
			}
		}
		System::Void MainForm::label2TrackBar_Scroll(System::Object ^ sender, System::EventArgs ^ e)
		{
			if (selectedModel)
			{
				selectedModel->UpdateView(controllerModel, 2);
				performFiltering();
			}
		}
		System::Void MainForm::label3TrackBar_Scroll(System::Object ^ sender, System::EventArgs ^ e)
		{
			if (selectedModel)
			{
				selectedModel->UpdateView(controllerModel, 3);
				performFiltering();
			}
		}
		System::Void MainForm::performFiltering()
		{
			im2 = im.clone();
			for each(Object ^ obj in filterList->Items)
			{
				im2 = (static_cast<FilterModel ^>(obj))->PerformAction(im2);
			}
			DrawCvImage(im2);
		}
		System::Void MainForm::rgbRadioButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
		{
			if(im2.data) DrawHist(im2);
		}
		System::Void MainForm::rRadioButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
		{
			if (im2.data) DrawHist(im2);
		}
		System::Void MainForm::gRadioButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
		{
			if (im2.data) DrawHist(im2);
		}
		System::Void MainForm::bRadioButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
		{
			if (im2.data) DrawHist(im2);
		}
	}
}
