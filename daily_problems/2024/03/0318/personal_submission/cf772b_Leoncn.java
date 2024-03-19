import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * @Description B
 * 4
 * 0 0
 * 0 1
 * 1 1
 * 1 0
 * 0.3535533906
 * @Author Leon
 * @Date 2024/3/5
 */
public class B {
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
        double[][] g = new double[n][2];
        for (int i = 0; i < n; i++) {
            g[i] = new double[]{sc.nd(), sc.nd()};
        }
        Double ans = Double.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            ans = Math.min(ans,pointToSegment(g[i], g[(i+n-1)%n], g[(i+1)%n])/2);
        }
        out.println(ans);


    }
    public static double pointToSegment(double[] point, double[] start, double[] end) {
        double[] v = new double[2];
        v[0] = end[0] - start[0];
        v[1] = end[1] - start[1];

        double[] w = new double[2];
        w[0] = point[0] - start[0];
        w[1] = point[1] - start[1];

        double c1 = dot(w, v);
        if (c1 <= 0) {
            // 点在线段起点侧
            return Math.sqrt(dot(w, w));
        }

        double c2 = dot(v, v);
        if (c2 <= c1) {
            // 点在线段终点侧
            double[] w2 = new double[2];
            w2[0] = end[0] - point[0];
            w2[1] = end[1] - point[1];
            return Math.sqrt(dot(w2, w2));
        }

        // 线段上的点
        double b = c1 / c2;
        double[] pb = new double[2];
        pb[0] = start[0] + b * v[0];
        pb[1] = start[1] + b * v[1];

        double[] diff = new double[2];
        diff[0] = point[0] - pb[0];
        diff[1] = point[1] - pb[1];

        return Math.sqrt(dot(diff, diff));
    }

    private static double dot(double[] v, double[] w) {
        return v[0] * w[0] + v[1] * w[1];
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
