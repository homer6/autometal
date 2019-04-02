#include "autometal/operators/KafkaOperator.h"

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


	FilePath KafkaOperator::getOperatorFilePath(){

		return {
			{ "srv", "autometal", "operators", "kafka" }, false
		};

	}

	string KafkaOperator::getOperatorVersion(){

		return "01_14_00";

	}

	void KafkaOperator::installPreflight(){}
	void KafkaOperator::install(){
		cout << "Installing Kafka" << endl;
	}
	void KafkaOperator::uninstall(){
		cout << "Uninstalling Kafka" << endl;
	}
	void KafkaOperator::assertInstalled(){}
	void KafkaOperator::assertUninstalled(){}


	void KafkaOperator::installService(){}
	void KafkaOperator::uninstallService(){}
	void KafkaOperator::assertRunning(){}
	void KafkaOperator::assertStopped(){}
	void KafkaOperator::run(){}
	void KafkaOperator::stop(){}



/*

	void KafkaOperator::run(){

		this->installPreflight();
		
		this->install();

	}
	

	void KafkaOperator::installPreflight(){

		unique_ptr<Platform> platform( Platform::createPlatform() );

		platform->installDependencies();

		CommandResult result = platform->executeCommand({
			{ "ls" }
		});

		cout << "command stdout: " << result.stdout_output << endl;

	}
	

	void KafkaOperator::install(){

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


