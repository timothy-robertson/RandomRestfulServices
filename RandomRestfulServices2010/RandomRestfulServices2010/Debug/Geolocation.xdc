<?xml version="1.0"?><doc>
<members>
<member name="T:RandomRestfulServices2010.GeolocationInformation" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\geolocationinformation.h" line="12">
<summary>
GeolocationInformation stores location information
</summary>
</member>
<member name="M:RandomRestfulServices2010.GeolocationInformation.GetStatus" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\geolocationinformation.h" line="46">
<summary>
GetStatus returns a string. If the string == "OK", then the rest of the data is valid
</summary>
</member>
<member name="M:RandomRestfulServices2010.GeolocationInformation.GetCity" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\geolocationinformation.h" line="54">
<summary>
GetCity returns the city the user is in, in all caps
</summary>
</member>
<member name="M:RandomRestfulServices2010.GeolocationInformation.GetState" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\geolocationinformation.h" line="62">
<summary>
GetState returns the state the user is in, in all caps
</summary>
</member>
<member name="M:RandomRestfulServices2010.GeolocationInformation.GetCountry" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\geolocationinformation.h" line="70">
<summary>
GetCountry returns the country the user is in, in all caps
</summary>
</member>
<member name="M:RandomRestfulServices2010.GeolocationInformation.GetIP" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\geolocationinformation.h" line="78">
<summary>
GetIP returns the ip address the user has, in all caps
</summary>
</member>
<member name="M:RandomRestfulServices2010.GeolocationInformation.GetZipcode" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\geolocationinformation.h" line="86">
<summary>
GetZipcode returns the sipcode the user is in, in all caps
</summary>
</member>
<member name="M:RandomRestfulServices2010.GeolocationInformation.Dispose" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\geolocationinformation.h" line="95">
<summary>
Clean up any resources being used.
</summary>
</member>
<member name="F:RandomRestfulServices2010.GeolocationInformation.components" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\geolocationinformation.h" line="113">
<summary>
Required designer variable.
</summary>
</member>
<member name="M:RandomRestfulServices2010.GeolocationInformation.InitializeComponent" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\geolocationinformation.h" line="119">
<summary>
Required method for Designer support - do not modify
the contents of this method with the code editor.
</summary>
</member>
<member name="T:RandomRestfulServices2010.Geolocation" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\geolocation.h" line="13">
<summary>
Wrapper C# Class for GeolocationMethods.h, which will generate A HttpWebRequest to the 
geolocation service at http://ipinfodb.com/
This requires an API key that you can obtain be registering here: http://ipinfodb.com/register.php
</summary>
</member>
<member name="M:RandomRestfulServices2010.Geolocation.GetLocation(System.String)" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\geolocation.h" line="38">
<summary>
GetLocation will return a GeolocationInformation Object, which stores zipcode, city, state, and country of 
The current IP address of the computer that is running this program. It also has a status, which you
should check if it equals "OK" otherwise the data may not be gathered.
</summary>
<param name="apikey">This is they key that you obtain by registering at http://ipinfodb.com/register.php. </param>
</member>
<member name="M:RandomRestfulServices2010.Geolocation.Dispose" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\geolocation.h" line="65">
<summary>
Clean up any resources being used.
</summary>
</member>
<member name="F:RandomRestfulServices2010.Geolocation.components" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\geolocation.h" line="77">
<summary>
Required designer variable.
</summary>
</member>
<member name="M:RandomRestfulServices2010.Geolocation.InitializeComponent" decl="false" source="c:\users\tim\documents\github\randomresfulservices\randomrestfulservices2010\randomrestfulservices2010\geolocation.h" line="83">
<summary>
Required method for Designer support - do not modify
the contents of this method with the code editor.
</summary>
</member>
</members>
</doc>