import java.io.*;
import java.util.*;

public class Graph1 {

    FastReader is;
    PrintWriter out;
    String INPUT = "4 3\n" +
            "0 1 0 1\n" +
            "0 1\n" +
            "1 2\n" +
            "2 3\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Graph1().run();
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

        int[] es = is.na(n);

        List<Integer>[] adjs = new List[n];
        for (int i = 0; i < n; i++) {
            adjs[i] = new ArrayList<>();
        }
        int[] inDegrees = new int[n];

        for (int i = 0; i < m; i++) {
            int t = is.ni();
            int s = is.ni();
            adjs[s].add(t);
            inDegrees[t]++;
        }

        int cs = coprocessors(n, es, adjs, inDegrees);
        out.println(cs);
    }
    private int coprocessors(int n, int[] es, List<Integer>[] adjs, int[] inDegrees) {
        boolean[] executed = new boolean[n];
        Set<Integer> coTasks = new HashSet<>();
        for (int i = 0; i < n; i++) {
            if (inDegrees[i] == 0 && !executed[i]) {
                if (es[i] == 1) {
                    coTasks.add(i);
                } else {
                    execute(i, 0, es, adjs, inDegrees, coTasks, executed);
                }
            }
        }

        int result = 0;
        while (!coTasks.isEmpty()) {
            result++;
            Set<Integer> mainTasks = new HashSet<>();
            for (int task : coTasks) {
                execute(task, 1, es, adjs, inDegrees, mainTasks, executed);
            }
            Set<Integer> next = new HashSet<>();
            for (int task : mainTasks) {
                execute(task, 0, es, adjs, inDegrees, next, executed);
            }
            coTasks = next;
        }

        return result;
    }

    private void execute(int ind, int type, int[] es, List<Integer>[] adjs, int[] inDegrees, Set<Integer> tasks, boolean[] executed) {
        executed[ind] = true;
        for (int next : adjs[ind]) {
            inDegrees[next]--;
            if (inDegrees[next] == 0) {
                if (es[next] == type) {
                    if (!executed[next]) {
                        execute(next, type, es, adjs, inDegrees, tasks, executed);
                    }
                } else {
                    tasks.add(next);
                }
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
