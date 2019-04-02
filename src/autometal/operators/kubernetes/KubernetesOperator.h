#pragma once

#include "autometal/operators/RunnableOperator.h"
using autometal::operators::RunnableOperator;

#include "autometal/platforms/Platform.h"
using autometal::platforms::FilePath;




namespace autometal{
namespace operators{

	class KubernetesOperator : public RunnableOperator{

		public:

			KubernetesOperator();

			void installPreflight();
			void install();
			void uninstall();
			void assertInstalled();
			void assertUninstalled();


			void installService();
			void uninstallService();
			void assertRunning();
			void assertStopped();
			void run();
			void stop();


			FilePath getOperatorFilePath();

			string kubernetes_version = "1.14.0";


	};


}
}