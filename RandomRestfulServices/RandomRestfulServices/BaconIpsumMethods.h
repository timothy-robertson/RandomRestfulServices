namespace Services
{
	class BaconIpsumMethods
	{
	public:        
		static __declspec(dllexport) char* GenerateBaconIpsum(bool justMeat, int paragraphs);

	};
};