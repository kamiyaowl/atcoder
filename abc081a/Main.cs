using System;
using System.Linq;
class Program {
    static void Main() {
        System.Console.WriteLine(Console.ReadLine().Count(x => x.Equals('1')));
    }
}