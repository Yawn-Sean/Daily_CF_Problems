import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.util.InputMismatchException;

public class D {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        int n = sc.ni();
        int[] xs = new int[n];
        int[] ys = new int[n];
        for (int i = 0; i < n; i++) {
            xs[i] = sc.ni();
            ys[i] = sc.ni();
        }
        int[] uxs = unique(xs);
        int[] uys = unique(ys);
        TreeSet<Integer>[] byY = new TreeSet[n];
        for (int i = 0; i < n; i++) {
            byY[i] = new TreeSet<>();
        }
        for (int i = 0; i < n; i++) {
            int x = Arrays.binarySearch(uxs, xs[i]);
            int y = Arrays.binarySearch(uys, ys[i]);
            byY[y].add(x);
        }
        Fenwick tree = new Fenwick(n);
        long answer = 0;
        for (int y = n - 1; y >= 0; y--) {
            if (byY[y].isEmpty()) {
                continue;
            }
            List<Integer> cur = new ArrayList<>(byY[y]);
            for (int x : cur) {
                if (tree.pre(x, x) == 0) {
                    tree.add(x);
                }
            }
            int total = tree.pre(n - 1);
            answer += sum(total);
            answer -= sum(tree.pre(0, cur.get(0) - 1));
            answer -= sum(tree.pre(cur.get(cur.size() - 1) + 1, n - 1));
            for (int i = 0; i + 1 < cur.size(); i++) {
                int a = cur.get(i);
                int b = cur.get(i + 1);
                answer -= sum(tree.pre(a + 1, b - 1));
            }
        }
        out.print(answer);
    }

    static long sum(long x) {
        return x * (x + 1) / 2;
    }

    static int[] unique(int[] a) {
        Arrays.sort(a = a.clone());
        int sz = 1;
        for (int i = 1; i < a.length; i++) {
            if (a[i] != a[i - 1]) {
                a[sz++] = a[i];
            }
        }
        return Arrays.copyOfRange(a, 0, sz);
    }



    static class Fenwick {
        int[] tree;

        Fenwick(int n) {
            tree = new int[n + 1];
        }

        void add(int at) {
            for (at++; at < tree.length; at += at & -at) {
                tree[at]++;
            }
        }

        int pre(int at) {
            int s = 0;
            for (at++; at > 0; at -= at & -at) {
                s += tree[at];
            }
            return s;
        }

        int pre(int l, int r) {
            return pre(r) - pre(l - 1);
        }

    }

    public static class RealFastReader {
        InputStream is;

        public RealFastReader(final InputStream is) {
            this.is = is;
        }

        private byte[] inbuf = new byte[8192];
        public int lenbuf = 0, ptrbuf = 0;

        public int readByte() {
            if (lenbuf == -1) {
                throw new InputMismatchException();
            }
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = is.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) {
                    return -1;
                }
            }
            return inbuf[ptrbuf++];
        }

        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        private int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b))
                ;
            return b;
        }

        public double nd() {
            return Double.parseDouble(ns());
        }

        public char nc() {
            return (char) skip();
        }

        public String ns() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        public char[] ns(int n) {
            char[] buf = new char[n];
            int b = skip(), p = 0;
            while (p < n && !(isSpaceChar(b))) {
                buf[p++] = (char) b;
                b = readByte();
            }
            return n == p ? buf : Arrays.copyOf(buf, p);
        }

        public int[] na(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = ni();
            }
            return a;
        }

        public long[] nal(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = nl();
            }
            return a;
        }

        public char[][] nm(int n, int m) {
            char[][] map = new char[n][];
            for (int i = 0; i < n; i++) {
                map[i] = ns(m);
            }
            return map;
        }

        public int[][] nmi(int n, int m) {
            int[][] map = new int[n][];
            for (int i = 0; i < n; i++) {
                map[i] = na(m);
            }
            return map;
        }

        public int ni() {
            int num = 0;
            int b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
                ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

        public long nl() {
            long num = 0;
            int b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
                ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }
    }
}
