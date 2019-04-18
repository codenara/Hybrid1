using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sharp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Cli1.Managed myManaged = new Cli1.Managed();    // C++/CLI Managed Wrapper
            Console.WriteLine(myManaged.DoInt(2));          // passing & returning int
            Console.WriteLine(myManaged.DoDouble(3.14));    // passing & returning double
            Console.WriteLine(myManaged.DoString("Hello")); // passing & returning string
            Console.ReadKey();
        }
    }
}
