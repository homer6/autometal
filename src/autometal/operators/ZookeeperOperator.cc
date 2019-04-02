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

		return "03_04_14";

	}

	void ZookeeperOperator::installPreflight(){}


	void ZookeeperOperator::install(){

		cout << "Installing Zookeeper" << endl;

		FilePath operator_filepath = this->getOperatorFilePath();

		this->getPlatform()->executeCommand({
			{ "mkdir" },
			{ "-p", this->getPlatform()->renderFilePath(operator_filepath) }
		});



		FilePath download_filepath = operator_filepath;
		download_filepath.append( "zookeeper-3.4.14.tar.gz" );


		this->getPlatform()->downloadFile(
			{ "www-us.apache.org", "/dist/zookeeper/zookeeper-3.4.14/zookeeper-3.4.14.tar.gz" },
			download_filepath
		);

		CommandResult result = this->getPlatform()->executeCommand({
			{ "tar" },
			{ "-C", this->getPlatform()->renderFilePath(operator_filepath), "-xvzf", this->getPlatform()->renderFilePath(download_filepath) }
		});

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




}
}


