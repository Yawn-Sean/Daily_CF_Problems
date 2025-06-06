import java.io.*;
import java.util.*;

public class Greedy {

    FastReader is;
    PrintWriter out;
    String INPUT = "10 3\n" +
            "4 2 4 2 1 0 1 0 0 0";

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
        int n = is.ni();
        int k = is.ni();
        int[] b = is.na(n);

        List<Integer>[] adjs = new List[n + 1];
        for (int i = 0; i <= n; i++) {
            adjs[i] = new ArrayList<>();
        }

        List<int[]> properties = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            int min = i + k;
            int count = b[i - 1];
            properties.add(new int[] {i, min, count});
        }

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            Collections.sort(properties, (x, y) -> {
                if (x[2] != y[2]) {
                    return Integer.compare(x[2], y[2]);
                } else {
                    return Integer.compare(x[0], y[0]);
                }
            });

            a[i] = properties.removeFirst()[0];
            for (int[] p : properties) {
                if (p[1] <= a[i] && p[2] > 0) {
                    p[2]--;
                }
            }
        }

        for (int aa : a) {
            out.print(aa);
            out.print(' ');
        }
        out.println();
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
