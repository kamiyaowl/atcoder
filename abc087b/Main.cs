using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static IEnumerable<Tuple<int, int, int>> Greedy(int a, int b, int c, int x)
    {
        if (x == 0)
        {
            yield return new Tuple<int, int, int>(a, b, c);
            yield break;
        }
        else if (x < 0)
        {
            yield break;
        }
        // 順番に試す
        if (a > 0)
        {
            foreach (var r in Greedy(a - 1, b, c, a - 500))
            {
                yield return r;
            }
        }
        if (b > 0)
        {
            foreach (var r in Greedy(a, b - 1, c, a - 100))
            {
                yield return r;
            }
        }
        if (c > 0)
        {
            foreach (var r in Greedy(a, b, c - 1, a - 50))
            {
                yield return r;
            }
        }
    }
    static void Main()
    {
        var a = int.Parse(Console.ReadLine()); // 500
        var b = int.Parse(Console.ReadLine()); // 100
        var c = int.Parse(Console.ReadLine()); // 50
        var x = int.Parse(Console.ReadLine()); // target(50の倍数)

        var result = Greedy(a,b,c,x).Distinct().Count();
        System.Console.WriteLine(result);
    }
}