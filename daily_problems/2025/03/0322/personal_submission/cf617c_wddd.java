import java.io.*;
import java.util.*;

public class Greedy {

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
        int p = is.ni();
        int k = is.ni();
        int[][] orders = new int[n][3];
        for (int i = 0; i < n; i++) {
            orders[i][0] = is.ni();
            orders[i][1] = is.ni();
            orders[i][2] = i;
        }

        Arrays.sort(orders, (x, y) -> {
            if (x[1] != y[1]) {
                return Integer.compare(y[1], x[1]);
            } else {
                return Integer.compare(x[0], y[0]);
            }
        });

        Integer[] inds1 = new Integer[n - (p - k)];
        for (int i = 0; i < inds1.length; i++) {
            inds1[i] = i;
        }
        Arrays.sort(inds1, (x, y) -> {
            if (orders[x][0] != orders[y][0]) {
                return Integer.compare(orders[y][0], orders[x][0]);
            } else {
                return Integer.compare(x, y);
            }
        });

        int maxPicked = inds1[0];
        for (int i = 1; i < k; i++) {
            if (inds1[i] > maxPicked) {
                maxPicked = inds1[i];
            }
        }

        List<Integer> inds2 = new ArrayList<>();
        for (int i = k; i < n; i++) {
            if (i < inds1.length) {
                if (inds1[i] <= maxPicked) {
                    continue;
                }
                inds2.add(inds1[i]);
            } else {
                inds2.add(i);
            }
        }
        Collections.sort(inds2, Comparator.comparingInt(i -> -orders[i][1]));

        for (int i = 0; i < k; i++) {
            out.print((orders[inds1[i]][2] + 1) + " ");
        }
        for (int i = 0; i < p - k; i++) {
            out.print((orders[inds2.get(i)][2] + 1) + " ");
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
