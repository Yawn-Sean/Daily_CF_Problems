import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Math2 {

    FastReader is;
    PrintWriter out;
    String INPUT = "100000 3";

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
        long m = is.ni();
        int r = is.ni();

        long rs = 0;
        long left = 0;
        long right = (m - 1) * 2;
        long diag = 0;
        for (int u = 1; u <= m; u++) {
            rs += left * u / 2;
            rs += right * (m - u + 1) / 2;
            rs += m * 2;

            rs -= Math.max(u - 2, 0) * 4L;
            diag += Math.max(u - 2, 0) * 2L;

            rs -= Math.max(m - 1 - u, 0) * 4L;
            diag += Math.max(m - 1 - u, 0) * 2L;

            if (u >= 2) {
                rs -= 2;
                diag++;
            }
            if (u <= m - 1) {
                rs -= 2;
                diag++;
            }

            left += 2;
            right -= 2;
        }

        out.println((rs * r + diag * Math.sqrt(r * r + r * r)) / (m * m));
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
