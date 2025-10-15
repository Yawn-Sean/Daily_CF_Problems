#define LOCAL
using System;
using System.Collections;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using Template;

Solution s = new();
s.Solve();

namespace Template
{
    internal class Solution
    {
#if LOCAL
        private static readonly string FILEPATH = "in.txt";
        private readonly StreamReader sr = new(FILEPATH);
#else
        private readonly StreamReader sr = new(Console.OpenStandardInput());
#endif
        private T Read<T>()
            where T : struct, IConvertible
        {
            char c;
            dynamic res = default(T);
            dynamic sign = 1;
            while (!sr.EndOfStream && char.IsWhiteSpace((char)sr.Peek())) sr.Read();
            if (!sr.EndOfStream && (char)sr.Peek() == '-')
            {
                sr.Read();
                sign = -1;
            }
            while (!sr.EndOfStream && char.IsDigit((char)sr.Peek()))
            {
                c = (char)sr.Read();
                res = res * 10 + c - '0';
            }
            return res * sign;
        }
        private T[] ReadArray<T>(int n)
            where T : struct, IConvertible
        {
            T[] arr = new T[n];
            for (int i = 0; i < n; ++i) arr[i] = Read<T>();
            return arr;
        }

        public void Solve()
        {
            StringBuilder output = new();
            int T = 1;
            //T = Read<int>();
            while (T-- > 0)
            {
                int n = Read<int>(), m = Read<int>(), k = Read<int>();

                int[,] g = new int[n, m];
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j)
                    {
                        g[i, j] = Read<int>();
                    }
                }

                int max = 0, min = 0;

                for (int j = 0; j < m; ++ j)
                {
                    int ma = 0, op = 0;
                    int cur = 0, tot = 0;
                    for (int i = 0; i < n; ++ i)
                    {
                        tot += g[i, j];
                        cur += g[i, j];
                        if (i >= k)
                        {
                            cur -= g[i - k, j];
                        }
                        if (cur > ma)
                        {
                            ma = cur;
                            op = tot - cur;
                        }
                    }
                    //Console.WriteLine($"{j}: {ma} {op}");
                    max += ma;
                    min += op;
                }

                output.Append($"{max} {min}").AppendLine();
            }

            Console.Write(output.ToString());
        }
    }
}
