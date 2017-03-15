#include "ControllerModel.h"

namespace pes {
	namespace model {

		ControllerModel::ControllerModel(
				System::Windows::Forms::Label^ label1,
				System::Windows::Forms::Label^ infoLabel1,
				System::Windows::Forms::Label^ label2,
				System::Windows::Forms::Label^ infoLabel2,
				System::Windows::Forms::Label^ label3,
				System::Windows::Forms::Label^ infoLabel3,
				System::Windows::Forms::TrackBar^ label1TrackerBar,
				System::Windows::Forms::TrackBar^ label2TrackerBar,
				System::Windows::Forms::TrackBar^ label3TrackerBar)
			{
				this->label1 = label1;
				this->label2 = label2;
				this->label3 = label3;

				this->infoLabel1 = infoLabel1;
				this->infoLabel2 = infoLabel2;
				this->infoLabel3 = infoLabel3;

				this->label1TrackerBar = label1TrackerBar;
				this->label2TrackerBar = label2TrackerBar;
				this->label3TrackerBar = label3TrackerBar;
			}
	}
}

