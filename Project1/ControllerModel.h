#pragma once

namespace pes {
	namespace model {

		public ref class ControllerModel
		{

		public:
			System::Windows::Forms::Label^ label1;
			System::Windows::Forms::Label^ infoLabel1;
			System::Windows::Forms::Label^ label2;
			System::Windows::Forms::Label^ infoLabel2;
			System::Windows::Forms::Label^ label3;
			System::Windows::Forms::Label^ infoLabel3;
			System::Windows::Forms::TrackBar^ label1TrackerBar;
			System::Windows::Forms::TrackBar^ label2TrackerBar;
			System::Windows::Forms::TrackBar^ label3TrackerBar;

			ControllerModel(
				System::Windows::Forms::Label^ label1,
				System::Windows::Forms::Label^ infoLabel1,
				System::Windows::Forms::Label^ label2,
				System::Windows::Forms::Label^ infoLabel2,
				System::Windows::Forms::Label^ label3,
				System::Windows::Forms::Label^ infoLabel3,
				System::Windows::Forms::TrackBar^ label1TrackerBar,
				System::Windows::Forms::TrackBar^ label2TrackerBar,
				System::Windows::Forms::TrackBar^ label3TrackerBar);
		};

	}
}
