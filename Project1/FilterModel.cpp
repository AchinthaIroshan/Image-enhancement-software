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
			case 0:
				break;
			}
		}

		System::Void FilterModel::Update2(ControllerModel ^ controllerModel)
		{
			Val[1] = controllerModel->label2TrackerBar->Value;
			switch (functionType)
			{
			}
		}

		System::Void FilterModel::Update3(ControllerModel ^ controllerModel)
		{
			Val[2] = controllerModel->label3TrackerBar->Value;
			switch (functionType)
			{
			}
		}

		System::Void FilterModel::Initialize1(ControllerModel ^ controllerModel)
		{
			switch (functionType)
			{
			case 0:
				controllerModel->label1->Text = "Value: ";
				controllerModel->infoLabel1->Text = "";
				controllerModel->label1TrackerBar->Minimum = -100;
				controllerModel->label1TrackerBar->Maximum = 100;
				controllerModel->label1TrackerBar->Value = variableValues[0];
				controllerModel->Visible(1);
				break;
			}
		}

		System::Void FilterModel::Initialize2(ControllerModel ^ controllerModel)
		{
			return System::Void();
		}

		System::Void FilterModel::Initialize3(ControllerModel ^ controllerModel)
		{
			return System::Void();
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
				controllerModel->label2TrackerBar->Value = variableValues[1];
				controllerModel->label3TrackerBar->Value = variableValues[2];
				break;
			}
		}

		System::String ^ FilterModel::ToString()
		{
			switch(functionType)
			{
			case 0:
				return "Temperature Adjustment";
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

