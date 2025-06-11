import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Greedy {

    FastReader is;
    PrintWriter out;
    String INPUT = "4\n" +
            "1 4 5 1000000\n";

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
        int s = (int) 1e6;
        int n = is.ni();
        int[] x = is.na(n);
        boolean[] visited = new boolean[n];

        boolean[] picked = new boolean[(int) (1e6 + 1)];
        for (int xx : x) {
            picked[xx] = true;
        }

        boolean[] y = new boolean[(int) (1e6 + 1)];
        int m = 0;
        for (int i = 0; i < x.length; i++) {
            int match = s - (x[i] - 1);
            if (!picked[match]) {
                picked[match] = true;
                y[match] = true;
                m++;
                visited[i] = true;
            }
        }

        int p = 1;
        for (int i = 0; i < x.length; i++) {
            if (x[i] > s / 2 || visited[i]) {
                continue;
            }
            while (picked[p] || picked[s - (p - 1)]) {
                p++;
            }
            picked[p] = true;
            picked[s - (p - 1)] = true;
            m += 2;
            y[p] = true;
            y[s - (p - 1)] = true;
        }

        out.println(m);
        for (int i = 1; i < y.length; i++) {
            if (y[i]) {
                out.print(i + " ");
            }
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
