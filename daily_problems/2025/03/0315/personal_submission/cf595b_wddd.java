import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Math {

    FastReader is;
    PrintWriter out;
    String INPUT = "8 2\n" +
            "1 22 3 44\n" +
            "5 4 3 2\n";

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

    static int MOD = (int) (1e9 + 7);

    void solve() {
        int n = is.ni();
        int k = is.ni();
        int c = n / k;
        int[] as = is.na(c);
        int[] bs = is.na(c);

        int[] counts = new int[c];
        long maxA = (long) (java.lang.Math.pow(10, k) - 1);
        long maxAPrev = (long) (java.lang.Math.pow(10, k - 1) - 1);
        for (int i = 0; i < c; i++) {
            counts[i] = goodNumbers(k, as[i], bs[i], maxA, maxAPrev);
        }
        long result = 1;
        for (int cc : counts) {
            result *= cc;
            result %= MOD;
        }
        out.println(result);
    }

    private int goodNumbers(int k, int a, int b, long maxA, long maxAPrev) {
        long as = maxA / a + 1;

        long remaining = (-b * (maxAPrev + 1)) % a;
        if (remaining < 0) {
            remaining += a;
        }
        long abs = java.lang.Math.floorDiv(maxAPrev - remaining, a) + 1;

        return (int) (as - abs);
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

        int[] na(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = ni();
            }
            return a;
        }
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
