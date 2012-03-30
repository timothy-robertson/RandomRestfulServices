#pragma once
#include "LocationInformation.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace RandomRestfulServices2010 {

	/// <summary>
	/// GeolocationInformation stores location information
	/// </summary>
	public ref class GeolocationInformation :  public System::ComponentModel::Component
	{
	public:
		GeolocationInformation(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		GeolocationInformation(Services::LocationInformation info)
		{
			InitializeComponent();
			
			status = gcnew String(reinterpret_cast<const char*>(info.status));
			city = gcnew String(reinterpret_cast<const char*>(info.city));
			state = gcnew String(reinterpret_cast<const char*>(info.state));
			country = gcnew String(reinterpret_cast<const char*>(info.country));
			ip = gcnew String(reinterpret_cast<const char*>(info.ip));
			zip = gcnew String(reinterpret_cast<const char*>(info.zip));
		}
		GeolocationInformation(System::ComponentModel::IContainer ^container)
		{
			/// <summary>
			/// Required for Windows.Forms Class Composition Designer support
			/// </summary>

			container->Add(this);
			InitializeComponent();
		}
		
		/// <summary>
		/// GetStatus returns a string. If the string == "OK", then the rest of the data is valid
		/// </summary>
		System::String^ GetStatus()
		{
			return status;
		}
		
		/// <summary>
		/// GetCity returns the city the user is in, in all caps
		/// </summary>
		System::String^ GetCity()
		{
			return city;
		}
		
		/// <summary>
		/// GetState returns the state the user is in, in all caps
		/// </summary>
		System::String^ GetState()
		{
			return state;
		}
		
		/// <summary>
		/// GetCountry returns the country the user is in, in all caps
		/// </summary>
		System::String^ GetCountry()
		{
			return country;
		}
		
		/// <summary>
		/// GetIP returns the ip address the user has, in all caps
		/// </summary>
		System::String^ GetIP()
		{
			return ip;
		}
		
		/// <summary>
		/// GetZipcode returns the sipcode the user is in, in all caps
		/// </summary>
		System::String^ GetZipcode()
		{
			return zip;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GeolocationInformation()
		{
			if (components)
			{
				delete components;
			}
		}
		System::String^ status;
		System::String^ city;
		System::String^ state;
		System::String^ country;
		System::String^ ip;
		System::String^ zip;

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
