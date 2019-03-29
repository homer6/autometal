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

		platform->installDependencies();

		CommandResult result = platform->executeCommand({
			{ "ls" }
		});

		cout << "command stdout: " << result.stdout_output << endl;

	}
	

	void KubernetesOperator::install(){

		unique_ptr<Platform> platform( Platform::createPlatform() );

		platform->downloadExecutableFile(
			{ "pkg.cfssl.org", "/R1.2/cfssl_linux-amd64" },
			{ { "usr", "local", "bin", "cfssl" }, false }
		);
		platform->downloadExecutableFile(
			{ "pkg.cfssl.org", "/R1.2/cfssljson_linux-amd64" },
			{ { "usr", "local", "bin", "cfssljson" }, false }
		);

		//cout << "download stdout: " << result.stdout_output << endl;

	}
	

	void KubernetesOperator::remove(){



	}
	


}
}


