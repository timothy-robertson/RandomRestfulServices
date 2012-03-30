using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TestRestfulServicesSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                System.Reflection.AssemblyName testAssembly =
                    System.Reflection.AssemblyName.GetAssemblyName("RandomRestfulServices2010.DLL");

                RestAPICalls.MakeAPICalls();
            }

            catch (System.IO.FileNotFoundException)
            {
                Console.WriteLine("The file cannot be found.");
                Console.ReadKey();
            }

            catch (BadImageFormatException)
            {
                Console.WriteLine("The file is not an assembly.");
                Console.ReadKey();
            }

            catch (System.IO.FileLoadException)
            {
                System.Console.WriteLine("The assembly has already been loaded.");
                System.Console.ReadKey();
            }
        }
    }
}
