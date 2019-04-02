#include "autometal/operators/ZookeeperOperator.h"

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


	FilePath ZookeeperOperator::getOperatorFilePath(){

		return {
			{ "srv", "autometal", "operators", "zookeeper" }, false
		};

	}

	string ZookeeperOperator::getOperatorVersion(){

		return "01_14_00";

	}

	void ZookeeperOperator::installPreflight(){}
	void ZookeeperOperator::install(){
		cout << "Installing Zookeeper" << endl;
	}
	void ZookeeperOperator::uninstall(){
		cout << "Uninstalling Zookeeper" << endl;
	}
	void ZookeeperOperator::assertInstalled(){}
	void ZookeeperOperator::assertUninstalled(){}


	void ZookeeperOperator::installService(){}
	void ZookeeperOperator::uninstallService(){}
	void ZookeeperOperator::assertRunning(){}
	void ZookeeperOperator::assertStopped(){}
	void ZookeeperOperator::run(){}
	void ZookeeperOperator::stop(){}



/*

	void ZookeeperOperator::run(){

		this->installPreflight();
		
		this->install();

	}
	

	void ZookeeperOperator::installPreflight(){

		unique_ptr<Platform> platform( Platform::createPlatform() );

		platform->installDependencies();

		CommandResult result = platform->executeCommand({
			{ "ls" }
		});

		cout << "command stdout: " << result.stdout_output << endl;

	}
	

	void ZookeeperOperator::install(){

		unique_ptr<Platform> platform( Platform::createPlatform() );

		FilePath operator_filepath = this->getOperatorFilePath();

		platform->executeCommand({
			{ "mkdir" },
			{ "-p", platform->renderFilePath(operator_filepath) }
		});

		platform->downloadExecutableFile(
			{ "pkg.cfssl.org", "/R1.2/cfssl_linux-amd64" },
			{ { "usr", "local", "bin", "cfssl" }, false }
		);

		platform->downloadExecutableFile(
			{ "pkg.cfssl.org", "/R1.2/cfssljson_linux-amd64" },
			{ { "usr", "local", "bin", "cfssljson" }, false }
		);

		platform->downloadExecutableFile(
			{ "storage.googleapis.com", "/kubernetes-release/release/v" + this->kubernetes_version + "/bin/linux/amd64/kubectl" },
			{ { "usr", "local", "bin", "kubectl" }, false }
		);

		//cout << "download stdout: " << result.stdout_output << endl;

	}
	
*/
	


}
}


