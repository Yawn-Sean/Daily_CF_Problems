import java.io.*;
import java.util.*;

public class Dijkstra2 {

    FastReader is;
    PrintWriter out;
    String INPUT = """
6 10 1
1
3 4
4 1
1 5
4 2
6 1
4 5
6 5
6 4
6 3
2 1
1 2
            """;

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Dijkstra2().run();
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
        int m = is.ni();
        int k = is.ni();
        Set<Integer> volunteers = new HashSet<>();
        for (int i = 0; i < k; i++) {
            volunteers.add(is.ni() - 1);
        }
        List<Integer>[] adjs = new List[n];
        for (int i = 0; i < n; i++) {
            adjs[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int u = is.ni() - 1;
            int v = is.ni() - 1;
            adjs[u].add(v);
            adjs[v].add(u);
        }
        int s = is.ni() - 1;
        int t = is.ni() - 1;

        int[] distTo = new int[n];
        Arrays.fill(distTo, Integer.MAX_VALUE / 2);
        distTo[s] = 0;

        int result = 0;
        Queue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(i -> i[1]));
        pq.add(new int[] {s, 0});
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            if (curr[1] > distTo[curr[0]]) {
                continue;
            }
            result = Math.max(result, distTo[curr[0]]);
            if (curr[0] == t) {
                break;
            }
            if (volunteers.contains(curr[0])) {
                distTo[curr[0]] = 0;
            }
            for (int next : adjs[curr[0]]) {
//                if (next != t && volunteers.contains(next) && distTo[next] > 0) {
//                    result = Math.max(result, distTo[curr[0]] + 1);
//                    distTo[next] = 0;
//                    pq.add(new int[] {next, 0});
//                    continue;
//                }
                if (distTo[next] > distTo[curr[0]] + 1) {
                    distTo[next] = distTo[curr[0]] + 1;
                    pq.add(new int[] {next, distTo[next]});
                }
            }
        }

        out.println(distTo[t] == Integer.MAX_VALUE / 2 ? -1 : result);
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
