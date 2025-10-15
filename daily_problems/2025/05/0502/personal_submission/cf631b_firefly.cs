using System.Runtime.InteropServices;
using System.Text;

#if ONLINE_JUDGE
Template631D.Solution631D a = new();
a.Main();
#endif

namespace Template631D { 
    internal class Solution631D {
        public void Solve() {
            int n = br.ReadInt32(), m = br.ReadInt32();
            List<(long l, char c)> a = Reads(n), b = Reads(m);
            n = a.Count;
            m = b.Count;
            long ans = 0;
            if (m == 1) {
                foreach (var (l, c) in a) {
                    if (c == b[0].c) {
                        ans += Math.Max(l - b[0].l + 1, 0);
                    }
                }
            } else {
                List<(long l, char c)> bb = new();
                bb.AddRange(b.Skip(1).Take(m - 2));
                bb.Add((0, '0'));
                bb.AddRange(a);
                int[] z = GetZ(bb);
                for (int i = 1; i <= n - m + 1; ++i) {
                    if (z[m - 1 + i] == m - 2) {
                        if (a[i - 1].c == b[0].c && a[i - 1].l >= b[0].l
                            && a[i + m - 2].c == b[^1].c && a[i + m - 2].l >= b[^1].l) {
                            ++ans;
                        }
                    }
                }
            }
            bw.AppendLine(ans);

            (int, char) Read() {
                int l = br.ReadInt32();
                br.Read();
                char c = (char)br.Read();
                return (l, c);
            }

            List<(long, char)> Reads(int n) {
                List<(long l, char c)> a = new(n);
                a.Add(Read());
                for (int i = 1; i < n; ++i) {
                    var (l, c) = Read();
                    if (c == a[^1].c) {
                        a[^1] = (a[^1].l + l, c);
                    } else {
                        a.Add((l, c));
                    }
                }
                return a;
            }

            int[] GetZ(List<(long, char)> s) {
                int n = s.Count;
                int[] z = new int[n];
                for (int i = 1, l = 0, r = 0; i < n; ++i) {
                    if (i <= r && z[i - l] < r - i + 1) z[i] = z[i - l];
                    else {
                        z[i] = Math.Max(0, r - i + 1);
                        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
                    }
                    if (i + z[i] - 1 > r) { l = i; r = i + z[i] - 1; }
                }
                return z;
            }
        }
        private readonly BufferedReader br = new(Console.OpenStandardInput(), 1 << 16);
        private readonly BufferedWriter bw = new();
        public void Main() {
            int T = 1;
            // T = br.ReadInt32();
            while (T-- > 0) {
                Solve();
            }
            bw.Output();
        }
    }
    internal class BufferedReader : IDisposable {
        private StreamReader sr;
        private char[] buffer;
        private int S = 0, T = 0;

        public int Peek() {
            if (buffer == null) {
                return sr.Peek();
            }
            if (S == T) {
                T = sr.ReadBlock(buffer.AsSpan());
                if (T == 0) return -1;
                S = 0;
            }
            return buffer[S];
        }

        public int Read() {
            if (buffer == null) {
                return sr.Read();
            }
            int p = Peek();
            if (p >= 0) ++S;
            return p;
        }

        public string ReadLine() {
            int c;
            StringBuilder sb = new();
            while ((c = Read()) != -1) {
                if (c == '\r') continue; // omit '\r'
                if (c == '\n') {
                    if (sb.Length > 0) break;
                    else continue; // omit empty lines
                }
                sb.Append((char)c);
            }
            return sb.ToString();
        }

        public BufferedReader(Stream stream, int capacity) {
            sr = new(stream);
            if (capacity > 0) {
                buffer = new char[capacity];
            } else {
                buffer = null;
            }
        }

        public bool EndOfStream { get => buffer == null ? sr.EndOfStream : Peek() == -1; }

        public T ReadInt<T>() {
            char c;
            dynamic res = default(T);
            dynamic sign = 1;
            while (!EndOfStream && char.IsWhiteSpace((char)Peek())) Read();
            if (!EndOfStream && (char)Peek() == '-') {
                Read();
                sign = -1;
            }
            while (!EndOfStream && char.IsDigit((char)Peek())) {
                c = (char)Read();
                res = res * 10 + c - '0';
            }
            return res * sign;
        }

        public T[] ReadArray<T>(int count) => ReadArray<T>(count, 0);
        public T[] ReadArray<T>(int count, int startIndex) {
            T[] arr = new T[count + startIndex];
            for (int i = 0; i < count; ++i) arr[i + startIndex] = ReadInt<T>();
            return arr;
        }

        public int ReadInt32() => ReadInt<int>();
        public long ReadInt64() => ReadInt<long>();
        public int[] ReadInt32(int count) => ReadArray<int>(count);
        public long[] ReadInt64(int count) => ReadArray<long>(count);

        public double ReadDouble() {
            double res = ReadInt64();
            if ((char)Peek() == '.') {
                Read();
                double tail = 0.1;
                while (!EndOfStream && char.IsDigit((char)Peek())) {
                    char c = (char)Read();
                    res += (c - '0') * tail;
                    tail *= 0.1;
                }
            }
            return res;
        }
        public void Dispose() {
            sr.Close();
        }
    }

    internal class BufferedWriter : IDisposable {
        private StringBuilder sb = new();
        private StreamWriter sw;
        public BufferedWriter() : this(Console.OpenStandardOutput()) { }
        public BufferedWriter(Stream stream) { sw = new(stream); }

        public void Append(object val) => sb.AppendFormat("{0}", val);

        public void AppendLine(object val) => sb.AppendFormat("{0}\n", val);

        public void AppendYes(bool suc) => sb.AppendLine(suc ? "YES" : "NO");

        public void AppendJoin<T>(IEnumerable<T> values) => sb.AppendJoin(' ', values).AppendLine();
        public void AppendFormat(string format, params object[] args) => sb.AppendFormat(format, args);
        public void Output() {
            sw.Write(sb.ToString());
            sw.Flush();
            sb.Clear();
        }
        public void Dispose() {
            sw.Close();
        }
    }
}