import java.io.*;
import java.util.StringTokenizer;

/**
 * @author ikun
 * @version v1.0.0
 * @since 2024/3/11 12:12
 **/
public class cf_780b_iron_buster {
    // 二分答案
    static long[] a, b;
    static boolean check(double mid) {
        double mn = 0;
        double mx = 1e9 + 10;
        for (int i = 0; i < a.length; i++) {
            mn = Math.max(mn, a[i] - b[i] * mid);
            mx = Math.min(mx, a[i] + b[i] * mid);
        }
        return mx > mn;
    }
    public static void solve() throws IOException {
        int n = in.nextInt();
        a = new long[n];
        b = new long[n];
        for (int i = 0; i < n; i++) a[i] = in.nextInt();
        for (int i = 0; i < n; i++) b[i] = in.nextInt();
        double err = 0.0000001;
        double l = 0, r = 1e9 + 10;
        while (r - l > err) {
            double mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        out.println(l);
    }

    static boolean MULTI_CASE = false;
    public static void main(String[] args) throws Exception {
        int T = MULTI_CASE ? in.nextInt() : 1;
        while (T-- > 0) {
            solve();
        }
        out.close();
    }

    static InputReader in = new InputReader();
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    static class InputReader {
        private StringTokenizer st;
        private BufferedReader bf;

        public InputReader() {
            bf = new BufferedReader(new InputStreamReader(System.in));
            st = null;
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(bf.readLine());
            }
            return st.nextToken();
        }

        public String nextLine() throws IOException {
            return bf.readLine();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}
