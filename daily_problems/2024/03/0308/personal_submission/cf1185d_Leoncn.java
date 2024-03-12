import java.util.*;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
/**
 * @Description
 *
 * @Author Leon
 * @Date 2024/03/28
 */
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
        int[] g = sc.na(n);
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0] = g[i];
            arr[i][1] = i;
        }
        Arrays.sort(arr,(a,b)->a[0]-b[0]);
        if(n==1 || n==2){
            out.println(1);
            return;
        }
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n-1; i++) {
            int dif = arr[i+1][0] - arr[i][0];
            map.merge(dif, 1, Integer::sum);
        }
        for (int i = 0; i < n; i++) {
            if(i == 0 ){
                int dif = arr[i+1][0] - arr[i][0];
                del(map, dif);
                if(map.size()==1){
                    out.println(arr[i][1] + 1);
                    return;
                }
                add(map, dif);
            }else if(i == n-1){
                int dif = arr[i][0] - arr[i-1][0];
                del(map, dif);
                if(map.size()==1){
                    out.println(arr[i][1] + 1);
                    return;
                }
                add(map, dif);


            }else {
                int dif1 = arr[i][0] - arr[i-1][0];
                int dif2 = arr[i+1][0] - arr[i][0];
                int dif = arr[i+1][0] - arr[i-1][0];
                del(map, dif1);
                del(map, dif2);
                add(map, dif);
                if(map.size()==1){
                    out.println(arr[i][1] + 1);
                    return;
                }
                add(map, dif1);
                add(map, dif2);
                del(map, dif);
            }
        }
        out.println(-1);

    }
    private static void del(Map<Integer, Integer> map, int key){
        int c = map.get(key);
        if(c==1){
            map.remove(key);
        }else {
            map.put(key, c-1);
        }
    }

    private static void add(Map<Integer, Integer> map, int key){
        map.merge(key, 1 , Integer::sum);
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
