import java.io.*;
import java.util.*;

public class Naive1 {

    FastReader is;
    PrintWriter out;
    String INPUT = """
""";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Naive1().run();
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
            int n = is.ni();
            int m = is.ni();
            int q = is.ni();
            long[][] tasks = new long[n][3];
            for (int j = 0; j < n; j++) {
                tasks[j][0] = is.nl();
            }
            for (int j = 0; j < n; j++) {
                tasks[j][1] = is.nl();
            }
            long[] episodes = is.nal(m);
            long[][] queries = new long[q][2];
            for (int j = 0; j < q; j++) {
                queries[j][0] = is.nl();
                queries[j][1] = j;
            }

            plan(n, m, q, tasks, episodes, queries);
        }
    }

    private void plan(int n, int m, int q, long[][] tasks, long[] episodes, long[][] queries) {
        int[] result = new int[q];
        Arrays.sort(queries, Comparator.comparingLong(i -> i[0]));

        Arrays.sort(tasks, Comparator.comparingLong(i -> i[1]));
        tasks[n - 1][2] = tasks[n - 1][1] - tasks[n - 1][0];
        for (int i = n - 2; i >= 0; i--) {
            tasks[i][2] = Math.min(tasks[i + 1][2], tasks[i][1]) - tasks[i][0];
        }
        int tInd = 0;
        int eInd = 0;
        long time = 0;
        for (int i = 0; i < q; i++) {
            long[] query = queries[i];
            while ((eInd < m && time + episodes[eInd] <= query[0]) && (tInd >= n || time + episodes[eInd] <= tasks[tInd][2])) {
                time += episodes[eInd];
                eInd++;
            }
            while (tInd < n && query[0] >= tasks[tInd][1]) {
                time += tasks[tInd][0];
                tInd++;
            }
            while ((eInd < m && time + episodes[eInd] <= query[0]) && (tInd >= n || time + episodes[eInd] <= tasks[tInd][2])) {
                time += episodes[eInd];
                eInd++;
            }
            result[(int) query[1]] = eInd;
        }
        for (int i = 0; i < q; i++) {
            out.print(result[i] + " ");
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

        long nl() {
            return Long.parseLong(ns());
        }

        private long[] nal(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = nl();
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
