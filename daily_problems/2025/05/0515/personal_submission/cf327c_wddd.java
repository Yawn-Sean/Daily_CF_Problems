import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Math {

    FastReader is;
    PrintWriter out;
    String INPUT = "13990\n" +
            "2\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Math().run();
    }

    void run() throws Exception {
        is = oj ? new FastReader(System.in) : new FastReader(new ByteArrayInputStream(INPUT.getBytes()));
        out = new PrintWriter(System.out);

        long s = System.currentTimeMillis();
        solve();
        out.flush();
        objTr(System.currentTimeMillis() - s + "ms");
        out.close();
    }

    int mod = (int) (1e9 + 7);

    void solve() {
        String s = is.ns();
        int k = is.ni();

        long result = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '5' || s.charAt(i) == '0') {
                result += counts(s.length(), i, k);
                result %= mod;
            }
        }
        out.println(result);
    }

    private long counts(int a, int x, int k) {
        long r1 = modPow(2, x, mod);
        long r2 = modPow(2, (long) a * k % (mod - 1), mod) - 1;
        long r3 = modInverse(modPow(2, a, mod) - 1, mod);
        long r = (r1 * r2 % mod) * r3 % mod;
        if (r < 0) {
            r += mod;
        }
        return r % mod;
    }

    public static long modPow(long x, long y, long mod) {
        long result = 1;
        while (y > 0) {
            if ((y & 1) == 1) {
                result = result * x % mod;
            }
            x = x * x % mod;
            y >>>= 1;
        }
        return result;
    }

    public static long modInverse(long x, long m) {
        if (x == 0) return 0;
        return modPow(x, m - 2, m);
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        String ns() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        int ni() {
            return Integer.parseInt(ns());
        }
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
