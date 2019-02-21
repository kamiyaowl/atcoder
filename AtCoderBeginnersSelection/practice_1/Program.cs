using System;
using System.Linq;

class Program {
    static void Main() {
        var a = int.Parse(Console.ReadLine());
        var bc = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        var b = bc[0];
        var c = bc[1];
        var s = Console.ReadLine();

        System.Console.WriteLine($"{a+b+c} {s}");
    }
}