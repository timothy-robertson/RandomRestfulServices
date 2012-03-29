#include "stdafx.h"
#include "GeolocationMethods.h"

using namespace System;

namespace Services
{
	Services::LocationInformation Services::GeolocationMethods::Lookup(char* apikey)
	{
		System::String^ url = "http://api.ipinfodb.com/v3/ip-city/?key=";

		//Convert the char* into a System::String^
		String^ key = gcnew String(reinterpret_cast<const char*>(apikey));
		url += key;

		url += "&format=xml";
		
		//Create a request to the bacon ipsum server
		Net::HttpWebRequest^ myReq = dynamic_cast<Net::HttpWebRequest^>(Net::WebRequest::Create( url ));
		//Get a response from the server
		Net::HttpWebResponse^ response = dynamic_cast<Net::HttpWebResponse^>(myReq->GetResponse());
		// Gets the stream associated with the response.
		IO::Stream^ receiveStream = response->GetResponseStream();
		Text::Encoding^ encode = Text::Encoding::GetEncoding( "utf-8" );
		// Pipes the stream to a higher level stream reader with the required encoding format.
		IO::StreamReader^ readStream = gcnew IO::StreamReader( receiveStream,encode );
		array<Char>^ read = gcnew array<Char>(1024);
		// Reads 256 characters at a time.
		Services::LocationInformation info;
		int count = readStream->Read( read, 0, 1024 );
		while ( count > 0 )
		{
		   // Dumps the 256 characters on a String* and displays the String* to the console.
		   String^ str = gcnew String( read,0,count );
		   
		   int index = str->IndexOf("<statusCode>");
		   if(index != -1)
		   {
			   index = index + 12;
			   String^ substr = str->Substring(index);
			   substr = substr->Substring(0, substr->IndexOf("</statusCode>"));	   
			   info.status = new char[substr->Length + 1];
			   for(int i = 0; i < substr->Length; ++i)
			   {
				   info.status[i] = (char)substr[i];
			   }
			   info.status[substr->Length] = '\0';
		   }
		   
		   index = str->IndexOf("<ipAddress>");
		   if(index != -1)
		   {
			   index = index + 11;
			   String^ substr = str->Substring(index);
			   substr = substr->Substring(0, substr->IndexOf("</ipAddress>"));	   
			   info.ip = new char[substr->Length + 1];
			   for(int i = 0; i < substr->Length; ++i)
			   {
				   info.ip[i] = (char)substr[i];
			   }
			   info.ip[substr->Length] = '\0';
		   }
		   
		   index = str->IndexOf("<countryName>");
		   if(index != -1)
		   {
			   index = index + 13;
			   String^ substr = str->Substring(index);
			   substr = substr->Substring(0, substr->IndexOf("</countryName>"));	   
			   info.country = new char[substr->Length + 1];
			   for(int i = 0; i < substr->Length; ++i)
			   {
				   info.country[i] = (char)substr[i];
			   }
			   info.country[substr->Length] = '\0';
		   }
		   
		   index = str->IndexOf("<regionName>");
		   if(index != -1)
		   {
			   index = index + 12;
			   String^ substr = str->Substring(index);
			   substr = substr->Substring(0, substr->IndexOf("</regionName>"));	   
			   info.state = new char[substr->Length + 1];
			   for(int i = 0; i < substr->Length; ++i)
			   {
				   info.state[i] = (char)substr[i];
			   }
			   info.state[substr->Length] = '\0';
		   }
		   
		   index = str->IndexOf("<cityName>");
		   if(index != -1)
		   {
			   index = index + 10;
			   String^ substr = str->Substring(index);
			   substr = substr->Substring(0, substr->IndexOf("</cityName>"));	   
			   info.city = new char[substr->Length + 1];
			   for(int i = 0; i < substr->Length; ++i)
			   {
				   info.city[i] = (char)substr[i];
			   }
			   info.city[substr->Length] = '\0';
		   }
		   
		   index = str->IndexOf("<zipCode>");
		   if(index != -1)
		   {
			   index = index + 9;
			   String^ substr = str->Substring(index);
			   substr = substr->Substring(0, substr->IndexOf("</zipCode>"));	   
			   info.zip = new char[substr->Length + 1];
			   for(int i = 0; i < substr->Length; ++i)
			   {
				   info.zip[i] = (char)substr[i];
			   }
			   info.zip[substr->Length] = '\0';
		   }

		   count = readStream->Read( read, 0, 256 );
		}
		// Releases the resources of the response.
		response->Close();
		// Releases the resources of the Stream.
		readStream->Close();	
		return info;
	}
};