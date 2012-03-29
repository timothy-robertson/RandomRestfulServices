#include "LocationInformation.h"

namespace Services
{
	class GeolocationMethods
	{
	public:        
		static __declspec(dllexport) Services::LocationInformation Lookup(char* apikey);

	};
};