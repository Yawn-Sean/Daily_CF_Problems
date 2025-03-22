import java.io.*;
import java.util.*;

public class Heap {

    FastReader is;
    PrintWriter out;
//    String INPUT = "5 3 2\n" +
//            "5 6\n" +
//            "5 8\n" +
//            "1 3\n" +
//            "4 3\n" +
//            "4 11\n";
    String INPUT = "10 7 4\n" +
            "4 3\n" +
            "5 3\n" +
            "5 5\n" +
            "4 3\n" +
            "4 5\n" +
            "3 5\n" +
            "4 5\n" +
            "4 4\n" +
            "3 5\n" +
            "4 5";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Heap().run();
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
        int p = is.ni();
        int k = is.ni();
        int[][] orders = new int[n][3];
        for (int i = 0; i < n; i++) {
            orders[i][0] = is.ni();
            orders[i][1] = is.ni();
            orders[i][2] = i + 1;
        }

        Arrays.sort(orders, (x, y) -> {
            if (x[1] != y[1]) {
                return Integer.compare(y[1], x[1]);
            } else {
                return Integer.compare(x[0], y[0]);
            }
        });

        Queue<Integer> pq = new PriorityQueue<>(Comparator.comparingInt(i -> orders[i][0]));
        int last = 0;
        for (int i = 0; i < n - (p - k); i++) {
            if (pq.size() < k) {
                pq.add(i);
                last = i;
            } else {
                if (orders[pq.peek()][0] < orders[i][0]) {
                    pq.poll();
                    pq.add(i);
                    last = i;
                }
            }
        }

        for (int ind : pq) {
            out.print(orders[ind][2] + " ");
        }
        for (int i = last + 1; i < last + 1 + p - k; i++) {
            out.print(orders[i][2] + " ");
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
