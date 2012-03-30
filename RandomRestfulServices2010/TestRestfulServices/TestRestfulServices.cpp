// TestRestServices.cpp : main project file.

#include "stdafx.h"
#include "BaconIpsumMethods.h"
#include "EarthquakePredictionMethods.h"
#include "GeolocationMethods.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	char* geo_api_key = "735f0930ca73e6984112daf17a77559488cd1995eaed18715fa5080ac6e1ede8";
	
    Console::WriteLine("CLR Test Project\n");
	//Let the user know what we are doing
    Console::WriteLine("Finding your location...");
	Services::LocationInformation locationResults = Services::GeolocationMethods::Lookup(geo_api_key);
	//Convert the char* into a System::String^
	String^ locationStr = gcnew String(reinterpret_cast<const char*>(locationResults.zip));

	//Let the user know what we are doing
    Console::Write("Getting Earthquake Probability for " + locationStr + " within the next year...");

	float answer = Services::EarthquakePredictionMethods::GetEarthquakeProbability(locationResults.zip, 365);
	


	Console::WriteLine("" + answer + "%\n");
	
	//Let the user know what we are doing
    Console::WriteLine("Generating Bacon Ipsum...");
	//Generate the bacon ipsum
	char* results = Services::BaconIpsumMethods::GenerateBaconIpsum(true, 1);
	//Convert the char* into a System::String^
	String^ msg = gcnew String(reinterpret_cast<const char*>(results));

	//Show the user the newly generated bacon ipsum
    Console::WriteLine(msg);

	
	//Delete the buffers 
	delete [] results;
	delete [] locationResults.status;			
	delete [] locationResults.state;
	delete [] locationResults.city;
	delete [] locationResults.country;
	delete [] locationResults.ip;
	delete [] locationResults.zip;

	//Wait until key press then exit
	Console::Read();
    return 0;
}
