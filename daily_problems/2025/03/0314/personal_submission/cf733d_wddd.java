import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Map1 {

    FastReader is;
    PrintWriter out;
    String INPUT = "7\n" +
            "10 7 8\n" +
            "5 10 3\n" +
            "4 2 6\n" +
            "5 5 5\n" +
            "10 2 8\n" +
            "4 2 1\n" +
            "7 7 7\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Map1().run();
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
        int[][] edges = is.nmi(n, 3);

        Map<Integer, Map<Integer, int[]>> edgesMap = new HashMap<>();

        int pick1 = 0;
        int[] pick2 = {-1, -1, -1, -1, -1};

        for (int i = 0; i < edges.length; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];

            if (arrMin(edges[i]) > arrMin(edges[pick1])) {
                pick1 = i;
            }

            if (edgesMap.containsKey(a) && edgesMap.get(a).containsKey(b)) {
                int[] cc = edgesMap.get(a).get(b);
                if (arrMin(a, b, cc[0] + c) > arrMin(pick2[2], pick2[3], pick2[4])) {
                    pick2[0] = i;
                    pick2[1] = cc[1];
                    pick2[2] = a;
                    pick2[3] = b;
                    pick2[4] = cc[0] + c;
                }
            }
            if (edgesMap.containsKey(a) && edgesMap.get(a).containsKey(c)) {
                int[] bb = edgesMap.get(a).get(c);
                if (arrMin(a, c, bb[0] + b) > arrMin(pick2[2], pick2[3], pick2[4])) {
                    pick2[0] = i;
                    pick2[1] = bb[1];
                    pick2[2] = a;
                    pick2[3] = c;
                    pick2[4] = bb[0] + b;
                }
            }
            if (edgesMap.containsKey(b) && edgesMap.get(b).containsKey(c)) {
                int[] aa = edgesMap.get(b).get(c);
                if (arrMin(b, c, aa[0] + a) > arrMin(pick2[2], pick2[3], pick2[4])) {
                    pick2[0] = i;
                    pick2[1] = aa[1];
                    pick2[2] = b;
                    pick2[3] = c;
                    pick2[4] = aa[0] + a;
                }
            }

            // add a b c
            if (!edgesMap.containsKey(a)) {
                edgesMap.put(a, new HashMap<>());
            }
            if (!edgesMap.get(a).containsKey(b)) {
                edgesMap.get(a).put(b, new int[] {c, i});
            }
            if (edgesMap.get(a).get(b)[0] < c) {
                edgesMap.get(a).put(b, new int[] {c, i});
            }
            // add a c b
            if (!edgesMap.get(a).containsKey(c)) {
                edgesMap.get(a).put(c, new int[] {b, i});
            }
            if (edgesMap.get(a).get(c)[0] < b) {
                edgesMap.get(a).put(c, new int[] {b, i});
            }

            // add b a c
            if (!edgesMap.containsKey(b)) {
                edgesMap.put(b, new HashMap<>());
            }
            if (!edgesMap.get(b).containsKey(a)) {
                edgesMap.get(b).put(a, new int[] {c, i});
            }
            if (edgesMap.get(b).get(a)[0] < c) {
                edgesMap.get(b).put(a, new int[] {c, i});
            }
            // add b c a
            if (!edgesMap.get(b).containsKey(c)) {
                edgesMap.get(b).put(c, new int[] {a, i});
            }
            if (edgesMap.get(b).get(c)[0] < a) {
                edgesMap.get(b).put(c, new int[] {a, i});
            }

            // add c a b
            if (!edgesMap.containsKey(c)) {
                edgesMap.put(c, new HashMap<>());
            }
            if (!edgesMap.get(c).containsKey(a)) {
                edgesMap.get(c).put(a, new int[] {b, i});
            }
            if (edgesMap.get(c).get(a)[0] < b) {
                edgesMap.get(c).put(a, new int[] {b, i});
            }
            // add c b a
            if (!edgesMap.get(c).containsKey(b)) {
                edgesMap.get(c).put(b, new int[] {a, i});
            }
            if (edgesMap.get(c).get(b)[0] < a) {
                edgesMap.get(c).put(b, new int[] {a, i});
            }
        }

        if (pick2[0] == -1) {
            out.println(1);
            out.println(pick1 + 1);
        } else {
            if (arrMin(pick2[2], pick2[3], pick2[4]) > arrMin(edges[pick1])) {
                out.println(2);
                out.println((pick2[0] + 1) + " " + (pick2[1] + 1));
            } else {
                out.println(1);
                out.println(pick1 + 1);
            }
        }
    }

    public static int arrMin(int... edge) {
        return Math.min(edge[0], Math.min(edge[1], edge[2]));
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
