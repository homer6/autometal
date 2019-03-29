#include "autometal/operators/kubernetes/KubernetesOperator.h"

#include "autometal/platforms/Platform.h"
using autometal::platforms::Platform;
using autometal::platforms::Command;
using autometal::platforms::CommandResult;

#include <memory>
using std::unique_ptr;

#include <iostream>
using std::cout;
using std::endl;




namespace autometal{
namespace operators{

	KubernetesOperator::KubernetesOperator()
	{



	}	




	void KubernetesOperator::run(){

		this->installPreflight();
		this->install();

	}
	

	void KubernetesOperator::installPreflight(){

		unique_ptr<Platform> platform( Platform::createPlatform() );

		Command command;
		command.setExecutable( { "ls" } );

		CommandResult result = platform->executeCommand( command );

		cout << "command stdout: " << result.stdout_output << endl;

	}
	

	void KubernetesOperator::install(){



	}
	

	void KubernetesOperator::remove(){



	}
	


}
}


