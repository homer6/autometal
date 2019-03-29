#pragma once

#include "autometal/platforms/Platform.h"


namespace autometal {
namespace platforms {
	

	class Linux : public Platform{

		public:
			CommandResult executeCommand( const Command& command );
			string renderFilePath( const FilePath& file_path );
			string renderCommand( const Command& command );

			CommandResult makeExecutable( const FilePath& executable_file );


	};


}
}