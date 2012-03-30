#include "stdafx.h"
#include "BaconIpsumMethods.h"

using namespace System;

namespace Services
{
	char* Services::BaconIpsumMethods::GenerateBaconIpsum(bool justMeat, int paragraphs)
	{
		System::String^ url = "http://baconipsum.com/api/?type=";
		if(justMeat)
		{
			url += "meat";
		}
		else
		{
			url += "meat-and-filler";
		}
		url += "&paras=" + paragraphs;
		
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
		char* returnString = new char[paragraphs * 2048];
		int index = 0;
		// Reads 256 characters at a time.
		int count = readStream->Read( read, 0, 256 );
		while ( count > 0 )
		{
		   // Dumps the 256 characters on a String* and displays the String* to the console.
		   //String^ str = gcnew String( read,0,count );
		   for(int tempIndex = index; tempIndex < index + count; tempIndex++)
		   {
				if(read[tempIndex - index] == '"' || read[tempIndex - index] == '[' || read[tempIndex - index] == ']')
				{
					returnString[tempIndex] = '\b';
				}
				else
				{
					returnString[tempIndex] = (char)read[tempIndex - index];
				}
		   }
		   index += count;
		   count = readStream->Read( read, 0, 256 );
		}
		returnString[index] = '\0';
		// Releases the resources of the response.
		response->Close();
		// Releases the resources of the Stream.
		readStream->Close();	
		
		return returnString;
	}
};