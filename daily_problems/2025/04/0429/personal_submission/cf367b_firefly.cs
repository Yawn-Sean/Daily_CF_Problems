using System.Text;

#if ONLINE_JUDGE
Template367B.Solution367B a = new();
a.Main();
#endif

namespace Template367B { 
    internal class Solution367B {
        public void Solve() {
            int n = br.ReadInt32(), m = br.ReadInt32(), p = br.ReadInt32();
            int[] a = br.ReadInt32(n), b = br.ReadInt32(m);
            Discrete<int> d = new(a.Concat(b));
            int k = d.Count;
            int[] mp = new int[k];
            int bad = 0;
            foreach (var x in b) {
                Add(x, 1);
            }
            List<int> ans = new();
            for (int i = 0; i < p; ++i) {
                int l = i, r = i;
                for (int j = 1; j < m && r < n; ++j, r += p) {
                    Add(a[r], -1);
                }
                while (r < n) {
                    Add(a[r], -1);
                    if (bad == 0) {
                        ans.Add(l + 1);
                    }
                    Add(a[l], 1);
                    r += p;
                    l += p;
                }
                for (r -= p; r >= l; r -= p) {
                    Add(a[r], 1);
                }
            }
            ans.Sort();
            bw.AppendLine(ans.Count);
            bw.AppendJoin(ans);

            void Add(int x, int value) {
                int i = d[x];
                if (mp[i] == 0) {
                    ++bad;
                }
                if ((mp[i] += value) == 0) {
                    --bad;
                }
            }
        }
        private readonly BufferedReader br = new(Console.OpenStandardInput(), 0);
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
    public class Discrete<T> {
        private readonly List<T> list;
        private readonly IComparer<T> comparer;
        public Discrete(IEnumerable<T> elements) : this(elements, null) { }
        public Discrete(IEnumerable<T> elements, IComparer<T> comparer) {
            this.list = elements.ToList();
            this.comparer = comparer ?? Comparer<T>.Default;
            if (list.Count == 0) {
                throw new ArgumentException("You cannot discretize zero elements!");
            }
            list.Sort(this.comparer);
            int i, j;
            for (i = 0, j = 1; j < list.Count; ++j) {
                if (this.comparer.Compare(list[i], list[j]) != 0) {
                    list[++i] = list[j];
                }
            }
            ++i;
            while (i < list.Count) {
                list.RemoveAt(list.Count - 1);
            }
        }
        public int Count { get => list.Count; }
        public int this[T index] {
            get {
                int j = list.BinarySearch(index, comparer);
                if (j < 0) {
                    j = ~j;
                }
                return j;
            }
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
            sr.Dispose();
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
            sw.Dispose();
        }
    }
}