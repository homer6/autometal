#pragma once

#include <vector>
using std::vector;

#include <string>
using std::string;

namespace autometal {
namespace platforms {
	

	struct FilePath{
		string drive_letter;
		vector<string> path_parts;

		string createPathString( const string separator, bool relative = true ) const;
	};

	struct Command{
		FilePath executable;
		vector<string> arguments;

		void setExecutable( vector<string> exec_path ){
			this->executable.path_parts = exec_path;
		};

	};

	struct CommandResult{

		CommandResult()
			:result_code(0)
		{

		};

		int result_code;
		string stdout_output;
		string stderr_output;

	};



	struct Platform{

		virtual CommandResult executeCommand( const Command& command ) = 0;

		virtual string renderFilePath( const FilePath& file_path ) = 0;
		virtual string renderCommand( const Command& command ) = 0;

		virtual ~Platform() = default;

		static Platform* createPlatform();

	};






}
}