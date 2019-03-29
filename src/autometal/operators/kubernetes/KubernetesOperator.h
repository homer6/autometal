#pragma once

#include "autometal/platforms/Platform.h"
using autometal::platforms::FilePath;


namespace autometal{
namespace operators{

	class KubernetesOperator{

		public:

			KubernetesOperator();

			void run();

			void installPreflight();
			void install();
			void remove();

			FilePath getOperatorFilePath();


			string kubernetes_version = "1.14.0";


	};


}
}