// TestRestfulServicesWin32.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

#include "BaconIpsumMethods.h"
#include "GeolocationMethods.h"
#include "EarthquakePredictionMethods.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Win32 Test Project\n\n");

	//The API key needed for the geolocation
	char* geo_api_key = "735f0930ca73e6984112daf17a77559488cd1995eaed18715fa5080ac6e1ede8";
	
	//Get the location of the user, and save it to the info struct
	printf("Getting your location...\n");
	Services::LocationInformation info = Services::GeolocationMethods::Lookup(geo_api_key);
	printf("You're in %s, %s!\n\n", info.city, info.state);
	
	//Use the information to get the earthquake data for the user
	printf("Generating earthquake prediction for the next year in your location...\n");
	float results = Services::EarthquakePredictionMethods::GetEarthquakeProbability(info.zip, 365);
	printf("%3.2f%%\n\n", results);

	//Print bacon ipsum, because it is awesome
	printf("Getting Bacon Ipsum...\n");
	char* bacon = Services::BaconIpsumMethods::GenerateBaconIpsum(true, 1);
	printf("%s\n", bacon);
	system("pause");

	//Delete everything that was created (we don't want leaks)
	delete [] info.status;			
	delete [] info.state;
	delete [] info.city;
	delete [] info.country;
	delete [] info.ip;
	delete [] info.zip;
	delete [] bacon;

	//Exit Cleanly
	return 0;
}

