#pragma once
#include "EarthquakePredictionMethods.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace RandomRestfulServices2010 {
	
	/// <summary>
	/// Wrapper C# Class for EarthquakePredictionMethods.h, which will generate A HttpWebRequest to the 
	/// open hazards Service at http://www.openhazards.com/data.
	/// No API Key is required
	/// </summary>
	public ref class EarthquakePrediction :  public System::ComponentModel::Component
	{
	public:
		EarthquakePrediction(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		EarthquakePrediction(System::ComponentModel::IContainer ^container)
		{
			/// <summary>
			/// Required for Windows.Forms Class Composition Designer support
			/// </summary>

			container->Add(this);
			InitializeComponent();
		}

        /// <summary>
        ///	GetChanceOfEarthquake takes in the parameters for generating a probability of an earthquake
		/// and returns back a float with precision to the hundreths place representing a precent chance
        /// </summary>
        /// <param name="location">A String which can identify a location, "City, State", "Zipcode", "Address", etc.</param>
        /// <param name="days">The number of days from the current day to predict. Entering 7 will generate odds for the next week for example</param>
		static float GetChanceOfEarthquake(System::String^ location, int days)
		{
			char* buffer = new char[location->Length + 1];
			for(int i = 0; i < location->Length; ++i)
			{
				buffer[i] = (char)location[i];
			}
			buffer[location->Length] = '\0';
			float result = Services::EarthquakePredictionMethods::GetEarthquakeProbability(buffer, days);
			delete [] buffer;
			return result;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EarthquakePrediction()
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
