import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BinarySearch4 {

    FastReader is;
    PrintWriter out;
    String INPUT = "5\n" +
            "3 2\n" +
            "3 1\n" +
            "8 6\n" +
            "8 7 6 5 3 2\n" +
            "9 6\n" +
            "9 8 5 4 3 1\n" +
            "1 1\n" +
            "1\n" +
            "7 3\n" +
            "7 4 3\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new BinarySearch4().run();
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
        int t = is.ni();
        for (int i = 0; i < t; i++) {
            int h = is.ni();
            int n = is.ni();
            int[] p = is.na(n);
            jump(h, n, p);
        }
    }

    private void jump(int h, int n, int[] p) {
        int left = 0;
        int right = h;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (valid(h, p, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        out.println(left);
    }

    private boolean valid(int h, int[] p, int m) {
        int curr = h;
        int ind = 1;
        while (curr - 2 > 0) {
            int next = ind >= p.length ? -1 : p[ind];
            if (next == -1) {
                curr = 0;
            } else if (next != curr - 1) {
                curr = next + 1;
            } else {
                if (ind + 1 < p.length && p[ind + 1] == curr - 2) {
                    curr -= 2;
                    ind += 2;
                } else {
                    curr -= 2;
                    m--;
                    if (m < 0) {
                        return false;
                    }
                    ind += 1;
                }
            }
        }
        return true;
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
