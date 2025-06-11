import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class DP {

    FastReader is;
    PrintWriter out;
    String INPUT = "10\n" +
            "abcdeabcde\n" +
            "5 5 5 5 4 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new DP().run();
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
        char[] cs = is.ns(n);
        int[] a = is.na(26);

        int mod = (int) (1e9 + 7);
        long[][] dp = new long[n][3];
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 1;
        for (int i = 1; i < n; i++) {
            dp[i][2] = Integer.MAX_VALUE;
            int minLen = Integer.MAX_VALUE;
            for (int j = i; j >= 0; j--) {
                minLen = Math.min(minLen, a[cs[j] - 'a']);
                if (minLen < i - j + 1) {
                    break;
                }
                dp[i][0] += (j - 1 >= 0 ? dp[j - 1][0] : 1);
                dp[i][0] %= mod;
                dp[i][1] = Math.max(dp[i][1], Math.max(j - 1 >= 0 ? dp[j - 1][1] : 0, i - j + 1));
                dp[i][2] = Math.min(dp[i][2], (j - 1 >= 0 ? dp[j - 1][2] : 0) + 1);
            }
        }

        out.println(dp[n - 1][0]);
        out.println(dp[n - 1][1]);
        out.println(dp[n - 1][2]);
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

        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        char[] ns(int n) {
            try {
                char[] buf = new char[n];
                for (int i = 0; i < n; i++) {
                    char c = (char) br.read();
                    while (isSpaceChar(c)) {
                        c = (char) br.read();
                    }
                    buf[i] = c;
                }
                return buf;
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
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
