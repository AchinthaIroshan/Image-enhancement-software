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
			cli::array<double>^ variableValues = gcnew cli::array<double>(3);
			System::Void Update1(ControllerModel^ controllerModel);
			System::Void Update2(ControllerModel^ controllerModel);
			System::Void Update3(ControllerModel^ controllerModel);


		public:
			property double Val[int]{
				double get(int index);
				void set(int index, double value);
			}

			FilterModel(int functionType, double var1, double var2, double var3);
			cv::Mat PerformAction(cv::Mat im);
			FilterModel^ FormatObject(System::String^ label);
			System::Void UpdateView(ControllerModel^ controllerModel, int index);


		};

	}
}
