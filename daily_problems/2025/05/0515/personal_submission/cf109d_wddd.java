import java.io.*;
import java.util.*;

public class Permutation {

    FastReader is;
    PrintWriter out;
    String INPUT = "7\n" +
            "77 66 55 44 33 22 11";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Permutation().run();
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
        int[] a = is.na(n);
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }
        Arrays.sort(idx, (x, y) -> {
            if (a[x] != a[y]) {
                return Integer.compare(a[x], a[y]);
            } else {
                return Integer.compare(x, y);
            }
        });

        int[] perm = new int[n];
        int[] rank = new int[n];
        boolean sorted = true;
        int lucky = -1;
        for (int i = 0; i < n; i++) {
            if (lucky == -1 && isLucky(a[i])) {
                lucky = i;
            }
            if (idx[i] != i) {
                sorted = false;
            }
            rank[i] = idx[i];
            perm[idx[i]] = i;
        }
        if (sorted) {
            out.println(0);
            return;
        }
        if (lucky == -1) {
            out.println(-1);
            return;
        }

        List<int[]> ops = new ArrayList<>();
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            Set<Integer> cycle = new HashSet<>();
            getCycle(perm, i, cycle, visited);
            if (cycle.size() > 1) {
                lucky = move(perm, cycle, lucky, ops, rank);
            }
        }

        out.println(ops.size());
        for (int i = 0; i < ops.size(); i++) {
            out.println((ops.get(i)[0] + 1) + " " + (ops.get(i)[1] + 1));
        }
        if (!oj) {
            for (int i = 0; i < ops.size(); i++) {
                int x = ops.get(i)[0];
                int y = ops.get(i)[1];
                int temp = a[x];
                a[x] = a[y];
                a[y] = temp;
            }
            out.println(Arrays.toString(a));
        }
    }

    private boolean isLucky(int num) {
        while (num > 0) {
            int digit = num % 10;
            if (digit != 4 && digit != 7) {
                return false;
            }
            num /= 10;
        }
        return true;
    }

    private void getCycle(int[] perm, int ind, Set<Integer> cycle, boolean[] visited) {
        if (visited[ind]) {
            return;
        }
        visited[ind] = true;
        if (cycle.contains(ind)) {
            return;
        }
        cycle.add(ind);
        getCycle(perm, perm[ind], cycle, visited);
    }

    private int move(int[] perm, Set<Integer> cycle, int lucky, List<int[]> ops, int[] rank) {
        if (cycle.contains(lucky)) {
            while (rank[lucky] != lucky) {
                int target = rank[lucky];
                swap(perm, target, lucky, ops, rank);
                lucky = target;
            }
            return lucky;
        } else {
            int curr = lucky;
            int next = cycle.iterator().next();
            swap(perm, curr, next, ops, rank);
            curr = next;

            for (int i = 0; i < cycle.size() - 1; i++) {
                int target = rank[curr];
                swap(perm, target, curr, ops, rank);
                curr = target;
            }
            swap(perm, lucky, curr, ops, rank);

            return lucky;
        }
    }

    private void swap(int[] perm, int x, int y, List<int[]> ops, int[] rank) {
        if (x == y) {
            return;
        }

        int temp = perm[x];
        perm[x] = perm[y];
        perm[y] = temp;
        ops.add(new int[] {x, y});

        rank[perm[x]] = x;
        rank[perm[y]] = y;
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
