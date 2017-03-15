#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "ControllerModel.h"


namespace pes {
	namespace model {


		public ref class FilterModel
		{
		private:
			int functionType;
			cli::array<int>^ variableValues = gcnew cli::array<int>(3);
			System::Void Update1(ControllerModel^ controllerModel);
			System::Void Update2(ControllerModel^ controllerModel);
			System::Void Update3(ControllerModel^ controllerModel);
			System::Void Initialize1(ControllerModel^ controllerModel);
			System::Void Initialize2(ControllerModel^ controllerModel);
			System::Void Initialize3(ControllerModel^ controllerModel);


		public:
			property int Val[int]{
				int get(int index);
				void set(int index, int value);
			}

			FilterModel(int functionType, int var1, int var2, int var3);
			cv::Mat PerformAction(cv::Mat im);
			FilterModel^ FormatObject(System::String^ label);
			System::Void UpdateView(ControllerModel^ controllerModel, int index);
			System::Void InitializeView(ControllerModel^ controllerModel, int index);
			virtual System::String^ ToString() override;

		};

	}
}
