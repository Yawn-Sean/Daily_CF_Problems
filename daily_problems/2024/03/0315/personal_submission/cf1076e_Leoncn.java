import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * @Description 1076E
 * @Author Leon
 * @Date 2024/2/27
 */
public class E {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) {
        int t = 1;
        while (t-->0){
            solve();
        }
        out.close();
    }
    static int n;
    static ArrayList<Integer>[] g;
    static ArrayList<int[]>[] queries;
    static long[] w;
    private static void solve(){
        n = sc.ni();
        g = new ArrayList[n];
        w = new long[n];
        queries = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
            queries[i] = new ArrayList<>();
        }
        for (int i = 0; i < n-1; i++) {
            int a = sc.ni() - 1, b = sc.ni() - 1;
            g[a].add(b);
            g[b].add(a);
        }
        w[0] = 1;
        int q = sc.ni();
        for (int i = 0; i < q; i++) {
            int u = sc.ni() - 1;
            int d = sc.ni();
            int x = sc.ni();
            queries[u].add(new int[]{x, d});
        }
        dfs(0, -1, 0, 0, new long[n]);
        printArr(w);
    }
    private static void dfs(int c, int p, int depth, long s, long[] arr){
        for(int[] q : queries[c]) {
            s += q[0];
            if(depth + q[1] + 1 < n) arr[depth + q[1] + 1] += q[0];
        }
        w[c] = s - arr[depth];
        for(int v : g[c]) {
            if(v == p) continue;
            dfs(v, c, depth + 1, w[c], arr);
        }
        for(int[] q : queries[c]) {
            s -= q[0];
            if(depth + q[1] + 1 < n) arr[depth + q[1] + 1] -= q[0];
        }
    }
    private static void printArr(long[] w){
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(w[i]).append(" ");
        }
        out.println(sb);
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
