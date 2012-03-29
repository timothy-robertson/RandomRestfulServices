#include "stdafx.h"
#include "EarthquakePredictionMethods.h"

using namespace System;

namespace Services
{
	float Services::EarthquakePredictionMethods::GetEarthquakeProbability(char* location, int days)
	{
		//Convert the char* into a System::String^
		String^ loc = gcnew String(reinterpret_cast<const char*>(location));

		System::String^ url = "http://api.openhazards.com/GetEarthquakeProbability?q='" + loc + "'&w=" + days;
		
		//Create a request to the bacon ipsum server
		Net::HttpWebRequest^ myReq = dynamic_cast<Net::HttpWebRequest^>(Net::WebRequest::Create( url ));
		//Get a response from the server
		Net::HttpWebResponse^ response = dynamic_cast<Net::HttpWebResponse^>(myReq->GetResponse());
		// Gets the stream associated with the response.
		IO::Stream^ receiveStream = response->GetResponseStream();
		Text::Encoding^ encode = Text::Encoding::GetEncoding( "utf-8" );
		// Pipes the stream to a higher level stream reader with the required encoding format.
		IO::StreamReader^ readStream = gcnew IO::StreamReader( receiveStream,encode );
		array<Char>^ read = gcnew array<Char>(256);
		// Reads 256 characters at a time.
		float result = -1.0f;
		int count = readStream->Read( read, 0, 256 );
		while ( count > 0 )
		{
		   // Dumps the 256 characters on a String* and displays the String* to the console.
		   String^ str = gcnew String( read,0,count );
		   
		   int index = str->IndexOf("<prob>");
		   if(index != -1)
		   {
			   index = index + 6;
			   String^ substr = str->Substring(index);
			   substr = substr->Substring(0, substr->IndexOf("%"));
			   result = float::Parse(substr);
		   }

		   count = readStream->Read( read, 0, 256 );
		}
		// Releases the resources of the response.
		response->Close();
		// Releases the resources of the Stream.
		readStream->Close();

		return result;
	}
};