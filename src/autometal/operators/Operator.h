#pragma once

#include "autometal/platforms/Platform.h"
using autometal::platforms::Platform;

#include "autometal/platforms/Platform.h"
using autometal::platforms::FilePath;

#include <string>
using std::string;

namespace autometal{
namespace operators{


	class Operator{

		public:
			virtual void assertInstalled() = 0;
			virtual void assertUninstalled() = 0;

			virtual void installPreflight() = 0;
			virtual void install() = 0;
			virtual void uninstall() = 0;

			virtual Platform* getPlatform();
			virtual ~Operator();

			virtual bool isRunnable(){ return false; }

			virtual FilePath getOperatorFilePath() = 0;
			virtual string getOperatorVersion() = 0;

		protected:
			Platform* platform = nullptr;

	};


}
}