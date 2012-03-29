// TestRestServices.cpp : main project file.

#include "stdafx.h"
#include "BaconIpsumMethods.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	//Let the user know what we are doing
    Console::WriteLine("Generating Bacon Ipsum...");

	//Generate the bacon ipsum
	//Note: This method will wait until it recieves a response from the server.
	//		It may take a while.
	char* results = Services::BaconIpsumMethods::GenerateBaconIpsum(true, 10);
	//Convert the char* into a System::String^
	String^ msg = gcnew String(reinterpret_cast<const char*>(results));
	//Delete the buffer
	delete [] results;

	//Show the user the newly generated bacon ipsum
    Console::WriteLine(msg);

	//Wait until key press then exit
	Console::Read();
    return 0;
}
