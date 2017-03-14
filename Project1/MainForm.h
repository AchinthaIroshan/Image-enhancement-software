#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace pes {
	namespace view {

		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;

		/// <summary>
		/// Summary for MainForm
		/// </summary>
		public ref class MainForm : public System::Windows::Forms::Form
		{
		public:
			MainForm(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~MainForm()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::PictureBox^  pictureBox;
		protected:

		private: System::Windows::Forms::GroupBox^  groupBox1;
		private: System::Windows::Forms::Button^  openButton;
		private: System::Windows::Forms::GroupBox^  groupBox2;
		private: System::Windows::Forms::Button^  saveButton;

		private: System::Windows::Forms::SplitContainer^  splitContainer1;
		private: System::Windows::Forms::CheckBox^  originalImageCheckBox;
		private: System::Windows::Forms::Panel^  panel1;
		private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
		private: System::Windows::Forms::SaveFileDialog^  saveFileDialog;
		private: System::Windows::Forms::ListBox^  filterList;

		private: System::Windows::Forms::Panel^  panel2;
		private: System::Windows::Forms::MenuStrip^  menuStrip1;
		private: System::Windows::Forms::ToolStripMenuItem^  addFilterToolStripMenuItem;

		private: System::Windows::Forms::ToolStripMenuItem^  adjustTempuratureToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  deleteFilterToolStripMenuItem;
		private: System::Windows::Forms::TrackBar^  label1TrackBar;

		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::TrackBar^  label3TrackBar;
		private: System::Windows::Forms::Label^  infoLabel2;



		private: System::Windows::Forms::Label^  infoLabel1;

		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::TrackBar^  label2TrackBar;
		private: System::Windows::Forms::Label^  infoLabel3;




		protected:


		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>
			System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
				this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
				this->originalImageCheckBox = (gcnew System::Windows::Forms::CheckBox());
				this->openButton = (gcnew System::Windows::Forms::Button());
				this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
				this->label3TrackBar = (gcnew System::Windows::Forms::TrackBar());
				this->infoLabel2 = (gcnew System::Windows::Forms::Label());
				this->infoLabel1 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->label2TrackBar = (gcnew System::Windows::Forms::TrackBar());
				this->label1TrackBar = (gcnew System::Windows::Forms::TrackBar());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->panel2 = (gcnew System::Windows::Forms::Panel());
				this->filterList = (gcnew System::Windows::Forms::ListBox());
				this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				this->addFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->adjustTempuratureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->deleteFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->panel1 = (gcnew System::Windows::Forms::Panel());
				this->saveButton = (gcnew System::Windows::Forms::Button());
				this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
				this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
				this->infoLabel3 = (gcnew System::Windows::Forms::Label());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
				this->groupBox1->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
				this->splitContainer1->Panel1->SuspendLayout();
				this->splitContainer1->SuspendLayout();
				this->groupBox2->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->label3TrackBar))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->label2TrackBar))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->label1TrackBar))->BeginInit();
				this->panel2->SuspendLayout();
				this->menuStrip1->SuspendLayout();
				this->panel1->SuspendLayout();
				this->SuspendLayout();
				// 
				// pictureBox
				// 
				this->pictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
				this->pictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
				this->pictureBox->Location = System::Drawing::Point(0, 0);
				this->pictureBox->Name = L"pictureBox";
				this->pictureBox->Size = System::Drawing::Size(867, 596);
				this->pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
				this->pictureBox->TabIndex = 0;
				this->pictureBox->TabStop = false;
				// 
				// groupBox1
				// 
				this->groupBox1->Controls->Add(this->splitContainer1);
				this->groupBox1->Location = System::Drawing::Point(12, 12);
				this->groupBox1->Name = L"groupBox1";
				this->groupBox1->Size = System::Drawing::Size(873, 796);
				this->groupBox1->TabIndex = 2;
				this->groupBox1->TabStop = false;
				this->groupBox1->Text = L"Image Viewer";
				// 
				// splitContainer1
				// 
				this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
				this->splitContainer1->Location = System::Drawing::Point(3, 16);
				this->splitContainer1->Name = L"splitContainer1";
				this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
				// 
				// splitContainer1.Panel1
				// 
				this->splitContainer1->Panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
				this->splitContainer1->Panel1->Controls->Add(this->pictureBox);
				this->splitContainer1->Size = System::Drawing::Size(867, 777);
				this->splitContainer1->SplitterDistance = 596;
				this->splitContainer1->TabIndex = 2;
				// 
				// originalImageCheckBox
				// 
				this->originalImageCheckBox->AutoSize = true;
				this->originalImageCheckBox->Location = System::Drawing::Point(15, 814);
				this->originalImageCheckBox->Name = L"originalImageCheckBox";
				this->originalImageCheckBox->Size = System::Drawing::Size(119, 17);
				this->originalImageCheckBox->TabIndex = 1;
				this->originalImageCheckBox->Text = L"View Original Image";
				this->originalImageCheckBox->UseVisualStyleBackColor = true;
				this->originalImageCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::originalImageCheckBox_CheckedChanged);
				// 
				// openButton
				// 
				this->openButton->Location = System::Drawing::Point(3, 3);
				this->openButton->Name = L"openButton";
				this->openButton->Size = System::Drawing::Size(94, 38);
				this->openButton->TabIndex = 3;
				this->openButton->Text = L"Open Image";
				this->openButton->UseVisualStyleBackColor = true;
				this->openButton->Click += gcnew System::EventHandler(this, &MainForm::openButton_Click);
				// 
				// groupBox2
				// 
				this->groupBox2->Controls->Add(this->infoLabel3);
				this->groupBox2->Controls->Add(this->label3TrackBar);
				this->groupBox2->Controls->Add(this->infoLabel2);
				this->groupBox2->Controls->Add(this->infoLabel1);
				this->groupBox2->Controls->Add(this->label3);
				this->groupBox2->Controls->Add(this->label2TrackBar);
				this->groupBox2->Controls->Add(this->label1TrackBar);
				this->groupBox2->Controls->Add(this->label2);
				this->groupBox2->Controls->Add(this->label1);
				this->groupBox2->Controls->Add(this->panel2);
				this->groupBox2->Controls->Add(this->panel1);
				this->groupBox2->Location = System::Drawing::Point(891, 12);
				this->groupBox2->Name = L"groupBox2";
				this->groupBox2->Size = System::Drawing::Size(519, 793);
				this->groupBox2->TabIndex = 4;
				this->groupBox2->TabStop = false;
				this->groupBox2->Text = L"Image Options";
				// 
				// label3TrackBar
				// 
				this->label3TrackBar->Location = System::Drawing::Point(56, 613);
				this->label3TrackBar->Name = L"label3TrackBar";
				this->label3TrackBar->Size = System::Drawing::Size(457, 45);
				this->label3TrackBar->TabIndex = 16;
				this->label3TrackBar->Visible = false;
				// 
				// infoLabel2
				// 
				this->infoLabel2->AutoSize = true;
				this->infoLabel2->Location = System::Drawing::Point(79, 586);
				this->infoLabel2->Name = L"infoLabel2";
				this->infoLabel2->Size = System::Drawing::Size(35, 13);
				this->infoLabel2->TabIndex = 14;
				this->infoLabel2->Text = L"label5";
				this->infoLabel2->Visible = false;
				// 
				// infoLabel1
				// 
				this->infoLabel1->AutoSize = true;
				this->infoLabel1->Location = System::Drawing::Point(79, 527);
				this->infoLabel1->Name = L"infoLabel1";
				this->infoLabel1->Size = System::Drawing::Size(35, 13);
				this->infoLabel1->TabIndex = 13;
				this->infoLabel1->Text = L"label4";
				this->infoLabel1->Visible = false;
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Location = System::Drawing::Point(15, 613);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(35, 13);
				this->label3->TabIndex = 12;
				this->label3->Text = L"label3";
				this->label3->Visible = false;
				// 
				// label2TrackBar
				// 
				this->label2TrackBar->Location = System::Drawing::Point(56, 554);
				this->label2TrackBar->Name = L"label2TrackBar";
				this->label2TrackBar->Size = System::Drawing::Size(457, 45);
				this->label2TrackBar->TabIndex = 11;
				this->label2TrackBar->Visible = false;
				// 
				// label1TrackBar
				// 
				this->label1TrackBar->Location = System::Drawing::Point(56, 495);
				this->label1TrackBar->Name = L"label1TrackBar";
				this->label1TrackBar->Size = System::Drawing::Size(457, 45);
				this->label1TrackBar->TabIndex = 10;
				this->label1TrackBar->Visible = false;
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Location = System::Drawing::Point(15, 554);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(35, 13);
				this->label2->TabIndex = 9;
				this->label2->Text = L"label2";
				this->label2->Visible = false;
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(15, 495);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(35, 13);
				this->label1->TabIndex = 8;
				this->label1->Text = L"label1";
				this->label1->Visible = false;
				// 
				// panel2
				// 
				this->panel2->Controls->Add(this->filterList);
				this->panel2->Controls->Add(this->menuStrip1);
				this->panel2->Location = System::Drawing::Point(10, 72);
				this->panel2->Name = L"panel2";
				this->panel2->Size = System::Drawing::Size(503, 396);
				this->panel2->TabIndex = 7;
				// 
				// filterList
				// 
				this->filterList->FormattingEnabled = true;
				this->filterList->Location = System::Drawing::Point(3, 25);
				this->filterList->Name = L"filterList";
				this->filterList->Size = System::Drawing::Size(336, 355);
				this->filterList->TabIndex = 6;
				// 
				// menuStrip1
				// 
				this->menuStrip1->Dock = System::Windows::Forms::DockStyle::Right;
				this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					this->addFilterToolStripMenuItem,
						this->deleteFilterToolStripMenuItem
				});
				this->menuStrip1->Location = System::Drawing::Point(418, 0);
				this->menuStrip1->Name = L"menuStrip1";
				this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
				this->menuStrip1->Size = System::Drawing::Size(85, 396);
				this->menuStrip1->TabIndex = 7;
				this->menuStrip1->Text = L"menuStrip1";
				// 
				// addFilterToolStripMenuItem
				// 
				this->addFilterToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->adjustTempuratureToolStripMenuItem });
				this->addFilterToolStripMenuItem->Name = L"addFilterToolStripMenuItem";
				this->addFilterToolStripMenuItem->Size = System::Drawing::Size(72, 19);
				this->addFilterToolStripMenuItem->Text = L"Add  filter";
				// 
				// adjustTempuratureToolStripMenuItem
				// 
				this->adjustTempuratureToolStripMenuItem->Name = L"adjustTempuratureToolStripMenuItem";
				this->adjustTempuratureToolStripMenuItem->Size = System::Drawing::Size(179, 22);
				this->adjustTempuratureToolStripMenuItem->Text = L"Adjust Tempurature";
				// 
				// deleteFilterToolStripMenuItem
				// 
				this->deleteFilterToolStripMenuItem->Name = L"deleteFilterToolStripMenuItem";
				this->deleteFilterToolStripMenuItem->Size = System::Drawing::Size(72, 19);
				this->deleteFilterToolStripMenuItem->Text = L"Delete filter";
				// 
				// panel1
				// 
				this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->panel1->Controls->Add(this->openButton);
				this->panel1->Controls->Add(this->saveButton);
				this->panel1->Location = System::Drawing::Point(6, 19);
				this->panel1->Name = L"panel1";
				this->panel1->Size = System::Drawing::Size(202, 47);
				this->panel1->TabIndex = 5;
				// 
				// saveButton
				// 
				this->saveButton->Location = System::Drawing::Point(103, 3);
				this->saveButton->Name = L"saveButton";
				this->saveButton->Size = System::Drawing::Size(94, 38);
				this->saveButton->TabIndex = 4;
				this->saveButton->Text = L"Save Image";
				this->saveButton->UseVisualStyleBackColor = true;
				// 
				// openFileDialog
				// 
				this->openFileDialog->Filter = L"JPEG Files|*.jpg";
				this->openFileDialog->InitialDirectory = L"./";
				this->openFileDialog->Title = L"Open Image";
				// 
				// saveFileDialog
				// 
				this->saveFileDialog->Filter = L"JPEG Files|*.jpg";
				this->saveFileDialog->InitialDirectory = L"./";
				this->saveFileDialog->Title = L"Save Image";
				// 
				// infoLabel3
				// 
				this->infoLabel3->AutoSize = true;
				this->infoLabel3->Location = System::Drawing::Point(79, 645);
				this->infoLabel3->Name = L"infoLabel3";
				this->infoLabel3->Size = System::Drawing::Size(35, 13);
				this->infoLabel3->TabIndex = 17;
				this->infoLabel3->Text = L"label6";
				this->infoLabel3->Visible = false;
				// 
				// MainForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(1422, 843);
				this->Controls->Add(this->originalImageCheckBox);
				this->Controls->Add(this->groupBox2);
				this->Controls->Add(this->groupBox1);
				this->MaximizeBox = false;
				this->Name = L"MainForm";
				this->Text = L"Picture Enhancement Software";
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
				this->groupBox1->ResumeLayout(false);
				this->splitContainer1->Panel1->ResumeLayout(false);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
				this->splitContainer1->ResumeLayout(false);
				this->groupBox2->ResumeLayout(false);
				this->groupBox2->PerformLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->label3TrackBar))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->label2TrackBar))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->label1TrackBar))->EndInit();
				this->panel2->ResumeLayout(false);
				this->panel2->PerformLayout();
				this->menuStrip1->ResumeLayout(false);
				this->menuStrip1->PerformLayout();
				this->panel1->ResumeLayout(false);
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion
		private: System::Void DrawCvImage(const cv::Mat cvImage);
		private: System::Void openButton_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void originalImageCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
};
	}
}
