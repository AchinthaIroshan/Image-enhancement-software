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
		private: cv::Mat* im;
		private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
		private: System::Windows::Forms::SaveFileDialog^  saveFileDialog;

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
				this->panel1 = (gcnew System::Windows::Forms::Panel());
				this->saveButton = (gcnew System::Windows::Forms::Button());
				this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
				this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
				this->groupBox1->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
				this->splitContainer1->Panel1->SuspendLayout();
				this->splitContainer1->SuspendLayout();
				this->groupBox2->SuspendLayout();
				this->panel1->SuspendLayout();
				this->SuspendLayout();
				// 
				// pictureBox
				// 
				this->pictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
				this->pictureBox->Location = System::Drawing::Point(0, 0);
				this->pictureBox->Name = L"pictureBox";
				this->pictureBox->Size = System::Drawing::Size(867, 596);
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
				this->groupBox2->Controls->Add(this->panel1);
				this->groupBox2->Location = System::Drawing::Point(891, 12);
				this->groupBox2->Name = L"groupBox2";
				this->groupBox2->Size = System::Drawing::Size(519, 644);
				this->groupBox2->TabIndex = 4;
				this->groupBox2->TabStop = false;
				this->groupBox2->Text = L"Image Options";
				// 
				// panel1
				// 
				this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->panel1->Controls->Add(this->openButton);
				this->panel1->Controls->Add(this->saveButton);
				this->panel1->Location = System::Drawing::Point(311, 19);
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
				this->panel1->ResumeLayout(false);
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion
		private: System::Void drawImage(cv::Mat image);
		private: System::Void openButton_Click(System::Object^  sender, System::EventArgs^  e);
		};
	}
}
