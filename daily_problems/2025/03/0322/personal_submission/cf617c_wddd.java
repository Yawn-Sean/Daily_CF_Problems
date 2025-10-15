import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Sorting {

    FastReader is;
    PrintWriter out;
    String INPUT = "4 0 0 5 0\n" +
            "9 4\n" +
            "8 3\n" +
            "-1 0\n" +
            "1 4\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Sorting().run();
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
        int[] f1 = is.na(2);
        int[] f2 = is.na(2);
        int[][] flowers = is.nmi(n, 2);

        Integer[] inds1 = new Integer[n];
        Integer[] inds2 = new Integer[n];
        for (int i = 0; i < n; i++) {
            inds1[i] = i;
            inds2[i] = i;
        }
        Arrays.sort(inds1, Comparator.comparingLong(i -> dist(f1, flowers[i])));
        Arrays.sort(inds2, Comparator.comparingLong(i -> dist(f2, flowers[i])));

        long min = Math.min(dist(f1, flowers[inds1[n - 1]]), dist(f2, flowers[inds2[n - 1]]));

        boolean[] covered2 = new boolean[n];
        int ind2 = 0;
        for (int i = n - 1; i > 0; i--) {
            while (!covered2[inds1[i]]) {
                covered2[inds2[ind2]] = true;
                ind2++;
            }

            min = Math.min(min, dist(f1, flowers[inds1[i - 1]]) + dist(f2, flowers[inds2[ind2 - 1]]));
        }
        out.println(min);
    }

    private long dist(int[] a, int[] b) {
        return (long) (a[0] - b[0]) * (a[0] - b[0]) + (long) (a[1] - b[1]) * (a[1] - b[1]);
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
