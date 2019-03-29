#include "autometal/platforms/Linux.h"


#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>


namespace autometal {
namespace platforms {
	

	CommandResult Linux::executeCommand( const Command& command ){

		CommandResult result;

		// http://stackoverflow.com/questions/478898/how-to-execute-a-command-and-get-output-of-command-within-c-using-posix
		char buffer[4096];

		string command_string = this->renderCommand(command);

		std::shared_ptr<FILE> pipe( popen(command_string.c_str(), "r"), pclose );
		if( !pipe ){
			throw std::runtime_error("popen() failed");
		}

		while( !feof( pipe.get() ) ){
			if( fgets( buffer, 4096, pipe.get() ) != 0 ){
				result.stdout_output += buffer;
			}
		}

		return result;

	}



	string Linux::renderFilePath( const FilePath& file_path ){

		return file_path.createPathString( "/", true );

	}



	string Linux::renderCommand( const Command& command ){

		return this->renderFilePath( command.executable );

	}


}
}