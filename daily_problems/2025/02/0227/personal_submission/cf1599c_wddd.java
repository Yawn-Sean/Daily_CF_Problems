package codeforces.C1599_C_BubbleStrike;

import java.io.*;
import java.util.*;

public class Math1 {

    FastReader is;
    PrintWriter out;
    String INPUT = "3 0.0000\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Math1().run();
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
        double p = is.nd();

        int left = 0;
        int right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;
            double pp = probability(n, mid);
            if (pp < p) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        out.println(left);
    }

    private double probability(int n, int m) {
        if (m == 0) {
            return 0;
        }
        if (m >= n - 1) {
            return 1;
        }

        if (m == 1) {
            return (double) 3 / (n * 2);
        }
        if (m == 2) {
            return (double) 3 * (n + 1) / (n * (n - 1));
        }
        if (m == n - 2) {
            return (double) (3 + (n - 3) * (n + 2)) / (n * (n - 1));
        }

        double p0 = (double) ((n - m - 2) * (n - m - 1) * (n - m)) / (n * (n - 1) * (n - 2));
        double p1 = (double) (m * (n - m) * (n - m - 1)) / (n * (n - 1) * (n - 2));
        return 1 - (p0 + p1 * 3 / 2);
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

        double nd() {
            return Double.parseDouble(ns());
        }
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
