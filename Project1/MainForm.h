#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "ControllerModel.h"
#include "FilterModel.h"

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
				controllerModel = gcnew pes::model::ControllerModel(label1, infoLabel1, label2, infoLabel2, label3, infoLabel3, label1TrackBar, label2TrackBar, label3TrackBar);
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

		private: pes::model::ControllerModel^ controllerModel;
		private: bool isDragging = false;
		private: System::Drawing::Point^ cropStart;
		private: System::Drawing::Point^ currentMouse;
		private: pes::model::FilterModel^ selectedModel;
		private: System::Windows::Forms::ToolStripMenuItem^  cropImageToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  savePresetToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  loadPresetToolStripMenuItem;
		private: System::Windows::Forms::PictureBox^  histPictureBox;

		private: System::Windows::Forms::RadioButton^  bRadioButton;
		private: System::Windows::Forms::RadioButton^  gRadioButton;
		private: System::Windows::Forms::RadioButton^  rRadioButton;
		private: System::Windows::Forms::RadioButton^  rgbRadioButton;
		private: System::Windows::Forms::Panel^  histPanel;
		private: System::Windows::Forms::ToolStripMenuItem^  vignetteToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  colorBalanceToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  autoCorrectionToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  shadowRecoveryToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  highlightRecoveryToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  adjustContrastToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  adjustSaturationToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  adjustExposureToolStripMenuItem;
		private: System::Windows::Forms::OpenFileDialog^  openPresetFileDialog;
		private: System::Windows::Forms::SaveFileDialog^  savePresetFileDialog;
		private: System::Windows::Forms::ToolStripMenuItem^  sharpenToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  showMetaDataToolStripMenuItem;





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
				this->histPanel = (gcnew System::Windows::Forms::Panel());
				this->histPictureBox = (gcnew System::Windows::Forms::PictureBox());
				this->bRadioButton = (gcnew System::Windows::Forms::RadioButton());
				this->gRadioButton = (gcnew System::Windows::Forms::RadioButton());
				this->rRadioButton = (gcnew System::Windows::Forms::RadioButton());
				this->rgbRadioButton = (gcnew System::Windows::Forms::RadioButton());
				this->originalImageCheckBox = (gcnew System::Windows::Forms::CheckBox());
				this->openButton = (gcnew System::Windows::Forms::Button());
				this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
				this->infoLabel3 = (gcnew System::Windows::Forms::Label());
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
				this->cropImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->addFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->adjustTempuratureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->vignetteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->colorBalanceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->autoCorrectionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->shadowRecoveryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->highlightRecoveryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->adjustContrastToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->adjustSaturationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->adjustExposureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->sharpenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->deleteFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->savePresetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->loadPresetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->panel1 = (gcnew System::Windows::Forms::Panel());
				this->saveButton = (gcnew System::Windows::Forms::Button());
				this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
				this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
				this->openPresetFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
				this->savePresetFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
				this->showMetaDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
				this->groupBox1->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
				this->splitContainer1->Panel1->SuspendLayout();
				this->splitContainer1->Panel2->SuspendLayout();
				this->splitContainer1->SuspendLayout();
				this->histPanel->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->histPictureBox))->BeginInit();
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
				this->pictureBox->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->pictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
				this->pictureBox->Location = System::Drawing::Point(60, 20);
				this->pictureBox->Name = L"pictureBox";
				this->pictureBox->Size = System::Drawing::Size(807, 540);
				this->pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
				this->pictureBox->TabIndex = 0;
				this->pictureBox->TabStop = false;
				this->pictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pictureBox_Paint);
				this->pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_MouseDown);
				this->pictureBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_MouseMove);
				this->pictureBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBox_MouseUp);
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
				// 
				// splitContainer1.Panel2
				// 
				this->splitContainer1->Panel2->Controls->Add(this->histPanel);
				this->splitContainer1->Panel2->Controls->Add(this->bRadioButton);
				this->splitContainer1->Panel2->Controls->Add(this->gRadioButton);
				this->splitContainer1->Panel2->Controls->Add(this->rRadioButton);
				this->splitContainer1->Panel2->Controls->Add(this->rgbRadioButton);
				this->splitContainer1->Size = System::Drawing::Size(867, 777);
				this->splitContainer1->SplitterDistance = 524;
				this->splitContainer1->TabIndex = 2;
				// 
				// histPanel
				// 
				this->histPanel->Controls->Add(this->histPictureBox);
				this->histPanel->Location = System::Drawing::Point(90, 3);
				this->histPanel->Name = L"histPanel";
				this->histPanel->Size = System::Drawing::Size(774, 243);
				this->histPanel->TabIndex = 5;
				// 
				// histPictureBox
				// 
				this->histPictureBox->Location = System::Drawing::Point(3, 3);
				this->histPictureBox->Name = L"histPictureBox";
				this->histPictureBox->Size = System::Drawing::Size(768, 237);
				this->histPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
				this->histPictureBox->TabIndex = 4;
				this->histPictureBox->TabStop = false;
				// 
				// bRadioButton
				// 
				this->bRadioButton->AutoSize = true;
				this->bRadioButton->Location = System::Drawing::Point(14, 84);
				this->bRadioButton->Name = L"bRadioButton";
				this->bRadioButton->Size = System::Drawing::Size(46, 17);
				this->bRadioButton->TabIndex = 3;
				this->bRadioButton->Text = L"Blue";
				this->bRadioButton->UseVisualStyleBackColor = true;
				this->bRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::bRadioButton_CheckedChanged);
				// 
				// gRadioButton
				// 
				this->gRadioButton->AutoSize = true;
				this->gRadioButton->Location = System::Drawing::Point(14, 61);
				this->gRadioButton->Name = L"gRadioButton";
				this->gRadioButton->Size = System::Drawing::Size(54, 17);
				this->gRadioButton->TabIndex = 2;
				this->gRadioButton->Text = L"Green";
				this->gRadioButton->UseVisualStyleBackColor = true;
				this->gRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::gRadioButton_CheckedChanged);
				// 
				// rRadioButton
				// 
				this->rRadioButton->AutoSize = true;
				this->rRadioButton->Location = System::Drawing::Point(14, 38);
				this->rRadioButton->Name = L"rRadioButton";
				this->rRadioButton->Size = System::Drawing::Size(45, 17);
				this->rRadioButton->TabIndex = 1;
				this->rRadioButton->Text = L"Red";
				this->rRadioButton->UseVisualStyleBackColor = true;
				this->rRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rRadioButton_CheckedChanged);
				// 
				// rgbRadioButton
				// 
				this->rgbRadioButton->AutoSize = true;
				this->rgbRadioButton->Checked = true;
				this->rgbRadioButton->Location = System::Drawing::Point(14, 15);
				this->rgbRadioButton->Name = L"rgbRadioButton";
				this->rgbRadioButton->Size = System::Drawing::Size(48, 17);
				this->rgbRadioButton->TabIndex = 0;
				this->rgbRadioButton->TabStop = true;
				this->rgbRadioButton->Text = L"RGB";
				this->rgbRadioButton->UseVisualStyleBackColor = true;
				this->rgbRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rgbRadioButton_CheckedChanged);
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
				// label3TrackBar
				// 
				this->label3TrackBar->Location = System::Drawing::Point(56, 613);
				this->label3TrackBar->Name = L"label3TrackBar";
				this->label3TrackBar->Size = System::Drawing::Size(457, 45);
				this->label3TrackBar->TabIndex = 16;
				this->label3TrackBar->Visible = false;
				this->label3TrackBar->Scroll += gcnew System::EventHandler(this, &MainForm::label3TrackBar_Scroll);
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
				this->label2TrackBar->Scroll += gcnew System::EventHandler(this, &MainForm::label2TrackBar_Scroll);
				// 
				// label1TrackBar
				// 
				this->label1TrackBar->Location = System::Drawing::Point(56, 495);
				this->label1TrackBar->Name = L"label1TrackBar";
				this->label1TrackBar->Size = System::Drawing::Size(457, 45);
				this->label1TrackBar->TabIndex = 10;
				this->label1TrackBar->Visible = false;
				this->label1TrackBar->Scroll += gcnew System::EventHandler(this, &MainForm::label1TrackBar_Scroll);
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
				this->filterList->Location = System::Drawing::Point(8, 21);
				this->filterList->Name = L"filterList";
				this->filterList->Size = System::Drawing::Size(336, 355);
				this->filterList->TabIndex = 6;
				this->filterList->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::filterList_SelectedIndexChanged);
				// 
				// menuStrip1
				// 
				this->menuStrip1->Dock = System::Windows::Forms::DockStyle::Right;
				this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
					this->cropImageToolStripMenuItem,
						this->addFilterToolStripMenuItem, this->deleteFilterToolStripMenuItem, this->savePresetToolStripMenuItem, this->loadPresetToolStripMenuItem,
						this->showMetaDataToolStripMenuItem
				});
				this->menuStrip1->Location = System::Drawing::Point(392, 0);
				this->menuStrip1->Name = L"menuStrip1";
				this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
				this->menuStrip1->Size = System::Drawing::Size(111, 396);
				this->menuStrip1->TabIndex = 7;
				this->menuStrip1->Text = L"menuStrip1";
				// 
				// cropImageToolStripMenuItem
				// 
				this->cropImageToolStripMenuItem->Name = L"cropImageToolStripMenuItem";
				this->cropImageToolStripMenuItem->Size = System::Drawing::Size(98, 19);
				this->cropImageToolStripMenuItem->Text = L"Crop Image";
				this->cropImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::cropImageToolStripMenuItem_Click);
				// 
				// addFilterToolStripMenuItem
				// 
				this->addFilterToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
					this->adjustTempuratureToolStripMenuItem,
						this->vignetteToolStripMenuItem, this->colorBalanceToolStripMenuItem, this->autoCorrectionToolStripMenuItem, this->shadowRecoveryToolStripMenuItem,
						this->highlightRecoveryToolStripMenuItem, this->adjustContrastToolStripMenuItem, this->adjustSaturationToolStripMenuItem, this->adjustExposureToolStripMenuItem,
						this->sharpenToolStripMenuItem
				});
				this->addFilterToolStripMenuItem->Name = L"addFilterToolStripMenuItem";
				this->addFilterToolStripMenuItem->Size = System::Drawing::Size(98, 19);
				this->addFilterToolStripMenuItem->Text = L"Add  filter";
				// 
				// adjustTempuratureToolStripMenuItem
				// 
				this->adjustTempuratureToolStripMenuItem->Name = L"adjustTempuratureToolStripMenuItem";
				this->adjustTempuratureToolStripMenuItem->Size = System::Drawing::Size(179, 22);
				this->adjustTempuratureToolStripMenuItem->Text = L"Adjust Tempurature";
				this->adjustTempuratureToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::adjustTempuratureToolStripMenuItem_Click);
				// 
				// vignetteToolStripMenuItem
				// 
				this->vignetteToolStripMenuItem->Name = L"vignetteToolStripMenuItem";
				this->vignetteToolStripMenuItem->Size = System::Drawing::Size(179, 22);
				this->vignetteToolStripMenuItem->Text = L"Vignette";
				this->vignetteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::vignetteToolStripMenuItem_Click);
				// 
				// colorBalanceToolStripMenuItem
				// 
				this->colorBalanceToolStripMenuItem->Name = L"colorBalanceToolStripMenuItem";
				this->colorBalanceToolStripMenuItem->Size = System::Drawing::Size(179, 22);
				this->colorBalanceToolStripMenuItem->Text = L"Color Balance";
				this->colorBalanceToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::colorBalanceToolStripMenuItem_Click);
				// 
				// autoCorrectionToolStripMenuItem
				// 
				this->autoCorrectionToolStripMenuItem->Name = L"autoCorrectionToolStripMenuItem";
				this->autoCorrectionToolStripMenuItem->Size = System::Drawing::Size(179, 22);
				this->autoCorrectionToolStripMenuItem->Text = L"Auto Correction";
				this->autoCorrectionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::autoCorrectionToolStripMenuItem_Click);
				// 
				// shadowRecoveryToolStripMenuItem
				// 
				this->shadowRecoveryToolStripMenuItem->Name = L"shadowRecoveryToolStripMenuItem";
				this->shadowRecoveryToolStripMenuItem->Size = System::Drawing::Size(179, 22);
				this->shadowRecoveryToolStripMenuItem->Text = L"Shadow Recovery";
				this->shadowRecoveryToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::shadowRecoveryToolStripMenuItem_Click);
				// 
				// highlightRecoveryToolStripMenuItem
				// 
				this->highlightRecoveryToolStripMenuItem->Name = L"highlightRecoveryToolStripMenuItem";
				this->highlightRecoveryToolStripMenuItem->Size = System::Drawing::Size(179, 22);
				this->highlightRecoveryToolStripMenuItem->Text = L"Highlight Recovery";
				this->highlightRecoveryToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::highlightRecoveryToolStripMenuItem_Click);
				// 
				// adjustContrastToolStripMenuItem
				// 
				this->adjustContrastToolStripMenuItem->Name = L"adjustContrastToolStripMenuItem";
				this->adjustContrastToolStripMenuItem->Size = System::Drawing::Size(179, 22);
				this->adjustContrastToolStripMenuItem->Text = L"Adjust Contrast";
				this->adjustContrastToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::adjustContrastToolStripMenuItem_Click);
				// 
				// adjustSaturationToolStripMenuItem
				// 
				this->adjustSaturationToolStripMenuItem->Name = L"adjustSaturationToolStripMenuItem";
				this->adjustSaturationToolStripMenuItem->Size = System::Drawing::Size(179, 22);
				this->adjustSaturationToolStripMenuItem->Text = L"Adjust Saturation";
				this->adjustSaturationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::adjustSaturationToolStripMenuItem_Click);
				// 
				// adjustExposureToolStripMenuItem
				// 
				this->adjustExposureToolStripMenuItem->Name = L"adjustExposureToolStripMenuItem";
				this->adjustExposureToolStripMenuItem->Size = System::Drawing::Size(179, 22);
				this->adjustExposureToolStripMenuItem->Text = L"Adjust Exposure";
				this->adjustExposureToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::adjustExposureToolStripMenuItem_Click);
				// 
				// sharpenToolStripMenuItem
				// 
				this->sharpenToolStripMenuItem->Name = L"sharpenToolStripMenuItem";
				this->sharpenToolStripMenuItem->Size = System::Drawing::Size(179, 22);
				this->sharpenToolStripMenuItem->Text = L"Sharpen";
				this->sharpenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::sharpenToolStripMenuItem_Click);
				// 
				// deleteFilterToolStripMenuItem
				// 
				this->deleteFilterToolStripMenuItem->Name = L"deleteFilterToolStripMenuItem";
				this->deleteFilterToolStripMenuItem->Size = System::Drawing::Size(98, 19);
				this->deleteFilterToolStripMenuItem->Text = L"Delete filter";
				this->deleteFilterToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::deleteFilterToolStripMenuItem_Click);
				// 
				// savePresetToolStripMenuItem
				// 
				this->savePresetToolStripMenuItem->Name = L"savePresetToolStripMenuItem";
				this->savePresetToolStripMenuItem->Size = System::Drawing::Size(98, 19);
				this->savePresetToolStripMenuItem->Text = L"Save Preset";
				// 
				// loadPresetToolStripMenuItem
				// 
				this->loadPresetToolStripMenuItem->Name = L"loadPresetToolStripMenuItem";
				this->loadPresetToolStripMenuItem->Size = System::Drawing::Size(98, 19);
				this->loadPresetToolStripMenuItem->Text = L"Load Preset";
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
				this->saveButton->Click += gcnew System::EventHandler(this, &MainForm::saveButton_Click);
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
				// openPresetFileDialog
				// 
				this->openPresetFileDialog->Filter = L"Preset Files|*.pr";
				this->openPresetFileDialog->InitialDirectory = L"./";
				this->openPresetFileDialog->Title = L"Open Preset File";
				// 
				// savePresetFileDialog
				// 
				this->savePresetFileDialog->Filter = L"Preset Files|*.pr";
				this->savePresetFileDialog->InitialDirectory = L"./";
				this->savePresetFileDialog->Title = L"Save Preset File";
				// 
				// showMetaDataToolStripMenuItem
				// 
				this->showMetaDataToolStripMenuItem->Name = L"showMetaDataToolStripMenuItem";
				this->showMetaDataToolStripMenuItem->Size = System::Drawing::Size(98, 19);
				this->showMetaDataToolStripMenuItem->Text = L"Show Meta Data";
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
				this->splitContainer1->Panel2->ResumeLayout(false);
				this->splitContainer1->Panel2->PerformLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
				this->splitContainer1->ResumeLayout(false);
				this->histPanel->ResumeLayout(false);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->histPictureBox))->EndInit();
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
		private: System::Void DrawHist(const cv::Mat cvImage);
		private: System::Void openButton_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void saveButton_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void originalImageCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		private: System::Void cropImageToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void pictureBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		private: System::Void pictureBox_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		private: System::Void pictureBox_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		private: System::Void pictureBox_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
		private: System::Void adjustTempuratureToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void filterList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		private: System::Void label1TrackBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		private: System::Void label2TrackBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		private: System::Void label3TrackBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		private: System::Void performFiltering();
		private: System::Void rgbRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		private: System::Void rRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		private: System::Void gRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		private: System::Void bRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		private: System::Void vignetteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void colorBalanceToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void autoCorrectionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void shadowRecoveryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void highlightRecoveryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void adjustContrastToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void adjustSaturationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void adjustExposureToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void sharpenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void deleteFilterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		};
	}
}
