import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class DP1 {

    FastReader is;
    PrintWriter out;
    String INPUT = "10\n" +
            "13\n" +
            "45\n" +
            "46\n" +
            "60\n" +
            "103\n" +
            "115\n" +
            "126\n" +
            "150\n" +
            "256\n" +
            "516\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new DP1().run();
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
        int[] ts = is.na(n);

        int[] dp = new int[n];
        dp[0] = 20;
        out.println(dp[0]);
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + 20;
            int t90 = ts[i] - 90;
            int ind = Arrays.binarySearch(ts, 0, i, t90);
            if (ind < 0) {
                ind = ~ind;
                if (ind == 0) {
                    dp[i] = Math.min(dp[i], 50);
                } else {
                    dp[i] = Math.min(dp[i], dp[ind - 1] + 50);
                }
            } else {
                dp[i] = Math.min(dp[i], dp[ind] + 50);
            }
            int t1440 = ts[i] - 1440;
            ind = Arrays.binarySearch(ts, 0, i, t1440);
            if (ind < 0) {
                ind = ~ind;
                if (ind == 0) {
                    dp[i] = Math.min(dp[i], 120);
                } else {
                    dp[i] = Math.min(dp[i], dp[ind - 1] + 120);
                }
            } else {
                dp[i] = Math.min(dp[i], dp[ind] + 120);
            }
            out.println(dp[i] - dp[i - 1]);
        }
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
