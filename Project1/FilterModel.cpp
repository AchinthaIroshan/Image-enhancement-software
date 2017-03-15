#include "FilterModel.h"
#include "Lib.h"

namespace pes {
	namespace model {

		using namespace pes::library;

		System::Void FilterModel::Update1(ControllerModel ^ controllerModel)
		{
			switch (functionType)
			{
			case 0:
				controllerModel->label1->Text = "Value: ";
				controllerModel->label1TrackerBar->Minimum = -100;
				controllerModel->label1TrackerBar->Maximum = 100;
				controllerModel->label1TrackerBar->Value = 0;
				controllerModel->label1->Visible = true;
				controllerModel->label1TrackerBar->Visible = true;
				break;
			}
		}

		System::Void FilterModel::Update2(ControllerModel ^ controllerModel)
		{
			switch (functionType)
			{
			}
		}

		System::Void FilterModel::Update3(ControllerModel ^ controllerModel)
		{
			return System::Void();
		}

		FilterModel::FilterModel(int functionType, double var1, double var2, double var3)
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
			default:
				return cv::Mat();
			}
		}

		FilterModel^ FilterModel::FormatObject(System::String ^ label)
		{
			cli::array<System::String^> ^text = label->Split(';');
			int functionType = System::Int32::Parse(text[0]);
			double var1 = System::Double::Parse(text[1]);
			double var2 = System::Double::Parse(text[2]);
			double var3 = System::Double::Parse(text[3]);
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
				controllerModel->label1->Text = "";
				controllerModel->label2->Text = "";
				controllerModel->label3->Text = "";
				controllerModel->infoLabel1->Text = "";
				controllerModel->infoLabel2->Text = "";
				controllerModel->infoLabel3->Text = "";
				Update1(controllerModel);
				Update2(controllerModel);
				Update3(controllerModel);
				controllerModel->label1TrackerBar->Value = variableValues[0];
				controllerModel->label2TrackerBar->Value = variableValues[1];
				controllerModel->label3TrackerBar->Value = variableValues[2];
			}
		}

		double FilterModel::Val::get(int index)
		{
			return variableValues[index];
		}

		void FilterModel::Val::set(int index, double value)
		{
			variableValues[index] = value;
		}

	}
}

