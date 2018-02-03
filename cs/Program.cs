using System;
using System.Threading;

namespace cs
{
    class Program
    {
        static Boolean is_prime(int number)
        {
            if (number % 2 == 0)
                return false;

            double max = Math.Sqrt(number) + 1;
            for (int i = 3; i < max; i += 2)
            {
                if (number % i == 0)
                {
                    return false;
                }
            }
            return true;
        }

        static void loop_prime(int start_number, int max, int pas, ref int j)
        {
            int jj = 0;
            for (int i = start_number; i < max; i += pas)
            {
                if (is_prime(i))
                {
                    jj++;
                    // Console.Write(i);
                }
            }
            Console.WriteLine(jj);
            j += jj;
        }

        static void go(int max, int number_thread)
        {
            int j = 0;
            Console.Write("Prime Benchmark : " + max);
            Thread[] tab_t = new Thread[number_thread];
            for (int i = 0; i < number_thread * 2; i += 2)
            {
                int k = i + 1;

                tab_t[i / 2] = new Thread(()=>loop_prime(k, max, number_thread * 2, ref j));
                tab_t[i / 2].Start();
            }

                for (int i = 0; i < number_thread; i++)
                {
                    tab_t[i].Join();
            }
            Console.WriteLine("There are " +
             j + " prime numbers between " + 1 + " and " + max);
        }

        static void Main(string[] args)
        {
            var watch = System.Diagnostics.Stopwatch.StartNew();

            go(Int32.Parse(args[0]), Int32.Parse(args[1]));
            watch.Stop();
            var elapsedMs = watch.ElapsedMilliseconds;
            Console.WriteLine(elapsedMs/1000 + " sec");
            Console.ReadKey();
        }
    }
}
