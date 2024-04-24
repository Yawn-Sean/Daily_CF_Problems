import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;
import java.util.InputMismatchException;

public class F {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = sc.ni();
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    static boolean[] prime;
    static {
        prime = new boolean[1000006];
        prime[1] = true;
        for (int i = 2; i*i <= 1000000 ; i++) {
            if(!prime[i]){
                for (int j = i+i; j <=1000; j+=i) {
                    prime[j] = true;
                }
            }
        }
    }
    public static void solve() {
        int n = sc.ni();
        int q = sc.ni();
        int now = n;
        Map<Integer,Integer> nMap = new HashMap<>();
        for (int i = 2; i*i <=now ; i++) {
            if(!prime[i]){
                int c = 0;
                if(now%i==0){
                    while (now%i==0){
                        c++;
                        now/=i;
                    }
                }
                nMap.put(i, c);
            }
        }
        if(now>1){
            nMap.put(now, 1);
        }

        Map<Integer, Integer> nMapTem = new HashMap<>(nMap);
        BigInteger big = new BigInteger(n+"");
        while (q-->0){
            int y = sc.ni();

            if(y==2){
                nMapTem = new HashMap<>(nMap);
                big = new BigInteger(n+"");
            }else {
                int x = sc.ni();
                big = big.multiply(new BigInteger(x+""));
                for (int i = 2; i*i <=x ; i++) {
                    if(!prime[i]){
                        int c = 0;
                        if(x%i==0){
                            while (x%i==0){
                                c++;
                                x/=i;
                            }
                        }
                        int f = nMapTem.getOrDefault(i, 0) + c;
                        nMapTem.put(i, f);
                    }
                }
                if(x>1){
                    nMapTem.merge(x, 1, Integer::sum);
                }
                int res = 1;
                for(int s: nMapTem.keySet()){
                    res *= nMapTem.get(s)+1;
                }
                if(big.divideAndRemainder(new BigInteger(res+""))[1].compareTo(new BigInteger(0+"")) == 0){
                    out.println("YES");
                }else {
                    out.println("NO");
                }

            }

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
