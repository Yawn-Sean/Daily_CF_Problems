import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.*;

/**
 * @Description A
 * @Author Leon
 * @Date 2024/3/20
 */
public class A {
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
        char[] cs = sc.ns().toCharArray();
        int[] cnt = new int[10];
        int n = cs.length;
        for (int i = 0; i < n; i++) {
            cnt[cs[i]-'0']++;
        }
        cnt[1]--;
        cnt[6]--;
        cnt[8]--;
        cnt[9]--;
        int[] record = new int[7];

        record[0] = 1869;
        record[1] = 1968;
        record[2] = 1689;
        record[3] = 6198;
        record[4] = 1698;
        record[5] = 1986;
        record[6] = 1896;

        //
        int[] where = new int[7];
        where[1] = 3;
        where[2] = 6;
        where[3] = 2;
        where[4] = 5;
        where[5] = 1;
        where[6] = 4;
        StringBuilder sb = new StringBuilder();
        int last = 0;
        for (int i = 1; i <=9; i++) {
            while (cnt[i]>0){
                sb.append(i);
                last = (last * 10 + i)%7;
                cnt[i]--;
            }
        }
        sb.append(record[where[last]]);
        while (cnt[0]>0){
            sb.append(0);
            cnt[0]--;
        }
        out.println(sb);



//        out.println(1689%7);
//        out.println(1698%7);
//        out.println(1869%7);
//        out.println(1896%7);
//        out.println(1968%7);
//        out.println(1986%7);
//
//
//        out.println(9186%7);
//        out.println(9168%7);
//        out.println(9816%7);
//        out.println(9861%7);
//        out.println(9618%7);
//        out.println(9681%7);
//
//        out.println(6918%7);
//        out.println(6981%7);
//        out.println(6819%7);
//        out.println(6891%7);
//        out.println(6189%7);
//        out.println(6198%7);
//
//        for (int i = 1; i <=6 ; i++) {
//            int a = i*10000;
//            for (int j = 0; j <=6 ; j++) {
//                out.println((a+j)%7 + " " +(a+j));
//            }
//
//        }


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
