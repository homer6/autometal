#pragma once

#include "autometal/platforms/Linux.h"


namespace autometal {
namespace platforms {
	

	class Ubuntu : public Linux{

		public:
			Ubuntu( const string version = "18" )
				:version(version)
			{}

			string version;

	};


}
}