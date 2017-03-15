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

		System::Void ControllerModel::HideAll()
		{
			label1->Visible = false;
			label2->Visible = false;
			label3->Visible = false;

			infoLabel1->Visible = false;
			infoLabel2->Visible = false;
			infoLabel3->Visible = false;

			label1TrackerBar->Visible = false;
			label2TrackerBar->Visible = false;
			label3TrackerBar->Visible = false;
		}

		System::Void ControllerModel::Visible(int no)
		{
			switch(no)
			{
			case 1:
				label1->Visible = true;
				infoLabel1->Visible = true;
				label1TrackerBar->Visible = true;
				break;
			case 2:
				label2->Visible = true;
				infoLabel2->Visible = true;
				label2TrackerBar->Visible = true;
				break;
			case 3:
				label3->Visible = true;
				infoLabel3->Visible = true;
				label3TrackerBar->Visible = true;
				break;
			}
		}
	}
}

