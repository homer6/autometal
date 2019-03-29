#pragma once

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <string>
using std::string;

namespace autometal {
namespace platforms {
	

	struct FilePath{

		FilePath();
		FilePath( const vector<string>& path_parts, bool relative = true );

		vector<string> path_parts;
		bool relative = true;
		string drive_letter;
		
		string createPathString( const string separator ) const;
	};

	struct HttpPath{

		HttpPath( const string& hostname, const string& path, map<string,string> query_parameters = {}, bool https = true );
			
		string hostname;
		string path;
		map<string,string> query_parameters;
		bool https = true;
		
		string createPathString() const;
	};



	struct Command{

		Command(){};

		Command( const vector<string>& path_parts, vector<string> arguments = {}, bool relative = true )
			:arguments(arguments)
		{
			executable.path_parts = path_parts;
			executable.relative = relative;
		};

		FilePath executable;
		vector<string> arguments;

		void setExecutable( vector<string> exec_path ){
			this->executable.path_parts = exec_path;
		};

	};

	struct CommandResult{

		int result_code = 0;
		string stdout_output;
		string stderr_output;

	};



	struct Platform{

		virtual CommandResult executeCommand( const Command& command ) = 0;

		virtual string renderFilePath( const FilePath& file_path ) = 0;
		virtual string renderCommand( const Command& command ) = 0;

		virtual bool installDependencies() = 0;
		virtual CommandResult downloadFile( const HttpPath& source_file, const FilePath& destination_file ) = 0;

		//downloads and ensures that it's executable
		virtual CommandResult downloadExecutableFile( const HttpPath& source_file, const FilePath& destination_file ) = 0;

		virtual CommandResult makeExecutable( const FilePath& executable_file ) = 0;


		virtual ~Platform() = default;

		static Platform* createPlatform();

	};






}
}