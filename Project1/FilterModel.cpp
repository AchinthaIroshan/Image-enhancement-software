#include "FilterModel.h"
#include "Lib.h"

namespace pes {
	namespace model {

		using namespace pes::library;

		System::Void FilterModel::Update1(ControllerModel ^ controllerModel)
		{
			Val[0] = controllerModel->label1TrackerBar->Value;
			switch (functionType)
			{
			case 2:
			case 4:
			case 5:
				controllerModel->infoLabel1->Text = Val[0].ToString();
				break;
			}
		}

		System::Void FilterModel::Update2(ControllerModel ^ controllerModel)
		{
			Val[1] = controllerModel->label2TrackerBar->Value;
			switch (functionType)
			{
			case 2:
				controllerModel->infoLabel2->Text = Val[1].ToString();
				break;
			}
		}

		System::Void FilterModel::Update3(ControllerModel ^ controllerModel)
		{
			Val[2] = controllerModel->label3TrackerBar->Value;
			switch (functionType)
			{
			case 2:
				controllerModel->infoLabel3->Text = Val[2].ToString();
				break;
			}
		}

		System::Void FilterModel::Initialize1(ControllerModel ^ controllerModel)
		{
			switch (functionType)
			{
			case 0:
			case 6:
			case 7:
			case 8:
				controllerModel->label1->Text = "Value: ";
				controllerModel->infoLabel1->Text = "";
				controllerModel->label1TrackerBar->Minimum = -100;
				controllerModel->label1TrackerBar->Maximum = 100;
				controllerModel->label1TrackerBar->Value = variableValues[0];
				controllerModel->Visible(1);
				break;
			case 1:
				controllerModel->label1->Text = "Value: ";
				controllerModel->infoLabel1->Text = "";
				controllerModel->label1TrackerBar->Minimum = 0;
				controllerModel->label1TrackerBar->Maximum = 100;
				controllerModel->label1TrackerBar->Value = variableValues[0];
				controllerModel->Visible(1);
				break;
			case 2:
				controllerModel->label1->Text = "Red: ";
				controllerModel->infoLabel1->Text = Val[0].ToString();
				controllerModel->label1TrackerBar->Minimum = -100;
				controllerModel->label1TrackerBar->Maximum = 100;
				controllerModel->label1TrackerBar->Value = variableValues[0];
				controllerModel->Visible(1);
				break;
			case 4:
			case 5:
				controllerModel->label1->Text = "Alpha: ";
				controllerModel->infoLabel1->Text = Val[0].ToString();
				controllerModel->label1TrackerBar->Minimum = -100;
				controllerModel->label1TrackerBar->Maximum = 100;
				controllerModel->label1TrackerBar->Value = variableValues[0];
				controllerModel->Visible(1);
				break;
			}
		}

		System::Void FilterModel::Initialize2(ControllerModel ^ controllerModel)
		{
			switch (functionType)
			{
			case 2:
				controllerModel->label2->Text = "Green: ";
				controllerModel->infoLabel2->Text = Val[1].ToString();
				controllerModel->label2TrackerBar->Minimum = -100;
				controllerModel->label2TrackerBar->Maximum = 100;
				controllerModel->label2TrackerBar->Value = variableValues[1];
				controllerModel->Visible(2);
				break;
			}
		}

		System::Void FilterModel::Initialize3(ControllerModel ^ controllerModel)
		{
			switch (functionType)
			{
			case 2:
				controllerModel->label3->Text = "Blue: ";
				controllerModel->infoLabel3->Text = Val[2].ToString();
				controllerModel->label3TrackerBar->Minimum = -100;
				controllerModel->label3TrackerBar->Maximum = 100;
				controllerModel->label3TrackerBar->Value = variableValues[2];
				controllerModel->Visible(3);
				break;
			}
		}

		FilterModel::FilterModel(int functionType, int var1, int var2, int var3)
		{
			this->functionType = functionType;
			variableValues[0] = var1;
			variableValues[1] = var2;
			variableValues[2] = var3;
		}

		cv::Mat FilterModel::PerformAction(cv::Mat im)
		{
			switch (functionType)
			{
			case 0:
				return Lib::AdjustTemperature(im, variableValues[0]);
			case 1:
				return Lib::Vignette(im, variableValues[0]);
			case 2:
				return Lib::ColorBalance(im, variableValues[0], variableValues[1], variableValues[2]);
			case 3:
				return Lib::BrightnessAndContrastAuto(im);
			case 4:
				return Lib::ShadowRecovery(im, variableValues[0]);
			case 5:
				return Lib::HighlightRecovery(im, variableValues[0]);
			case 6:
				return Lib::ContrastAdjustment(im, variableValues[0]);
			case 7:
				return Lib::SaturationAdjustment(im, variableValues[0]);
			case 8:
				return Lib::ExposureAdjustment(im, variableValues[0]);
			default:
				return cv::Mat();
			}
		}

		FilterModel^ FilterModel::FormatObject(System::String ^ label)
		{
			cli::array<System::String^> ^text = label->Split(';');
			int functionType = System::Int32::Parse(text[0]);
			int var1 = System::Int32::Parse(text[1]);
			int var2 = System::Int32::Parse(text[2]);
			int var3 = System::Int32::Parse(text[3]);
			return gcnew FilterModel(functionType, var1, var2, var3);
		}

		System::Void FilterModel::UpdateView(ControllerModel ^ controllerModel, int index)
		{
			switch (index)
			{
			case 1:
				Update1(controllerModel);
				break;
			case 2:
				Update2(controllerModel);
				break;
			case 3:
				Update3(controllerModel);
				break;
			default:
				Update1(controllerModel);
				Update2(controllerModel);
				Update3(controllerModel);
				controllerModel->label1TrackerBar->Value = variableValues[0];
				controllerModel->label2TrackerBar->Value = variableValues[1];
				controllerModel->label3TrackerBar->Value = variableValues[2];
				break;
			}
		}

		System::Void FilterModel::InitializeView(ControllerModel ^ controllerModel, int index)
		{
			controllerModel->HideAll();
			switch (index)
			{
			case 1:
				Initialize1(controllerModel);
				break;
			case 2:
				Initialize2(controllerModel);
				break;
			case 3:
				Initialize3(controllerModel);
				break;
			default:
				Initialize1(controllerModel);
				Initialize2(controllerModel);
				Initialize3(controllerModel);
				break;
			}
		}

		System::String ^ FilterModel::ToString()
		{
			switch(functionType)
			{
			case 0:
				return "Temperature Adjustment";
			case 1:
				return "Vignette";
			case 2:
				return "Color Balance";
			case 3:
				return "Auto Correction";
			case 4:
				return "Shadow Recovery";
			case 5:
				return "Highlight Recovery";
			case 6:
				return "Contrast Adjustment";
			case 7:
				return "Saturation Adjustment";
			case 8: 
				return "Exposure Adjustment";
			default:
				return "Not Implemented!!!";
			}
		}

		int FilterModel::Val::get(int index)
		{
			return variableValues[index];
		}

		void FilterModel::Val::set(int index, int value)
		{
			variableValues[index] = value;
		}

	}
}

// Change this to add a filter:
/*
 * Update
 * Initialize
 * Perform Action
 * To String
 */
