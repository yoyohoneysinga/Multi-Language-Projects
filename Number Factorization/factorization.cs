using System;
using System.Collections.Generic;

namespace Factorization
{
    public class Factorization
    {
        static void Main(string[] args)
        {
            List<int> factors = new List<int>();
            Console.WriteLine("Enter a number: ");
            int n = int.Parse(Console.ReadLine());

            while (n != 1)
            {
                for (int i = 2; i <= n; i++)
                {
                    if (n % i == 0)
                    {
                        n /= i;
                        factors.Add(i);
                        break;
                    }
                }
            }

            Console.Write("n = ");
            for (int j = 0; j < factors.Count; j++)
            {
                Console.Write(factors[j]);
                if (j < factors.Count - 1)
                {
                    Console.Write(" * ");
                }
            }
            Console.WriteLine();
        }
    }
}
