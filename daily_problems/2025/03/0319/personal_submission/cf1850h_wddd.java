import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Graph {

    FastReader is;
    PrintWriter out;
    String INPUT = "4\n" +
            "5 3\n" +
            "1 2 2\n" +
            "2 3 4\n" +
            "4 2 -6\n" +
            "6 5\n" +
            "1 2 2\n" +
            "2 3 4\n" +
            "4 2 -6\n" +
            "5 4 4\n" +
            "3 5 100\n" +
            "2 2\n" +
            "1 2 5\n" +
            "1 2 4\n" +
            "4 1\n" +
            "1 2 3\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Graph().run();
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
            int[][] conditions = is.nmi(m, 3);

            valid(n, m, conditions);
        }
    }

    private void valid(int n, int m, int[][] conditions) {
        List<int[]>[] adjs = new List[n + 1];
        for (int i = 0; i < adjs.length; i++) {
            adjs[i] = new ArrayList<>();
        }
        for (int[] condition : conditions) {
            adjs[condition[0]].add(condition);
            adjs[condition[1]].add(condition);
        }

        Long[] pos = new Long[n + 1];
        for (int i = 0; i < adjs.length; i++) {
            if (pos[i] == null) {
                if (!visit(adjs, i, 0, pos)) {
                    out.println("NO");
                    return;
                }
            }
        }
        out.println("YES");
    }

    private boolean visit(List<int[]>[] adjs, int ind, long position, Long[] pos) {
        if (pos[ind] != null) {
            return pos[ind] == position;
        }
        pos[ind] = position;

        for (int[] next : adjs[ind]) {
            if (next[0] == ind) {
                if (!visit(adjs, next[1], position + next[2], pos)) {
                    return false;
                }
            } else {
                if (!visit(adjs, next[0], position - next[2], pos)) {
                    return false;
                }
            }
        }
        return true;
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

        private int[][] nmi(int n, int m) {
            int[][] map = new int[n][];
            for (int i = 0; i < n; i++) {
                map[i] = na(m);
            }
            return map;
        }
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
