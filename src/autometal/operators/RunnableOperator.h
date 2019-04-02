#pragma once

#include "autometal/operators/Operator.h"
using autometal::operators::Operator;

namespace autometal{
namespace operators{


	class RunnableOperator : public Operator{

		public:
			virtual void installService() = 0;
			virtual void uninstallService() = 0;

			virtual void assertRunning() = 0;
			virtual void assertStopped() = 0;

			virtual void run() = 0;
			virtual void stop() = 0;

			virtual bool isRunnable(){ return true; }			

	};


}
}