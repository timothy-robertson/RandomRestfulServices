#pragma once
#include "BaconIpsumMethods.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;

namespace RandomRestfulServices2010 {

	/// <summary>
	/// Wrapper C# Class for BaconIpsumMethods.h, which will generate A HttpWebRequest to the 
	/// BaconIpsum Service at http://baconipsum.com/.
	/// No API Key is required
	/// </summary>
	public ref class BaconIpsum :  public System::ComponentModel::Component
	{
	public:
		BaconIpsum(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		BaconIpsum(System::ComponentModel::IContainer ^container)
		{
			/// <summary>
			/// Required for Windows.Forms Class Composition Designer support
			/// </summary>

			container->Add(this);
			InitializeComponent();
		}
		
        /// <summary>
        ///	GetBaconIpsum takes in the parameters for generating the BaconIpsum, and makes a 
		/// HTTPWebrequest in order to get back generated BaconIpsum
        /// </summary>
        /// <param name="justMeat">If true, only returns meat, rather than meat and lorum ipsum</param>
        /// <param name="paragraphs">The number of paragraphs that are being requested</param>
		static System::String^ GetBaconIpsum(bool justMeat, int paragraphs)
		{
			char* buffer = Services::BaconIpsumMethods::GenerateBaconIpsum(justMeat, paragraphs);
			System::String^ str = gcnew String(reinterpret_cast<const char*>(buffer));
			delete [] buffer;
			return str;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BaconIpsum()
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
