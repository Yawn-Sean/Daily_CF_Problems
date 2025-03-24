import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Math2 {

    FastReader is;
    PrintWriter out;
    String INPUT = "1000000000";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Math2().run();
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

    void solve() {
        int n = is.ni();

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0 && gcd(i, n / i) == 1) {
                int b0 = i;
                int b1 = n / i;

                long a0 = modInverse2(b1, b0);
                a0 = (long) (b0 - 1) * a0 % b0;
                long a1 = (n - 1 - b1 * a0) / b0;
                out.println("YES");
                out.println(2);
                out.println(a0 + " " + b0);
                out.println(a1 + " " + b1);
                return;
            }
        }

        out.println("NO");
    }

    private static long modInverse2(long a, long m) {
        long[] xy = new long[2];
        extgcd(a, m, xy);
        return (xy[0] % m + m) % m;
    }

    private static long extgcd(long a, long b, long[] xy) {
        if (a == 0) {
            xy[0] = 0;
            xy[1] = 1;
            return b;
        }
        long[] xy1 = new long[2];
        long d = extgcd(b % a, a, xy1);
        xy[0] = xy1[1] - (b / a) * xy1[0];
        xy[1] = xy1[0];
        return d;
    }

    public static int gcd(int a, int b) {
        return b == 0 ? Math.abs(a) : gcd(b, a % b);
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
