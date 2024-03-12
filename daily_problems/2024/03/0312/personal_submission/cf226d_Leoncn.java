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
        int m = sc.ni();
        int[][] g = sc.nmi(n, m);

        int[] flipsX = new int[n];
        int[] flipsY = new int[m];
        int[] totX = new int[n];
        int[] totY = new int[m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                totX[i] += g[i][j];
                totY[j] += g[i][j];
            }
        }
        while (min(totX)<0 || min(totY)<0 ){
            for (int i = 0; i < n; i++) {
                if(totX[i] < 0){
                    totX[i] *= -1;
                    flipsX[i] ^= 1;
                    for (int j = 0; j < m; j++) {
                        totY[j] -= g[i][j] * 2;
                        g[i][j] *= -1;
                    }
                }
            }
            for (int j = 0; j < m; j++) {
                if(totY[j] < 0){
                    totY[j] *= -1;
                    flipsY[j] ^= 1;
                    for (int i = 0; i < n; i++) {
                        totX[i] -= g[i][j] * 2;
                        g[i][j] *= -1;
                    }
                }
            }
        }
        
        StringBuilder sbX = new StringBuilder();
        int sumX = 0;
        for (int i = 0; i < n; i++) {
            sumX += flipsX[i];
        }
        sbX.append(sumX).append(" ");
        for (int i = 0; i < n; i++) {
            if(flipsX[i]>0){
                sbX.append( i + 1).append(" ");
            }
        }
        StringBuilder sbY = new StringBuilder();

        int sumY = 0;
        for (int i = 0; i < m; i++) {
            sumY += flipsY[i];
        }
        sbY.append(sumY).append(" ");
        for (int i = 0; i < m; i++) {
            if(flipsY[i]>0){
                sbY.append( i + 1).append(" ");
            }
        }
        out.println(sbX);
        out.println(sbY);
        
        
        
    }
    private static int min(int[] f) {
        int min = 0;
        for (int j : f) {
            min = Math.min(j, min);
        }
        return min;
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
