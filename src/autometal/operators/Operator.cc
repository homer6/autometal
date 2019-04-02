#include "autometal/operators/Operator.h"

#include "autometal/platforms/Platform.h"
using autometal::platforms::Platform;
using autometal::platforms::Command;
using autometal::platforms::CommandResult;



namespace autometal{
namespace operators{


	Platform* Operator::getPlatform(){

		if( this->platform == nullptr ){

			this->platform = Platform::createPlatform();

		}

		return this->platform;

	}
	

	Operator::~Operator(){

		if( this->platform != nullptr ){
			delete this->platform;
			this->platform = nullptr;
		}

	}
	


}
}


