#pragma once

namespace pes {
	namespace view {

		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;

		/// <summary>
		/// Summary for MetaDataForm
		/// </summary>
		public ref class MetaDataForm : public System::Windows::Forms::Form
		{
		public:
			MetaDataForm(void)
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
			~MetaDataForm()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Label^  metaLabel;
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
				this->metaLabel = (gcnew System::Windows::Forms::Label());
				this->SuspendLayout();
				// 
				// metaLabel
				// 
				this->metaLabel->AutoSize = true;
				this->metaLabel->Location = System::Drawing::Point(38, 42);
				this->metaLabel->Name = L"metaLabel";
				this->metaLabel->Size = System::Drawing::Size(35, 13);
				this->metaLabel->TabIndex = 0;
				this->metaLabel->Text = L"label1";
				// 
				// MetaDataForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(568, 570);
				this->Controls->Add(this->metaLabel);
				this->MaximizeBox = false;
				this->Name = L"MetaDataForm";
				this->ShowIcon = false;
				this->Text = L"Meta Information of the Image";
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion

		public: System::Void showMetaData(System::String^ data);
		};
	}
}
