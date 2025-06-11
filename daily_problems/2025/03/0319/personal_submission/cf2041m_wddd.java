import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Greedy {

    FastReader is;
    PrintWriter out;
//    String INPUT = "6\n" +
//            "3 2 5 5 4 1\n";
//    String INPUT = "4\n" +
//            "4 3 2 1\n";
//    String INPUT = "4\n" +
//            "1 2 3 4\n";
//    String INPUT = "5\n" +
//        "2 1 3 5 4\n";
    String INPUT = "20\n" +
        "2 1 3 4 20 19 9 10 5 6 7 8 11 12 13 14 15 16 17 18";

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

        int[][] a = new int[n][2];
        for (int i = 0; i < n; i++) {
            a[i][0] = is.ni();
            a[i][1] = i;
        }

        Arrays.sort(a, (x, y) -> {
            if (x[0] != y[0]) {
                return Integer.compare(x[0], y[0]);
            } else {
                return Integer.compare(x[1], y[1]);
            }
        });

        long minCost = (long) n * n;
        int lastCovered = n;
        int left = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            lastCovered = Math.min(lastCovered, a[i][1]);
            if (i >= lastCovered && left >= i) {
                left--;
            }
            while (left >= 0 && left < lastCovered && a[left][1] == left) {
                left--;
            }
            minCost = Math.min((long) (n - lastCovered) * (n - lastCovered) + (long) (left + 1) * (left + 1), minCost);
        }

        lastCovered = -1;
        int right = 0;
        for (int i = 0; i < n; i++) {
            lastCovered = Math.max(lastCovered, a[i][1]);
            if (i <= lastCovered && right <= i) {
                right++;
            }
            while (right < n && right > lastCovered && a[right][1] == right) {
                right++;
            }
            minCost = Math.min((long) (lastCovered + 1) * (lastCovered + 1) + (long) (n - right) * (n - right), minCost);
        }

        for (int i = n - 1; i >= 0; i--) {
            if (a[i][1] == i) {
                minCost = Math.min(minCost, (long) i * i);
            } else {
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i][1] == i) {
                minCost = Math.min(minCost, (long) (n - i) * (n - i));
            } else {
                break;
            }
        }
        out.println(minCost);
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
