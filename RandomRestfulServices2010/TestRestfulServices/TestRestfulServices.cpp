// TestRestServices.cpp : main project file.

#include "stdafx.h"
#include "BaconIpsumMethods.h"
#include "EarthquakePredictionMethods.h"
#include "GeolocationMethods.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	//Let the user know what we are doing
    Console::WriteLine("Finding your location...");
	Services::LocationInformation locationResults = Services::GeolocationMethods::Lookup("735f0930ca73e6984112daf17a77559488cd1995eaed18715fa5080ac6e1ede8");
	//Convert the char* into a System::String^
	String^ locationStr = gcnew String(reinterpret_cast<const char*>(locationResults.zip));

	//Let the user know what we are doing
    Console::Write("Getting Earthquake Probability for " + locationStr + " within the next year...");

	float answer = Services::EarthquakePredictionMethods::GetEarthquakeProbability(locationResults.zip, 365);
	
	Console::WriteLine("" + answer + "%\n");
	
	//Let the user know what we are doing
    Console::WriteLine("Generating Bacon Ipsum...");
	//Generate the bacon ipsum
	//Note: This method will wait until it recieves a response from the server.
	//		It may take a while.
	char* results = Services::BaconIpsumMethods::GenerateBaconIpsum(true, 1);
	//Convert the char* into a System::String^
	String^ msg = gcnew String(reinterpret_cast<const char*>(results));

	//Show the user the newly generated bacon ipsum
    Console::WriteLine(msg);

	//Wait until key press then exit
	Console::Read();
    return 0;
}
