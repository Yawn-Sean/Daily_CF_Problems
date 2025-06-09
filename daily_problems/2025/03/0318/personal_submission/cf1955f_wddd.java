import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Greedy {

    FastReader is;
    PrintWriter out;
    String INPUT = "5\n" +
            "1 1 1 0\n" +
            "1 0 1 2\n" +
            "2 2 2 0\n" +
            "3 3 2 0\n" +
            "0 9 9 9\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Greedy().run();
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
        int t = is.ni();
        for (int i = 0; i < t; i++) {
            int[] p = is.na(4);
            int result = 0;
            result += p[0] / 2;
            result += p[1] / 2;
            result += p[2] / 2;
            result += p[3] / 2;
            p[0] %= 2;
            p[1] %= 2;
            p[2] %= 2;
            p[3] %= 2;
            if (p[0] == 1 && p[1] == 1 && p[2] == 1) {
                result++;
            }
            out.println(result);
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
