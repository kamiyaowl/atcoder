using System;
using System.Linq;
class Program {
    static void Main() {
        var n = int.Parse(Console.ReadLine());
        var arr = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

        int i = 0;
        for(i = 0; arr.All(x => x % 2 == 0) ; ++i) {
            arr = arr.Select(x => x/2).ToArray();
        }
        System.Console.WriteLine(i);
    }
}