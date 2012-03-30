<?xml version="1.0"?><doc>
<members>
<member name="T:RandomRestfulServices2010.EarthquakePrediction" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\earthquakeprediction.h" line="12">
<summary>
Wrapper C# Class for EarthquakePredictionMethods.h, which will generate A HttpWebRequest to the 
open hazards Service at http://www.openhazards.com/data.
No API Key is required
</summary>
</member>
<member name="M:RandomRestfulServices2010.EarthquakePrediction.GetChanceOfEarthquake(System.String,System.Int32)" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\earthquakeprediction.h" line="37">
<summary>
GetChanceOfEarthquake takes in the parameters for generating a probability of an earthquake
and returns back a float with precision to the hundreths place representing a precent chance
</summary>
<param name="location">A String which can identify a location, "City, State", "Zipcode", "Address", etc.</param>
<param name="days">The number of days from the current day to predict. Entering 7 will generate odds for the next week for example</param>
</member>
<member name="M:RandomRestfulServices2010.EarthquakePrediction.Dispose" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\earthquakeprediction.h" line="57">
<summary>
Clean up any resources being used.
</summary>
</member>
<member name="F:RandomRestfulServices2010.EarthquakePrediction.components" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\earthquakeprediction.h" line="69">
<summary>
Required designer variable.
</summary>
</member>
<member name="M:RandomRestfulServices2010.EarthquakePrediction.InitializeComponent" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\earthquakeprediction.h" line="75">
<summary>
Required method for Designer support - do not modify
the contents of this method with the code editor.
</summary>
</member>
</members>
</doc>