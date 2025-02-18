using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using Template;
using System.Globalization;

#if !PROBLEM
SolutionA a = new();
a.Solve();
#endif

namespace Template
{
    internal class SolutionA
    {
        private readonly StreamReader sr = new(Console.OpenStandardInput());
        private T Read<T>()
            where T: struct, IConvertible
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
            int n = Read<int>();
            int[] a = ReadArray<int>(n);
            int[] idx = a.Select((x, i) => (x, i)).OrderBy(t => t.x).Select(t => t.i).ToArray();
            int[] ans = new int[n - 1];
            SimpleSegTree seg = new(new int[n]);
            foreach (var i in idx)
            {
                seg.Update(i, 1);
                for (int k = 1; k < n; ++k)
                {
                    int l = k * i + 1;
                    if (l >= n) break;
                    int r = Math.Min(n - 1, k * i + k);
                    ans[k - 1] += seg.Query(l, r);
                }
            }
            output.AppendJoin(' ', ans);
            Console.WriteLine(output.ToString());
        }
    }
}

public class SimpleSegTree
{
    private int[] tree;
    private int n;

    private void Build(int[] arr, int v, int l, int r)
    {
        if (l == r) tree[v] = arr[l];
        else
        {
            int m = l + (r - l) / 2;
            Build(arr, v * 2 + 1, l, m);
            Build(arr, v * 2 + 2, m + 1, r);
            tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
        }
    }
    private void Update(int v, int i, int l, int r, int value)
    {
        if (l == r && i == l) tree[v] = value;
        else
        {
            int m = l + (r - l) / 2;
            if (i <= m) Update(v * 2 + 1, i, l, m, value);
            else Update(v * 2 + 2, i, m + 1, r, value);
            tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
        }
    }
    private int Query(int v, int L, int R, int l, int r)
    {
        if (L > R) return 0;
        else if (l == L && r == R) return tree[v];
        int m = l + (r - l) / 2;
        int left = Query(v * 2 + 1, L, Math.Min(R, m), l, m);
        int right = Query(v * 2 + 2, Math.Max(L, m + 1), R, m + 1, r);
        return left + right;
    }

    public SimpleSegTree(int[] arr)
    {
        n = arr.Length;
        tree = new int[n * 4];
        Build(arr, 0, 0, n - 1);
    }
    public void Update(int i, int add) => Update(0, i, 0, n - 1, add);
    public int Query(int L, int R) => Query(0, L, R, 0, n - 1);
}
