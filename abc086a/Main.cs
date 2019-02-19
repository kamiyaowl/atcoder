using System;
using System.Linq;
class Program {
    static void Main() {
        var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        var a = input[0];
        var b = input[1];
        System.Console.WriteLine((a * b) % 2 == 0 ? "Even" : "Odd");
    }
}