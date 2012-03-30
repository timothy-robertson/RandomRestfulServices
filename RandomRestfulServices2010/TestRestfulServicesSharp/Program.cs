using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using RandomRestfulServices2010;

namespace TestRestfulServicesSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            //Let the user know what version they are using
            Console.Out.WriteLine("C# Test Project\n");

            //The API key needed for the geolocation
            String geo_api_key = "735f0930ca73e6984112daf17a77559488cd1995eaed18715fa5080ac6e1ede8";

            //Get the location of the user, and save it to the GeolocationInformation class
            Console.Out.WriteLine("Getting your location...");
            GeolocationInformation info = Geolocation.GetLocation(geo_api_key);
            Console.Out.WriteLine("You are in " + info.GetCity() + ", " + info.GetState() + "!\n");

            //Use the information to get the earthquake data for the user
            Console.Out.WriteLine("Generating earthquake prediction for the next year in your location...");
            Console.Out.WriteLine(EarthquakePrediction.GetChanceOfEarthquake(info.GetZipcode(), 365) + "%\n");

            //Print bacon ipsum, because it is awesome
            Console.Out.WriteLine("Generating BaconIpsum...");
            Console.Out.WriteLine(BaconIpsum.GetBaconIpsum(true, 1));

            Console.Read();
        }
    }
}
