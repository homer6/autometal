#include "autometal/platforms/Ubuntu.h"


#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>


namespace autometal {
namespace platforms {
	
	string FilePath::createPathString( const string separator, bool relative ) const{

		string result;
		bool first = true;

		for( const string& path_part : this->path_parts ){

			if( first ){

				if( relative ){
					result += path_part;
				}else{
					result += separator + path_part;
				}

				first = false;

			}else{

				result += separator + path_part;

			}			

		}

		return result;

	}



	Platform* Platform::createPlatform(){

		return new Ubuntu("18");

	}

}
}