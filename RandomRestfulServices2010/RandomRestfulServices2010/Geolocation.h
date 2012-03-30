#pragma once
#include "GeolocationMethods.h"
#include "GeolocationInformation.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace RandomRestfulServices2010 {

	/// <summary>
	/// Summary for Geolocation
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
