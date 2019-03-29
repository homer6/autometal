#include "autometal/platforms/Ubuntu.h"


#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>

#include <iostream>
using std::cout;
using std::endl;


namespace autometal {
namespace platforms {
	
		bool Ubuntu::installDependencies(){

			CommandResult result = this->executeCommand({
				{ "sudo apt" },
				{ "-y", "install", "wget" }
			});

			//cout << "command stdout: " << result.stdout_output << endl;

			return true;

		}


		CommandResult Ubuntu::downloadFile( const HttpPath& source_file, const FilePath& destination_file ){

			CommandResult result = this->executeCommand({
				{ "wget" },
				{ "-O", this->renderFilePath(destination_file), source_file.createPathString() }
			});

			return result;

		}


		CommandResult Ubuntu::downloadExecutableFile( const HttpPath& source_file, const FilePath& destination_file ){

			CommandResult result = this->executeCommand({
				{ "wget" },
				{ "-O", this->renderFilePath(destination_file), source_file.createPathString() }
			});

			this->makeExecutable( destination_file );

			return result;

		}


}
}