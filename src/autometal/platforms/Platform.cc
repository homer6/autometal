#include "autometal/platforms/Ubuntu.h"


#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>


namespace autometal {
namespace platforms {
	

	FilePath::FilePath(){

	}


	FilePath::FilePath( const vector<string>& path_parts, bool relative )
		:path_parts(path_parts), relative(relative)
	{



	}




	string FilePath::createPathString( const string separator ) const{

		string result;
		bool first = true;

		for( const string& path_part : this->path_parts ){

			if( first ){

				if( this->relative ){
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


	HttpPath::HttpPath( const string& hostname, const string& path, map<string,string> query_parameters, bool https )
		:hostname(hostname), path(path), query_parameters(query_parameters), https(https)
	{



	}



	string HttpPath::createPathString() const{

		string result;

		if( this->https ){
			result = "https://";
		}else{
			result = "http://";
		}

		result += this->hostname;
		result += this->path;


		if( this->query_parameters.size() == 0 ){
			return result;
		}

		result += "?";

		bool first = true;

		for( const auto& query_param : this->query_parameters ){

			if( first ){

				result += query_param.first + "=" + query_param.second;

				first = false;

			}else{

				result += "&" + query_param.first + "=" + query_param.second;

			}

		}

		return result;

	}





	Platform* Platform::createPlatform(){

		return new Ubuntu("18");

	}

}
}