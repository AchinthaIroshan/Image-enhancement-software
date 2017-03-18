#include "MetaDataForm.h"

namespace pes {
	namespace view {

		System::Void MetaDataForm::showMetaData(System::String ^ data)
		{
			metaLabel->Text = data;
		}

	}
}
