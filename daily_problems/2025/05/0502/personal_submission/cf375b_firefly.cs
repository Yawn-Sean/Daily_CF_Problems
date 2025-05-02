using System.Text;

#if ONLINE_JUDGE
Template375B.Solution375B a = new();
a.Main();
#endif

namespace Template375B { 
    internal class Solution375B {
        public void Solve() {
            int n = br.ReadInt32(), m = br.ReadInt32();
            string[] s = new string[n];
            int[][] sum = new int[m][];
            for (int j = 0; j < m; ++j) {
                sum[j] = new int[n];
            }
            for (int i = 0; i < n; ++i) {
                s[i] = br.ReadLine();
                sum[0][i] = s[i][0] - '0';
                for (int j = 1; j < m; ++j) {
                    if (s[i][j] == '1') {
                        sum[j][i] = sum[j - 1][i] + 1;
                    }
                }
            }
            int ans = 0;
            int[] mp = new int[m + 1];
            for (int r = 0; r < m; ++r) {
                foreach (var x in sum[r]) {
                    ++mp[x];
                }
                for (int i = m, j = 0; i >= 0; --i) {
                    while (mp[i] > 0) {
                        --mp[i];
                        sum[r][j++] = i;
                    }
                }
                for (int i = 0; i < n; ++i) {
                    ans = Math.Max(ans, (i + 1) * sum[r][i]);
                }
            }
            bw.AppendLine(ans);
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

        private int Peek() {
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

        private int Read() {
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