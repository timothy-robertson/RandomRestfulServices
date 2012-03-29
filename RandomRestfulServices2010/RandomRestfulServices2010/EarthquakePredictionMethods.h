namespace Services
{
	class EarthquakePredictionMethods
	{
	public:        
		static __declspec(dllexport) float GetEarthquakeProbability(char* location, int days);

	};
};