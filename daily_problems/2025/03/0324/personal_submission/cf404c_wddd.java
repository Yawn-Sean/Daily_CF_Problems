import java.io.*;
import java.util.*;

public class Graph {

    FastReader is;
    PrintWriter out;
    String INPUT = "3 1\n" +
            "0 0 0\n";

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
        int n = is.ni();
        int k = is.ni();
        int maxD = 0;
        Map<Integer, List<Integer>> distToV = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int d = is.ni();
            if (!distToV.containsKey(d)) {
                distToV.put(d, new ArrayList<>());
            }
            distToV.get(d).add(i);
            maxD = Math.max(maxD, d);
        }

        if (!distToV.containsKey(0) || distToV.get(0).size() != 1) {
            out.println(-1);
            return;
        }

        for (int d = 1; d <= maxD; d++) {
            if (!distToV.containsKey(d) || (long) distToV.get(d).size() > (long) distToV.get(d - 1).size() * (k - (d == 1 ? 0 : 1))) {
                out.println(-1);
                return;
            }
        }

        List<int[]> edges = new ArrayList<>();
        for (int d = 1; d <= maxD; d++) {
            List<Integer> curr = distToV.get(d);
            List<Integer> prev = distToV.get(d - 1);
            int pi = 0;
            for (int v : curr) {
                edges.add(new int[] {v + 1, prev.get(pi) + 1});
                pi++;
                pi %= prev.size();
            }
        }

        out.println(edges.size());
        for (int[] edge : edges) {
            out.println(edge[0] + " " + edge[1]);
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
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
