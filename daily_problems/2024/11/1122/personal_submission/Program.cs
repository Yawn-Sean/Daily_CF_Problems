#define LOCAL
using System;
using System.Collections;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
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
            T = Read<int>();

            while (T -- > 0)
            {
                
            }

            Console.Write(output.ToString());
        }
    }
}
