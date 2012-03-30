#pragma once
#include "GeolocationMethods.h"
#include "GeolocationInformation.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace RandomRestfulServices2010 {
	
	/// <summary>
	/// Wrapper C# Class for GeolocationMethods.h, which will generate A HttpWebRequest to the 
	/// geolocation service at http://ipinfodb.com/
	/// This requires an API key that you can obtain be registering here: http://ipinfodb.com/register.php
	/// </summary>
	public ref class Geolocation :  public System::ComponentModel::Component
	{
	public:
		Geolocation(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Geolocation(System::ComponentModel::IContainer ^container)
		{
			/// <summary>
			/// Required for Windows.Forms Class Composition Designer support
			/// </summary>

			container->Add(this);
			InitializeComponent();
		}

		/// <summary>
		///	GetLocation will return a GeolocationInformation Object, which stores zipcode, city, state, and country of 
		/// The current IP address of the computer that is running this program. It also has a status, which you
		/// should check if it equals "OK" otherwise the data may not be gathered.
        /// </summary>
        /// <param name="apikey">This is they key that you obtain by registering at http://ipinfodb.com/register.php. </param>
        static RandomRestfulServices2010::GeolocationInformation^ GetLocation(System::String^ apikey)
		{
			char* buffer = new char[apikey->Length + 1];
			for(int i = 0; i < apikey->Length; ++i)
			{
				buffer[i] = (char)apikey[i];
			}
			buffer[apikey->Length] = '\0';

			Services::LocationInformation info = Services::GeolocationMethods::Lookup(buffer);
			RandomRestfulServices2010::GeolocationInformation^ geo_info = gcnew RandomRestfulServices2010::GeolocationInformation(info);
			delete [] info.status;
			delete [] info.state;
			delete [] info.city;
			delete [] info.country;
			delete [] info.ip;
			delete [] info.zip;
			return geo_info;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Geolocation()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			components = gcnew System::ComponentModel::Container();
		}
#pragma endregion
	};
}
