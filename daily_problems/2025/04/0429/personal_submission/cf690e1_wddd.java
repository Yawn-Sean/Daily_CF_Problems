import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Classification1 {

    FastReader is;
    PrintWriter out;
    String INPUT = "";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Classification1().run();
    }

    void run() throws Exception {
        // is = oj ? new FastReader(System.in) : new FastReader(new ByteArrayInputStream(INPUT.getBytes()));
        File file = new File("src/codeforces/C690_E1_PhotographsI/easy_contestant_package/all.in");
        is = oj ? new FastReader(System.in) : new FastReader(file.toURI().toURL().openStream());
        out = new PrintWriter(System.out);

        long s = System.currentTimeMillis();
        solve();
        out.flush();
        objTr(System.currentTimeMillis() - s + "ms");
        out.close();
    }

    void solve() {
        int q = is.ni();
        int ind = 0;
        while (q > 0) {
            q--;

            int h = is.ni();
            int w = is.ni();
            int[][] image = is.nmi(h, w);

            classify(h, w, image, ind);
            ind++;
        }
    }

    private void classify(int h, int w, int[][] image, int ind) {
        int check = Math.min(h / 2, 10);
        int diff1 = 0;
        for (int i = h / 2 - check + 1; i <= h / 2 + check; i++) {
            for (int j = 0; j < w; j++) {
                if (i <= h / 2) {
                    diff1 += image[i][j];
                } else {
                    diff1 -= image[i][j];
                }
            }
        }

        int diff2 = 0;
        for (int i = 0; i < check; i++) {
            for (int j = 0; j < w; j++) {
                diff2 += image[i][j];
                diff2 -= image[h - 1 - i][j];
            }
        }

        // out.println(ind + " " + diff1 + " " + diff2 + " " + (diff1 - diff2));
        out.println(Math.abs(diff1) > Math.abs(diff2) ? "YES" : "NO");
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
